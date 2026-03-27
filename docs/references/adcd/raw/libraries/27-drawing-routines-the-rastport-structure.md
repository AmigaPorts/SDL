# 27 / Drawing Routines / The RastPort Structure


The RastPort data structure can be found in the include files
<graphics/[rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html#line55)> and <graphics/[rastport.i](../Includes_and_Autodocs_2._guide/node00B3.html#line67)>. It contains the following
information:


struct RastPort
{
```c
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
```
#ifndef GFX_RASTPORT_1_2
```c
    UWORD   wordreserved[7];   /* Used to be a node */
    UBYTE   reserved[8];       /* For future use */
```
#endif
};


The sections that follow explain each of the items in the
RastPort structure is used.

 [Initializing a BitMap Structure](../Libraries_Manual_guide/node034B.html) 
 [Initializing a RastPort Structure](../Libraries_Manual_guide/node034C.html) 
 [RastPort Area-fill Information](../Libraries_Manual_guide/node034D.html) 
 [RastPort Graphics Element Pointer](../Libraries_Manual_guide/node034E.html) 
 [RastPort Write Mask](../Libraries_Manual_guide/node034F.html) 
 [RastPort Drawing Pens](../Libraries_Manual_guide/node0350.html) 
 [RastPort Drawing Modes](../Libraries_Manual_guide/node0351.html) 
 [RastPort Line and Area Drawing Patterns](../Libraries_Manual_guide/node0352.html) 
 [RastPort Pen Position and Size](../Libraries_Manual_guide/node0353.html) 
 [Text Attributes](../Libraries_Manual_guide/node0354.html) 

