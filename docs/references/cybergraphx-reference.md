# CyberGraphX V4 Reference

## Overview

CyberGraphX (CGX) is the standard ReTargetable Graphics (RTG) API for AmigaOS 3.x.
It patches graphics.library to integrate third-party graphics boards and provides
truecolor screen modes that Intuition handles transparently.

For the SDL2 video backend, CyberGraphX is used for:
- Enumerating available RTG screen modes (width, height, depth, pixel format)
- Opening fullscreen truecolor screens
- Opening windows on RTG screens or on the Workbench
- Writing pixel data from SDL surfaces to the screen (WritePixelArray)
- Direct framebuffer access for high-speed pixel rendering (LockBitMapTags)
- Checking pixel format of the current screen bitmap

The library version required is V40 (first public release). V41 added
WriteLUTPixelArray, ExtractColor, and ScalePixelArray. LockBitMapTagList
arrived in V40 release 40.60 (later V40 builds).

In FS-UAE with `graphics_card = uaegfx`, the uaegfx driver emulates
CyberGraphX V41. On real hardware, cards shipped with CGX include
CyberVision64, Picasso IV, Piccolo, Spectrum, A2410, and CVision3D.

## Headers

```c
#include <proto/cybergraphics.h>   /* Function inlines + CyberGfxBase extern */
#include <cybergraphx/cybergraphics.h> /* Structures, constants, pixel formats */
#include <proto/intuition.h>       /* OpenScreenTagList, OpenWindowTagList */
#include <proto/graphics.h>        /* NextDisplayInfo, LoadRGB32, GetVPModeID */
#include <graphics/displayinfo.h>  /* INVALID_ID, DimensionInfo, DTAG_DIMS */
#include <intuition/screens.h>     /* struct Screen, struct Window, SA_* tags */
#include <intuition/intuition.h>   /* IDCMP_* flags, struct IntuiMessage */
```

## Library Base

```c
#include <proto/cybergraphics.h>

struct Library *CyberGfxBase = NULL;

/* Minimum version: 40 for WritePixelArray/LockBitMapTags
 * Version 41 for WriteLUTPixelArray, ScalePixelArray, ExtractColor
 */
CyberGfxBase = OpenLibrary("cybergraphics.library", 40L);
if (!CyberGfxBase) {
    /* No RTG board present or driver not installed */
    /* Fall back to AGA or report error */
}

/* On exit: */
if (CyberGfxBase) {
    CloseLibrary(CyberGfxBase);
    CyberGfxBase = NULL;
}
```

Note: The library name constant is `CYBERGFXNAME` defined as "cybergraphics.library".

---

## Screen Mode Enumeration

### IsCyberModeID()

**Synopsis:** `BOOL IsCyberModeID(ULONG displayID)`

**Description:** Returns TRUE if the given 32-bit display mode ID belongs to
CyberGraphX (i.e., it is an RTG mode, not a native Amiga chipset mode).

**Parameters:**
- `displayID` -- 32-bit display mode ID from NextDisplayInfo() or GetVPModeID()

**Returns:** TRUE if CGX mode, FALSE otherwise.

**Notes:** Always call this before calling GetCyberIDAttr() -- applying
GetCyberIDAttr() to a non-CGX mode ID returns garbage.

---

### NextDisplayInfo() / FindDisplayInfo() / GetDisplayInfoData()

These are graphics.library functions used to iterate all display modes.

**Synopsis:**
```c
ULONG NextDisplayInfo(ULONG displayID);          /* graphics.library */
DisplayInfoHandle FindDisplayInfo(ULONG displayID); /* graphics.library */
ULONG GetDisplayInfoData(DisplayInfoHandle handle, APTR buf,
                         ULONG size, ULONG tagID, ULONG displayID);
```

**Mode enumeration pattern from SDL 1.2 CGX backend:**

```c
#include <graphics/displayinfo.h>  /* INVALID_ID, DTAG_DIMS, DimensionInfo */

ULONG nextid = INVALID_ID;  /* INVALID_ID = ~0UL = 0xFFFFFFFF */

nextid = NextDisplayInfo(INVALID_ID);
while (nextid != INVALID_ID) {
    if (IsCyberModeID(nextid)) {
        DisplayInfoHandle handle = FindDisplayInfo(nextid);
        if (handle) {
            struct DimensionInfo diminfo;
            if (GetDisplayInfoData(handle, (APTR)&diminfo,
                                   sizeof(diminfo), DTAG_DIMS, 0)) {
                ULONG w = diminfo.Nominal.MaxX - diminfo.Nominal.MinX + 1;
                ULONG h = diminfo.Nominal.MaxY - diminfo.Nominal.MinY + 1;
                ULONG bppix = GetCyberIDAttr(CYBRIDATTR_BPPIX, nextid);
                /* Record mode: w x h x (bppix*8) bits */
            }
        }
    }
    nextid = NextDisplayInfo(nextid);
}
```

**DimensionInfo fields (from graphics/displayinfo.h):**
```c
struct DimensionInfo {
    struct QueryHeader Header;
    UWORD MaxDepth;           /* log2(max colors) */
    UWORD MinRasterWidth;
    UWORD MinRasterHeight;
    UWORD MaxRasterWidth;
    UWORD MaxRasterHeight;
    struct Rectangle Nominal; /* "standard" dimensions: MinX/MinY/MaxX/MaxY */
    struct Rectangle MaxOScan;
    struct Rectangle VideoOScan;
    struct Rectangle TxtOScan;
    struct Rectangle StdOScan;
    /* ... */
};
```

`DTAG_DIMS = 0x80001000` -- tag for GetDisplayInfoData to retrieve DimensionInfo.

---

### AllocCModeListTagList() / FreeCModeList()

An alternative enumeration approach that returns an Exec List of CyberModeNode
structs filtered by criteria.

**Synopsis:**
```c
struct List *AllocCModeListTagList(struct TagItem *tags);
struct List *AllocCModeListTags(Tag tag1, ...);
void FreeCModeList(struct List *modeList);
```

