/* Source: ADCD 2.1
 * Section: 20-other-memory-functions-allocating-memory-at-an-absolute
 * Library: libraries
 * ADCD reference: libraries/20-other-memory-functions-allocating-memory-at-an-absolute.md
 */

    APTR absoluteptr;

    absoluteptr = (APTR)AllocAbs(10000, 0x2F0000);
    if (!(absoluteptr))
        { /* Couldn't get memory, act accordingly. */  }

    /* After we're done using it, we call FreeMem() to free the memory */
    /* block. */
    FreeMem(absoluteptr, 10000);
