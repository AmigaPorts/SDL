---
title: 32 Expansion Library / The Expansion Sequence
manual: libraries
chapter: libraries
section: 32-expansion-library-the-expansion-sequence
functions: []
libraries: []
---

# 32 Expansion Library / The Expansion Sequence

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

During system initialization, expansion.library configures each expansion
peripheral in turn by examining its identification information and
assigning it an appropriate address space.  If the board is a RAM board,
it can be added to the system memory list to make the RAM available for
allocation by system tasks.

Descriptions of all configured boards are kept in a private [ExpansionBase](autodocs-2.0/includes-libraries-expansionbase-h.md)
list of ConfigDev structures.  A board's identification information is
stored in the ExpansionRom sub-structure contained within the ConfigDev
structure.  Applications can examine individual or all ConfigDev
structures with the expansion.library function [FindConfigDev()](libraries/32-the-expansion-sequence-simple-expansion-library-example.md).

The ConfigDev structure is defined in <libraries/[configvars.h](autodocs-2.0/includes-libraries-configvars-h.md)> and <[.i](autodocs-2.0/includes-libraries-configvars-i.md)>:


struct ConfigDev {
   struct Node         cd_Node;
   UBYTE               cd_Flags;     /* (read/write) */
   UBYTE               cd_Pad;       /* reserved */
   struct ExpansionRom cd_Rom;       /* copy of board's expansion ROM */
   APTR                cd_BoardAddr; /* memory where board was placed */
   ULONG               cd_BoardSize; /* size of board in bytes */
   UWORD               cd_SlotAddr;  /* which slot number (PRIVATE) */
   UWORD               cd_SlotSize;  /* number of slots (PRIVATE) */
   APTR                cd_Driver;    /* pointer to node of driver */
   struct ConfigDev    *cd_NextCD;   /* linked list of drivers to config */
   ULONG               cd_Unused[4]; /* for whatever the driver wants */
};

/* cd_Flags */
#define CDB_SHUTUP      0       /* this board has been shut up */
#define CDB_CONFIGME    1       /* this board needs a driver to claim it */

#define CDF_SHUTUP      0x01
#define CDF_CONFIGME    0x02


The ExpansionRom structure within ConfigDev contains the board
identification information that is read from the board's PAL or ROM at
expansion time.  The actual onboard identification information of a Zorro
II board appears in the high nibbles of the first $40 words at the start
of the board.  Except for the first nibble pair ($00/$02) which when
combined form er_Type, the information is stored in inverted
("ones-complement") format where binary 1's are represented as 0's and 0's
are represented as 1's.  The expansion.library reads the nibbles of
expansion information from the board, un-inverts them (except for $00/$02
er_Type which is already un-inverted), and combines them to form the
elements of the ExpansionRom structure.

The ExpansionRom structure is defined in <libraries/[configregs.h](autodocs-2.0/includes-libraries-configregs-h.md)> and <[.i](autodocs-2.0/includes-libraries-configregs-i.md)>:


struct ExpansionRom {            /* First 16 bytes of the expansion ROM */
```c
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
```
};


 [Simple Expansion Library Example](libraries/32-the-expansion-sequence-simple-expansion-library-example.md) 

