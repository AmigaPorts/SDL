/* Source: ADCD 2.1
 * Section: intuition-library-sysreqhandler
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-sysreqhandler.md
 */

    Implementation of EasyRequest() input loop:

    window = BuildEasyRequest( ZZZZ )
    while ( (retval = SysReqHandler( window, idcmp_ptr, TRUE )) == -2 )
    {
        /* loop     */;
    }
    FreeSysRequest( window );
