# SDL2 Video Backend Contract

## Overview

SDL2 uses a driver/backend architecture for all subsystems. This document
describes the contract between the SDL2 core (SDL_video.c) and a video
backend driver. It covers every function pointer in SDL_VideoDevice that
is relevant to an AmigaOS 3.x software-renderer implementation.

GL/Vulkan/Metal sections are omitted. They are not applicable to AmigaOS 3.x.

Source files to read alongside this document:
  src/video/SDL_sysvideo.h          -- SDL_VideoDevice struct, VideoBootStrap
  src/video/SDL_video.c             -- core calls into the driver
  src/video/dummy/SDL_nullvideo.c   -- minimal working example
  src/video/amigaos3/SDL_os3video.c -- our implementation

---

## 1. VideoBootStrap -- Driver Registration

Every backend exports one VideoBootStrap. SDL_video.c includes it in the
static bootstrap[] array. The core tries each entry in order until one
succeeds.

```c
typedef struct VideoBootStrap
{
    const char *name;          /* short driver name, e.g. "amigaos3" */
    const char *desc;          /* human description */
    SDL_VideoDevice *(*create)(void);
    int (*ShowMessageBox)(const SDL_MessageBoxData *messageboxdata,
                          int *buttonid);
} VideoBootStrap;
```

Fields:

  name
    Short lowercase identifier. Appears in SDL_VIDEODRIVER environment
    variable. SDL_video.c does case-insensitive comparison when the user
    forces a specific driver via SDL_HINT_VIDEODRIVER.

  desc
    Human-readable description. Appears in SDL_GetVideoDriver() output.

  create
    Called to allocate and populate an SDL_VideoDevice. Must return NULL
    if the hardware is absent or the driver cannot be used. SDL_calloc
    the device so all function pointers default to NULL. Set only the
    pointers your backend implements.

    On AmigaOS 3.x: create() should return NULL when CyberGraphX is not
    installed. This lets SDL fall through to the dummy driver.

  ShowMessageBox
    Optional. May be called before VideoInit() -- for example, to report
    fatal errors at startup without a full video session. Set to NULL if
    not implemented.

Our bootstrap declaration (src/video/amigaos3/SDL_os3video.c):

```c
VideoBootStrap OS3_bootstrap = {
    "amigaos3", "AmigaOS 3.x CyberGraphX/P96",
    OS3_CreateDevice, NULL
};
```

And in src/video/SDL_video.c bootstrap[]:

```c
#ifdef SDL_VIDEO_DRIVER_AMIGAOS3
    &OS3_bootstrap,
#endif
```

---

## 2. SDL_VideoDevice -- The Driver Object

SDL_VideoDevice is allocated by create() using SDL_calloc(). All function
pointer fields default to NULL. Set only the slots you implement.

```c
struct SDL_VideoDevice
{
    const char *name;      /* set by SDL core from bootstrap->name */
    /* ... function pointers ... */
    int  num_displays;     /* SDL core manages this */
    SDL_VideoDisplay *displays;
    SDL_Window *windows;   /* linked list; SDL core manages */
    SDL_bool is_dummy;     /* set SDL_TRUE for stub-only drivers */
    Uint32 quirk_flags;    /* see DeviceQuirkFlags below */
    void *driverdata;      /* backend-private data */
    void (*free)(_THIS);   /* called to free the device; must SDL_free(device) */
};
```

The macro `_THIS` expands to `SDL_VideoDevice *_this`. All driver function
pointers take `_THIS` as the first argument so they can access shared state
via `_this->driverdata`, `_this->displays`, etc.

DeviceQuirkFlags (set in device->quirk_flags):

  VIDEO_DEVICE_QUIRK_DISABLE_DISPLAY_MODE_SWITCHING (0x01)
    SDL core will not call SetDisplayMode. Use for drivers that have no
    mode-switch capability.

  VIDEO_DEVICE_QUIRK_DISABLE_UNSET_FULLSCREEN_ON_MINIMIZE (0x02)
    SDL core will not leave fullscreen when the window is minimized.

  VIDEO_DEVICE_QUIRK_FULLSCREEN_ONLY (0x04)
    All windows are treated as fullscreen. SDL core ignores windowed
    positioning.

