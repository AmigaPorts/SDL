/* Source: ADCD 2.1
 * Section: 27-the-rastport-structure-rastport-write-mask
 * Library: libraries
 * ADCD reference: libraries/27-the-rastport-structure-rastport-write-mask.md
 */

    SetWrMsk(&rastPort, 0xE0);          /* Disable planes 1 through 5. */

    SetAPen(&rastPort, 0);           /* Clear the Extra-Half-Brite bit */
    RectFill(&rastPort, 20, 20, 40, 30);    /*   in the old rectangle. */

    SetAPen(&rastPort, 32);            /* Set the Extra-Half-Brite bit */
    RectFill(&rastPort, 30, 25, 50, 35);    /*   in the new rectangle. */

    SetWrMsk(&rastPort, -1);                  /* Re-enable all planes. */
