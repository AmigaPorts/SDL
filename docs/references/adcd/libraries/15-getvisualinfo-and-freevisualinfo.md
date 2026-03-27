---
title: 15 / / / GetVisualInfo() and FreeVisualInfo()
manual: libraries
chapter: libraries
section: 15-getvisualinfo-and-freevisualinfo
functions: [CloseScreen, CloseWindow, FreeVisualInfo, LockPubScreen, OpenScreen, UnlockPubScreen]
libraries: [gadtools.library, intuition.library]
---

# 15 / / / GetVisualInfo() and FreeVisualInfo()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In order to ensure their best appearance, GadTools gadgets and menus need
information about the screen on which they will appear.  Before creating
any GadTools gadgets or menus, the program must get this information using
the [GetVisualInfo()](autodocs-2.0/gadtools-library-getvisualinfoa.md) call.


```c
    APTR GetVisualInfoA( struct Screen *screen, struct TagItem *taglist );
    APTR GetVisualInfo( struct Screen *screen, Tag tag1, ... );
```
Set the screen argument to a pointer to the screen you are using.  The tag
arguments, tag1 or taglist, are reserved for future extensions.  Currently
none are recognized, so only TAG_END should be used.

The function returns an abstract handle called the VisualInfo.  For
GadTools gadgets, the [ng_VisualInfo](libraries/15-gadtools-gadgets-the-newgadget-structure.md) field of the [NewGadget](libraries/15-gadtools-gadgets-the-newgadget-structure.md) structure must
be set to this handle before the gadget can be added to the window.
GadTools menu layout and creation functions also require the VisualInfo
handle as an argument.

There are several ways to get the pointer to the screen on which the
window will be opened.  If the application has its own custom screen, this
pointer is known from the call to [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md) or [OpenScreenTags()](libraries/3-intuition-screens-custom-screen-functions.md).  If
the application already has its window opened on the Workbench or some
other public screen, the screen pointer can be found in [Window.WScreen](libraries/4-intuition-windows-the-window-structure.md).
Often the program will create its gadgets and menus before opening the
window.  In this case, use [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md) to get a pointer to the desired
public screen, which also provides a lock on the screen to prevent it from
closing.  See the chapters "[Intuition Screens](libraries/3-intuition-screens-public-screen-functions.md)" and "[Intuition Windows](libraries/4-basic-window-structures-and-functions-windows-and-screens.md)" for
more about public screens.

The VisualInfo data must be freed after all the gadgets and menus have
been freed but before releasing the screen.  Custom screens are released
by calling [CloseScreen()](libraries/3-creating-a-new-custom-screen-closing-the-screen.md), public screens are released by calling
[CloseWindow()](libraries/4-basic-window-structures-and-functions-closing-windows.md) or [UnlockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md), depending on the technique used.  Use
[FreeVisualInfo()](autodocs-2.0/gadtools-library-freevisualinfo.md) to free the visual info data.


```c
    void FreeVisualInfo( APTR vi );
```
This function takes just one argument, the VisualInfo handle as returned
by [GetVisualInfo()](autodocs-2.0/gadtools-library-getvisualinfoa.md).  The sequence of events for using the VisualInfo
handle could look like this:


```c
    init()
    {
    myscreen = LockPubScreen(NULL);
    if (!myscreen)
        {
        cleanup("Failed to lock default public screen");
        }
    vi = GetVisualInfo(myscreen);
    if (!vi)
        {
        cleanup("Failed to GetVisualInfo");
        }
    /* Create gadgets here */
    ng.ng_VisualInfo = vi;
    ...
    }

    void cleanup(STRPTR errorstr)
    {
    /* These functions may be safely called with a NULL parameter: */
    FreeGadgets(glist);
    FreeVisualInfo(vi);

    if (myscreen)
        UnlockPubScreen(NULL, myscreen);

    printf(errorstr);
    }
```

---

## See Also

- [CloseScreen — intuition.library](../autodocs/intuition.library.md#closescreen)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [FreeVisualInfo — gadtools.library](../autodocs/gadtools.library.md#freevisualinfo)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
