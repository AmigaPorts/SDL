/* Source: ADCD 2.1
 * Section: 28-using-bobs-vsprite-flags-and-bobs
 * Library: libraries
 * ADCD reference: libraries/28-using-bobs-vsprite-flags-and-bobs.md
 */

    /* space for 16 bits times 5 lines times 5 bitplanes */
    myBob.SaveBuffer = AllocRaster( (UWORD) 16, (UWORD) (5 * 5) );


    Warning:
    --------
    The [SaveBuffer](../Libraries_Manual_guide/node0398.html#line5) must be allocated from Chip memory and contain an
    even number of word-aligned bytes.  The [AllocRaster()](../Libraries_Manual_guide/node032E.html) function
    does this for you.  The AllocRaster() function rounds the width
    value up to the next integer multiple of 16 bits which is greater
    than or equal to the current value an it obtains memory from the Chip
    memory pool.
