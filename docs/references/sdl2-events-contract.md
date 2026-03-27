# SDL2 Backend Events Contract

## Overview

SDL2 event handling is split between the core event system and the platform
backend.  The core (src/events/) owns the event queue, event structs, and all
consumer-facing functions (SDL_PollEvent, SDL_WaitEvent).  The backend owns
only one thing: translating platform events into calls to the SDL_Send*
family of functions.

This document covers everything a backend implementer needs to know to wire
up IDCMP messages (or any other platform event source) into SDL2's event
system.  All information is derived from the SDL2 source tree in this repo.

## Call Chain: SDL_PollEvent to PumpEvents

```
Application calls SDL_PollEvent(event)
  -> SDL_WaitEventTimeout(event, 0)           [SDL_events.c]
    -> SDL_PumpEventsInternal(push_sentinel)  [SDL_events.c]
      -> _this->PumpEvents(_this)             [SDL_sysvideo.h]
        -> OS3_PumpEvents(_this)              [SDL_os3events.c]
          -> SDL_SendKeyboardKey(...)
          -> SDL_SendMouseMotion(...)
          -> SDL_SendMouseButton(...)
          -> SDL_SendMouseWheel(...)
          -> SDL_SendWindowEvent(...)
      -> SDL_JoystickUpdate()   (if joystick enabled)
      -> SDL_SensorUpdate()     (if sensor enabled)
    -> SDL_PeepEvents(event, 1, SDL_GETEVENT, ...)
  returns 1 if event was available, 0 if not
```

The key insight: SDL2 calls _this->PumpEvents() from inside
SDL_WaitEventTimeout's polling loop.  The backend must drain ALL pending
platform events in a single PumpEvents() call, because SDL_PollEvent expects
to find events already queued when PeepEvents runs immediately after.

## PumpEvents Contract

Function pointer in SDL_VideoDevice:

```c
void (*PumpEvents)(_THIS);
```

Rules that must hold:

1. NON-BLOCKING.  PumpEvents must never sleep or block waiting for an event.
   Drain only what is already available.  SDL_WaitEventTimeout handles the
   blocking loop at a higher level via WaitEventTimeout device callback.

2. DRAIN ALL PENDING.  Process every queued platform event before returning.
   If only one message is processed per call, SDL_PollEvent will appear to
   stall on multi-message sequences.

3. NO DIRECT QUEUE MANIPULATION.  The backend must not call SDL_PushEvent or
   touch SDL_EventQ directly.  Only call the SDL_Send* functions listed in
   this document.

4. THREAD SAFETY.  SDL2 calls PumpEvents from the main thread only (the
   thread that called SDL_Init).  On AmigaOS 3.x this is fine since IDCMP
   messages are per-window and owned by the creating process.

5. REPLY PLATFORM MESSAGES PROMPTLY.  On AmigaOS 3.x, IntuiMessages are in
   Intuition's memory.  Copy all required fields (Class, Code, MouseX,
   MouseY) before calling ReplyMsg().  Never read imsg fields after
   ReplyMsg().  This is a hard crash if violated.

### AmigaOS 3.x PumpEvents skeleton

```c
void OS3_PumpEvents(_THIS)
{
    SDL_Window *sdlwin;
    OS3_WindowData *data;
    struct IntuiMessage *imsg;
    ULONG  class;
    UWORD  code;
    WORD   mousex, mousey;

    for (sdlwin = _this->windows; sdlwin; sdlwin = sdlwin->next) {
        data = (OS3_WindowData *)sdlwin->driverdata;
        if (!data || !data->window) continue;

        while ((imsg = (struct IntuiMessage *)
                GetMsg(data->window->UserPort)) != NULL)
        {
            /* Copy BEFORE ReplyMsg -- message is Intuition's memory */
            class  = imsg->Class;
            code   = imsg->Code;
            mousex = imsg->MouseX;
            mousey = imsg->MouseY;
            ReplyMsg((struct Message *)imsg);

            /* Now translate the copy */
            switch (class) {
            case IDCMP_RAWKEY:
                /* ... */
            }
        }
    }
}
```

