---
title: 12 / / The Boopsi Gadget Methods / GM_GOACTIVE/GM_HANDLEINPUT
manual: libraries
chapter: libraries
section: 12-the-boopsi-gadget-methods-gm-goactive-gm-handleinput
functions: [ActivateGadget]
libraries: [intuition.library]
---

# 12 / / The Boopsi Gadget Methods / GM_GOACTIVE/GM_HANDLEINPUT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If a gadget returns [GMR_GADGETHIT](libraries/12-the-boopsi-gadget-methods-gm-hittest.md), Intuition will send it a GM_GOACTIVE
message (defined in <intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>):


```c
    struct gpInput /* Used by GM_GOACTIVE and GM_HANDLEINPUT */
    {
        ULONG             MethodID;
        struct GadgetInfo *gpi_GInfo;
        struct InputEvent *gpi_IEvent;
                             /* The input event that triggered this method
                              * (for GM_GOACTIVE, this can be NULL)      */
        LONG              *gpi_Termination;
                             /* For GADGETUP IntuiMessage.Code           */
        struct
        {
            WORD X;          /* Mouse position relative to upper         */
            WORD Y;          /* left corner of gadget (LeftEdge,TopEdge) */
        } gpi_Mouse;
    };
```
The GM_GOACTIVE message gives a gadget the opportunity to become the
active gadget.  The active gadget is the gadget that is currently
receiving user input.  Under normal conditions, only one gadget can be the
active gadget (it is possible to have more than one active gadget using a
[groupgclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md) object--See the Boopsi Class Reference in the [Appendix B](libraries/b-boopsi-class-reference-groupgclass.md) of
this manual for more details).

While a gadget is active, Intuition sends it GM_HANDLEINPUT messages. Each
GM_HANDLEINPUT message corresponds to a single [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) structure.
These InputEvents can be keyboard presses, timer events, mouse moves, or
mouse button presses.  The message's gpi_IEvent field points to this
InputEvent structure. It's up to the GM_HANDLEINPUT method to interpret
the meaning of these events and update the visual state of the gadget as
the user manipulates the gadget.  For example, the GM_HANDLEINPUT method
of a prop gadget has to track mouse events to see where the user has moved
the prop gadget's knob and update the gadget's imagery to reflect the new
position of the knob.

For the GM_GOACTIVE method, the gpi_IEvent field points to the struct
[InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) that triggered the GM_GOACTIVE message. Unlike the
GM_HANDLEINPUT message, GM_GOACTIVE's gpi_IEvent can be NULL.  If the
GM_GOACTIVE message was triggered by a function like intuition.library's
[ActivateGadget()](libraries/5-string-gadget-type-program-control-of-string-gadgets.md) and not by a real InputEvent (like the user clicking the
gadget), the gpi_IEvent field will be NULL.

For gadgets that only want to become active as a direct result of a mouse
click, this difference is important.  For example, the prop gadget becomes
active only when the user clicks on its knob.  Because the only way the
user can control the prop gadget is via the mouse, it does not make sense
for anything but the mouse to activate the gadget.  On the other hand, a
string gadget doesn't care how it is activated because, as soon as it's
active, it gets user input from the keyboard rather than the mouse.  Not
all gadgets can become active.  Some gadgets cannot become active because
they have been temporarily disabled (their [Gadget.Flags](libraries/5-intuition-gadgets-gadget-structure.md) [GFLG_DISABLED](libraries/5-gadget-structure-gadget-flags.md) bit
is set).  Other gadgets will not become active because they don't need to
process input.  For example, a toggle gadget won't become active because
it only needs to process one input event, the mouse click that toggles the
gadget (which it gets from the GM_GOACTIVE message). If a toggle gadget
gets a GM_GOACTIVE message and its gpi_IEvent field is not NULL, it will
toggle its state and refuse to "go active".

The GM_GOACTIVE method has to take care of any visual state changes to a
gadget that a GM_GOACTIVE message might trigger.  For example, the toggle
gadget in the previous paragraph has to take care of toggling its visual
state from selected imagery to unselected imagery.  If the gadget goes
through a state change when it becomes the active gadget, (like when a
string gadget positions its cursor) GM_GOACTIVE has to take care of this.