**CyberModeNode structure:**
```c
struct CyberModeNode {
    struct Node Node;
    char   ModeText[DISPLAYNAMELEN]; /* human-readable name */
    ULONG  DisplayID;                /* display mode ID */
    UWORD  Width;                    /* visible width in pixels */
    UWORD  Height;                   /* visible height in pixels */
    UWORD  Depth;                    /* bits per pixel */
    struct TagItem *DisplayTagList;  /* extended info taglist */
};
```

**Filter tags for AllocCModeListTagList:**
```c
CYBRMREQ_MinWidth    /* ULONG: minimum width  (default 320) */
CYBRMREQ_MaxWidth    /* ULONG: maximum width  (default 1600) */
CYBRMREQ_MinHeight   /* ULONG: minimum height (default 240) */
CYBRMREQ_MaxHeight   /* ULONG: maximum height (default 1200) */
CYBRMREQ_MinDepth    /* UWORD: minimum depth in bits (default 8) */
CYBRMREQ_MaxDepth    /* UWORD: maximum depth in bits (default 32) */
CYBRMREQ_CModelArray /* UWORD *: NULL-terminated array of PIXFMT_* to include */
```

**Usage pattern:**
```c
struct List *modelist;
struct CyberModeNode *node;

modelist = AllocCModeListTags(
    CYBRMREQ_MinDepth,  15,
    CYBRMREQ_MaxDepth,  32,
    CYBRMREQ_MinWidth,  320,
    CYBRMREQ_MinHeight, 240,
    TAG_DONE
);
if (modelist) {
    for (node = (struct CyberModeNode *)modelist->lh_Head;
         node->Node.ln_Succ != NULL;
         node = (struct CyberModeNode *)node->Node.ln_Succ) {
        /* node->DisplayID, node->Width, node->Height, node->Depth */
    }
    FreeCModeList(modelist);
}
```

**Notes:** Returns NULL if no modes match. Always call FreeCModeList() on
the result. Do not free individual nodes.

---

### BestCModeIDTagList()

**Synopsis:**
```c
ULONG BestCModeIDTagList(struct TagItem *tags);
ULONG BestCModeIDTags(Tag tag1, ...);
```

**Description:** Returns the CyberGraphX display mode ID that best matches
the requested parameters.

**Tags:**
```c
CYBRBIDTG_Depth         /* ULONG: required depth in bits (default 8) */
CYBRBIDTG_NominalWidth  /* UWORD: desired width in pixels */
CYBRBIDTG_NominalHeight /* UWORD: desired height in pixels */
CYBRBIDTG_MonitorID     /* ULONG: specific board (see below) */
CYBRBIDTG_BoardName     /* STRPTR: board name e.g. "CVision3D" */
```

**Returns:** 32-bit mode ID, or INVALID_ID (~0UL) if no match found.

**Usage pattern (from SDL 1.2 CGX backend):**
```c
ULONG modeid = BestCModeIDTags(
    CYBRBIDTG_NominalWidth,  width,
    CYBRBIDTG_NominalHeight, height,
    CYBRBIDTG_Depth,         bpp,
    TAG_DONE
);
if (modeid == INVALID_ID) {
    /* No suitable mode -- fall back to 8bpp or windowed mode */
}
```

**Known board MonitorIDs:**
- CVision64 = 1
- Piccolo = 2
- PicassoII = 3
- Spectrum = 4
- Domino = 5
- RetinaZ3/DraCoAltais = 6
- PiccoSD64 = 7
- A2410 = 8
- CVision3D = 13  (V41)
- Inferno = 14    (V41)
- PicassoIV = 15  (V41)

**Pitfall:** Older revisions return wrong depth if the exact depth is
unavailable. If width/height are very small (e.g., icon size), returns
INVALID_ID instead of the smallest available mode. Always validate the
returned mode with GetCyberIDAttr() after selecting.

---

### GetCyberIDAttr()

**Synopsis:** `ULONG GetCyberIDAttr(ULONG attribute, ULONG displayModeID)`

**Description:** Returns a property of a CyberGraphX display mode ID.
Must only be called on a mode that IsCyberModeID() returns TRUE for.

**Parameters:**
- `attribute` -- one of the CYBRIDATTR_* constants
- `displayModeID` -- CyberGraphX mode ID

**Attributes:**
```c
CYBRIDATTR_PIXFMT  /* pixel format constant (PIXFMT_*) */
CYBRIDATTR_WIDTH   /* visible width in pixels */
CYBRIDATTR_HEIGHT  /* visible height in lines */
CYBRIDATTR_DEPTH   /* bits per pixel */
CYBRIDATTR_BPPIX   /* bytes per pixel */
```

**Returns:** Attribute value, or -1 for unknown attribute.

**Usage:**
```c
if (IsCyberModeID(modeid)) {
    ULONG w    = GetCyberIDAttr(CYBRIDATTR_WIDTH,  modeid);
    ULONG h    = GetCyberIDAttr(CYBRIDATTR_HEIGHT, modeid);
    ULONG bpp  = GetCyberIDAttr(CYBRIDATTR_DEPTH,  modeid);
    ULONG bppx = GetCyberIDAttr(CYBRIDATTR_BPPIX,  modeid);
    ULONG fmt  = GetCyberIDAttr(CYBRIDATTR_PIXFMT, modeid);
}
```

---

## Screen Opening

Screens are opened with intuition.library/OpenScreenTagList() using the
CGX display mode ID in the SA_DisplayID tag.

**Synopsis:**
```c
struct Screen *OpenScreenTags(struct NewScreen *ns, Tag tag1, ...);
/* NewScreen may be NULL when using tags */
```

