# 27 / / Forming a Basic Display / Preparing the ViewPort Structure


To prepare the [ViewPort](../Libraries_Manual_guide/node032B.html#line59) structure for further use, you call [InitVPort()](../Includes_and_Autodocs_2._guide/node0457.html)
and initialize certain fields as follows:


```c
    InitVPort(&viewPort);        /* Initialize the ViewPort.             */
    viewPort.RasInfo = &rasInfo; /* The rasInfo must also be initialized */
    viewPort.DWidth  = WIDTH;
    viewPort.DHeight = HEIGHT;

    /* Under 1.3, you should set viewPort.Modes here to select a display
     * mode. Under Release 2, use VideoControl() with VTAG_NORMAL_DISP_SET
     * to select a display mode by attaching a DisplayInfo structure to
     *  the ViewPort.                                                    */
```
The [InitVPort()](../Includes_and_Autodocs_2._guide/node0457.html) routine presets certain default values in the [ViewPort](../Libraries_Manual_guide/node032B.html#line59)
structure.  The defaults include:

  * [Modes](../Libraries_Manual_guide/node0327.html) variable set to zero--this means you select a low-resolution

```c
    display.  (To alter this, use [VideoControl()](../Libraries_Manual_guide/node0339.html#line15) with the
    [VTAG_NORMAL_DISP_SET](../Libraries_Manual_guide/node0339.html#line44) tag as explained below.)
```
  * [Next](../Includes_and_Autodocs_2._guide/node00B8.html#line40) variable set to NULL--no other [ViewPort](../Libraries_Manual_guide/node032B.html#line59) is linked to this one.

    If you want a display with multiple ViewPorts, you must fill in the
    link yourself.
If you want to create a [View](../Libraries_Manual_guide/node032B.html#line51) with two or more [ViewPort](../Libraries_Manual_guide/node032B.html#line59)s you must declare
and initialize the ViewPorts as above.  Then link them together using the
[ViewPort.Next](../Includes_and_Autodocs_2._guide/node00B8.html#line40) field with a NULL link for the ViewPort at the end of the
chain:



```c
    viewPortA.Next = &viewPortB; /* Tell 1st one the address of the 2nd. */
    viewPortB.Next = NULL;       /* There are no others after this one.  */
```
For Release 2 applications, once a [ViewPort](../Libraries_Manual_guide/node032B.html#line59) has been prepared, a
[ViewPortExtra](../Libraries_Manual_guide/node032C.html#line16) structure must also be created with [GfxNew()](../Libraries_Manual_guide/node032C.html#line22), initialized,
and associated with the ViewPort via the [VideoControl()](../Libraries_Manual_guide/node0339.html#line15) function.  In
addition, a [DisplayInfo](../Includes_and_Autodocs_2._guide/node00BD.html#line49) for this mode must be attached to the ViewPort.
The fragment below shows how to do this.  For complete examples, refer to
the program listings of [RGBBoxes.c](../Libraries_Manual_guide/node059D.html) and [WBClone.c](../Libraries_Manual_guide/node059B.html).


struct TagItem vcTags[] =              /* These tags will be passed to   */
{                                      /* the VideoControl() function to */
```c
    { VTAG_ATTACH_CM_SET, NULL },      /* set up the extended ViewPort   */
    { VTAG_VIEWPORTEXTRA_SET, NULL },  /* structures required in Release */
    { VTAG_NORMAL_DISP_SET, NULL },    /* 2. The NULL ti_Data field of   */
    { VTAG_END_CM, NULL }              /* these tags must be filled in   */
```
};                                     /* before making the call to      */

```c
                                       /* VideoControl().                */
```
struct DimensionInfo dimquery;  /* Release 2 structure for display size  */

                                /* data */
/* Make a ViewPortExtra and get ready to attach it */
if( vpextra = GfxNew(VIEWPORT_EXTRA_TYPE) )
```c
    {
    vcTags[1].ti_Data = (ULONG) vpextra;

    /* Initialize the DisplayClip field of the ViewPortExtra structure */
    if( GetDisplayInfoData( NULL , (UBYTE *) &dimquery ,
                           sizeof(struct dimquery) , DTAG_DIMS, modeID) )
        {
        vpextra->DisplayClip = dimquery.Nominal;

        /* Make a DisplayInfo and get ready to attach it */
        if( !(vcTags[2].ti_Data = (ULONG) FindDisplayInfo(modeID)) )
            fail("Could not get DisplayInfo\n");
        }
    else fail("Could not get DimensionInfo\n");
    }
```
else fail("Could not get ViewPortExtra\n");

/* This is for backwards compatibility with, for example,   */
/* a 1.3 screen saver utility that looks at the Modes field */
viewPort.Modes = (UWORD) (modeID & 0x0000ffff);

