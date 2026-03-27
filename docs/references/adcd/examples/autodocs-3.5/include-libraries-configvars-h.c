/* Source: ADCD 2.1
 * Section: include-libraries-configvars-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-libraries-configvars-h.md
 */

    struct Node		cd_Node;
    UBYTE		cd_Flags;	/* (read/write) */
    UBYTE		cd_Pad;		/* reserved */
    struct ExpansionRom	cd_Rom;		/* copy of board's expansion ROM */
    APTR		cd_BoardAddr; /* where in memory the board was placed */
    ULONG		cd_BoardSize;	/* size of board in bytes */
    UWORD		cd_SlotAddr;	/* which slot number (PRIVATE) */
    UWORD		cd_SlotSize;	/* number of slots (PRIVATE) */
    APTR		cd_Driver;	/* pointer to node of driver */
    struct ConfigDev *	cd_NextCD;	/* linked list of drivers to config */
    ULONG		cd_Unused[4];	/* for whatever the driver wants */