## Keyboard Events

### SDL_SendKeyboardKey

```c
int SDL_SendKeyboardKey(Uint8 state, SDL_Scancode scancode);
```

Defined in: src/events/SDL_keyboard_c.h

Parameters:
- state: SDL_PRESSED (1) or SDL_RELEASED (0)
- scancode: an SDL_Scancode value; SDL_SCANCODE_UNKNOWN silently returns 0

Returns: 1 if an event was posted, 0 if it was filtered or a no-op.

Internally this function:
- Updates keyboard->keystate[scancode]
- Derives the SDL_Keycode from keyboard->keymap[scancode]
- Posts SDL_KEYDOWN or SDL_KEYUP to the event queue
- Updates modifier state (Shift, Ctrl, Alt, GUI, CapsLock, Numlock)
- Detects repeat (key pressed while already pressed)

The backend does NOT need to track modifier state or repeat.  SDL2 handles
both.

### SDL_SetKeyboardFocus

```c
void SDL_SetKeyboardFocus(SDL_Window *window);
```

Defined in: src/events/SDL_keyboard_c.h

Call this when the keyboard input focus changes to a window.  SDL2 uses this
to direct keyboard events.  When focus is NULL, SDL2 resets all key states
(sends SDL_KEYUP for every key that appears pressed).

SDL2 also posts SDL_WINDOWEVENT_FOCUS_GAINED / SDL_WINDOWEVENT_FOCUS_LOST as
a side effect of SetKeyboardFocus -- do NOT also send those window events
manually when using SetKeyboardFocus.

Alternatively, if focus is tracked via IDCMP_ACTIVEWINDOW and
IDCMP_INACTIVEWINDOW directly as window events, call SDL_SendWindowEvent with
SDL_WINDOWEVENT_FOCUS_GAINED/LOST instead of SetKeyboardFocus.  Pick one
approach and do not mix them.

### SDL_SendKeyboardText

```c
int SDL_SendKeyboardText(const char *text);
```

Defined in: src/events/SDL_keyboard_c.h

Sends an SDL_TEXTINPUT event.  The text must be UTF-8.  Only relevant when
the application has enabled text input mode via SDL_StartTextInput().

On AmigaOS 3.x this requires converting Amiga character codes (Latin-1 or
Amiga character set) to UTF-8.  For ASCII characters this is trivial.  For
non-ASCII characters (accented letters, AltGr symbols) IntuiMessage.Code
under IDCMP_RAWKEY contains the physical key only; the actual character
requires mapping through InputEvent/MapRawKey.

### Scancode Table Pattern

SDL_Scancode values are based on USB HID usage page 0x07.  They are
physical key positions, not characters.  SDL_SCANCODE_A is always the A
physical key regardless of keyboard layout.

The standard backend pattern is a static lookup table indexed by the
platform keycode:

```c
static const SDL_Scancode os3_scancode_table[0x78] = {
    /* 0x00 */ SDL_SCANCODE_GRAVE,
    /* 0x01 */ SDL_SCANCODE_1,
    /* ... */
    /* 0x78 entries, SDL_SCANCODE_UNKNOWN for unmapped positions */
};
```

Usage:

```c
static void OS3_HandleRawKey(SDL_Window *win, UWORD code)
{
    Uint8 state   = (code & 0x80) ? SDL_RELEASED : SDL_PRESSED;
    UWORD rawcode = code & ~0x80;

    if (rawcode >= 0x78) return;

    SDL_Scancode sc = os3_scancode_table[rawcode];
    if (sc == SDL_SCANCODE_UNKNOWN) return;

    SDL_SendKeyboardKey(state, sc);
}
```

The release flag on Amiga is bit 7 of the raw keycode (0x80 = key up).
Defined as AMIGA_KEY_UP 0x80 in SDL_os3events.c.

### Amiga Rawkey to SDL_Scancode Table (complete)

The table in src/video/amigaos3/SDL_os3events.c maps all 0x00-0x77 Amiga
rawkey codes.  Key mappings:

