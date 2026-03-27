# B / gadgetclass / New Methods: GM_HITTEST


This method asks a gadget if a point is within its bounds. Usually the
point corresponds to a mouse click.  Intuition sends a gadget this message
when the user clicks inside the rectangular bounds found in the object's
[Gadget](../Libraries_Manual_guide/node0149.html) structure (using its [TopEdge](../Libraries_Manual_guide/node0149.html#line33), [LeftEdge](../Libraries_Manual_guide/node0149.html#line33), [Width](../Libraries_Manual_guide/node0149.html#line33), and [Height](../Libraries_Manual_guide/node0149.html#line33) fields).
This method returns GMR_GADGETHIT if a point is within the gadget,
otherwise it returns zero.  Because the gadget decides if it was hit, the
gadget can be almost any shape or pattern.  Boopsi gadgets that default to
using the bounds of their Gadget structure should always return
GMR_GADGETHIT.

GM_HITTEST uses a custom message structure (defined in
<intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html#line174)>):


```c
    struct gpHitTest
    {
        ULONG             MethodID;     /* GM_HITTEST   */
        struct GadgetInfo *gpht_GInfo;
        struct
        {
            WORD X;                     /* Is this point inside */
            WORD Y;                     /* of the gadget?       */
        } gpht_Mouse;
    };
```
The gpht_Mouse.X and gpht_Mouse.Y fields make up the X and Y coordinates
of the hit point.  These coordinates are relative to the upper-left corner
of the gadget ([Gadget.LeftEdge](../Libraries_Manual_guide/node0149.html#line33), [Gadget.TopEdge](../Libraries_Manual_guide/node0149.html#line33)).

