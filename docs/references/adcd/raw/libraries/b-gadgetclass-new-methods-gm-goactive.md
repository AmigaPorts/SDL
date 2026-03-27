# B / gadgetclass / New Methods: GM_GOACTIVE


This method asks a gadget if it is OK to make it the active gadget.  The
active gadget is the gadget that is currently receiving user input.
Intuition sends this message after a gadget responds affirmatively to the
[GM_HITTEST](../Libraries_Manual_guide/node04F3.html) method.  A gadget becomes active because it needs to process
input events (like a prop gadget or string gadget).

Some types of gadget do not need to become active.  These gadgets do not
have to process input from the user, they only have to deal with a single
mouse click to toggle their state.  Because that mouse click triggered
this method, the button already has all of the user input it requires.
Note that the behavior of the GadTools button differs from a Boopsi
buttongclass gadget, which processes other input events besides a single
mouse click.  See the entry for [buttongclass](../Libraries_Manual_guide/node051F.html) in this Appendix for more
details.

GM_GOACTIVE uses a custom message structure (defined in
<intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html#line199)>):


```c
    struct gpInput
    {
        ULONG             MethodID;    /* GM_GOACTIVE or GM_HANDLEINPUT */
        struct GadgetInfo *gpi_GInfo;
        struct InputEvent *gpi_IEvent; /* The input event that triggered */
                                       /* this method (can be NULL for   */
                                       /* GM_GOACTIVE).                  */
        LONG         *gpi_Termination; /* For GADGETUP IntuiMessage.Code */
        struct
        {
            WORD X;             /* Mouse position relative to upper      */
            WORD Y;             /* left corner of gadget (LeftEdge,      */
        } gpi_Mouse;            /* TopEdge).                             */
    };
```
The gpi_IEvent field points to the struct InputEvent that triggered the
GM_GOACTIVE message.  If gpi_IEvent is NULL, the GM_GOACTIVE message was
triggered by a function like intuition.library's [ActivateGadget()](../Libraries_Manual_guide/node0167.html) and not
by the user clicking the gadget.

For gadgets that only want to become active as a direct result of a mouse
click, this difference is important.  For example, the prop gadget becomes
active only when the user clicks on its knob.  Because the only way the
user can control the prop gadget is via the mouse, it would not make sense
for it to be activated by anything besides the mouse.  On the other hand,
a string gadget gets input from the keyboard, so a string gadget doesn't
care what activates it.  Its input comes from the keyboard rather than the
mouse.

A gadget's GM_GOACTIVE method returns GMR_MEACTIVE (defined in
<intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html#line211)>) if it wants to be the active gadget.  Otherwise
it returns [GMR_NOREUSE](../Libraries_Manual_guide/node04F6.html#line32).  For a description of what these values mean, See
their description in the [gadgetclass](../Libraries_Manual_guide/node04F2.html)'s [GM_HANDLEINPUT](../Libraries_Manual_guide/node04F6.html) method, below.

If necessary, a gadget's GM_GOACTIVE method can precalculate and cache
information before it becomes the active gadget.  The gadget will use this
information while it's processing user input with the [GM_HANDLEINPUT](../Libraries_Manual_guide/node04F6.html)
method.  When it is time for the active gadget to become inactive,
Intuition will send the gadget a GM_GOINACTIVE message.  The gadget can
clean up its precalculations and cache in the GM_GOINACTIVE method.  For
more information on GM_GOINACTIVE, see its description below.

