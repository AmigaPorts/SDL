---
title: 32 / / ROM Based and Autoboot Drivers / Events At DIAG Time
manual: libraries
chapter: libraries
section: 32-rom-based-and-autoboot-drivers-events-at-diag-time
functions: []
libraries: []
---

# 32 / / ROM Based and Autoboot Drivers / Events At DIAG Time

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When your AUTOCONFIG hardware board is configured by the expansion
initialization routine, its [ExpansionRom](autodocs-2.0/includes-libraries-configregs-h.md) structure is copied into the
ExpansionRom subfield of a [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md) structure.  This ConfigDev structure
will be linked to the expansion.library's private list of configured
boards.

After the board is configured, the er_Type field of its [ExpansionRom](autodocs-2.0/includes-libraries-configregs-h.md)
structure is checked.  The DIAGVALID bit set declares that there is a
valid DiagArea (a ROM/diagnostic area) on this board.  If there is a valid
DiagArea, expansion next tests the er_InitDiagVec vector in its copy of
the ExpansionRom structure.  This offset is added to the base address of
the configured board; the resulting address points to the start of this
board's DiagArea.


```c
    struct ExpansionRom
    {
        UBYTE   er_Type;          /* <-- if ERTB_DIAGVALID set */
        UBYTE   er_Product;
        UBYTE   er_Flags;
        UBYTE   er_Reserved03;
        UWORD   er_Manufacturer;
        ULONG   er_SerialNumber;
        UWORD   er_InitDiagVec;   /* <-- then er_InitDiagVec      */
        UBYTE   er_Reserved0c;    /*     is added to cd_BoardAddr */
        UBYTE   er_Reserved0d;    /*     and points to DiagArea   */
        UBYTE   er_Reserved0e;
        UBYTE   er_Reserved0f;
    };
```
Now expansion knows that there is a [DiagArea](autodocs-2.0/includes-libraries-configregs-h.md), and knows where it is.


```c
     struct DiagArea
     {
         UBYTE   da_Config;        /* <-- if DAC_CONFIGTIME is set */
         UBYTE   da_Flags;
         UWORD   da_Size;          /* <-- then da_Size bytes will  */
         UWORD   da_DiagPoint;     /*     be copied into RAM       */
         UWORD   da_BootPoint;
         UWORD   da_Name;
         UWORD   da_Reserved01;
         UWORD   da_Reserved02;
     };

    /* da_Config definitions */
    #define DAC_BUSWIDTH    0xC0  /* two bits for bus width */
    #define DAC_NIBBLEWIDE  0x00
    #define DAC_BYTEWIDE    0x40  /* invalid for 1.3 - see note below */
    #define DAC_WORDWIDE    0x80

    #define DAC_BOOTTIME    0x30  /* two bits for when to boot */
    #define DAC_NEVER       0x00  /* obvious */
    #define DAC_CONFIGTIME  0x10  /* call da_BootPoint when first
                                     configging the device */
    #define DAC_BINDTIME    0x20  /* run when binding drivers to boards */
```
Next, expansion tests the first byte of the DiagArea structure to
determine if the CONFIGTIME bit is set.  If this bit is set, it checks the
da_BootPoint offset vector to make sure that a valid bootstrap routine
exists.  If so, expansion copies da_Size bytes into RAM memory, starting
at beginning of the DiagArea structure.

The copy will include the DiagArea structure itself, and typically will
also include the da_DiagPoint ROM/diagnostic routine, a [Resident](libraries/18-adding-a-library-resident-romtag-structure.md) structure
(romtag), a device driver (or at least the device initialization tables or
structures which need patching), and the da_BootPoint routine.  In
addition, the [BootNode](libraries/32-rom-based-and-autoboot-drivers-events-at-romtag-init-time.md) and parameter packet for [MakeDosNode()](libraries/32-expansion-board-drivers-expansion-drivers-and-dos.md) may be
included in the copy area for Diag-time patching.  Strings such as DOS and
Exec device names, library names, and the romtag ID string may also be
included in the copy area so that both position-independent ROM code and
position-independent routines in the copy area may reference them PC
relative.