---

## 3. Initialization and Shutdown

### VideoInit

```c
int (*VideoInit)(_THIS);
```

Called once by SDL_VideoInit() after create() succeeds.

Responsibilities:
  1. Open platform libraries (graphics.library, intuition.library, etc.)
  2. Enumerate displays and call SDL_AddBasicVideoDisplay() for each.
     At least one display must be added or SDL_VideoInit() will fail.
  3. Optionally call SDL_AddDisplayMode() for each supported mode.
     GetDisplayModes (section 4) is called lazily if not done here.

Returns 0 on success, -1 with SDL_SetError on failure. If -1 is returned,
SDL_VideoQuit() is called immediately -- VideoQuit MUST handle partial
initialization (some libraries open, others not).

Example minimum (from dummy driver):

```c
int DUMMY_VideoInit(_THIS)
{
    SDL_DisplayMode mode;
    SDL_zero(mode);
    mode.format = SDL_PIXELFORMAT_RGB888;
    mode.w = 1024;
    mode.h = 768;
    mode.refresh_rate = 60;
    mode.driverdata = NULL;
    if (SDL_AddBasicVideoDisplay(&mode) < 0) {
        return -1;
    }
    SDL_AddDisplayMode(&_this->displays[0], &mode);
    return 0;
}
```

SDL_AddBasicVideoDisplay() creates a display with the given mode as both
desktop_mode and current_mode. SDL_AddDisplayMode() adds that mode to the
display's list of available modes.

### VideoQuit

```c
void (*VideoQuit)(_THIS);
```

Called by SDL_VideoQuit() when the video subsystem shuts down. DestroyWindow
will have been called on all windows before VideoQuit is called.

Responsibilities:
  1. Close all platform libraries opened in VideoInit.
  2. Free any driverdata allocated in VideoInit.
  3. Must tolerate being called after a partial VideoInit (some libraries
     open, some not).

The close order for AmigaOS libraries is the reverse of open order:
  Close: cybergraphics -> intuition -> graphics

### free

```c
void (*free)(_THIS);
```

Called to destroy the SDL_VideoDevice itself. Must call SDL_free(device).
This is separate from VideoQuit -- free() releases the struct after Quit
has cleaned up resources.

---

## 4. Display Mode Functions

### GetDisplayModes

```c
void (*GetDisplayModes)(_THIS, SDL_VideoDisplay *display);
```

Called lazily the first time SDL_GetNumDisplayModes() or
SDL_GetDisplayMode() is invoked for a display. Not called if modes were
already added in VideoInit.

Responsibilities:
  Call SDL_AddDisplayMode(display, &mode) for each supported resolution.
  Duplicates are ignored by SDL core. Modes are sorted by resolution
  (descending width, then height, then bits per pixel).

NULL is acceptable if modes were fully populated in VideoInit, or if the
driver supports only one mode.

SDL_DisplayMode fields:

```c
typedef struct SDL_DisplayMode
{
    Uint32 format;        /* SDL_PIXELFORMAT_* */
    int w;                /* width in pixels */
    int h;                /* height in pixels */
    int refresh_rate;     /* 0 = unspecified */
    void *driverdata;     /* driver's per-mode data, must initialize to NULL */
} SDL_DisplayMode;
```

driverdata is yours to use (e.g. store CyberGraphX ModeID). SDL core copies
the SDL_DisplayMode struct, so driverdata is also copied. If driverdata
points to allocated memory, you must be careful about lifetime -- the struct
copy does a shallow copy only.

For AmigaOS 3.x: store the CyberGraphX mode ID here if you need it in
SetDisplayMode. A plain ULONG packed into the void* is the simplest approach.

### SetDisplayMode

```c
int (*SetDisplayMode)(_THIS, SDL_VideoDisplay *display, SDL_DisplayMode *mode);
```

Called when SDL_SetWindowFullscreen() changes the display mode. Also called
with the desktop mode when returning to windowed.

