# 27 / / Forming a Basic Display / Preparing the RasInfo Structure


The [RasInfo](../Libraries_Manual_guide/node032B.html#line69) structure provides information to the system about the
location of the [BitMap](../Libraries_Manual_guide/node032B.html#line74) as well as the positioning of the display area as a
window against a larger drawing area. Use the following steps to prepare
the RasInfo structure:


```c
    /* Initialize the RasInfos. */
    rasInfo.BitMap = &bitMap;  /* Attach the corresponding BitMap.       */
    rasInfo.RxOffset = 0;      /* Align upper left corners of display    */
    rasInfo.RyOffset = 0;      /* with upper left corner of drawing area.*/
    rasInfo.Next = NULL;       /* for a single playfield display, there
                                * is only one RasInfo structure present  */
```
The system may be made to reinterpret the [RxOffset](../Includes_and_Autodocs_2._guide/node00B8.html#line106) and [RyOffset](../Includes_and_Autodocs_2._guide/node00B8.html#line106) values in
a [ViewPort](../Libraries_Manual_guide/node032B.html#line59)'s [RasInfo](../Libraries_Manual_guide/node032B.html#line69) structure by calling [ScrollVPort()](../Includes_and_Autodocs_2._guide/node0474.html) with the address
of the ViewPort. Changing one or both offsets and calling ScrollVPort()
has the effect of scrolling the ViewPort.

