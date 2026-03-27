/* Source: ADCD 2.1
 * Section: 27-drawing-multiple-lines-with-a-single-command
 * Library: libraries
 * ADCD reference: libraries/27-drawing-multiple-lines-with-a-single-command.md
 */

    SHORT linearray[] =
        {
         3, 3,
        15, 3,
        15,15,
         3,15,
         3, 3
        };

    PolyDraw(&rastPort, 5, linearray);
