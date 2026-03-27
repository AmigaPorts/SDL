/* Source: ADCD 2.1
 * Section: includes-libraries-configregs-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-libraries-configregs-h.md
 */

    UBYTE	da_Config;	/* see below for definitions */
    UBYTE	da_Flags;	/* see below for definitions */
    UWORD	da_Size;	/* the size (in bytes) of the total diag area */
    UWORD	da_DiagPoint;	/* where to start for diagnostics, or zero */
    UWORD	da_BootPoint;	/* where to start for booting */
    UWORD	da_Name;	/* offset in diag area where a string */
