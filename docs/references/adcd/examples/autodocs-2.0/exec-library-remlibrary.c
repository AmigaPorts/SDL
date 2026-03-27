/* Source: ADCD 2.1
 * Section: exec-library-remlibrary
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-remlibrary.md
 */

    This function calls the library's EXPUNGE vector, which requests
    that a library delete itself.  The library may refuse to do this if
    it is busy or currently open. This is not typically called by user
    code.

    There are certain, limited circumstances where it may be
    appropriate to attempt to specifically flush a certain [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34).
    Example:

     /* Attempts to flush the named library out of memory. */
     #include [<exec/types.h>](../Includes_and_Autodocs_2._guide/node0096.html)
     #include [<exec/execbase.h>](../Includes_and_Autodocs_2._guide/node009E.html)

     void FlushLibrary(name)
     STRPTR name;
     {
     struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *result;

        Forbid();
        if(result=(struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *)FindName(&SysBase->LibList,name))
            RemLibrary(result);
        Permit();
     }