The mode->driverdata field contains whatever you stored in GetDisplayModes.

Returns 0 on success, -1 on failure.

Set VIDEO_DEVICE_QUIRK_DISABLE_DISPLAY_MODE_SWITCHING to prevent SDL from
calling this at all (windowed-only driver).

NULL pointer is treated as unsupported; SDL core will not call it.

### GetDisplayBounds

```c
int (*GetDisplayBounds)(_THIS, SDL_VideoDisplay *display, SDL_Rect *rect);
```

Fills rect with the bounds (x, y, w, h) of the display. x and y are the
display's origin relative to the virtual desktop.

May be NULL. SDL core uses the current_mode dimensions as a fallback.

---

## 5. Window Lifecycle

### CreateSDLWindow

```c
int (*CreateSDLWindow)(_THIS, SDL_Window *window);
```

Called to create the native window for a new SDL_Window. SDL core has
already set window->w, window->h, window->x, window->y, window->flags,
and window->title.

Responsibilities:
  1. Allocate a private data struct (SDL_calloc) and store in window->driverdata.
  2. Open the native window using window->w, window->h, window->flags, etc.
  3. Store the native window handle in driverdata.

Returns 0 on success. Returns -1 and calls SDL_SetError on failure. If -1
is returned, SDL_DestroyWindow is called immediately -- DestroyWindow must
handle partial creation.

window->flags to check:

  SDL_WINDOW_FULLSCREEN (0x00000001)
    Open an exclusive fullscreen screen + borderless window.

  SDL_WINDOW_FULLSCREEN_DESKTOP (0x00001001)
    "Fake" fullscreen at current desktop resolution. On AmigaOS 3.x,
    treat like fullscreen but use the Workbench screen resolution.

  SDL_WINDOW_BORDERLESS (0x00000010)
    No window decoration (no title bar, no gadgets).

  SDL_WINDOW_RESIZABLE (0x00000020)
    Window may be resized by the user.

window->x and window->y:
  May be SDL_WINDOWPOS_CENTERED (0x2FFF0000) or SDL_WINDOWPOS_UNDEFINED
  (0x1FFF0000). Backend must choose a sensible position for these values.

After CreateSDLWindow, SDL core may call SetWindowTitle, ShowWindow, and
SetWindowFullscreen immediately (via SDL_FinishWindowCreation). The backend
must tolerate these calls on a newly created window.

### DestroyWindow

```c
void (*DestroyWindow)(_THIS, SDL_Window *window);
```

Called to close the native window. Also called to clean up if CreateSDLWindow
fails midway through.

Responsibilities:
  1. Call DestroyWindowFramebuffer if a framebuffer exists.
  2. Close native window.
  3. Close native screen (if fullscreen and driver owns the screen).
  4. SDL_free(window->driverdata) and set window->driverdata = NULL.

Close order on AmigaOS 3.x:
  DestroyWindowFramebuffer -> CloseWindow -> CloseScreen

DestroyWindow is guaranteed to be called before VideoQuit.

### SetWindowTitle

```c
void (*SetWindowTitle)(_THIS, SDL_Window *window);
```

Called when the application changes the window title. The new title is in
window->title (a char * owned by SDL core, valid for the duration of the
call).

NULL title should be treated as empty string.

### ShowWindow / HideWindow

```c
void (*ShowWindow)(_THIS, SDL_Window *window);
void (*HideWindow)(_THIS, SDL_Window *window);
```

ShowWindow makes the window visible. HideWindow hides it (typically to the
taskbar or as an iconified app).

On AmigaOS 3.x: Intuition windows are visible upon opening, so ShowWindow
is a no-op. HideWindow has no equivalent in bare Intuition without
workbench.library iconification support.

Both may be NULL if not implemented.

### RaiseWindow

```c
void (*RaiseWindow)(_THIS, SDL_Window *window);
```

Brings the window to the front and activates it. On AmigaOS 3.x: call
WindowToFront() then ActivateWindow().

May be NULL.

### SetWindowSize

