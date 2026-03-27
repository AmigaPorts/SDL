/* Source: ADCD 2.1
 * Section: 28-sprite-functions-changing-the-appearance-of-a-simple
 * Library: libraries
 * ADCD reference: libraries/28-sprite-functions-changing-the-appearance-of-a-simple.md
 */

    struct spriteimage
        {
        UWORD posctl[2];  /* position and control data for this Sprite */

        /* Two words per line of Sprite height, first of the two words
         *  contains the MSB for color selection, second word contains
         * LSB (colors 0,1,2,3 from allowable color register selection
         *  set). Color '0' for any Sprite pixel makes it transparent.
         */
        UWORD data[height][2];  /* actual Sprite image */

        UWORD reserved[2];  /* reserved, initialize to 0, 0 */
        };
