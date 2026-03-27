/* Source: ADCD 2.1
 * Section: 27-display-routines-and-structures-viewport-display-memory
 * Library: libraries
 * ADCD reference: libraries/27-display-routines-and-structures-viewport-display-memory.md
 */

    #include <graphics/gfx.h>

    /* Depth, Width, and Height get set to something reasonable. */
    UBYTE Depth, Width, Height;

    /* Calculate resulting VP size. */
    bytes_per_ViewPort = Depth * RASSIZE(Width, Height);