The copy will be made either nibblewise, or wordwise, according to the
BUSWIDTH subfield of da_Config. Note that the da_BootPoint offset must be
non-NULL, or else no copy will occur. (Note - under 1.3, DAC_BYTEWIDE is
not supported. Byte wide ROMs must use DAC_NIBBLEWIDE and drivers must
supply additional code to re-copy their DiagArea)

The following illustrates an example Diag copy area, and specifies the
various fields which should be coded as relative offsets for later
patching by your DiagPoint routine.



                      Example DiagArea Copy in RAM
DiagStart:          ; a struct DiagArea

```c
            CCFF    ; da_Config, da_Flags
            SIZE    ; da_Size         - coded as EndCopy-DiagStart
            DIAG    ; da_DiagPoint    - coded as DiagEntry-DiagStart
            BOOT    ; da_BootPoint    - coded as BootEntry-DiagStart
            NAME    ; da_Name         - coded as DevName-DiagStart
            0000    ; da_Reserved01   - Above fields above are supposed
            0000    ; da_Reserved02     to be relative. No patching needed
```
Romtag:     rrrr    ; a struct Resident ("Romtag")

            ...       RT_MATCHTAG, RT_ENDSKIP, RT_NAME and  RT_IDSTRING
            ...       addresses are coded relatively as label-DiagStart.
            ...       The RT_INIT vector is coded as a relative offset
            ...       from the start of the ROM.  DiagEntry patches these.
DevName:    ssss..0 ; The name string for the exec device
IdString:   iiii..0 ; The ID string for the Romtag

BootEntry:  BBBB    ; Boot-time code

            ...
DiagEntry:  DDDD    ; Diag-time code (position independent)
            ...       When called, performs patching of the relative-
                      coded addresses which need to be absolute.
OtherData:
```c
            dddd    ; Device node or structs/tables (patch names, vectors)
            bbbb    ; BootNode (patch ln_Name and bn_DeviceNode)
            pppp    ; MakeDosNode packet (patch dos and exec names)

            ssss    ; other name, ID, and library name strings
            ...
```
EndCopy:


Now the ROM "image" exists in RAM memory.  Expansion stores the ULONG
address of that "image" in the UBYTES er_Reserved0c, 0d, 0e and 0f.  The
address is stored with the most significant byte in er_Reserved0c, the
next to most significant byte in er_Reserved0d, the next to least
significant byte in er_Reserved0e, and the least significant byte in
er_Reserved0f - i.e., it is stored as a longword at the address
er_Reserved0c.

Expansion finally checks the da_DiagPoint offset vector, and if valid
executes the ROM/diagnostic routine contained as part of the ROM "image".
This diagnostic routine is responsible for patching the ROM image so that
required absolute addresses are relocated to reflect the actual location
of code and strings, as well as performing any diagnostic functions
essential to the operation of its associated AUTOCONFIG board. The
structures which require patching are located within the copy area so that
they can be patched at this time. Patching is required because many of the
structures involved require absolute pointers to such things as name
strings and code, but the absolute locations of the board and the RAM copy
area are not known when code the structures.

The patching may be accomplished by coding pointers which require absolute
addresses instead as relative offsets from either the start of the
DiagArea structure, or the start of the board's ROM (depending on whether
the final absolute pointer will point to a RAM or ROM location). The Diag
routine is passed both the actual base address of the board, and the
address of the Diag copy area in RAM. The routine can then patch the
structures in the Diag copy area by adding the appropriate address to
resolve each pointer.

Example DiagArea and Diag patching routine:


