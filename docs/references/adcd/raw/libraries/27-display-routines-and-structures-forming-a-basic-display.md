# 27 / Display Routines and Structures / Forming a Basic Display


Here are the data structures that you need to define to create a basic
display:


```c
    struct View view;               /* These get used in all versions of */
    struct ViewPort viewPort;       /* the OS */
    struct BitMap bitMap;
    struct RasInfo rasInfo;
    struct ColorMap *cm;

    struct ViewExtra *vextra;       /* Extra View data, new in Release 2 */
    struct ViewPortExtra *vpextra;  /* Extra ViewPort data, new in       */
                                    /* Release 2 */
    struct MonitorSpec *monspec;    /* Monitor data needed in Release 2  */
    struct DimensionInfo dimquery;  /* Display dimension data needed in  */
                                    /* Release 2 */
```
[ViewExtra](../Includes_and_Autodocs_2._guide/node00B8.html#line67) and [ViewPortExtra](../Includes_and_Autodocs_2._guide/node00B8.html#line76) are new data structures used in Release 2 to
hold extended data about their corresponding parent structure.  ViewExtra
contains information about the video monitor being used to render the
[View](../Libraries_Manual_guide/node032B.html#line51).  ViewPortExtra contains information required for clipping of the
[ViewPort](../Libraries_Manual_guide/node032B.html#line59).

[GfxNew()](../Includes_and_Autodocs_2._guide/node044E.html) is used to create these extended data structures and
[GfxAssociate()](../Includes_and_Autodocs_2._guide/node044B.html) is used to associate the extended data structure with an
appropriate parent structure.  Although GfxAssociate() can associate a
[ViewPortExtra](../Includes_and_Autodocs_2._guide/node00B8.html#line76) structure with a [ViewPort](../Libraries_Manual_guide/node032B.html#line59), it is better to use
[VideoControl()](../Libraries_Manual_guide/node0339.html#line15) with the [VTAG_VIEWPORTEXTRA_SET](../Libraries_Manual_guide/node0339.html#line38) tag instead.  Keep in mind
that GfxNew() allocates memory for the resulting data structure which must
be returned using [GfxFree()](../Includes_and_Autodocs_2._guide/node044C.html) before the application exits.  The function
[GfxLookUp()](../Includes_and_Autodocs_2._guide/node044D.html) will find the address of an extended data structure from the
address of its parent.

 [Preparing the View Structure](../Libraries_Manual_guide/node032D.html) 
 [Preparing the BitMap Structure](../Libraries_Manual_guide/node032E.html) 
 [Preparing the RasInfo Structure](../Libraries_Manual_guide/node032F.html) 
 [Preparing the ViewPort Structure](../Libraries_Manual_guide/node0330.html) 
 [Preparing the ColorMap Structure](../Libraries_Manual_guide/node0331.html) 
 [Creating the Display Instructions](../Libraries_Manual_guide/node0332.html) 

