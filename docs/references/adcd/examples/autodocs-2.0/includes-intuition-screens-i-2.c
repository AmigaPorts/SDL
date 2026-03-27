/* Source: ADCD 2.1
 * Section: includes-intuition-screens-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-screens-i.md
 */

    APTR sc_NextScreen		; linked list of screens
    APTR sc_FirstWindow		; linked list Screen's Windows

    WORD sc_LeftEdge		; parameters of the screen
    WORD sc_TopEdge		; parameters of the screen

    WORD sc_Width		; null-terminated Title text
    WORD sc_Height		; for Windows without ScreenTitle

    WORD sc_MouseY		; position relative to upper-left
    WORD sc_MouseX		; position relative to upper-left

    WORD sc_Flags		; see definitions below

    APTR sc_Title
    APTR sc_DefaultTitle

    ; Bar sizes for this Screen and all Window's in this Screen
    BYTE sc_BarHeight
    BYTE sc_BarVBorder
    BYTE sc_BarHBorder
    BYTE sc_MenuVBorder
    BYTE sc_MenuHBorder
    BYTE sc_WBorTop
    BYTE sc_WBorLeft
    BYTE sc_WBorRight
    BYTE sc_WBorBottom

    BYTE sc_KludgeFill00	; This is strictly for word-alignment

    ; the display data structures for this Screen
    APTR sc_Font			; this screen's default font
    STRUCT sc_ViewPort,vp_SIZEOF	; describing the Screen's display
    STRUCT sc_RastPort,rp_SIZEOF	; describing Screen rendering
    STRUCT sc_BitMap,bm_SIZEOF		; auxiliary graphexcess baggage
    STRUCT sc_LayerInfo,li_SIZEOF	; each screen gets a LayerInfo

    APTR sc_FirstGadget

    BYTE sc_DetailPen		; for bar/border/gadget rendering
    BYTE sc_BlockPen		; for bar/border/gadget rendering

    ; the following variable(s) are maintained by Intuition to support the
    ; DisplayBeep() color flashing technique
    WORD sc_SaveColor0

    ; This layer is for the Screen and Menu bars
    APTR sc_BarLayer		; was "BarLayer"

    APTR sc_ExtData

    APTR sc_UserData		; general-purpose pointer to User data

    LABEL sc_SIZEOF	; actually, you have no business talking about
