/* Source: ADCD 2.1
 * Section: intuition-library-makeclass
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-makeclass.md
 */

    iclass = MakeClass( ClassID, SuperClassID, SuperClassPtr,
    D0                  A0       A1            A2
            InstanceSize, Flags )
            D0            D1

    struct IClass *MakeClass( UBYTE *, UBYTE *, struct IClass *,
            UWORD, ULONG );
