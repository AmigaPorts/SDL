/* Source: ADCD 2.1
 * Section: 27-rastport-structure-rastport-line-and-area-drawing
 * Library: libraries
 * ADCD reference: libraries/27-rastport-structure-rastport-line-and-area-drawing.md
 */

    USHORT ditherData[] =
    {
        0x5555, 0xAAAA
    };

    SetAfPt(&rastPort, ditherData, 1);
