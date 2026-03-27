/* Source: ADCD 2.1
 * Section: graphics-library-cinit
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/graphics-library-cinit.md
 */

    CINIT will not actually allocate a new [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) if ucl==0.
    Instead you must allocate a block MEMF_PUBLIC|MEMF_CLEAR, the
    sizeof(struct UCopList) and pass it to this function.

    The system's [FreeVPortCopLists](../Includes_and_Autodocs_2._guide/node0444.html) function will take care of
    deallocating it if they are called.

    Prior to release V36 the  CINIT macro had { } braces surrounding
    the definition, preventing the proper return of the result value.
    These braces have been removed for the V36 include definitions.
