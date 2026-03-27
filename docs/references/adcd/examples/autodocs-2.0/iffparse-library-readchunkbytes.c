/* Source: ADCD 2.1
 * Section: iffparse-library-readchunkbytes
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-readchunkbytes.md
 */

    actual = ReadChunkBytes (iff, buf, size)
      d0                     a0   a1    d0

    LONG             actual;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    UBYTE            *buf;
    LONG             size;
