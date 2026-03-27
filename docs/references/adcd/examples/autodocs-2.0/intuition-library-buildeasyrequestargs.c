/* Source: ADCD 2.1
 * Section: intuition-library-buildeasyrequestargs
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-buildeasyrequestargs.md
 */

    ReqWindow = BuildEasyRequestArgs( RefWindow, easyStruct, IDCMP, Args )
    D0                                A0         A1          D0     A3

    struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *BuildEasyRequestArgs( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
            struct [EasyStruct](../Includes_and_Autodocs_2._guide/node00D4.html#line1253) *, ULONG, APTR );

    ReqWindow = BuildEasyRequest( RefWindow, easyStruct, IDCMP, Arg1, ... )

    struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *BuildEasyRequest( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *,
            struct [EasyStruct](../Includes_and_Autodocs_2._guide/node00D4.html#line1253) *, ULONG, APTR, ... );
