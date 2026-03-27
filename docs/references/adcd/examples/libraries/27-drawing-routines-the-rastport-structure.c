/* Source: ADCD 2.1
 * Section: 27-drawing-routines-the-rastport-structure
 * Library: libraries
 * ADCD reference: libraries/27-drawing-routines-the-rastport-structure.md
 */

    struct  Layer  *Layer;
    struct  BitMap *BitMap;
    UWORD          *AreaPtrn;  /* Ptr to areafill pattern */
    struct  TmpRas *TmpRas;
    struct  AreaInfo *AreaInfo;
    struct  GelsInfo *GelsInfo;
    UBYTE   Mask;              /* Write mask for this raster */
    BYTE    FgPen;             /* Foreground pen for this raster */
    BYTE    BgPen;             /* Background pen  */
    BYTE    AOlPen;            /* Areafill outline pen */
    BYTE    DrawMode;          /* Drawing mode for fill, lines, and text */
    BYTE    AreaPtSz;          /* 2^n words for areafill pattern */
    BYTE    linpatcnt;         /* Current line drawing pattern preshift */
    BYTE    dummy;
    UWORD   Flags;             /* Miscellaneous control bits */
    UWORD   LinePtrn;          /* 16 bits for textured lines */
    WORD    cp_x, cp_y;	       /* Current pen position */
    UBYTE   minterms[8];
    WORD    PenWidth;
    WORD    PenHeight;
    struct  TextFont *Font;    /* Current font address */
    UBYTE   AlgoStyle;         /* The algorithmically generated style */
    UBYTE   TxFlags;           /* Text specific flags */
    UWORD   TxHeight;          /* Text height */
    UWORD   TxWidth;           /* Text nominal width */
    UWORD   TxBaseline;        /* Text baseline */
    WORD    TxSpacing;         /* Text spacing (per character) */
    APTR    *RP_User;
    ULONG   longreserved[2];
