/* Source: ADCD 2.1
 * Section: 27-rastport-structure-rastport-line-and-area-drawing
 * Library: libraries
 * ADCD reference: libraries/27-rastport-structure-rastport-line-and-area-drawing.md
 */

    USHORT areaPattern[3][8] =
    {
    /* plane 0 pattern */
        {
               0x0000, 0x0000,
               0xffff, 0xffff,
               0x0000, 0x0000,
               0xffff, 0xffff
        },
    /* plane 1 pattern */
        {
               0x0000, 0x0000,
               0x0000, 0x0000,
               0xffff, 0xffff,
               0xffff, 0xffff
        },
    /* plane 2 pattern */
        {
               0xff00, 0xff00,
               0xff00, 0xff00,
               0xff00, 0xff00,
               0xff00, 0xff00
        }
    };

    SetAfPt(&rastPort, &areaPattern, -3);

    /* when doing this, it is best to set */
    /* three other parameters as follows: */
    SetAPen(&rastPort, -1);
    SetBPen(&rastPort, 0);
    SetDrMd(&rastPort, JAM2);
