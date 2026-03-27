/* Source: ADCD 2.1
 * Section: include-graphics-graphint-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-graphics-graphint-h.md
 */

    struct Node is_Node;
    struct Isrvstr *Iptr;   /* passed to srvr by os */
    LONG (*code)();
    LONG (*ccode) __CLIB_PROTOTYPE((APTR));
    APTR Carg;
