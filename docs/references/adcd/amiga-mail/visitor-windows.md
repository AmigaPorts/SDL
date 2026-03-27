---
title: Visitor Windows
manual: amiga-mail
chapter: amiga-mail
section: visitor-windows
functions: [GetDefaultPubScreen, LockPubScreen]
libraries: [intuition.library]
---

# Visitor Windows

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Opening a visitor window on a public screen is like opening a window
on a custom screen except that the window is specifically defined as a
visitor.  This is done when opening the window by either replacing the
CUSTOMSCREEN flag in the (Ext)NewWindow->Type field with PUBLICSCREEN
or using a WA_PubScreenName or WA_PubScreen tag.  To use the
PUBLICSCREEN flag or the WA_PubScreen tag (this tag has a pointer to
the public screen as data), the screen must be prevented from closing.
Normally this is done by locking the desired public screen.  In either
case the program must provide a pointer to the public screen if it
requires a specific public screen.  If an application has no
preference towards a particular screen, it can pass NULL as the data
for the WA_PubScreen tag to open a window on the default public
screen.

The following example shows how to open a visitor window on a specific
public screen or, if that screen can't be found, on the default public
screen.




```c
    struct Screen *screen;
    struct Window *window;
    UBYTE namebuffer[MAXPUBSCREENNAME];

    if (!(screen = LockPubScreen("CATScreen"))) {
        /* Can't lock CATScreen, fall back on default */
        /* The method used in this example to fall back on the default
           screen is not necessary and is provided only to illustrate
           the usage of GetDefaultPubScreen().
        */
        GetDefaultPubScreen(namebuffer);
        /* Lock it, so it can't go away. */
        /* If in this split second another screen is made the default
           and this one closes, screen would become NULL and the window
           will open on the default public screen anyway.
        */
        screen = LockPubScreen(namebuffer);
    }
    if (window = OpenWindowTags(NULL,
                    WA_Left, 0, WA_Width, screen->Width,
                    WA_Top, screen->BarHeight,
                    WA_Height, screen->Height - screen->BarHeight,
                    WA_PubScreen, screen,
                    WA_Flags,
                    WINDOWDRAG|WINDOWDEPTH|WINDOWCLOSE|ACTIVATE|
                              SIMPLE_REFRESH|NOCAREREFRESH,
                    WA_Title, "AmigaMail Visitor window", TAG_END)) {
        /* Don't need the lock anymore. */
        UnlockPubScreen(NULL, screen);
                        .
                        .
                        .
        CloseWindow(window);
    } else UnlockPubScreen(NULL, screen);   /* OpenWindow failed for
                                           some other reason */
```
In this code example, once it is locked (first by LockPubScreen(),
later by the visitor window) the screen can't go away until all its
visitors have left.  After opening its initial visitor window, an
application can open non-visitor windows on a public screen, however
these windows will have to be closed before releasing the lock on the
public screen.

When opening a visitor window, the public screen on which it opens
can be specified by using a pointer to the screen (with the
WA_PubScreen tag) or by supplying the screen name (using the
WA_PubScreenName tag).  This latter method is particularly useful
where an application prefers a specific public screen, but can run
using the default public screen.  If the preferred public screen is
not present when an application attempts to open a visitor window,
the window will either open on the default public screen or will fail
to open depending on the WA_PubScreenFallBack tag. If this tag is
present and is set to TRUE, the window will open on the default
screen.  If WA_PubScreenFallBack is not present or is set to FALSE,
the window will not open.

---

## See Also

- [GetDefaultPubScreen — intuition.library](../autodocs/intuition.library.md#getdefaultpubscreen)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
