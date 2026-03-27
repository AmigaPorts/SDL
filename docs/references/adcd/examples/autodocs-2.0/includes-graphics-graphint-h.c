/* Source: ADCD 2.1
 * Section: includes-graphics-graphint-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-graphics-graphint-h.md
 */

    struct Node is_Node;
    struct Isrvstr *Iptr;   /* passed to srvr by os */
    int (*code)();
    int (*ccode)();
    int Carg;
