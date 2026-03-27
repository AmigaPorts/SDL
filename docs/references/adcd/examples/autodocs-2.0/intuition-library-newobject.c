/* Source: ADCD 2.1
 * Section: intuition-library-newobject
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-newobject.md
 */

    object = NewObjectA( class, classID, tagList )
    D0                   A0     A1       A2

    APTR NewObjectA( struct IClass *, UBYTE *, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) * );

    object = NewObject( class, classID, Tag1, ... )

    APTR NewObject( struct IClass *, UBYTE *, ULONG, ... );
