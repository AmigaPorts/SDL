# B / gadgetclass / New Methods: GM_HANDLEINPUT


This method asks an active gadget to handle an input event.  After
Intuition gets an OK to make this gadget object active (see the
[GM_GOACTIVE](../Libraries_Manual_guide/node04F5.html) method above), Intuition starts sending input events to the
gadget.  Intuition sends them in the form of a GM_HANDLEINPUT message.
This method uses the same custom message structure as GM_GOACTIVE (see the
[gpInput](../Libraries_Manual_guide/node04F5.html#line18) structure above).

The information in the [gpInput](../Libraries_Manual_guide/node04F5.html#line18) structure is the same for GM_HANDLEINPUT as
it is for [GM_GOACTIVE](../Libraries_Manual_guide/node04F5.html).  The only difference is that the GM_HANDLEINPUT
message's [gpi_IEvent](../Libraries_Manual_guide/node04F5.html#line33) can never be NULL.  It always points to an [InputEvent](../Libraries_Manual_guide/node01D0.html)
structure.

The gadget has to examine the incoming InputEvents to see how its state
may have changed.  For example,  a string gadget processes key presses,
inserting them into the gadgets string.  When the string changes, the
gadget has to update its visual state to reflect that change.  Another
example is the prop gadget.  If the user picks up the prop gadget's knob,
the prop gadget has to track the mouse to process changes to the gadget's
internal values.  It does this by processing IECLASS_RAWMOUSE events.

If the GM_HANDLEINPUT method needs to do some rendering, it must call
[ObtainGIRPort()](../Includes_and_Autodocs_2._guide/node0232.html) on the GM_HANDLEINPUT message's [gpi_GInfo](../Libraries_Manual_guide/node04F5.html#line18) to get a pointer
to a [RastPort](../Libraries_Manual_guide/node034A.html).  To relinquish this RastPort, the GM_HANDLEINPUT method
must call [ReleaseGIRPort()](../Includes_and_Autodocs_2._guide/node0243.html).  The GM_HANDLEINPUT method has to allocate and
release this RastPort, it cannot be cached in the [GM_GOACTIVE](../Libraries_Manual_guide/node04F5.html) method.

The return value from GM_HANDLEINPUT informs Intuition if the gadget wants
to remain active.  The return values for the GM_HANDLEINPUT are similar to
[GM_GOACTIVE](../Libraries_Manual_guide/node04F5.html).  The gadget tells Intuition that it wants to remain active by
returning GMR_MEACTIVE.  A gadget tells Intuition it wants to become
inactive by returning one of the "go inactive" return values:

GMR_NOREUSE     Tells Intuition to throw away the [gpInput.gpi_IEvent](../Libraries_Manual_guide/node04F5.html#line18)

                InputEvent.
GMR_REUSE       Tells Intuition to reprocess the [gpInput.gpi_IEvent](../Libraries_Manual_guide/node04F5.html#line18)

                InputEvent after deactivating the gadget.
GMR_NEXTACTIVE  Tells Intuition to throw away the [gpInput.gpi_IEvent](../Libraries_Manual_guide/node04F5.html#line18)

```c
                InputEvent and activate the next [GFLG_TABCYCLE](../Libraries_Manual_guide/node014A.html#line89) gadget.
```
GMR_PREVACTIVE  Tells Intuition to throw away the [gpInput.gpi_IEvent](../Libraries_Manual_guide/node04F5.html#line18)

```c
                InputEvent and activate the previous [GFLG_TABCYCLE](../Libraries_Manual_guide/node014A.html#line89) gadget.
```
GMR_NOREUSE tells Intuition that the gadget does not want to be active and
should throw away the InputEvent that triggered the GM_HANDLEINPUT message
(or the [GM_GOACTIVE](../Libraries_Manual_guide/node04F5.html) message).  For example, an active prop gadget returns
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
its [GFLG_TABCYCLE](../Libraries_Manual_guide/node014A.html#line89) flag set in its [Gadget.Activation](../Libraries_Manual_guide/node0149.html#line53) field (see the
[gadgetclass](../Libraries_Manual_guide/node04F2.html) [GA_TabCycle](../Libraries_Manual_guide/node0504.html) attribute below), and attempts to activate it.

For both [GM_GOACTIVE](../Libraries_Manual_guide/node04F5.html) and GM_HANDLEINPUT, the gadget can bitwise OR any of
these "go inactive" return values with GMR_VERIFY.  The GMR_VERIFY flag
tells Intuition to send a [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) IntuiMessage to the gadget's
window. If the gadget uses GMR_VERIFY, it has to supply a value for the
[IntuiMessage](../Libraries_Manual_guide/node01D9.html)'s [Code](../Libraries_Manual_guide/node01D9.html#line33) field.  It does this by passing a value in the
[gpInput](../Libraries_Manual_guide/node04F5.html#line18)'s gpi_Termination field.  This field points to a long word, the
lower 16-bits of which Intuition copies into the Code field.  The upper
16-bits are for future enhancements, so clear these bits.