**Essential tags for CGX fullscreen:**
```c
SA_DisplayID  /* ULONG: CGX mode ID from BestCModeIDTags() */
SA_Depth      /* LONG: bit depth (15, 16, 24, or 32) */
SA_Width      /* LONG: screen width in pixels */
SA_Height     /* LONG: screen height in pixels */
SA_Type       /* ULONG: CUSTOMSCREEN for exclusive, PUBLICSCREEN for shared */
SA_Quiet      /* BOOL: TRUE = no screen title bar drag bar rendered */
SA_ShowTitle  /* BOOL: FALSE = no title bar */
SA_Draggable  /* BOOL: FALSE = screen cannot be dragged */
SA_Exclusive  /* BOOL: TRUE = exclusive use, no other screen can share */
SA_AutoScroll /* BOOL: FALSE = no auto-scroll (use when SA_Width == display width) */
SA_Title      /* STRPTR: screen title string (ASCII only) */
```

**Fullscreen pattern (from SDL 1.2 CGX backend):**
```c
struct Screen *screen;

screen = OpenScreenTags(NULL,
    SA_Title,      (ULONG)"SDL Screen",
    SA_Quiet,      TRUE,
    SA_ShowTitle,  FALSE,
    SA_Depth,      bpp,          /* e.g. 16 or 32 */
    SA_DisplayID,  modeid,       /* from BestCModeIDTags() */
    SA_Type,       CUSTOMSCREEN,
    SA_Exclusive,  TRUE,
    SA_Draggable,  FALSE,
    SA_AutoScroll, FALSE,
    TAG_DONE
);
if (!screen) {
    /* Failed -- check IoErr() or try lower depth/resolution */
}
```

**Notes:**
- `SA_Type, CUSTOMSCREEN` -- your private screen; must provide SA_DisplayID
- `SA_Type, PUBLICSCREEN` -- shared public screen; user can open other windows
- You MUST call `CloseScreen(screen)` on exit. Leaked screens survive reboot.
- Do not supply a custom BitMap to OpenScreenTags with CGX modes -- the bitmap
  format is managed internally by CyberGraphX.
- After opening, use `GetVPModeID(&screen->ViewPort)` then `IsCyberModeID()`
  to confirm the screen got the requested CGX mode.

**Getting screen RastPort:**
```c
struct RastPort *rp = screen->RastPort; /* Direct pointer -- always valid */
/* Or via window: */
struct RastPort *rp = window->RPort;
```

---

## Window Management

Windows are opened with intuition.library/OpenWindowTagList().

### OpenWindowTags() for Fullscreen (on CUSTOMSCREEN)

```c
struct Window *window;

window = OpenWindowTags(NULL,
    WA_Left,         0,
    WA_Top,          0,
    WA_Width,        screen->Width,
    WA_Height,       screen->Height,
    WA_Flags,        WFLG_ACTIVATE   |
                     WFLG_RMBTRAP    |   /* trap right mouse button */
                     WFLG_BORDERLESS |   /* no window border */
                     WFLG_REPORTMOUSE,   /* deliver IDCMP_MOUSEMOVE */
    WA_IDCMP,        IDCMP_RAWKEY        |
                     IDCMP_MOUSEBUTTONS  |
                     IDCMP_MOUSEMOVE     |
                     IDCMP_ACTIVEWINDOW  |
                     IDCMP_INACTIVEWINDOW,
    WA_CustomScreen, (ULONG)screen,      /* our CUSTOMSCREEN */
    TAG_DONE
);
```

### OpenWindowTags() for Windowed Mode (on Public Screen / Workbench)

```c
window = OpenWindowTags(NULL,
    WA_Left,          xpos,
    WA_Top,           ypos,
    WA_InnerWidth,    w,              /* content area width, excl. border */
    WA_InnerHeight,   h,              /* content area height, excl. border */
    WA_Flags,         WFLG_REPORTMOUSE |
                      WFLG_ACTIVATE    |
                      WFLG_RMBTRAP     |
                      WFLG_DEPTHGADGET |
                      WFLG_CLOSEGADGET |
                      WFLG_DRAGBAR,
    WA_IDCMP,         IDCMP_RAWKEY        |
                      IDCMP_CLOSEWINDOW   |
                      IDCMP_MOUSEBUTTONS  |
                      IDCMP_NEWSIZE       |
                      IDCMP_MOUSEMOVE     |
                      IDCMP_ACTIVEWINDOW  |
                      IDCMP_INACTIVEWINDOW,
    WA_PubScreen,     (ULONG)pub_screen,  /* NULL = default public screen */
    WA_GimmeZeroZero, TRUE,              /* coordinate origin at inner area */
    WA_Title,         (ULONG)"Window Title",
    TAG_DONE
);
```

**WA_GimmeZeroZero:** When TRUE, the window's coordinate origin (0,0) is at
the top-left of the inner content area. Without this, RastPort coordinates
include the border offsets. STRONGLY RECOMMENDED for SDL backends.

When WA_GimmeZeroZero is FALSE (or the window has borders), adjust pixel
write positions:
```c
destx = rects[i].x + window->BorderLeft;
desty = rects[i].y + window->BorderTop;
```

**Cleanup:**
```c
CloseWindow(window);   /* Must be before CloseScreen() */
CloseScreen(screen);
```

---

### IDCMP Event Processing

