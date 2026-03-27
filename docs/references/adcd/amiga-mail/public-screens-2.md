---
title: Public Screens
manual: amiga-mail
chapter: amiga-mail
section: public-screens-2
functions: [NextPubScreen]
libraries: [intuition.library]
---

# Public Screens

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The public screens introduced in 2.0 make it possible for the user to open
several screens where different applications can open windows.  If an
application allows the user to choose the public screen on which it opens
its window, the user can more easily organize their working environment.
They can spread their work across several public screens allowing them to
use the screen that has the palette or resolution best suited to their
purposes. This also buys the user more room for windows.  In case one
screen gets too cluttered with windows, the user can open an application's
window on a different public screen.

There are number of ways you can support public screens.  If your
application uses command line options or reads tooltypes, it can support
the PUBSCREEN keyword as a command line argument or tooltype.  This lets
the user indicate the name of the public screen on which your windows
should open.  For example, if some developer wrote a new shell that
supported public screens, the shell's icon could have the following
tooltype in its icon:


```c
    PUBSCREEN=<pubscreenname>
```
which tells the shell to open its window on the public screen named
pubscreenname.

If an application supports ARexx, it can support a JUMPTOSCREEN command
that tells it to move, or jump, its window to a specific public screen.
The application would open a new window on the public screen named in the
JUMPTOSCREEN command and closes its old window.  Your application can even
provide a jump-to-next-screen gadget, that makes the window jump to the
next public screen.  By using the intuition.library NextPubScreen(), your
application can get the name of the next screen in the public screen list,
close its window on the current screen and re-open it on the next.

The example program [jumpy.c](amiga-mail/iv-69-jumpy-c.md) opens a window which jumps from one screen to
another when the user clicks the jump gadget.

---

## See Also

- [NextPubScreen — intuition.library](../autodocs/intuition.library.md#nextpubscreen)
