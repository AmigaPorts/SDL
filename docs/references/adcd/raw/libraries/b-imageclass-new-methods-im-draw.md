# B / imageclass / New Methods: IM_DRAW


This method tells an image object to draw itself.  Applications should not
call this method directly, instead use the intuition.library function
[DrawImageState()](../Includes_and_Autodocs_2._guide/node0211.html).  The return value for this method is not explicitly
defined.

The IM_DRAW method uses a custom message structure:

```c
    struct impDraw
    {
        ULONG           MethodID;    /* IM_DRAW                    */
        struct RastPort *imp_RPort;  /* RastPort to render into    */
        struct
        {                            /* X and Y offset relative to */
            WORD X;                  /* the image's IA_Left and    */
            WORD Y;                  /* IA_Top attributes          */
        } imp_Offset;
        ULONG           imp_State;   /* Visual state of image      */
        struct DrawInfo *imp_DrInfo; /* describing rendering area  */
    };
```
n


The imp_State field contains the visual state to render the image.  The
visual states (defined in <intuition/[imageclass.h](../Includes_and_Autodocs_2._guide/node00E3.html#line124)>) are:

IDS_NORMAL            Render using normal imagery.  This is the only

                      kind of imagery available to non-Boopsi images.
IDS_SELECTED          Render using "selected" imagery.  "Selected"

                      refers to the state of a gadget's imagery when it
                      is the selected gadget.
IDS_DISABLED          Render using "disabled" imagery.  "Disabled"

                      refers to the state of a gadget's imagery when it
                      is disabled.  Typically, a disabled image has a
                      ghosting pattern on top of it.
IDS_INACTIVENORMAL    This is a special version of IDS_NORMAL for a

                      "normal" image that is in the border of an
                      inactive window.
IDS_INACTIVESELECTED  This is a special version of IDS_SELECTED for a

                      "selected" image that is in the border of an
                      inactive window.
IDS_INACTIVEDISABLED  This is a special version of IDS_DISABLED for a

                      "disabled" image that is in the border of an
                      inactive window.
IDS_BUSY              Render using "busy" imagery as if the object

                      was the image of a gadget in a busy state.  The
                      busy gadget state is not yet supported by
                      Intuition.
IDS_INDETERMINATE     Render using "indeterminate" imagery as if the

                      object was the image of a gadget in an
                      indeterminate state.  The indeterminate gadget
                      state is not yet supported by Intuition.
Most image objects do not have different visual states for each possible
imp_State.  See the [imageclass](../Libraries_Manual_guide/node04D1.html) entries in this index for more details.

When setting the pens to render an image, use the values from the
imp_DrInfo->dri_Pens pen array (Note that it is possible for imp_DrInfo to
be NULL).  The possible pen values are defined in <intuition/[screens.h](../Includes_and_Autodocs_2._guide/node00DD.html#line78)>.
See the "[Intuition Screens](../Libraries_Manual_guide/node00EB.html)" chapter of the Amiga ROM Kernel Reference
Manual: Libraries for more information on the pen array.

