# 12 / / The Boopsi Gadget Methods / GM_GOACTIVE/GM_HANDLEINPUT


If a gadget returns [GMR_GADGETHIT](../Libraries_Manual_guide/node021B.html#line22), Intuition will send it a GM_GOACTIVE
message (defined in <intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html#line168)>):


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
[groupgclass](../Libraries_Manual_guide/node020A.html#line10) object--See the Boopsi Class Reference in the [Appendix B](../Libraries_Manual_guide/node052B.html) of
this manual for more details).

While a gadget is active, Intuition sends it GM_HANDLEINPUT messages. Each
GM_HANDLEINPUT message corresponds to a single [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) structure.
These InputEvents can be keyboard presses, timer events, mouse moves, or
mouse button presses.  The message's gpi_IEvent field points to this
InputEvent structure. It's up to the GM_HANDLEINPUT method to interpret
the meaning of these events and update the visual state of the gadget as
the user manipulates the gadget.  For example, the GM_HANDLEINPUT method
of a prop gadget has to track mouse events to see where the user has moved
the prop gadget's knob and update the gadget's imagery to reflect the new
position of the knob.

For the GM_GOACTIVE method, the gpi_IEvent field points to the struct
[InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) that triggered the GM_GOACTIVE message. Unlike the
GM_HANDLEINPUT message, GM_GOACTIVE's gpi_IEvent can be NULL.  If the
GM_GOACTIVE message was triggered by a function like intuition.library's
[ActivateGadget()](../Libraries_Manual_guide/node0167.html) and not by a real InputEvent (like the user clicking the
gadget), the gpi_IEvent field will be NULL.

For gadgets that only want to become active as a direct result of a mouse
click, this difference is important.  For example, the prop gadget becomes
active only when the user clicks on its knob.  Because the only way the
user can control the prop gadget is via the mouse, it does not make sense
for anything but the mouse to activate the gadget.  On the other hand, a
string gadget doesn't care how it is activated because, as soon as it's
active, it gets user input from the keyboard rather than the mouse.  Not
all gadgets can become active.  Some gadgets cannot become active because
they have been temporarily disabled (their [Gadget.Flags](../Libraries_Manual_guide/node0149.html#line48) [GFLG_DISABLED](../Libraries_Manual_guide/node014A.html#line73) bit
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
method returns GMR_MEACTIVE (defined in <intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html#line211)>) if it
wants to become the active gadget.  A gadget's GM_HANDLEINPUT method
returns GMR_MEACTIVE if it wants to remain the active gadget.  If a gadget
either does not want to become or remain the active gadget, it returns one
of the "go inactive" return values:

GMR_NOREUSE     Tells Intuition to throw away the gpInput.gpi_IEvent

```c
                [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198).
```
GMR_REUSE       Tells Intuition to process the gpInput.gpi_IEvent

```c
                [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198).
```
GMR_NEXTACTIVE  Tells Intuition to throw away the gpInput.gpi_IEvent

```c
                [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) and activate the next [GFLG_TABCYCLE](../Libraries_Manual_guide/node014A.html#line89) gadget.
```
GMR_PREVACTIVE  Tells Intuition to throw away the gpInput.gpi_IEvent

```c
                [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) and activate the previous [GFLG_TABCYCLE](../Libraries_Manual_guide/node014A.html#line89)
                gadget.
```
GMR_NOREUSE tells Intuition that the gadget does not want to be active and
to throw away the [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) that triggered the message.  For example, an
active prop gadget returns GMR_NOREUSE when the user lets go of the left
mouse button (thus letting go of the prop gadget's knob).

For the GM_HANDLEINPUT method, a gadget can also return GMR_REUSE, which
tells Intuition to reuse the [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198).  For example, if the user clicks
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
Intuition reuse that [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) as the gadget has already taken care of
the the event's purpose (clicking on the gadget).  In essence, the user
tried to activate the gadget and the gadget refused to become active.

The other two possible return values, GMR_NEXTACTIVE and GMR_PREVACTIVE
were added to the OS for Release 2.04.  These tell Intuition that a gadget
does not want to be active and that the [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) should be discarded.
Intuition then looks for the next (GMR_NEXTACTIVE) or previous
(GMR_PREVACTIVE) gadget that has its [GFLG_TABCYCLE](../Libraries_Manual_guide/node014A.html#line89) flag set in its
[Gadget.Activation](../Libraries_Manual_guide/node0149.html#line53) field (see the [gadgetclass](../Libraries_Manual_guide/node020A.html) [GA_TabCycle](../Libraries_Manual_guide/node0504.html) attribute in the
Boopsi Class Reference in the Appendix B of this manual).

For both GM_GOACTIVE and GM_HANDLEINPUT, the gadget can bitwise-OR any of
these "go inactive" return values with GMR_VERIFY.  The GMR_VERIFY flag
tells Intuition to send a GADGETUP [IntuiMessage](../Libraries_Manual_guide/node01D9.html) to the gadget's window.
If the gadget uses GMR_VERIFY, it has to supply a value for the
[IntuiMessage.Code](../Libraries_Manual_guide/node01D9.html#line33) field.  It does this by passing a value in the
gpInput.gpi_Termination field.  This field points to a long word, the
lower 16-bits of which Intuition copies into the Code field.  The upper
16-bits are for future enhancements, so clear these bits.