```c
void (*SetWindowSize)(_THIS, SDL_Window *window);
```

Called when SDL_SetWindowSize() is called by the application. New size is
in window->w and window->h.

On AmigaOS 3.x: use SizeWindow() to resize the Intuition window. The
framebuffer must be invalidated -- SDL core will call CreateWindowFramebuffer
again on the next SDL_GetWindowSurface() call.

May be NULL if runtime resize is not supported.

### SetWindowPosition

```c
void (*SetWindowPosition)(_THIS, SDL_Window *window);
```

Called when SDL_SetWindowPosition() is called. New position is in window->x
and window->y.

On AmigaOS 3.x: use MoveWindow(). May be NULL for fullscreen-only drivers.

### SetWindowFullscreen

```c
void (*SetWindowFullscreen)(_THIS, SDL_Window *window,
                            SDL_VideoDisplay *display, SDL_bool fullscreen);
```

Called to transition an existing window in/out of fullscreen. This is
separate from the fullscreen flag at CreateSDLWindow time.

When fullscreen is SDL_TRUE: switch to fullscreen mode on display.
When fullscreen is SDL_FALSE: restore windowed mode.

On AmigaOS 3.x: close the current Intuition window+screen and reopen with
new parameters. The framebuffer is automatically destroyed/recreated by SDL
core around this call via DestroyWindowFramebuffer / CreateWindowFramebuffer.

May be NULL. If NULL, SDL core handles fullscreen transitions using
SetDisplayMode and window resize only -- suitable for drivers where
fullscreen is just a borderless window.

### SetWindowBordered / SetWindowResizable

```c
void (*SetWindowBordered)(_THIS, SDL_Window *window, SDL_bool bordered);
void (*SetWindowResizable)(_THIS, SDL_Window *window, SDL_bool resizable);
```

Called when the app changes border or resize flags at runtime.

On AmigaOS 3.x: requires reopening the window with new WFLG_ flags.
Costly. May be NULL for Phase 1.

### MinimizeWindow / MaximizeWindow / RestoreWindow

```c
void (*MinimizeWindow)(_THIS, SDL_Window *window);
void (*MaximizeWindow)(_THIS, SDL_Window *window);
void (*RestoreWindow)(_THIS, SDL_Window *window);
```

Minimize/maximize/restore window operations. All may be NULL.

On AmigaOS 3.x: iconification requires workbench.library. These are
no-ops for Phase 1.

### OnWindowEnter

```c
void (*OnWindowEnter)(_THIS, SDL_Window *window);
```

Called by SDL core when a window receives mouse focus (SDL_WINDOWEVENT_ENTER
is sent). The backend may adjust cursor handling here.

May be NULL.

---

## 6. Framebuffer Functions (Software Renderer Path)

These three functions implement the SDL_GetWindowSurface() / SDL_UpdateWindowSurface()
software rendering path. The application renders into a CPU-side SDL_Surface
and the backend blits it to the physical display.

This is the primary rendering path for AmigaOS 3.x (no GPU renderer).

### CreateWindowFramebuffer

```c
int (*CreateWindowFramebuffer)(_THIS, SDL_Window *window,
                               Uint32 *format, void **pixels, int *pitch);
```

Called by SDL core the first time SDL_GetWindowSurface() is called, and
again whenever the window size changes.

Responsibilities:
  1. Free any existing framebuffer (call DestroyWindowFramebuffer first).
  2. Get pixel dimensions: SDL_GetWindowSizeInPixels(window, &w, &h).
  3. Allocate a pixel buffer (usually an SDL_Surface).
  4. Store the surface in window->driverdata or SDL_SetWindowData().
  5. Set *format to the SDL_PIXELFORMAT_* for the allocated buffer.
  6. Set *pixels to the start of the pixel data.
  7. Set *pitch to the byte stride (bytes per row).

Returns 0 on success, -1 on failure.

SDL core will call SDL_PixelFormatEnumToMasks() on the returned format to
wrap the pixel pointer in an SDL_Surface. The surface is owned by SDL core
(window->surface). The backend only owns the pixel memory.

