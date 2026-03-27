/* Source: ADCD 2.1
 * Section: iffparse-library-pushchunk
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-pushchunk.md
 */

    error = PushChunk (iff, type, id, size)
     d0                a0    d0   d1   d2

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    LONG             type, id, size;
