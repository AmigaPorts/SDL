/* Source: ADCD 2.1
 * Section: 27-forming-a-basic-display-preparing-the-colormap-structure
 * Library: libraries
 * ADCD reference: libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md
 */

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
