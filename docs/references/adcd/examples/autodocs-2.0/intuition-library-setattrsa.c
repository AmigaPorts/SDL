/* Source: ADCD 2.1
 * Section: intuition-library-setattrsa
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-setattrsa.md
 */

    result = SetAttrsA( Object, TagList )
    D0                  A0      A1

    ULONG SetAttrsA( APTR, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) * );

    result = SetAttrs( Object, Tag1, ... )

    ULONG SetAttrs( APTR, ULONG, ... );