Format selection: pick the format that requires the least conversion for
your display hardware. On CyberGraphX with an ARGB32 board:
  SDL_PIXELFORMAT_ARGB8888 maps directly to RECTFMT_ARGB.
On 16-bit boards: SDL_PIXELFORMAT_RGB565 maps to RECTFMT_RGB16.

Example (from our AmigaOS 3.x driver):

```c
int OS3_CreateWindowFramebuffer(_THIS, SDL_Window *window,
                                Uint32 *format, void **pixels, int *pitch)
{
    SDL_Surface *surface;
    int w, h;

    OS3_DestroyWindowFramebuffer(_this, window);
    SDL_GetWindowSizeInPixels(window, &w, &h);

    surface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32,
                                            SDL_PIXELFORMAT_ARGB8888);
    if (!surface) return -1;

    SDL_SetWindowData(window, "_SDL_OS3Surface", surface);
    *format = SDL_PIXELFORMAT_ARGB8888;
    *pixels = surface->pixels;
    *pitch  = surface->pitch;
    return 0;
}
```

### UpdateWindowFramebuffer

```c
int (*UpdateWindowFramebuffer)(_THIS, SDL_Window *window,
                               const SDL_Rect *rects, int numrects);
```

Called by SDL_UpdateWindowSurface() and SDL_UpdateWindowSurfaceRects().
Blits the dirty rectangles from the CPU framebuffer to the display.

Responsibilities:
  1. Retrieve the framebuffer surface from driverdata/SDL_GetWindowData().
  2. For each rect in rects[0..numrects-1]: blit the pixels to the display.
  3. Rects may be empty (w==0 or h==0). Skip them.

Returns 0 on success, -1 on failure.

On AmigaOS 3.x: use WritePixelArray() to blit each dirty rect from the
SDL surface's pixel buffer to the Intuition window's RastPort. With
WA_GimmeZeroZero, coordinate (0,0) of the RastPort equals the top-left
of the window's inner area -- so rect->x, rect->y map directly.

The rects array is not guaranteed to cover the full window. SDL core
optimizes updates to dirty regions only.

### DestroyWindowFramebuffer

```c
void (*DestroyWindowFramebuffer)(_THIS, SDL_Window *window);
```

Free the framebuffer allocation. Called before window destruction and
before CreateWindowFramebuffer is called again (e.g., on resize).

Responsibilities:
  1. Retrieve the surface from SDL_SetWindowData(window, key, NULL).
  2. Call SDL_FreeSurface(surface).

Using SDL_SetWindowData with key=NULL both retrieves and removes the data
from the window's data map in one call.

Example:

```c
void OS3_DestroyWindowFramebuffer(_THIS, SDL_Window *window)
{
    SDL_Surface *surface;
    surface = (SDL_Surface *)SDL_SetWindowData(window, "_SDL_OS3Surface", NULL);
    SDL_FreeSurface(surface);
}
```

---

## 7. PumpEvents -- The Event Pump

```c
void (*PumpEvents)(_THIS);
```

Called from SDL_PumpEvents(), which is called from SDL_PollEvent() and
SDL_WaitEventTimeout().

Responsibilities:
  1. Drain the native event queue (non-blocking -- do NOT block waiting).
  2. Translate each platform event to an SDL event by calling the SDL
     internal Send* functions.
  3. Return immediately if no events are pending.

PumpEvents must never block. SDL_WaitEventTimeout() handles the waiting
itself; PumpEvents is called inside that loop.

Walk _this->windows (linked list via SDL_Window.next) to find all open
windows and their native handles. Drain each window's message queue.

### Event Translation Functions

Send functions to call from PumpEvents:

