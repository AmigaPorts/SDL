/* Source: ADCD 2.1
 * Section: the-object-chunks-stxt
 * Library: devices
 * ADCD reference: devices/the-object-chunks-stxt.md
 */

    struct STXTstruct {
        ULONG       ID;
        ULONG       Size;
        UBYTE       Pad0;           /* Always 0 (for future expansion) */
        UBYTE       WhichFont;      /* Which font to use */
        IEEE        CharW, CharH,   /* W/H of an individual char */
                    BaseX, BaseY,   /* Start of baseline */
                    Rotation;       /* Angle of text (in degrees) */
        USHORT      NumChars;
        char        TextChars[NumChars];
    };