The return values of both GM_GOACTIVE and GM_HANDLEINPUT tell Intuition
whether or not the gadget wants to be active.  A gadget's GM_GOACTIVE
method returns GMR_MEACTIVE (defined in <intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>) if it
wants to become the active gadget.  A gadget's GM_HANDLEINPUT method
returns GMR_MEACTIVE if it wants to remain the active gadget.  If a gadget
either does not want to become or remain the active gadget, it returns one
of the "go inactive" return values:

GMR_NOREUSE     Tells Intuition to throw away the gpInput.gpi_IEvent

```c
                [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md).
```
GMR_REUSE       Tells Intuition to process the gpInput.gpi_IEvent

```c
                [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md).
```
GMR_NEXTACTIVE  Tells Intuition to throw away the gpInput.gpi_IEvent

```c
                [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) and activate the next [GFLG_TABCYCLE](libraries/5-gadget-structure-gadget-flags.md) gadget.
```
GMR_PREVACTIVE  Tells Intuition to throw away the gpInput.gpi_IEvent

```c
                [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) and activate the previous [GFLG_TABCYCLE](libraries/5-gadget-structure-gadget-flags.md)
                gadget.
```
GMR_NOREUSE tells Intuition that the gadget does not want to be active and
to throw away the [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) that triggered the message.  For example, an
active prop gadget returns GMR_NOREUSE when the user lets go of the left
mouse button (thus letting go of the prop gadget's knob).

For the GM_HANDLEINPUT method, a gadget can also return GMR_REUSE, which
tells Intuition to reuse the [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md).  For example, if the user clicks
outside the active string gadget, that string gadget returns GMR_REUSE.
Intuition can now process that mouse click, which can be over another
gadget.  Another case where a string gadget returns GMR_REUSE is when the
user pushes the right mouse button (the menu button).  The string gadget
becomes inactive and the menu button InputEvent gets reused.  Intuition
sees this event and tries to pop up the menu bar.

For the GM_GOACTIVE method, a gadget must not return GMR_REUSE.  If a
gadget gets a GM_GOACTIVE message from Intuition and the message has an
gpi_IEvent, the message was triggered by the user clicking on the gadget.
In this case, Intuition knows that the user is trying to select the
gadget.  Intuition doesn't know if the gadget can be activated, but if it
can be activated, the event that triggered the activation has just taken
place.  If the gadget cannot become active for any reason, it must not let
Intuition reuse that [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) as the gadget has already taken care of
the the event's purpose (clicking on the gadget).  In essence, the user
tried to activate the gadget and the gadget refused to become active.

The other two possible return values, GMR_NEXTACTIVE and GMR_PREVACTIVE
were added to the OS for Release 2.04.  These tell Intuition that a gadget
does not want to be active and that the [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) should be discarded.
Intuition then looks for the next (GMR_NEXTACTIVE) or previous
(GMR_PREVACTIVE) gadget that has its [GFLG_TABCYCLE](libraries/5-gadget-structure-gadget-flags.md) flag set in its
[Gadget.Activation](libraries/5-intuition-gadgets-gadget-structure.md) field (see the [gadgetclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md) [GA_TabCycle](libraries/b-gadgetclass-attributes-ga-endgadget-ga-tabcycle-is.md) attribute in the
Boopsi Class Reference in the Appendix B of this manual).

For both GM_GOACTIVE and GM_HANDLEINPUT, the gadget can bitwise-OR any of
these "go inactive" return values with GMR_VERIFY.  The GMR_VERIFY flag
tells Intuition to send a GADGETUP [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) to the gadget's window.
If the gadget uses GMR_VERIFY, it has to supply a value for the
[IntuiMessage.Code](libraries/9-using-the-idcmp-intuimessages.md) field.  It does this by passing a value in the
gpInput.gpi_Termination field.  This field points to a long word, the
lower 16-bits of which Intuition copies into the Code field.  The upper
16-bits are for future enhancements, so clear these bits.

---

## See Also

- [ActivateGadget — intuition.library](../autodocs/intuition.library.md#activategadget)