```c
struct IntuiMessage *imsg;
struct MsgPort     *port = window->UserPort;

/* Poll without blocking: */
while ((imsg = (struct IntuiMessage *)GetMsg(port)) != NULL) {
    ULONG class  = imsg->Class;
    UWORD code   = imsg->Code;
    UWORD qual   = imsg->Qualifier;
    WORD  mousex = imsg->MouseX;
    WORD  mousey = imsg->MouseY;

    ReplyMsg((struct Message *)imsg); /* Must reply before processing */

    switch (class) {
    case IDCMP_RAWKEY:
        /* code & ~IECODE_UP_PREFIX = raw key code (0x00..0x77) */
        /* code & IECODE_UP_PREFIX  = key release */
        if (code & IECODE_UP_PREFIX) {
            /* key release: code & ~IECODE_UP_PREFIX is the keycode */
        } else {
            /* key press */
        }
        break;
    case IDCMP_MOUSEBUTTONS:
        /* code == IECODE_LBUTTON         left press */
        /* code == IECODE_LBUTTON|IECODE_UP_PREFIX  left release */
        /* code == IECODE_RBUTTON         right press (if WFLG_RMBTRAP) */
        /* code == IECODE_MBUTTON         middle press */
        break;
    case IDCMP_MOUSEMOVE:
        /* mousex, mousey = pointer position relative to window inner area */
        /* (relative to inner area when WA_GimmeZeroZero is TRUE) */
        break;
    case IDCMP_CLOSEWINDOW:
        /* user clicked close gadget */
        break;
    case IDCMP_NEWSIZE:
        /* window was resized -- re-read window->Width, window->Height */
        break;
    case IDCMP_ACTIVEWINDOW:
        /* window gained focus */
        break;
    case IDCMP_INACTIVEWINDOW:
        /* window lost focus */
        break;
    }
}
```

**IMPORTANT:** Always call `ReplyMsg()` on an IntuiMessage before doing
anything that could block. Intuition will stall if messages are not replied.

**Waiting for events (blocking):**
```c
ULONG signals = Wait(1L << window->UserPort->mp_SigBit);
/* Then process with GetMsg() loop above */
```

---

## Pixel Format Constants

Defined in `cybergraphx/cybergraphics.h`:

```c
/* Bitmap pixel formats (returned by GetCyberMapAttr/GetCyberIDAttr) */
#define PIXFMT_LUT8    0UL   /* 8-bit indexed (palette) */
#define PIXFMT_RGB15   1UL   /* 15-bit RGB, big-endian (XRRRRRGGGGGBBBBB) */
#define PIXFMT_BGR15   2UL   /* 15-bit BGR, big-endian */
#define PIXFMT_RGB15PC 3UL   /* 15-bit RGB, little-endian (byteswapped) */
#define PIXFMT_BGR15PC 4UL   /* 15-bit BGR, little-endian */
#define PIXFMT_RGB16   5UL   /* 16-bit RGB, big-endian (RRRRRGGGGGGBBBBB) */
#define PIXFMT_BGR16   6UL   /* 16-bit BGR, big-endian */
#define PIXFMT_RGB16PC 7UL   /* 16-bit RGB, little-endian */
#define PIXFMT_BGR16PC 8UL   /* 16-bit BGR, little-endian */
#define PIXFMT_RGB24   9UL   /* 24-bit RGB packed */
#define PIXFMT_BGR24   10UL  /* 24-bit BGR packed */
#define PIXFMT_ARGB32  11UL  /* 32-bit ARGB (AA RR GG BB) */
#define PIXFMT_BGRA32  12UL  /* 32-bit BGRA */
#define PIXFMT_RGBA32  13UL  /* 32-bit RGBA */

/* Source rectangle formats for WritePixelArray / ReadPixelArray */
#define RECTFMT_RGB    0UL  /* 3 bytes/pixel: R G B */
#define RECTFMT_RGBA   1UL  /* 4 bytes/pixel: R G B A (alpha last) */
#define RECTFMT_ARGB   2UL  /* 4 bytes/pixel: A R G B (alpha first) */
#define RECTFMT_LUT8   3UL  /* 1 byte/pixel: indexed pen number */
#define RECTFMT_GREY8  4UL  /* 1 byte/pixel: greyscale */
```

**SDL pixel format mapping:**

SDL2 `SDL_PIXELFORMAT_ARGB8888` corresponds to RECTFMT_ARGB for WritePixelArray.
SDL2 `SDL_PIXELFORMAT_RGB24` corresponds to RECTFMT_RGB.

On most RTG boards, the native pixel format is PIXFMT_ARGB32 (32-bit) or
PIXFMT_RGB16 (16-bit). Use GetCyberMapAttr(CYBRMATTR_PIXFMT) to detect
the actual format after opening a screen.

**Recommended formats:** PIXFMT_LUT8, PIXFMT_RGB16, PIXFMT_RGB24, PIXFMT_ARGB32.
Avoid PC (byteswapped) variants unless you know the board requires them.

---

## Framebuffer Access -- WritePixelArray

WritePixelArray is the standard method for updating the screen from a
software pixel buffer. It is slower than direct locked access but works
on all boards including those without linear framebuffer.

### WritePixelArray()

**Synopsis:**
```c
ULONG WritePixelArray(
    APTR           srcRect,    /* A0: source pixel buffer */
    UWORD          srcX,       /* D0: x offset into source buffer */
    UWORD          srcY,       /* D1: y offset into source buffer */
    UWORD          srcMod,     /* D2: bytes per row in source buffer (pitch) */
    struct RastPort *rastPort, /* A1: destination RastPort */
    UWORD          destX,      /* D3: x position in RastPort */
    UWORD          destY,      /* D4: y position in RastPort */
    UWORD          sizeX,      /* D5: width in pixels to transfer */
    UWORD          sizeY,      /* D6: height in pixels to transfer */
    UBYTE          srcFormat   /* D7: source pixel format (RECTFMT_*) */
);
```

**Returns:** Count of pixels written (NOTE: this value is documented as
incorrect in all versions up to V41 -- do not rely on it).

**Parameters:**
- `srcRect` -- pointer to your pixel buffer (must be WORD-aligned at minimum)
- `srcX, srcY` -- starting offset within the source buffer (usually 0, 0)
- `srcMod` -- bytes per row in source (pitch = width * bytes_per_pixel or padded)
- `rastPort` -- destination screen->RastPort or window->RPort
- `destX, destY` -- destination coordinates in RastPort
- `sizeX, sizeY` -- rectangle size in pixels
- `srcFormat` -- RECTFMT_RGB, RECTFMT_RGBA, RECTFMT_ARGB, RECTFMT_LUT8, RECTFMT_GREY8

