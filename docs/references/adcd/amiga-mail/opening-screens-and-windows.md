---
title: Opening Screens and Windows
manual: amiga-mail
chapter: amiga-mail
section: opening-screens-and-windows
functions: [FreeScreenDrawInfo, GetDisplayInfoData, GetScreenDrawInfo, GetVPModeID, LockPubScreen, OpenScreen, OpenScreenTagList, OpenWindow, OpenWindowTagList, UnlockPubScreen]
libraries: [graphics.library, intuition.library]
---

# Opening Screens and Windows

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Intuition V36 supplies two new functions to open screens and windows:
OpenScreenTagList() and OpenWindowTagList(). They provide added
functionality over the older OpenScreen() and OpenWindow() functions.
Instead of the NewScreen and NewWindow structures, an array of
parameters called tags is passed to the function in the form of a
TagItem structure pointer.  This array is known as a tag list.  For a
description of using tags in Intuition, see the Amiga Mail article
``TagItems and Tag Lists''.

The following is a simple example of the usage of OpenScreenTagList()
and OpenWindowTagList(), using only a tag list as a parameter to each
function.




```c
    struct TagItem tagitem[3];
    struct Screen *screen;
    struct Window *window;

    tagitem[0].ti_Tag  = SA_DisplayID;
    tagitem[0].ti_Data = HIRES_KEY;     /* Use HIRES displaymode
                                           for default monitor */
    tagitem[1].ti_Tag  = SA_Title;
    tagitem[1].ti_Data = "AmigaMail Test Screen";
    tagitem[2].ti_Tag  = TAG_DONE;    /* Marks the end of the tag array. */

    /* All others options will be set to default. Note this screen will not
       open with the 'New Look', due to the absence of the SA_Pens tag and
       data. Further examples will have this tag */

    if (screen = OpenScreenTagList(NULL,   tagitem)) {
        tagitem[0].ti_Tag = WA_CustomScreen;
        tagitem[0].ti_Data = screen;    /* Open on my own screen */
        tagitem[1].ti_Tag = WA_Title;
        tagitem[1].ti_Data = "AmigaMail Test Window";
        tagitem[2].ti_Tag = TAG_DONE; /* Marks the end of the tag array. */

        /* Use defaults for everything else. Will open as big as the screen. */

        if (window = OpenWindowTagList(NULL, tagitem)) {

            /* rest of code */

            CloseWindow(window);
        }
        CloseScreen(screen)
    }
```
See the intuition/intuition.h and intuition/screens.h include files
for a complete list of currently supported tags.

Intuition.library provides a function to get information about screens
and display modes called GetScreenDrawInfo().  This function returns a
subset of the data supplied by the graphics.library's
GetDisplayInfoData() function.  Given a pointer to a screen,
GetScreenDrawInfo() returns a pointer to a DrawInfo structure
describing that screen.  Note that this structure is read-only.  The
DrawInfo structure contains information about the resolution, default
font and pen colors of the screen.  Since the system allocates the
DrawInfo structure when GetScreenDrawInfo() is called, a program must
tell the system to free it by calling FreeScreenDrawInfo().  Of
course, a program should only release the DrawInfo structure after it
is no longer needed.

When using GetScreenDrawInfo() on a public screen, the screen should
first be locked using Intuition's LockPubScreen() function.  This will
prevent a public screen from closing while your program is looking at
the screen's DrawInfo structure.  UnlockPubScreen() will unlock the
screen.  Public screens are discussed in more detail later in this
article.

The graphics.library function GetVPModeID() provides a way of
determining the display mode ID associated with a ViewPort.  Passed
the ViewPort attached to a screen, the function will return the
display mode ID for that ViewPort, or INVALID_ID if no display mode ID
is associated with the ViewPort.

An example of the usage of GetVPModeID() and the other functions
discussed so far in this article are provided in at the end of
thisarticle in example 1, [CloneWB.c](amiga-mail/iv-3-clonewb-c.md).  This example also uses the
stack-based amiga.lib support library functions OpenScreenTags() and
OpenWindowTags(), both of which are documented in the release 2.0
Autodocs.

---

## See Also

- [FreeScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#freescreendrawinfo)
- [GetDisplayInfoData — graphics.library](../autodocs/graphics.library.md#getdisplayinfodata)
- [GetScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#getscreendrawinfo)
- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
