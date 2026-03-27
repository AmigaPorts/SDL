---
title: Refreshing a Sizable Window
manual: amiga-mail
chapter: amiga-mail
section: refreshing-a-sizable-window
functions: [DrawImage, LockIBase, LockLayer, LockLayerInfo, PrintIText, RefreshGList, UnlockLayer]
libraries: [intuition.library, layers.library]
---

# Refreshing a Sizable Window

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A sizable window is by far the trickiest to refresh correctly.  The
most important and often overlooked point is that an application
needs to ensure the size of its window does not change while it is
refreshing the window.  If the application doesn't and the user
changes the window size, the application will refresh the window at
the window's old size rather than its new size.  This can severely
corrupt the appearance of the window.

There are two main ways an application can keep the size of its
window stable while refreshing  the window.  The first method is to
keep the size of the window locked most of the time, unlocking the
window only when the user tries to size the window.  The other
approach is to lock the window size only while rendering to the
window.

The first method is part of Intuition's IDCMP mechanism.  To lock a
window's size, an application sets the window's IDCMP_SIZEVERIFY
IDCMP flag.  When the user attempts to size the window by clicking on
the window's sizing gadget, Intuition notifies the application by
sending an IDCMP_SIZEVERIFY message to the window's IDCMP port.
Intuition will keep the window's size locked until the application
returns the IDCMP_SIZEVERIFY message.

In general this scheme works well, but it does have two problems.
First, if the application is busy doing some processing, such as
recalculating a spreadsheet, it may not notice that the message
arrived until it is done with its current processing.  The result is
the user will not be able to size the window until the application is
finished processing, which might more time than the user wants.

The second problem occurs when the application is waiting for input
from Intuition, such as in the middle of an EasyRequest() call.  If
the user clicks on the sizing gadget of the application's window
while the requester is up, Intuition will wait for the system will
enter a deadlock.  Intuition will wait for the application to send
back will not see the IDCMP_SIZEVERIFY event until the user satisfies
the EasyRequest().  The result will be a system deadlock.  Many
applications suffer from this problem.

The second problem occurs when the application is waiting for input
from Intuition, such as in the middle of an EasyRequest() call.  If
the user clicks on the sizing gadget of the application's window
while the requester is up, the system will enter a deadlock.  When
the user clicks the sizing gadget, Intuition sends the
IDCMP_SIZEVERIFY message and waits for a reply.  Because the
application is already waiting for the EasyRequest() to return, the
application cannot send back the reply.  Many applications suffer
from this problem.

As of Release 2, Intuition has adapted and avoids these deadlocks.
Intuition will time out the sizing operation if the application does
not process the IDCMP_SIZEVERIFY message within a given time period.
Although the user can no longer deadlock the system, this situation
can still confuse the user because clicking on the window's sizing
gadget no longer sizes the window.  That does not mean an application
should rely upon Intuition to avoid the deadlock.  An application
should always avoid these conditions.

In general, it is simpler and safer for the application to lock a
window only during the rendering process.  The application can do
this by surrounding all rendering operations with calls to the Layers
library functions LockLayer() and UnlockLayer().  LockLayer() locks
the size and position of a layer.  While a window's layer is locked,
an application can safely look at the window's current size and
render to it without any danger of the size changing.  Once the
application finishes rendering, it unlocks the window's layer by
calling UnlockLayer().  When using this method, an application must
not set the window's IDCMP_SIZEVERIFY bit.  Be careful which system
functions an application calls while it has a layer locked.  Only use
the Graphics library rendering functions and the simple Intuition
rendering functions (i.e., PrintIText(), DrawImage(), etc.).  In
particular, avoid calls that deal with gadgets (including
RefreshGList()) and other locks (i.e., LockIBase() and
LockLayerInfo()).

---

## See Also

- [DrawImage — intuition.library](../autodocs/intuition.library.md#drawimage)
- [LockIBase — intuition.library](../autodocs/intuition.library.md#lockibase)
- [LockLayer — layers.library](../autodocs/layers.library.md#locklayer)
- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
- [PrintIText — intuition.library](../autodocs/intuition.library.md#printitext)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [UnlockLayer — layers.library](../autodocs/layers.library.md#unlocklayer)
