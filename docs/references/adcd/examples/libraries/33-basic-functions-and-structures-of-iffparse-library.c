/* Source: ADCD 2.1
 * Section: 33-basic-functions-and-structures-of-iffparse-library
 * Library: libraries
 * ADCD reference: libraries/33-basic-functions-and-structures-of-iffparse-library.md
 */

    /*
     * Structure associated with an active IFF stream.
     * "iff_Stream" is a value used by the client's read/write/seek
     * functions - it will not be accessed by the library itself and
     * can have any value (could even be a pointer or a BPTR).
     */
    struct IFFHandle {
            ULONG   iff_Stream;
            ULONG   iff_Flags;
            LONG    iff_Depth;      /*  Depth of context stack.  */
            /*  There are private fields hiding here.  */
    };