**Full-screen update (windowed, with GimmeZeroZero):**
```c
WritePixelArray(
    pixels,                          /* SDL surface->pixels */
    0, 0,                            /* source offset */
    pitch,                           /* SDL surface->pitch */
    window->RPort,                   /* window RastPort */
    0, 0,                            /* dest top-left */
    width, height,                   /* full surface size */
    RECTFMT_ARGB                     /* SDL_PIXELFORMAT_ARGB8888 */
);
```

**Dirty rectangle update:**
```c
for (int i = 0; i < num_rects; i++) {
    UBYTE *src = (UBYTE *)pixels
                 + rects[i].y * pitch
                 + rects[i].x * bytes_per_pixel;
    WritePixelArray(
        src,
        0, 0,
        pitch,
        window->RPort,
        rects[i].x + window->BorderLeft,  /* if NOT GimmeZeroZero */
        rects[i].y + window->BorderTop,
        rects[i].w, rects[i].h,
        RECTFMT_ARGB
    );
}
```

**Notes:**
- On 8-bit (PIXFMT_LUT8) RastPorts, only RECTFMT_LUT8 works.
- For > 8-bit screens, RECTFMT_LUT8 uses the screen's ViewPort colormap.
- CGX handles color space conversion internally when srcFormat differs from
  the native screen pixel format.
- Alignment: srcRect should be LONG-aligned for best performance.

---

### ReadPixelArray()

**Synopsis:**
```c
ULONG ReadPixelArray(
    APTR           destRect,   /* A0: destination buffer */
    UWORD          destX,      /* D0: x offset into dest buffer */
    UWORD          destY,      /* D1: y offset into dest buffer */
    UWORD          destMod,    /* D2: bytes per row in dest buffer */
    struct RastPort *rastPort, /* A1: source RastPort */
    UWORD          srcX,       /* D3: x position in RastPort */
    UWORD          srcY,       /* D4: y position in RastPort */
    UWORD          sizeX,      /* D5: width in pixels */
    UWORD          sizeY,      /* D6: height in pixels */
    UBYTE          destFormat  /* D7: RECTFMT_RGB, RECTFMT_RGBA, or RECTFMT_ARGB */
);
```

**Notes:** Use for screen capture / readback. Slower than WritePixelArray.
Only RECTFMT_RGB, RECTFMT_RGBA, and RECTFMT_ARGB are supported as destFormat
(not LUT8 or GREY8).

---

## Framebuffer Access -- Direct Lock

LockBitMapTagList provides direct access to the framebuffer memory.
This is the fastest method for pixel rendering but must be used carefully.

### LockBitMapTagList() / LockBitMapTags()

**Synopsis:**
```c
APTR LockBitMapTagList(APTR bitmap, struct TagItem *tags);
APTR LockBitMapTags(APTR bitmap, Tag tag1, ...);
```

**Description:** Locks a CyberGraphX bitmap for direct memory access.
Returns a non-NULL handle on success. The LBMI_BASEADDRESS tag receives
the address of the framebuffer memory.

**Parameters:**
- `bitmap` -- the BitMap pointer. For a screen: `screen->RastPort->BitMap`.
  For a window: `window->RPort->BitMap`. Must pass IsCyberModeID() check.
- `tags` -- taglist with LBMI_* entries. Each ti_Data is a pointer to a
  ULONG that receives the value. All tags are output-only.

**Lock tags (all ULONG * -- pointer to a ULONG that receives the value):**
```c
LBMI_WIDTH       (0x84001001) /* ULONG *: bitmap width in pixels */
LBMI_HEIGHT      (0x84001002) /* ULONG *: bitmap height in lines */
LBMI_DEPTH       (0x84001003) /* ULONG *: depth (BUG: always returns 8) */
LBMI_PIXFMT      (0x84001004) /* ULONG *: pixel format (PIXFMT_*) */
LBMI_BYTESPERPIX (0x84001005) /* ULONG *: bytes per pixel */
LBMI_BYTESPERROW (0x84001006) /* ULONG *: bytes per row (stride/pitch) */
LBMI_BASEADDRESS (0x84001007) /* ULONG *: pointer to framebuffer base */
```

**Returns:** Non-NULL opaque handle on success, NULL on failure.
The handle must be passed to UnLockBitMap().

**CRITICAL:** LBMI_BASEADDRESS is only valid between Lock and UnLock.
Do NOT use any library calls while the bitmap is locked -- no Intuition,
no graphics.library, no exec. Only direct memory writes are safe.
Hold the lock for at most one frame (e.g., 1/50th second at 50Hz).

**Pattern -- lock, render, unlock:**
```c
ULONG bm_width  = 0;
ULONG bm_height = 0;
ULONG bm_pixfmt = 0;
ULONG bm_bppix  = 0;
ULONG bm_pitch  = 0;
ULONG bm_base   = 0;  /* receives framebuffer address as ULONG */
APTR  lock_handle;
struct BitMap *bm = screen->RastPort->BitMap;

/* Verify it is a CGX bitmap before locking */
if (!GetCyberMapAttr(bm, CYBRMATTR_ISCYBERGFX)) {
    /* Not a CGX bitmap -- use WritePixelArray instead */
}

lock_handle = LockBitMapTags(bm,
    LBMI_WIDTH,       (ULONG)&bm_width,
    LBMI_HEIGHT,      (ULONG)&bm_height,
    LBMI_PIXFMT,      (ULONG)&bm_pixfmt,
    LBMI_BYTESPERPIX, (ULONG)&bm_bppix,
    LBMI_BYTESPERROW, (ULONG)&bm_pitch,
    LBMI_BASEADDRESS, (ULONG)&bm_base,
    TAG_DONE
);

if (lock_handle) {
    UBYTE *fb = (UBYTE *)bm_base;
    /* Direct pixel writes here -- NO library calls! */
    /* Example: copy 32-bit ARGB source to 32-bit ARGB framebuffer */
    for (ULONG y = 0; y < bm_height; y++) {
        ULONG *dst = (ULONG *)(fb + y * bm_pitch);
        ULONG *src = (ULONG *)(pixels + y * src_pitch);
        for (ULONG x = 0; x < bm_width; x++) {
            dst[x] = src[x];
        }
    }
    UnLockBitMap(lock_handle);
}
```

