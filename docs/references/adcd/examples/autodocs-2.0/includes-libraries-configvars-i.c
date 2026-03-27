/* Source: ADCD 2.1
 * Section: includes-libraries-configvars-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-libraries-configvars-i.md
 */

    STRUCT	cd_Node,LN_SIZE
    UBYTE	cd_Flags	; (read/write)
    UBYTE	cd_Pad		; reserved
    STRUCT	cd_Rom,ExpansionRom_SIZEOF ; copy of board's expansion ROM
    APTR	cd_BoardAddr	; where in memory the board was placed
    ULONG	cd_BoardSize	; size of board in bytes
    UWORD	cd_SlotAddr	; which slot number (PRIVATE)
    UWORD	cd_SlotSize	; number of slots (PRIVATE)
    APTR	cd_Driver	; pointer to node of driver
    APTR 	cd_NextCD	; linked list of drivers to config
    STRUCT	cd_Unused,4*4	; for whatever the driver wants!
    LABEL	ConfigDev_SIZEOF