Row 0 (0x00-0x0F): ` 1 2 3 4 5 6 7 8 9 0 - = (intl) undef KP0
Row 1 (0x10-0x1F): Q W E R T Y U I O P [ ] undef KP1 KP2 KP3
Row 2 (0x20-0x2F): A S D F G H J K L ; ' (intl) undef KP4 KP5 KP6
Row 3 (0x30-0x3F): (intl) Z X C V B N M , . / undef KP. KP7 KP8 KP9
Row 4 (0x40-0x4F): Space Backspace Tab KPEnter Return Escape Delete
                   undef undef undef KP- undef Up Down Right Left
Row 5 (0x50-0x5F): F1 F2 F3 F4 F5 F6 F7 F8 F9 F10 undef undef
                   KP/ KP* KP+ Help
Row 6 (0x60-0x67): LShift RShift CapsLock LCtrl LAlt(LGUI) RAlt(RGUI)
                   LAlt(LALT) RAlt(RALT)

Notes:
- 0x64 (Left Amiga) maps to SDL_SCANCODE_LGUI (Windows/Command key)
- 0x65 (Right Amiga) maps to SDL_SCANCODE_RGUI
- 0x5F (Help) maps to SDL_SCANCODE_HELP
- 0x0D (international key left of backspace) maps to SDL_SCANCODE_BACKSLASH
- 0x2B (international #~ on UK layout) is SDL_SCANCODE_UNKNOWN
- 0x30 (international </> on DE layout) is SDL_SCANCODE_UNKNOWN
- Amiga has no Scroll Lock, Print Screen, Insert, Home, PageUp, PageDown,
  End, or Pause keys; leave them as SDL_SCANCODE_UNKNOWN


## Mouse Events

### SDL_SendMouseMotion

```c
int SDL_SendMouseMotion(SDL_Window *window, SDL_MouseID mouseID,
                        int relative, int x, int y);
```

Defined in: src/events/SDL_mouse_c.h

Parameters:
- window: the window that currently has mouse focus
- mouseID: device ID; use 0 for the primary mouse
- relative: 1 if x/y are deltas; 0 if x/y are absolute coordinates
- x, y: position or delta depending on relative flag

When relative is 0 (absolute), SDL2 automatically computes xrel/yrel
for the SDL_MouseMotionEvent by subtracting the previous position.
Duplicate positions (no actual movement) are silently dropped.

SDL2 also calls SDL_SetMouseFocus() internally if the absolute position
is inside the window.

For AmigaOS 3.x with WA_GimmeZeroZero windows, IntuiMessage.MouseX/Y
are already relative to the window's inner area.  Pass relative=0 and
the raw coordinates:

```c
case IDCMP_MOUSEMOVE:
    SDL_SendMouseMotion(sdlwin, 0, 0, (int)imsg->MouseX, (int)imsg->MouseY);
    break;
```

### SDL_SendMouseButton

```c
int SDL_SendMouseButton(SDL_Window *window, SDL_MouseID mouseID,
                        Uint8 state, Uint8 button);
```

Defined in: src/events/SDL_mouse_c.h

Parameters:
- state: SDL_PRESSED or SDL_RELEASED
- button: SDL_BUTTON_LEFT (1), SDL_BUTTON_MIDDLE (2), SDL_BUTTON_RIGHT (3),
          SDL_BUTTON_X1 (4), SDL_BUTTON_X2 (5)

For AmigaOS 3.x, IDCMP_MOUSEBUTTONS carries the button code in
IntuiMessage.Code.  IECODE_UP_PREFIX (0x80) is set on release.

```c
static void OS3_HandleMouseButton(SDL_Window *win, UWORD code)
{
    Uint8 state  = (code & IECODE_UP_PREFIX) ? SDL_RELEASED : SDL_PRESSED;
    UWORD btn    = code & ~IECODE_UP_PREFIX;
    Uint8 button;

    switch (btn) {
    case IECODE_LBUTTON: button = SDL_BUTTON_LEFT;   break;
    case IECODE_RBUTTON: button = SDL_BUTTON_RIGHT;  break;
    case IECODE_MBUTTON: button = SDL_BUTTON_MIDDLE; break;
    default: return;
    }
    SDL_SendMouseButton(win, 0, state, button);
}
```

### SDL_SendMouseWheel

```c
int SDL_SendMouseWheel(SDL_Window *window, SDL_MouseID mouseID,
                       float x, float y, SDL_MouseWheelDirection direction);
