/* Source: ADCD 2.1
 * Section: includes-intuition-screens-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-screens-i.md
 */

    WORD ns_LeftEdge		; initial Screen dimensions
    WORD ns_TopEdge		; initial Screen dimensions
    WORD ns_Width		; initial Screen dimensions
    WORD ns_Height		; initial Screen dimensions
    WORD ns_Depth		; initial Screen dimensions

    BYTE ns_DetailPen		; default rendering pens (for Windows too)
    BYTE ns_BlockPen		; default rendering pens (for Windows too)

    WORD ns_ViewModes		; display "modes" for this Screen

    WORD ns_Type		; Intuition Screen Type specifier

    APTR ns_Font		; default font for Screen and Windows

    APTR ns_DefaultTitle	; Title when Window doesn't care

    APTR ns_Gadgets		; UNUSED:  Leave this NULL

    ; if you are opening a CUSTOMSCREEN and already have a BitMap
    ; that you want used for your Screen, you set the flags CUSTOMBITMAP in
    ; the Types variable and you set this variable to point to your BitMap
    ; structure.  The structure will be copied into your Screen structure,
    ; after which you may discard your own BitMap if you want
    APTR ns_CustomBitMap
