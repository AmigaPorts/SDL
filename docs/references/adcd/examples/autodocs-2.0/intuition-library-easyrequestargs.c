/* Source: ADCD 2.1
 * Section: intuition-library-easyrequestargs
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-easyrequestargs.md
 */

    num = EasyRequestArgs( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), easyStruct, IDCMP_ptr, ArgList )
    D0                     A0      A1          A2         A3

    LONG EasyRequestArgs( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, struct [EasyStruct](../Includes_and_Autodocs_2._guide/node00D4.html#line1253) *,
            ULONG *, APTR );

    num = EasyRequest( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), easyStruct, IDCMP_ptr, Arg1, Arg2, ... )

    LONG EasyRequest( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, struct [EasyStruct](../Includes_and_Autodocs_2._guide/node00D4.html#line1253) *,
            ULONG *, APTR, ... );

    ( from intuition.h )
    struct [EasyStruct](../Includes_and_Autodocs_2._guide/node00D4.html#line1253) {
        ULONG       es_StructSize;
        ULONG       es_Flags;
        UBYTE       *es_Title;
        UBYTE       *es_TextFormat;
        UBYTE       *es_GadgetFormat;
    };