```

Defined in: src/events/SDL_mouse_c.h

Parameters:
- x: horizontal scroll, positive = right, negative = left
- y: vertical scroll, positive = away from user (scroll up), negative = toward
- direction: SDL_MOUSEWHEEL_NORMAL or SDL_MOUSEWHEEL_FLIPPED

AmigaOS 3.x does not have a hardware scroll wheel event in IDCMP.  Scroll
wheel events from USB mice under MUI or third-party drivers may come as
custom IDCMP messages or separate input events.  If not available, do not
send wheel events; the application will function without them.

### SDL_SetMouseFocus

```c
void SDL_SetMouseFocus(SDL_Window *window);
```

Defined in: src/events/SDL_mouse_c.h

Sets which window currently has mouse focus.  SDL_SendMouseMotion calls this
automatically for absolute motion.  Direct calls are only needed when the
mouse leaves the window without a final motion event (i.e., send
SDL_SetMouseFocus(NULL) or use SDL_SendWindowEvent LEAVE).


## Window Events

### SDL_SendWindowEvent

```c
int SDL_SendWindowEvent(SDL_Window *window, Uint8 windowevent,
                        int data1, int data2);
```

Defined in: src/events/SDL_windowevents_c.h

This is the single function for all window state changes.  The windowevent
parameter is one of the SDL_WindowEventID values from SDL_video.h.

Duplicate events are filtered.  For example, if a window already has
SDL_WINDOW_INPUT_FOCUS set, sending SDL_WINDOWEVENT_FOCUS_GAINED is a no-op.

### Window Event IDs and Their data1/data2 Meanings

SDL_WINDOWEVENT_SHOWN        -- data1=0, data2=0
    Window made visible.  Opposite: HIDDEN.
    SDL2 updates window->flags automatically.

SDL_WINDOWEVENT_HIDDEN       -- data1=0, data2=0
    Window hidden.

SDL_WINDOWEVENT_EXPOSED      -- data1=0, data2=0
    Window needs redraw.  Duplicate EXPOSED events are coalesced.
    Send on IDCMP_REFRESHWINDOW.  On AmigaOS 3.x you must also call
    BeginRefresh/EndRefresh; do that BEFORE sending the SDL event.

SDL_WINDOWEVENT_MOVED        -- data1=new_x, data2=new_y
    Window position changed.  Duplicate moves are coalesced.
    On AmigaOS 3.x send on IDCMP_NEWPOSITION (if used) or when the Intuition
    Window->LeftEdge/TopEdge changes.

SDL_WINDOWEVENT_RESIZED      -- data1=new_w, data2=new_h
    Window was resized by the user.  data1/data2 are in pixels.
    On AmigaOS 3.x with WA_GimmeZeroZero windows, use GZZWidth/GZZHeight
    (inner size excluding border and title bar).

SDL_WINDOWEVENT_SIZE_CHANGED -- data1=new_w, data2=new_h
    Window size changed by any means (program or user).  Typically backends
    send SIZE_CHANGED; RESIZED is for user-initiated resizes.  The SDL2
    window event code coalesces SIZE_CHANGED events in the queue.
    On AmigaOS 3.x, send on IDCMP_NEWSIZE:

```c
case IDCMP_NEWSIZE:
    SDL_SendWindowEvent(sdlwin, SDL_WINDOWEVENT_RESIZED,
                        (int)intuiwin->GZZWidth,
                        (int)intuiwin->GZZHeight);
    break;
