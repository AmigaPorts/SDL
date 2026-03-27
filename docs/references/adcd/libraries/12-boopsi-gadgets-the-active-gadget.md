---
title: 12 / Boopsi Gadgets / The Active Gadget
manual: libraries
chapter: libraries
section: 12-boopsi-gadgets-the-active-gadget
functions: [ObtainGIRPort, ReleaseGIRPort]
libraries: [intuition.library]
---

# 12 / Boopsi Gadgets / The Active Gadget

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

While a gadget is active, Intuition sends it a [GM_HANDLEINPUT](libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md) message for
every timer pulse, mouse move, mouse click, and key press that takes
place.  A timer event pulse arrives about every tenth of a second.  Mouse
move events can arrive at a much higher rate than the timer pulses.
Without even considering the keyboard, a gadget can get a lot of
GM_HANDLEINPUT messages in a short amount of time. Because the active
gadget has to handle a large volume of GM_HANDLEINPUT messages, the
overhead of this method should be kept to a minimum.

Because the gadget will always receive a [GM_GOACTIVE](libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md) message before it is
active and a [GM_GOINACTIVE](libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md) message after it is no longer active, the
gadget can use these methods to allocate, initialize, and deallocate
temporary resources it needs for the [GM_HANDLEINPUT](libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md) method.  This can
significantly reduce the overhead of GM_HANDLEINPUT because it eliminates
the need to allocate, initialize, and deallocate resources for every
GM_HANDLEINPUT message.

Note that the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) from [ObtainGIRPort()](autodocs-2.0/intuition-library-obtaingirport.md) is not cachable using this
method.  If the [GM_HANDLEINPUT](libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md) method needs to use a RastPort, it has to
obtain and release the RastPort for every GM_HANDLEINPUT message using
ObtainGIRPort() and [ReleaseGIRPort()](autodocs-2.0/intuition-library-releasegirport.md).

 [RKMButtonclass.c](libraries/12-the-active-gadget-rkmbuttonclass-c.md) 

---

## See Also

- [ObtainGIRPort — intuition.library](../autodocs/intuition.library.md#obtaingirport)
- [ReleaseGIRPort — intuition.library](../autodocs/intuition.library.md#releasegirport)
