/* Source: ADCD 2.1
 * Section: 32-expansion-library-the-expansion-sequence
 * Library: libraries
 * ADCD reference: libraries/32-expansion-library-the-expansion-sequence.md
 */

    UBYTE  er_Type;         /* Board type, size and flags */
    UBYTE  er_Product;      /* Product number, assigned by manufacturer */
    UBYTE  er_Flags;        /* Flags */
    UBYTE  er_Reserved03;   /* Must be zero ($ff inverted) */
    UWORD  er_Manufacturer; /* Unique ID,ASSIGNED BY AMIGA, INC.! */
    ULONG  er_SerialNumber; /* Available for use by manufacturer */
    UWORD  er_InitDiagVec;  /* Offset to optional "DiagArea" structure */
    UBYTE  er_Reserved0c;
    UBYTE  er_Reserved0d;
    UBYTE  er_Reserved0e;
    UBYTE  er_Reserved0f;
