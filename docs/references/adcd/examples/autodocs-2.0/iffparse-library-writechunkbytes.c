/* Source: ADCD 2.1
 * Section: iffparse-library-writechunkbytes
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-writechunkbytes.md
 */

    error = WriteChunkBytes (iff, buf, size)
     d0                      a0   a1    d0

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    UBYTE            *buf;
    LONG             size;
