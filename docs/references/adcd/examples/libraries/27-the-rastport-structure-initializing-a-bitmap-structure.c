/* Source: ADCD 2.1
 * Section: 27-the-rastport-structure-initializing-a-bitmap-structure
 * Library: libraries
 * ADCD reference: libraries/27-the-rastport-structure-initializing-a-bitmap-structure.md
 */

    #define DEPTH 2       /* Two planes deep. */
    #define WIDTH 320     /* Width in pixels. */
    #define HEIGHT 200    /* Height in scanlines. */

    struct BitMap bitMap;

    /* Initialize the BitMap. */
    InitBitMap(&bitMap, DEPTH, WIDTH, HEIGHT);
