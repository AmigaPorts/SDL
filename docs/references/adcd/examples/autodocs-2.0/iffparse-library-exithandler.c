/* Source: ADCD 2.1
 * Section: iffparse-library-exithandler
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-exithandler.md
 */

    error = ExitHandler (iff, type, id, position, hook, object)
     d0                  a0    d0   d1    d2       a1     a2

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    LONG             type, id, position;
    struct [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23)     *hook;
    APTR             object;
