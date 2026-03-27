/* Source: ADCD 2.1
 * Section: 27-forming-a-basic-display-preparing-the-colormap-structure
 * Library: libraries
 * ADCD reference: libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md
 */

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
