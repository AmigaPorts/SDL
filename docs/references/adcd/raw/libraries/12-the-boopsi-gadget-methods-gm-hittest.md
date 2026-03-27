# 12 / / The Boopsi Gadget Methods / GM_HITTEST


When Intuition gets a left mouse button click in a window, one of the
things it does is check through the window's list of gadgets to see if
that click was inside the bounds of a gadget's [Gadget](../Libraries_Manual_guide/node0149.html) structure (using the
[LeftEdge](../Libraries_Manual_guide/node0149.html#line33), [TopEdge](../Libraries_Manual_guide/node0149.html#line33), [Width](../Libraries_Manual_guide/node0149.html#line33), and [Height](../Libraries_Manual_guide/node0149.html#line33) fields).  If it was (and that gadget
is a Boopsi gadget), Intuition sends that gadget a GM_HITTEST message
(defined in <intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html#line174)>):


```c
    struct gpHitTest
    {
        ULONG             MethodID;     /* GM_HITTEST   */
        struct GadgetInfo *gpht_GInfo;
        struct
        {
            WORD X;     /* Is this point inside of the gadget? */
            WORD Y;
        } gpht_Mouse;
    };
```
This message contains the coordinates of the mouse click.  These
coordinates are relative to the upper-left of the gadget ([LeftEdge](../Libraries_Manual_guide/node0149.html#line33),
[TopEdge](../Libraries_Manual_guide/node0149.html#line33)).

Because Intuition can only tell if the user clicked inside gadget's
"bounding box", Intuition only knows that the click was close to the
gadget.  Intuition uses the GM_HITTEST to ask the gadget if the click was
really inside the gadget.  The gadget returns GMR_GADGETHIT (defined in
<intuition/[gadgetclass](../Includes_and_Autodocs_2._guide/node00D3.html#line183)>) to tell Intuition that the user hit it,
otherwise it returns zero.  This method allows a gadget to be any shape or
pattern, rather than just rectangular.