**BUG in all versions:** LBMI_DEPTH always returns 8, even for deeper bitmaps.
Use `GetCyberMapAttr(bm, CYBRMATTR_DEPTH)` or `GetCyberIDAttr()` instead.

---

### UnLockBitMap() / UnLockBitMapTagList()

**Synopsis:**
```c
void UnLockBitMap(APTR handle);
void UnLockBitMapTagList(APTR handle, struct TagItem *tags);
void UnLockBitMapTags(APTR handle, Tag tag1, ...);
```

**UnLockBitMapTagList tags (optional):**
```c
UBMI_UPDATERECTS  (0x85001001) /* struct RectList *: rectangles to update
                                * (for non-linear framebuffer boards) */
UBMI_REALLYUNLOCK (0x85001002) /* BOOL: FALSE = update rects but keep locked */
```

**RectList structure** (for UBMI_UPDATERECTS):
```c
struct RectList {
    ULONG            rl_num;   /* number of rectangles in this node */
    struct RectList *rl_next;  /* pointer to next RectList node */
    struct Rectangle rect1;    /* first rectangle (followed by rl_num-1 more) */
};
```

For boards with linear framebuffer (most modern cards and uaegfx), use
`UnLockBitMap(handle)` directly. UBMI_UPDATERECTS is needed for cards
where the framebuffer is not directly mapped to CPU address space.

---

## Bitmap Attributes -- GetCyberMapAttr()

Query properties of an existing CyberGraphX bitmap.

**Synopsis:** `ULONG GetCyberMapAttr(struct BitMap *bitmap, ULONG attribute)`

**Always call `CYBRMATTR_ISCYBERGFX` first** -- applying other attributes
to a non-CGX bitmap returns garbage.

**Attributes:**
```c
CYBRMATTR_XMOD        (0x80000001) /* bytes per row (pitch) */
CYBRMATTR_BPPIX       (0x80000002) /* bytes per pixel */
CYBRMATTR_PIXFMT      (0x80000004) /* pixel format (PIXFMT_*) */
CYBRMATTR_WIDTH       (0x80000005) /* width in pixels */
CYBRMATTR_HEIGHT      (0x80000006) /* height in lines */
CYBRMATTR_DEPTH       (0x80000007) /* bits per pixel */
CYBRMATTR_ISCYBERGFX  (0x80000008) /* -1 (TRUE) if CGX bitmap, 0 if not */
CYBRMATTR_ISLINEARMEM (0x80000009) /* -1 (TRUE) if linear CPU memory access */
```

**Returns:** Attribute value, or -1 for unknown attributes.

**Usage:**
```c
struct BitMap *bm = screen->RastPort->BitMap;

if (GetCyberMapAttr(bm, CYBRMATTR_ISCYBERGFX)) {
    ULONG pixfmt = GetCyberMapAttr(bm, CYBRMATTR_PIXFMT);
    ULONG pitch  = GetCyberMapAttr(bm, CYBRMATTR_XMOD);
    ULONG bppix  = GetCyberMapAttr(bm, CYBRMATTR_BPPIX);
    ULONG depth  = GetCyberMapAttr(bm, CYBRMATTR_DEPTH);
    BOOL  linear = (BOOL)GetCyberMapAttr(bm, CYBRMATTR_ISLINEARMEM);
}
```

**SDL2 usage:** Call this after OpenScreen to confirm pixel format, then
configure the SDL_PixelFormat accordingly.

---

## Palette / Color Management

### LoadRGB32() -- graphics.library

For 8-bit (PIXFMT_LUT8) screens, palette is loaded with LoadRGB32().

**Synopsis:** `void LoadRGB32(struct ViewPort *vp, const ULONG *table)`

**Table format:** Array of ULONGs. Each color entry is 3 ULONGs:
`{ count << 16 | first_color, red_component, green_component, blue_component, ...}`
where color components are 32-bit values (0x00000000 = black, 0xFFFFFFFF = full).
Terminated by a ULONG of 0.

**Pattern:**
```c
/* Load 256-color palette for 8-bit screen */
static ULONG palette[256*3 + 2];  /* 2 extra for header + terminator */

/* Header: count=256, start=0 */
palette[0] = (256UL << 16) | 0;

/* Fill R, G, B for each of 256 colors */
for (int i = 0; i < 256; i++) {
    palette[1 + i*3 + 0] = (ULONG)sdl_colors[i].r << 24; /* red */
    palette[1 + i*3 + 1] = (ULONG)sdl_colors[i].g << 24; /* green */
    palette[1 + i*3 + 2] = (ULONG)sdl_colors[i].b << 24; /* blue */
}
/* Terminator */
palette[1 + 256*3] = 0;

LoadRGB32(&screen->ViewPort, palette);
```

**Notes:** LoadRGB32 is graphics.library (not CyberGraphX). For truecolor
screens (>8 bit), this has no visible effect. On LUT8 screens it sets
hardware color registers 0-255.

---

## AllocBitMap() for Off-Screen Buffers

CyberGraphX extends graphics.library/AllocBitMap() to allow allocation of
truecolor bitmaps for off-screen rendering.

```c
#include <proto/graphics.h>
#include <cybergraphx/cybergraphics.h>  /* BMF_SPECIALFMT, SHIFT_PIXFMT */

/* Allocate a 32-bit ARGB offscreen bitmap, friend to screen */
struct BitMap *bm = AllocBitMap(
    width, height, depth,
    BMF_MINPLANES | BMF_SPECIALFMT | SHIFT_PIXFMT(PIXFMT_ARGB32),
    screen->RastPort->BitMap   /* friend bitmap */
);
/* SHIFT_PIXFMT(fmt) = ((ULONG)(fmt)) << 24 */
/* BMF_MINPLANES: required for CGX compatibility with picture.datatype */
/* BMF_SPECIALFMT: upper 8 bits of flags contain SHIFT_PIXFMT */

if (bm) {
    /* Use bm for rendering, lock for direct access */
    FreeBitMap(bm);
}
```

