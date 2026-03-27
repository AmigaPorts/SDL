/* Source: ADCD 2.1
 * Section: 27-display-routines-and-structures-viewport-display-memory
 * Library: libraries
 * ADCD reference: libraries/27-display-routines-and-structures-viewport-display-memory.md
 */

    values [DxOffset](../Includes_and_Autodocs_2._guide/node00B8.html#line40) and [DyOffset](../Includes_and_Autodocs_2._guide/node00B8.html#line40) that are used to position this portion
    relative to the overall View.  The ViewPort also contains the
    variables [DHeight](../Libraries_Manual_guide/node0324.html) and [DWidth](../Libraries_Manual_guide/node0325.html), which define the size of this display
    segment; a [Modes](../Libraries_Manual_guide/node0327.html) variable; and a pointer to the local [ColorMap](../Libraries_Manual_guide/node00F1.html#line4).
    Under Release 2, the [VideoControl()](../Libraries_Manual_guide/node0339.html#line15) function and its various tags are
    used to manipulate the ColorMap and ViewPort.Modes.  Each ViewPort
    also contains a pointer to the next ViewPort.  You create a linked
    list of ViewPorts to define the complete display.