```

SDL_WINDOWEVENT_MINIMIZED    -- data1=0, data2=0
    Window iconified/minimized.  No Amiga equivalent; omit.

SDL_WINDOWEVENT_MAXIMIZED    -- data1=0, data2=0
    Window maximized.  No Amiga equivalent; omit.

SDL_WINDOWEVENT_RESTORED     -- data1=0, data2=0
    Window un-minimized or un-maximized.

SDL_WINDOWEVENT_ENTER        -- data1=0, data2=0
    Mouse entered window.  SDL2 sets SDL_WINDOW_MOUSE_FOCUS.
    Send on IDCMP_MOUSEMOVE when the window did not previously have focus.
    Alternatively SDL_SendMouseMotion handles this via SDL_UpdateMouseFocus
    for absolute motion events.

SDL_WINDOWEVENT_LEAVE        -- data1=0, data2=0
    Mouse left window.  SDL2 clears SDL_WINDOW_MOUSE_FOCUS.

SDL_WINDOWEVENT_FOCUS_GAINED -- data1=0, data2=0
    Keyboard focus gained.  SDL2 sets SDL_WINDOW_INPUT_FOCUS.
    Send on IDCMP_ACTIVEWINDOW.

SDL_WINDOWEVENT_FOCUS_LOST   -- data1=0, data2=0
    Keyboard focus lost.  SDL2 clears SDL_WINDOW_INPUT_FOCUS.
    Send on IDCMP_INACTIVEWINDOW.

SDL_WINDOWEVENT_CLOSE        -- data1=0, data2=0
    User requested window close.  If this is the last window and the
    SDL_HINT_QUIT_ON_LAST_WINDOW_CLOSE hint is set (default: true), SDL2
    also sends SDL_QUIT automatically.
    Send on IDCMP_CLOSEWINDOW.

SDL_WINDOWEVENT_TAKE_FOCUS   -- data1=0, data2=0
    Window is being offered focus.  Rarely used; ignore for basic backend.

SDL_WINDOWEVENT_HIT_TEST     -- data1=0, data2=0
    Hit test result changed.  Only needed with SDL_SetWindowHitTest.

### Focus Events and IDCMP Mapping

```c
case IDCMP_ACTIVEWINDOW:
    SDL_SendWindowEvent(sdlwin, SDL_WINDOWEVENT_FOCUS_GAINED, 0, 0);
    break;

case IDCMP_INACTIVEWINDOW:
    SDL_SendWindowEvent(sdlwin, SDL_WINDOWEVENT_FOCUS_LOST, 0, 0);
    break;

case IDCMP_CLOSEWINDOW:
    SDL_SendWindowEvent(sdlwin, SDL_WINDOWEVENT_CLOSE, 0, 0);
    break;
```

Note: SDL_SendWindowEvent(FOCUS_GAINED) is a no-op if the window already
has SDL_WINDOW_INPUT_FOCUS.  It is safe to send redundant focus events.


## Quit Events

SDL_SendQuit() is declared in src/events/SDL_events_c.h.  It sends
SDL_QUIT to the event queue.  It is called automatically by
SDL_SendWindowEvent(CLOSE) when the last window closes (see window events
section above).

To send quit directly (for example, in response to a Ctrl-C signal or
a global application quit):

```c
SDL_SendQuit();
```


## IDCMP Flags Required

The Intuition window must be opened with the correct IDCMP flags for
each class of events the backend wants to receive.  The recommended
set for a full-featured SDL2 window:

```c
ULONG idcmp = IDCMP_RAWKEY          /* keyboard */
            | IDCMP_MOUSEMOVE       /* mouse motion */
            | IDCMP_MOUSEBUTTONS    /* mouse buttons */
            | IDCMP_CLOSEWINDOW     /* close gadget */
            | IDCMP_NEWSIZE         /* resize */
            | IDCMP_REFRESHWINDOW   /* expose / damage */
            | IDCMP_ACTIVEWINDOW    /* focus gained */
            | IDCMP_INACTIVEWINDOW  /* focus lost */
            ;
