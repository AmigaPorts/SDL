# 27 / / Forming a Basic Display / Preparing the ColorMap Structure


When the [View](../Libraries_Manual_guide/node032B.html#line51) is created, Copper instructions are generated to change the
current contents of each color register just before the topmost line of a
[ViewPort](../Libraries_Manual_guide/node032B.html#line59) so that this ViewPort's color registers will be used for
interpreting its display.  To set the color registers you create a
[ColorMap](../Libraries_Manual_guide/node00F1.html#line4) for the ViewPort with [GetColorMap()](../Includes_and_Autodocs_2._guide/node0445.html) and call [SetRGB4()](../Includes_and_Autodocs_2._guide/node047C.html).  Here are
the steps used in 1.3 to initialize a ColorMap:


```c
    if( view.ColorMap=GetColorMap( 4L ) )
        LoadRGB4((&viewPort, colortable, 4);
```
Under Release 2, a [ColorMap](../Libraries_Manual_guide/node00F1.html#line4) is attached to the [View](../Libraries_Manual_guide/node032B.html#line51) -- usually along with
[DisplayInfo](../Includes_and_Autodocs_2._guide/node00BD.html#line49) and [ViewExtra](../Libraries_Manual_guide/node032C.html#line16) -- by calling the [VideoControl()](../Libraries_Manual_guide/node0339.html#line15) function.


```c
    /*  RGB values for the four colors used.  */
    #define BLACK 0x000
    #define RED   0xf00
    #define GREEN 0x0f0
    #define BLUE  0x00f

    /*  Define some colors in an array of UWORDS.  */
    static UWORD colortable[] = { BLACK, RED, GREEN, BLUE };

    /* Fill the TagItem Data field with the address of the properly
       initialized (including ViewPortExtra) structure to be passed to
       VideoControl().                                                 */
    vc[0].ti_Data = (ULONG)viewPort;

    /* Init ColorMap.  2 planes deep, so 4 entries
       (2 raised to #planes power).                */
    if(cm = GetColorMap( 4L ) )
    {
        /* For applications that must be compatible with 1.3, replace  */
        /* the next 2 lines with: viewPort.ColorMap=cm;                */
        if( VideoControl( cm , vcTags ) )
            fail("Could not attach extended structures\n");

        /*  Change colors to those in colortable.  */
        LoadRGB4(&viewPort, colortable, 4);
    }


    The 4 Is For Bits, Not Entries.
    -------------------------------
    The 4 in the name [LoadRGB4()](../Includes_and_Autodocs_2._guide/node0458.html) refers to the fact that each of the red,
    green, and blue values in a color table entry consists of four bits.
    It has nothing to do with the fact that this particular color table
    contains four entries. The call [GetRGB4()](../Includes_and_Autodocs_2._guide/node0448.html) returns the RGB value of a
    single entry of a [ColorMap](../Libraries_Manual_guide/node00F1.html#line4). [SetRGB4CM()](../Includes_and_Autodocs_2._guide/node047D.html) allows individual control of
    the entries in the ColorMap before or after linking it into the
    [ViewPort](../Libraries_Manual_guide/node032B.html#line59).
```
The [LoadRGB4()](../Includes_and_Autodocs_2._guide/node0458.html) call above could be replaced with the following:


```c
    register USHORT entry;

    /*  Operate on the same four ColorMap entries as above.  */
    for (entry = 0; entry < 4; entry++)
        {
        /* Call SetRGB4CM() with the address of the ColorMap, the entry to
           be changed, and the Red, Green, and Blue values to be stored
           there.
        */
        SetRGB4CM(viewPort.ColorMap, entry,
        /* Extract the three color values from the one colortable entry. */
            ((colortable[entry] & 0x0f00) >> 8),
                ((colortable[entry] & 0x00f0) >> 4),
                    (colortable[entry] & 0x000f));
        }
```
Notice above how the four bits for each color are masked out and shifted
right to get values from 0 to 15.


```c
    WARNING!
    --------
    It is important to use only the standard system [ColorMap](../Libraries_Manual_guide/node00F1.html#line4)-related
    calls to access the ColorMap entries.  These calls will remain
    compatible with recent and future enhancements to the ColorMap
    structure.
```
You might need to specify more colors in the color map than you think. If
you use a [dual playfield](../Libraries_Manual_guide/node0345.html) display (covered later in this chapter) with a
depth of 1 for each of the two playfields, this means a total of four
colors (two for each playfield). However, because playfield 2 uses color
registers starting from number 8 on up when in dual-playfield mode, the
color map must be initialized to contain at least 10 entries. That is, it
must contain entries for colors 0 and 1 (for playfield 1) and color
numbers 8 and 9 (for playfield 2). Space for sprite colors must be
allocated as well. For Amiga system software version 1.3 and earlier, when
in doubt, allocate a [ColorMap](../Libraries_Manual_guide/node00F1.html#line4) with 32 entries, just in case.

