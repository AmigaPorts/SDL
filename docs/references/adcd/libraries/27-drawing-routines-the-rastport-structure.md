---
title: 27 / Drawing Routines / The RastPort Structure
manual: libraries
chapter: libraries
section: 27-drawing-routines-the-rastport-structure
functions: []
libraries: []
---

# 27 / Drawing Routines / The RastPort Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The RastPort data structure can be found in the include files
<graphics/[rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)> and <graphics/[rastport.i](autodocs-2.0/includes-graphics-rastport-i.md)>. It contains the following
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

 [Initializing a BitMap Structure](libraries/27-the-rastport-structure-initializing-a-bitmap-structure.md) 
 [Initializing a RastPort Structure](libraries/27-the-rastport-structure-initializing-a-rastport-structure.md) 
 [RastPort Area-fill Information](libraries/27-the-rastport-structure-rastport-area-fill-information.md) 
 [RastPort Graphics Element Pointer](libraries/27-the-rastport-structure-rastport-graphics-element-pointer.md) 
 [RastPort Write Mask](libraries/27-the-rastport-structure-rastport-write-mask.md) 
 [RastPort Drawing Pens](libraries/27-the-rastport-structure-rastport-drawing-pens.md) 
 [RastPort Drawing Modes](libraries/27-the-rastport-structure-rastport-drawing-modes.md) 
 [RastPort Line and Area Drawing Patterns](libraries/27-rastport-structure-rastport-line-and-area-drawing.md) 
 [RastPort Pen Position and Size](libraries/27-the-rastport-structure-rastport-pen-position-and-size.md) 
 [Text Attributes](libraries/27-the-rastport-structure-text-attributes.md) 

