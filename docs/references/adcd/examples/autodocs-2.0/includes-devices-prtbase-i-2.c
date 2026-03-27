/* Source: ADCD 2.1
 * Section: includes-devices-prtbase-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-devices-prtbase-i.md
 */

    UBYTE   pd_Pad1		    ; padding
    STRUCT  pd_Stk,P_STKSIZE	    ; stack space
    LABEL   pd_SIZEOF               ; warning! this may be odd

    BITDEF  PPC,GFX,0		;graphics (bit position)
    BITDEF  PPC,COLOR,1		;color (bit position)