**Notes:** Do NOT pass this bitmap to OpenScreenTagList as SA_BitMap.
The off-screen CGX bitmap can be attached to a RastPort for rendering
calls, or locked with LockBitMapTagList for direct access.

---

## Other CyberGraphX Functions

### FillPixelArray()

**Synopsis:**
```c
ULONG FillPixelArray(struct RastPort *rp, UWORD destX, UWORD destY,
                     UWORD sizeX, UWORD sizeY, ULONG argb);
```

Fills a rectangular area with a solid ARGB color.
`argb` format: 0xAARRGGBB (AA=alpha, set to 0x00 if unused).
Useful for clearing backgrounds. For LUT8 screens, only the blue byte
(0x000000BB) is used as a palette index.

### MovePixelArray()

**Synopsis:**
```c
ULONG MovePixelArray(UWORD srcX, UWORD srcY, struct RastPort *rp,
                     UWORD destX, UWORD destY, UWORD sizeX, UWORD sizeY);
```

Copies a rectangular region within the same RastPort. Hardware-accelerated
on cards where the blitter can access display memory.

### ScalePixelArray() -- V41+

**Synopsis:**
```c
LONG ScalePixelArray(APTR srcRect, UWORD srcW, UWORD srcH, UWORD srcMod,
                     struct RastPort *rp, UWORD destX, UWORD destY,
                     UWORD destW, UWORD destH, UBYTE srcFormat);
```

Writes a scaled version of a pixel array to the RastPort.
srcFormat values same as WritePixelArray.

### WriteLUTPixelArray() -- V41+

**Synopsis:**
```c
ULONG WriteLUTPixelArray(APTR srcRect, UWORD srcX, UWORD srcY,
                         UWORD srcMod, struct RastPort *rp, APTR colorTab,
                         UWORD destX, UWORD destY, UWORD sizeX, UWORD sizeY,
                         UBYTE ctFormat);
```

Writes an indexed (LUT8) pixel array using a supplied color table.
`ctFormat` = `CTABFMT_XRGB8`: colorTab is a ULONG[256] array, each entry
is 0x00RRGGBB. Useful for blitting indexed sprites to truecolor screens.
Available V41+. Has a bug in cgxsystem.library <= 41.19 where it returns
immediately with CTABFMT_XRGB8.

---

## DPMS / Video Control

```c
/* Control monitor power state */
CVideoCtrlTags(&screen->ViewPort,
    SETVC_DPMSLevel, DPMS_ON,  /* or DPMS_STANDBY, DPMS_SUSPEND, DPMS_OFF */
    TAG_DONE
);
```

---

## Complete SDL2 Backend Usage Pattern

This is the recommended sequence for the SDL2 video backend:

```c
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/cybergraphics.h>
#include <cybergraphx/cybergraphics.h>
#include <graphics/displayinfo.h>
#include <intuition/screens.h>
#include <intuition/intuition.h>

struct Library *CyberGfxBase = NULL;

/*
 * 1. Open library
 */
int OS3_VideoInit(void)
{
    CyberGfxBase = OpenLibrary(CYBERGFXNAME, 40L);
    if (!CyberGfxBase) {
        SDL_SetError("Cannot open cybergraphics.library V40+");
        return -1;
    }
    return 0;
}

/*
 * 2. Enumerate modes
 */
void OS3_GetDisplayModes(void)
{
    ULONG nextid = NextDisplayInfo(INVALID_ID);
    while (nextid != INVALID_ID) {
        if (IsCyberModeID(nextid)) {
            ULONG w   = GetCyberIDAttr(CYBRIDATTR_WIDTH,  nextid);
            ULONG h   = GetCyberIDAttr(CYBRIDATTR_HEIGHT, nextid);
            ULONG bpp = GetCyberIDAttr(CYBRIDATTR_DEPTH,  nextid);
            /* Add (w, h, bpp) to mode list */
        }
        nextid = NextDisplayInfo(nextid);
    }
}

/*
 * 3. Open screen and window
 */
int OS3_CreateWindow(int w, int h, int bpp, int fullscreen)
{
    ULONG modeid = BestCModeIDTags(
        CYBRBIDTG_NominalWidth,  w,
        CYBRBIDTG_NominalHeight, h,
        CYBRBIDTG_Depth,         bpp,
        TAG_DONE
    );
    if (modeid == INVALID_ID) return -1;

    struct Screen *screen = OpenScreenTags(NULL,
        SA_Title,      (ULONG)"SDL",
        SA_Quiet,      TRUE,
        SA_ShowTitle,  FALSE,
        SA_Depth,      bpp,
        SA_DisplayID,  modeid,
        SA_Type,       CUSTOMSCREEN,
        SA_Exclusive,  TRUE,
        SA_Draggable,  FALSE,
        SA_AutoScroll, FALSE,
        TAG_DONE
    );
    if (!screen) return -1;

    struct Window *window = OpenWindowTags(NULL,
        WA_Left,         0,
        WA_Top,          0,
        WA_Width,        w,
        WA_Height,       h,
        WA_Flags,        WFLG_ACTIVATE | WFLG_RMBTRAP |
                         WFLG_BORDERLESS | WFLG_REPORTMOUSE,
        WA_IDCMP,        IDCMP_RAWKEY | IDCMP_MOUSEBUTTONS |
                         IDCMP_MOUSEMOVE | IDCMP_ACTIVEWINDOW |
                         IDCMP_INACTIVEWINDOW,
        WA_CustomScreen, (ULONG)screen,
        TAG_DONE
    );
    if (!window) {
        CloseScreen(screen);
        return -1;
    }

    /* Query actual pixel format */
    struct BitMap *bm = screen->RastPort->BitMap;
    ULONG pixfmt = GetCyberMapAttr(bm, CYBRMATTR_PIXFMT);
    /* Map pixfmt to SDL_PixelFormatEnum */

    return 0;
}

/*
 * 4. Update framebuffer
 */
void OS3_UpdateFramebuffer(struct Window *window, void *pixels,
                           int pitch, int x, int y, int w, int h)
{
    UBYTE *src = (UBYTE *)pixels + y * pitch + x * 4;
    WritePixelArray(
        src,
        0, 0,
        pitch,
        window->RPort,
        x, y,  /* with WA_GimmeZeroZero */
        w, h,
        RECTFMT_ARGB
    );
}

/*
 * 5. Cleanup
 */
void OS3_VideoQuit(struct Window *window, struct Screen *screen)
{
    if (window) CloseWindow(window);
    if (screen) CloseScreen(screen);
    if (CyberGfxBase) {
        CloseLibrary(CyberGfxBase);
        CyberGfxBase = NULL;
    }
}
```

