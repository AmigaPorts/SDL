/* Source: ADCD 2.1
 * Section: iffparse-library-readchunkrecords
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-readchunkrecords.md
 */

    actual = ReadChunkRecords (iff, buf, recsize, numrec)
      d0                       a0   a1     d0       d1

    LONG             actual;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    UBYTE            *buf;
    LONG             recsize, numrec;
