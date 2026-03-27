---
title: B / gadgetclass / New Methods: GM_HANDLEINPUT
manual: libraries
chapter: libraries
section: b-gadgetclass-new-methods-gm-handleinput
functions: [ObtainGIRPort, ReleaseGIRPort]
libraries: [intuition.library]
---

# B / gadgetclass / New Methods: GM_HANDLEINPUT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method asks an active gadget to handle an input event.  After
Intuition gets an OK to make this gadget object active (see the
[GM_GOACTIVE](libraries/b-gadgetclass-new-methods-gm-goactive.md) method above), Intuition starts sending input events to the
gadget.  Intuition sends them in the form of a GM_HANDLEINPUT message.
This method uses the same custom message structure as GM_GOACTIVE (see the
[gpInput](libraries/b-gadgetclass-new-methods-gm-goactive.md) structure above).

The information in the [gpInput](libraries/b-gadgetclass-new-methods-gm-goactive.md) structure is the same for GM_HANDLEINPUT as
it is for [GM_GOACTIVE](libraries/b-gadgetclass-new-methods-gm-goactive.md).  The only difference is that the GM_HANDLEINPUT
message's [gpi_IEvent](libraries/b-gadgetclass-new-methods-gm-goactive.md) can never be NULL.  It always points to an [InputEvent](libraries/9-intuition-input-and-output-methods-intuition-input.md)
structure.

The gadget has to examine the incoming InputEvents to see how its state
may have changed.  For example,  a string gadget processes key presses,
inserting them into the gadgets string.  When the string changes, the
gadget has to update its visual state to reflect that change.  Another
example is the prop gadget.  If the user picks up the prop gadget's knob,
the prop gadget has to track the mouse to process changes to the gadget's
internal values.  It does this by processing IECLASS_RAWMOUSE events.

If the GM_HANDLEINPUT method needs to do some rendering, it must call
[ObtainGIRPort()](autodocs-2.0/intuition-library-obtaingirport.md) on the GM_HANDLEINPUT message's [gpi_GInfo](libraries/b-gadgetclass-new-methods-gm-goactive.md) to get a pointer
to a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).  To relinquish this RastPort, the GM_HANDLEINPUT method
must call [ReleaseGIRPort()](autodocs-2.0/intuition-library-releasegirport.md).  The GM_HANDLEINPUT method has to allocate and
release this RastPort, it cannot be cached in the [GM_GOACTIVE](libraries/b-gadgetclass-new-methods-gm-goactive.md) method.

The return value from GM_HANDLEINPUT informs Intuition if the gadget wants
to remain active.  The return values for the GM_HANDLEINPUT are similar to
[GM_GOACTIVE](libraries/b-gadgetclass-new-methods-gm-goactive.md).  The gadget tells Intuition that it wants to remain active by
returning GMR_MEACTIVE.  A gadget tells Intuition it wants to become
inactive by returning one of the "go inactive" return values:

GMR_NOREUSE     Tells Intuition to throw away the [gpInput.gpi_IEvent](libraries/b-gadgetclass-new-methods-gm-goactive.md)

                InputEvent.
GMR_REUSE       Tells Intuition to reprocess the [gpInput.gpi_IEvent](libraries/b-gadgetclass-new-methods-gm-goactive.md)

                InputEvent after deactivating the gadget.
GMR_NEXTACTIVE  Tells Intuition to throw away the [gpInput.gpi_IEvent](libraries/b-gadgetclass-new-methods-gm-goactive.md)

```c
                InputEvent and activate the next [GFLG_TABCYCLE](libraries/5-gadget-structure-gadget-flags.md) gadget.
```
GMR_PREVACTIVE  Tells Intuition to throw away the [gpInput.gpi_IEvent](libraries/b-gadgetclass-new-methods-gm-goactive.md)

```c
                InputEvent and activate the previous [GFLG_TABCYCLE](libraries/5-gadget-structure-gadget-flags.md) gadget.
```
GMR_NOREUSE tells Intuition that the gadget does not want to be active and
should throw away the InputEvent that triggered the GM_HANDLEINPUT message
(or the [GM_GOACTIVE](libraries/b-gadgetclass-new-methods-gm-goactive.md) message).  For example, an active prop gadget returns
GMR_NOREUSE when the user lets go of the left mouse button (thus letting
go of the prop gadget's knob).

A gadget can also return GMR_REUSE, which tells Intuition to reuse the
InputEvent.  For example, if the user clicks outside of an active string
gadget, that string gadget returns GMR_REUSE so Intuition can process that
mouse click, which could be over another gadget.  Another case where a
string gadget returns GMR_REUSE is when the user pushes the right mouse
button (the menu button).  The string gadget becomes inactive and the menu
button InputEvent gets reused by Intuition so it can pop up the menu bar.

The other two possible return values, GMR_NEXTACTIVE and GMR_PREVACTIVE
were added to the OS for Release 2.04.  These tell Intuition that a gadget
no longer wants to be active and that the GM_HANDLEINPUT message
InputEvent should be discarded.  Intuition then looks for the next
non-disabled (GMR_NEXTACTIVE) or previous (GMR_PREVACTIVE) gadget that has
its [GFLG_TABCYCLE](libraries/5-gadget-structure-gadget-flags.md) flag set in its [Gadget.Activation](libraries/5-intuition-gadgets-gadget-structure.md) field (see the
[gadgetclass](libraries/b-boopsi-class-reference-gadgetclass.md) [GA_TabCycle](libraries/b-gadgetclass-attributes-ga-endgadget-ga-tabcycle-is.md) attribute below), and attempts to activate it.

For both [GM_GOACTIVE](libraries/b-gadgetclass-new-methods-gm-goactive.md) and GM_HANDLEINPUT, the gadget can bitwise OR any of
these "go inactive" return values with GMR_VERIFY.  The GMR_VERIFY flag
tells Intuition to send a [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) IntuiMessage to the gadget's
window. If the gadget uses GMR_VERIFY, it has to supply a value for the
[IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)'s [Code](libraries/9-using-the-idcmp-intuimessages.md) field.  It does this by passing a value in the
[gpInput](libraries/b-gadgetclass-new-methods-gm-goactive.md)'s gpi_Termination field.  This field points to a long word, the
lower 16-bits of which Intuition copies into the Code field.  The upper
16-bits are for future enhancements, so clear these bits.

---

## See Also

- [ObtainGIRPort — intuition.library](../autodocs/intuition.library.md#obtaingirport)
- [ReleaseGIRPort — intuition.library](../autodocs/intuition.library.md#releasegirport)