```c
/* Keyboard -- include src/events/SDL_keyboard_c.h */
int SDL_SendKeyboardKey(Uint8 state, SDL_Scancode scancode);
    /* state: SDL_PRESSED or SDL_RELEASED */
    /* scancode: SDL_Scancode value from your rawkey table */

/* Mouse motion -- include src/events/SDL_mouse_c.h */
int SDL_SendMouseMotion(SDL_Window *window, SDL_MouseID mouseID,
                        int relative, int x, int y);
    /* mouseID: 0 for default mouse */
    /* relative: 0 for absolute coordinates, 1 for relative delta */
    /* x, y: position in window client coordinates */

/* Mouse button -- include src/events/SDL_mouse_c.h */
int SDL_SendMouseButton(SDL_Window *window, SDL_MouseID mouseID,
                        Uint8 state, Uint8 button);
    /* button: SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT, SDL_BUTTON_MIDDLE */

/* Mouse wheel -- include src/events/SDL_mouse_c.h */
int SDL_SendMouseWheel(SDL_Window *window, SDL_MouseID mouseID,
                       float x, float y, SDL_MouseWheelDirection direction);

/* Window events -- include src/events/SDL_windowevents_c.h */
int SDL_SendWindowEvent(SDL_Window *window, Uint8 windowevent,
                        int data1, int data2);
    /* windowevent: SDL_WINDOWEVENT_* constants */
    /* data1, data2: event-specific payload (see below) */
```

SDL_WINDOWEVENT constants used from an AmigaOS 3.x IDCMP pump:

  SDL_WINDOWEVENT_CLOSE         -- IDCMP_CLOSEWINDOW
  SDL_WINDOWEVENT_RESIZED       -- IDCMP_NEWSIZE; data1=newW, data2=newH
  SDL_WINDOWEVENT_FOCUS_GAINED  -- IDCMP_ACTIVEWINDOW
  SDL_WINDOWEVENT_FOCUS_LOST    -- IDCMP_INACTIVEWINDOW
  SDL_WINDOWEVENT_ENTER         -- mouse entered window (if reported)
  SDL_WINDOWEVENT_LEAVE         -- mouse left window

### AmigaOS 3.x IDCMP Pump Pattern

Critical: copy IntuiMessage fields BEFORE calling ReplyMsg(). Intuition
owns the IntuiMessage; after ReplyMsg, the message memory may be reused.

```c
void OS3_PumpEvents(_THIS)
{
    SDL_Window *sdlwin;
    for (sdlwin = _this->windows; sdlwin; sdlwin = sdlwin->next) {
        OS3_WindowData *data = (OS3_WindowData *)sdlwin->driverdata;
        struct IntuiMessage *imsg;

        while ((imsg = (struct IntuiMessage *)
                       GetMsg(data->window->UserPort)) != NULL) {
            ULONG class  = imsg->Class;  /* copy before ReplyMsg */
            UWORD code   = imsg->Code;
            WORD  mousex = imsg->MouseX;
            WORD  mousey = imsg->MouseY;

            ReplyMsg((struct Message *)imsg);  /* MUST come before processing */

            switch (class) {
            case IDCMP_RAWKEY:
                /* translate code to SDL_Scancode, call SDL_SendKeyboardKey */
                break;
            case IDCMP_MOUSEBUTTONS:
                /* call SDL_SendMouseButton */
                break;
            case IDCMP_MOUSEMOVE:
                SDL_SendMouseMotion(sdlwin, 0, 0, mousex, mousey);
                break;
            case IDCMP_CLOSEWINDOW:
                SDL_SendWindowEvent(sdlwin, SDL_WINDOWEVENT_CLOSE, 0, 0);
                break;
            }
        }
    }
}
```

See also: crash-patterns.md -- ReplyMsg before processing is documented
there as a critical ordering requirement.

---

## 8. Optional Event Functions

### WaitEventTimeout

```c
int (*WaitEventTimeout)(_THIS, int timeout);
```

If implemented alongside SendWakeupEvent, SDL core uses this instead of
spin-polling PumpEvents. Allows the process to sleep until an event
arrives, saving CPU.

timeout is in milliseconds. Return value is not used by SDL core.

On AmigaOS 3.x: use Wait() with a signal mask covering all open window
UserPorts plus a timer signal. This is Phase 2+ work.

If NULL, SDL core spin-polls PumpEvents with a small sleep interval.

### SendWakeupEvent

