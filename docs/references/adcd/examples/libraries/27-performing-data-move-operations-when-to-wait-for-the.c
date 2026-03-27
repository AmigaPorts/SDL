/* Source: ADCD 2.1
 * Section: 27-performing-data-move-operations-when-to-wait-for-the
 * Library: libraries
 * ADCD reference: libraries/27-performing-data-move-operations-when-to-wait-for-the.md
 */

    OwnBlitter();    /* Gain exclusive access to the hardware blitter    */

    for(planes=0; planes < bitmap->depth; planes++)
            {
            WaitBlit();    /* Sleep until the previous blitter operation */
                           /* completes start a blit                     */
            }

    DisownBlitter(); /* Release exclusive access to the hardware blitter */