```c
     [Diag.asm](libraries/lib-examples-diag-asm.md) 
```
Your da_DiagPoint ROM/diagnostic routine should return a non-zero value to
indicate success;  otherwise the ROM "image" will be unloaded from memory,
and its address will be replaced with NULL bytes in locations
er_Reserved0c, 0d, 0e and 0f.

Now that the ROM "image" has been copied into RAM, validated, and linked
to board's [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md) structure, the expansion module is free to configure
all other boards on the utility.library's private list of boards.

It may help to see just how a card's ROM AUTOCONFIG information
corresponds to the ExpansionRom structure.  This chart shows the contents
of on-card memory for a fictional expansion card.  Note that the
ExpansionRom.Flags field ($3F in addresses $08/$0A below) is shown
interpreted in its inverted form of $3F.  Once the value is uninverted to
become $C0, you should use the #defines in <libraries/[configregs.h](autodocs-2.0/includes-libraries-configregs-h.md)> to
interpret it.


Table 32-1: Sample Zorro II AUTOCONFIG ROM Information Viewed as a Hex Dump




```c
            FLAG AND FIELD DEFINITIONS                THIS BOARD
    -----------------------------------------------------------------
              1xxx chained                          11 = Normal type
              x111 size                             Don't addmem
              000=8meg,001=64K,010=128K,etc.        ROM Vector Valid
     11xx type     /        1xxx nopref             Not chained
     xx1x addmem  /         x1xx canshut            Size 256K
     xxx1 ROM    /          xx11 reserved           Product#=~$FE=1
        \       / ~Prod#      /                     Flags=~$3F=$C0
         \     /   /  \      /  res. reserved       Prefer exp space
    0000: D0003000 F000E000 3000F000 F000F000       Can't be shut up
    -----------------------------------------------------------------
          ~Manufacturer#    ~HiWord Serial#    Manu#=~$F824=$7DB=2011
           /   /  \   \      /   /  \   \      HiSer=~$FFDA=$0025=37
    0010: F0008000 20004000 F000F000 D000A000
    -----------------------------------------------------------------
          ~LoWord Serial#    ~Rom Vector       LoSer=~$FFFE=$0001=1
           /   /  \ \      /   /  \   \      Rom Vector=~$FF7F=$80
    0020: F000F000 F000E000 F000F000 7000F000        from board base
    -----------------------------------------------------------------
```
The AUTOCONFIG information from the above card would appear as follows in
an ExpansionRom structure:




```c
        Nibble Pairs        ExpansionRom Field    Value
        ------------        ------------------    -----
        00/02               er_Type               $D3
        04/06               er_Product            $01 = 1
        08/0A               er_Flags              $C0
        10/12 and 14/16     er_Manufacturer       $07DB = 2011
        18/1A thru 24/26    er_SerialNumber       $00250001
        28/2A and 2C/2E     er_InitDiagVec        $0080
```
If a card contains a ROM driver (Rom Vector valid), and the vector is at
offset $80 (as in this example) the DiagArea structure will appear at
offset $0080 from the base address of the board.  This example card's
[Resident](libraries/18-adding-a-library-resident-romtag-structure.md) structure (romtag) directly follows its DiagArea structure.



       WORDWIDE+CONFIGTIME              ROMTAG
        \ flags    DiagPt   Devname     starts
         \ \ DAsize  / BootPt /          here       DiagPt, BootPt,
          \ \  /\   /\  /\   /\ res. res. /\        DevName relative
    0080: 90000088 004A0076 00280000 00004AFC       to Diag struct
    -----------------------------------------------------------------
                       COLDSTART  NT_DEVICE         backptr,endskip,
                           \ ver  /priority         and DevName coded
          backptr  endskip  \ \  / /  DevName       relative, patched
    0090: 0000000E 00000088 01250314 00000028       at Diag time
    -----------------------------------------------------------------
                                                    ID and InitEntry
          IDstring InitEntry                        coded relative,
    00A0: 00000033 00000116                         patched at Diag
    -----------------------------------------------------------------