---

## Common Error Patterns and Pitfalls

### 1. Not checking IsCyberModeID() before GetCyberIDAttr()

Always verify a mode ID is a CGX mode before querying CGX attributes.
Native Amiga chip modes (OCS/ECS/AGA) will return garbage from GetCyberIDAttr.

### 2. LockBitMapTags returns NULL

Possible causes:
- Bitmap is not a CGX bitmap (check CYBRMATTR_ISCYBERGFX first)
- Board does not support locking (use WritePixelArray as fallback)
- Lock held too long -- Intuition may have invalidated it
Use WritePixelArray as the primary method; try Lock as an optimization.

### 3. LBMI_DEPTH bug

`LBMI_DEPTH` always returns 8 in all CGX versions. Use
`GetCyberMapAttr(bm, CYBRMATTR_DEPTH)` to get the real depth.

### 4. LBMI_BASEADDRESS is a ULONG, not a pointer

Tags pass `(ULONG)&variable` where variable is `ULONG`. Cast to pointer:
```c
ULONG bm_base = 0;
/* ... LockBitMapTags(..., LBMI_BASEADDRESS, (ULONG)&bm_base, ...) */
UBYTE *fb = (UBYTE *)bm_base;  /* cast AFTER locking */
```

### 5. Library calls forbidden during lock

Do NOT call OpenLibrary, AllocMem, intuition functions, or any OS call
while a bitmap is locked. The system may deadlock or corrupt memory.

### 6. Window border offsets without GimmeZeroZero

Without `WA_GimmeZeroZero, TRUE`, add `window->BorderLeft` and
`window->BorderTop` to all WritePixelArray destination coordinates.
See crash-patterns.md for off-by-one rendering artifacts.

### 7. Alignment for WritePixelArray

The `srcRect` pointer should be aligned to at least 4 bytes (LONG-aligned).
Stack-allocated pixel buffers with odd sizes can cause slow or incorrect
transfers on some boards. Use LONG-aligned heap memory.

### 8. BestCModeIDTags INVALID_ID for small sizes

BestCModeIDTags returns INVALID_ID when width < ~100 or height < ~60.
Always have a fallback path (windowed mode on Workbench, or a minimum
resolution of 320x240).

### 9. Screen not closed before CloseLibrary

Always CloseWindow before CloseScreen. Always CloseScreen before
CloseLibrary(CyberGfxBase). Reversing this order corrupts the Amiga's
display database and requires reboot.

### 10. Forgetting ReplyMsg()

Failing to call ReplyMsg() on IntuiMessages causes Intuition to stall.
The user port message queue fills up, input stops responding. Always
reply before doing any processing.

---

## Version History

- **V40 (initial):** IsCyberModeID, BestCModeIDTagList, CModeRequestTagList,
  AllocCModeListTagList, FreeCModeList, GetCyberMapAttr, GetCyberIDAttr,
  ReadRGBPixel, WriteRGBPixel, ReadPixelArray, WritePixelArray, MovePixelArray,
  InvertPixelArray, FillPixelArray, DoCDrawMethodTagList, CVideoCtrlTagList
- **V40 release 40.60:** LockBitMapTagList, UnLockBitMap, UnLockBitMapTagList
- **V41:** ExtractColor, WriteLUTPixelArray, ScalePixelArray

Open with `OpenLibrary("cybergraphics.library", 40L)` for V40 features.
Open with 41L for WriteLUTPixelArray/ScalePixelArray.

---

## FS-UAE / uaegfx Emulation Notes

In FS-UAE with `graphics_card = uaegfx`, the uaegfx driver presents itself
as a CyberGraphX V41-compatible board. The emulated card:
- Supports all PIXFMT_* formats listed above
- Has a linear framebuffer (CYBRMATTR_ISLINEARMEM returns TRUE)
- Supports LockBitMapTagList with direct host memory mapping
- Emulates standard RTG screen modes (320x240, 640x480, 800x600, etc.)

FS-UAE configuration required for RTG:
```
graphics_card = uaegfx
graphics_card_memory = 16384
joystick_port_1_mode = nothing
```

The `joystick_port_1_mode = nothing` setting is critical -- without it,
FS-UAE routes arrow keys to the emulated joystick and they never reach
console.device. See crash-patterns.md on the FS-UAE arrow key issue.

---

## See Also

- `docs/references/crash-patterns.md` -- #7 (stack), #10 (large buffers),
  #15 (alignment), #16 (struct returns at -O2)
- `docs/references/autodocs/intuition.library.md` -- OpenScreenTagList,
  OpenWindowTagList, SA_* and WA_* tag reference
- `docs/references/autodocs/graphics.library.md` -- LoadRGB32, AllocBitMap,
  NextDisplayInfo, GetDisplayInfoData
- `docs/references/libnix-reference.md` -- available C library functions