```

For IDCMP_MOUSEMOVE to fire, the window must also be opened with
WA_ReportMouse, TRUE or have WFLG_REPORTMOUSE in the flags.

For coordinates relative to the inner client area (not including the
window border and title bar), use WA_GimmeZeroZero.  This is strongly
recommended for SDL2 windows; without it, MouseX/Y include the border
offset and must be manually adjusted.


## Required IDCMP Flags vs Optional

Required (must work for basic SDL2 compliance):
  IDCMP_RAWKEY, IDCMP_MOUSEBUTTONS, IDCMP_MOUSEMOVE, IDCMP_CLOSEWINDOW

Strongly recommended:
  IDCMP_NEWSIZE (resize events), IDCMP_ACTIVEWINDOW, IDCMP_INACTIVEWINDOW

Optional (Phase 2+):
  IDCMP_REFRESHWINDOW (expose events for non-RTG windows)
  IDCMP_NEWPOSITION (move events)


## Event Queue Internals (for reference only)

The backend does not need to interact with the queue directly.  This
section describes what happens inside SDL_Send* for context.

The queue is a doubly linked list of SDL_EventEntry nodes:

```c
typedef struct _SDL_EventEntry {
    SDL_Event event;
    SDL_SysWMmsg msg;
    struct _SDL_EventEntry *prev;
    struct _SDL_EventEntry *next;
} SDL_EventEntry;
```

Queue is bounded at SDL_MAX_QUEUED_EVENTS = 65535.  If the queue is full,
new events are silently dropped.  On AmigaOS 3.x with moderate frame rates
this should never be reached, but a game that never calls SDL_PollEvent
while generating many input events could hit this limit.

SDL_PollEvent ultimately calls SDL_PeepEvents(GETEVENT) which dequeues
the oldest event matching the type range SDL_FIRSTEVENT..SDL_LASTEVENT.

Timestamps on events are populated by SDL2 internally using SDL_GetTicks().
The backend does not set timestamps.


## Summary of Backend Send Functions

```c
/* Keyboard */
void SDL_SetKeyboardFocus(SDL_Window *window);
int  SDL_SendKeyboardKey(Uint8 state, SDL_Scancode scancode);
int  SDL_SendKeyboardText(const char *text);           /* UTF-8 */

/* Mouse */
void SDL_SetMouseFocus(SDL_Window *window);
int  SDL_SendMouseMotion(SDL_Window *w, SDL_MouseID id,
                         int relative, int x, int y);
int  SDL_SendMouseButton(SDL_Window *w, SDL_MouseID id,
                         Uint8 state, Uint8 button);
int  SDL_SendMouseWheel(SDL_Window *w, SDL_MouseID id,
                        float x, float y,
                        SDL_MouseWheelDirection dir);

/* Window */
int  SDL_SendWindowEvent(SDL_Window *w, Uint8 event,
                         int data1, int data2);

/* Application */
int  SDL_SendQuit(void);
```

All are declared in src/events/SDL_events_c.h and its subsidiary headers
(SDL_keyboard_c.h, SDL_mouse_c.h, SDL_windowevents_c.h).  The backend
source must include SDL_events_c.h to get them all via the chain:

```c
#include "../../events/SDL_events_c.h"
#include "../../events/SDL_keyboard_c.h"
#include "../../events/SDL_mouse_c.h"
#include "../../events/SDL_windowevents_c.h"
```


## Cross-References

- src/video/amigaos3/SDL_os3events.c -- AmigaOS 3.x implementation of all
  the patterns in this document
- docs/references/cybergraphx-reference.md -- IDCMP section covers ReplyMsg
  ordering and IDCMP_REFRESHWINDOW handling
- docs/references/crash-patterns.md -- pitfall #10 (ReplyMsg before
  processing), #7 and #15 (stack and alignment in event pump functions)
- include/SDL_scancode.h -- complete SDL_Scancode enum (USB HID values)
- include/SDL_events.h -- SDL_EventType, SDL_KeyboardEvent,
  SDL_MouseMotionEvent, SDL_MouseButtonEvent, SDL_WindowEvent structs
- src/events/SDL_keyboard.c -- SDL_SendKeyboardKeyInternal implementation;
  modifier tracking, repeat detection
- src/events/SDL_windowevents.c -- SDL_SendWindowEvent implementation;
  duplicate suppression logic for MOVED, SIZE_CHANGED, EXPOSED