```c
void (*SendWakeupEvent)(_THIS, SDL_Window *window);
```

Called from another thread to wake up a thread blocked in WaitEventTimeout.
Must be thread-safe.

On AmigaOS 3.x: Signal() the task that owns the event loop.

If NULL (and WaitEventTimeout is also NULL), SDL uses the fallback
spin-poll path.

---

## 9. NULL Means Unsupported

Every function pointer in SDL_VideoDevice defaults to NULL (because
create() uses SDL_calloc). SDL core checks for NULL before calling most
optional functions. NULL is not an error.

Required minimum for a software-renderer backend:

  VideoInit          -- required; must add at least one display
  VideoQuit          -- required; must close libraries
  free               -- required; must SDL_free(device)
  PumpEvents         -- required; even an empty function body works
  CreateSDLWindow    -- required for any windowing to work
  DestroyWindow      -- required
  CreateWindowFramebuffer   -- required for SDL_GetWindowSurface()
  UpdateWindowFramebuffer   -- required for SDL_UpdateWindowSurface()
  DestroyWindowFramebuffer  -- required

All other pointers may be NULL for Phase 1.

---

## 10. driverdata Patterns

SDL_VideoDevice, SDL_VideoDisplay, SDL_Window, and SDL_DisplayMode each
have a void *driverdata field for backend-private data.

  SDL_VideoDevice.driverdata
    Global backend state. Open once in VideoInit, free in VideoQuit.

  SDL_VideoDisplay.driverdata
    Per-display data. Allocated in VideoInit when creating the display.
    Example: OS3_DisplayData with modeID, width, height, depth.

  SDL_Window.driverdata
    Per-window data. Allocated in CreateSDLWindow, freed in DestroyWindow.
    Example: OS3_WindowData with struct Window *, struct Screen *, flags.

  SDL_DisplayMode.driverdata
    Per-mode data. Set in GetDisplayModes. SDL copies the struct so this
    is a shallow copy -- pointer values are copied, not the pointed-to data.
    Safest approach: pack a ULONG value directly into the void* pointer
    field via a cast.

SDL_SetWindowData / SDL_GetWindowData provide a named key-value map for
per-window data beyond the single driverdata pointer. Use for framebuffer
surfaces and other ancillary data:

```c
SDL_SetWindowData(window, "mykey", ptr);   /* store */
ptr = SDL_GetWindowData(window, "mykey");  /* retrieve */
ptr = SDL_SetWindowData(window, "mykey", NULL);  /* remove and return old */
```

---

## 11. Display Registration Helpers

These are internal SDL_sysvideo.h functions called by the backend during
VideoInit and GetDisplayModes:

```c
/* Create a display with desktop_mode as the current mode. Returns index. */
int SDL_AddBasicVideoDisplay(const SDL_DisplayMode *desktop_mode);

/* Create a display from a full SDL_VideoDisplay struct. Returns index. */
int SDL_AddVideoDisplay(const SDL_VideoDisplay *display, SDL_bool send_event);

/* Add a mode to a display's mode list. Returns SDL_TRUE if added (not dup). */
SDL_bool SDL_AddDisplayMode(SDL_VideoDisplay *display,
                            const SDL_DisplayMode *mode);

/* Update the current mode for a display. */
void SDL_SetCurrentDisplayMode(SDL_VideoDisplay *display,
                               const SDL_DisplayMode *mode);
```

Minimum VideoInit sequence for a single-display driver:

```c
SDL_DisplayMode mode;
SDL_zero(mode);
mode.format = SDL_PIXELFORMAT_ARGB8888;
mode.w = 640;
mode.h = 480;
mode.refresh_rate = 60;
SDL_AddBasicVideoDisplay(&mode);       /* display 0 */
SDL_AddDisplayMode(&_this->displays[0], &mode);
```

---

## 12. Pixel Format Constants

Pixel formats used in SDL_DisplayMode.format and returned from
CreateWindowFramebuffer:

  SDL_PIXELFORMAT_ARGB8888   -- 32-bit ARGB, most common on RTG boards
  SDL_PIXELFORMAT_RGB888     -- 32-bit, no alpha (same storage as ARGB8888)
  SDL_PIXELFORMAT_RGB565     -- 16-bit 5-6-5
  SDL_PIXELFORMAT_RGB555     -- 15-bit 5-5-5
  SDL_PIXELFORMAT_RGB24      -- 24-bit packed (rare on Amiga)
  SDL_PIXELFORMAT_UNKNOWN    -- indicates unsupported/unrecognized

CyberGraphX RECTFMT to SDL_PIXELFORMAT mapping (for WritePixelArray):

  RECTFMT_ARGB   <-> SDL_PIXELFORMAT_ARGB8888
  RECTFMT_RGB16  <-> SDL_PIXELFORMAT_RGB565
  RECTFMT_RGB15  <-> SDL_PIXELFORMAT_RGB555
  RECTFMT_RGB    <-> SDL_PIXELFORMAT_RGB24

Choose the same format for CreateWindowFramebuffer that matches your
WritePixelArray RECTFMT to avoid color conversion on every blit.

---

## 13. Common Pitfalls

### Framebuffer not recreated on resize

When SetWindowSize is called, the existing framebuffer is stale (wrong
dimensions). SDL core sets window->surface_valid = SDL_FALSE after a resize
event (SDL_WINDOWEVENT_RESIZED). On the next SDL_GetWindowSurface() call,
SDL_CreateWindowFramebuffer is called again. The backend does not need to
recreate the framebuffer in SetWindowSize -- but DestroyWindowFramebuffer
must be idempotent (safe to call when no framebuffer exists).

### SDL_GetWindowSizeInPixels vs window->w / window->h

Always call SDL_GetWindowSizeInPixels(window, &w, &h) in
CreateWindowFramebuffer rather than reading window->w and window->h
directly. On HiDPI systems the pixel size differs from the logical size.
On AmigaOS 3.x they are always equal, but using the API is correct practice.

### PumpEvents must be non-blocking

If PumpEvents blocks even briefly (e.g., calling Wait() with a zero timeout
that can stall), SDL_PollEvent() will block too. Use GetMsg() (non-blocking)
not WaitPort() (blocking) in the IDCMP loop.

### IntuiMessage must be replied before processing

See crash-patterns.md. Copy Class, Code, MouseX, MouseY from the
IntuiMessage into local variables, then call ReplyMsg(), then process.
Processing may allocate memory or call OS functions that require Intuition's
message memory to be free.

### window->driverdata is NULL if CreateSDLWindow failed

DestroyWindow is called if CreateSDLWindow fails midway. DestroyWindow
must check for window->driverdata == NULL and return immediately.

### Library close order

On AmigaOS 3.x, VideoQuit must close libraries in reverse order:
  cybergraphics.library -> intuition.library -> graphics.library
Closing graphics.library before intuition.library causes a crash because
intuition depends on graphics.

---

## 14. SDL_Window Flags Reference

Flags available in window->flags when CreateSDLWindow is called:

  SDL_WINDOW_FULLSCREEN          0x00000001  exclusive fullscreen
  SDL_WINDOW_OPENGL              0x00000002  (ignore; not used on AmigaOS3)
  SDL_WINDOW_SHOWN               0x00000004  window should be visible
  SDL_WINDOW_HIDDEN              0x00000008  window should be hidden
  SDL_WINDOW_BORDERLESS          0x00000010  no decorations
  SDL_WINDOW_RESIZABLE           0x00000020  user can resize
  SDL_WINDOW_MINIMIZED           0x00000040  start minimized
  SDL_WINDOW_MAXIMIZED           0x00000080  start maximized
  SDL_WINDOW_FULLSCREEN_DESKTOP  0x00001001  desktop fullscreen (fake)

SDL_WINDOW_SHOWN is set internally by SDL after creation. At CreateSDLWindow
time the window is created but not yet shown -- however on AmigaOS 3.x,
OpenWindowTags() makes it visible immediately. This is fine; SDL core
tolerates the window being visible before ShowWindow() is called.
