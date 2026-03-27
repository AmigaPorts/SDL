/* Source: ADCD 2.1
 * Section: includes-intuition-intuition-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-intuition-i.md
 */

    APTR wd_NextWindow		; for the linked list of a Screen

    WORD wd_LeftEdge		; screen dimensions
    WORD wd_TopEdge		; screen dimensions
    WORD wd_Width		; screen dimensions
    WORD wd_Height		; screen dimensions

    WORD wd_MouseY		; relative top top-left corner
    WORD wd_MouseX		; relative top top-left corner

    WORD wd_MinWidth		; minimum sizes
    WORD wd_MinHeight		; minimum sizes
    WORD wd_MaxWidth		; maximum sizes
    WORD wd_MaxHeight		; maximum sizes

    LONG wd_Flags		; see below for definitions

    APTR wd_MenuStrip		; first in a list of menu headers

    APTR wd_Title		; title text for the Window

    APTR wd_FirstRequest	; first in linked list of active Requesters
    APTR wd_DMRequest		; the double-menu Requester
    WORD wd_ReqCount		; number of Requesters blocking this Window
    APTR wd_WScreen		; this Window's Screen
    APTR wd_RPort		; this Window's very own RastPort

    ; the border variables describe the window border.	If you specify
    ; WFLG_GIMMEZEROZERO when you open the window, then the upper-left of the
    ; ClipRect for this window will be upper-left of the BitMap (with correct
    ; offsets when in SuperBitMap mode; you MUST select WFLG_GIMMEZEROZERO
    ; when using SuperBitMap).	If you don't specify ZeroZero, then you save
    ; memory (no allocation of RastPort, Layer, ClipRect and associated
    ; Bitmaps), but you also must offset all your writes by BorderTop,
    ; BorderLeft and do your own mini-clipping to prevent writing over the
    ; system gadgets
    BYTE wd_BorderLeft
    BYTE wd_BorderTop
    BYTE wd_BorderRight
    BYTE wd_BorderBottom
    APTR wd_BorderRPort

    ; You supply a linked-list of gadget that you want for your Window.
    ; This list DOES NOT include system Gadgets.  You get the standard
    ; window system Gadgets by setting flag-bits in the variable Flags (see
    ; the bit definitions below)
    APTR wd_FirstGadget

    ; these are for opening/closing the windows
    APTR wd_Parent
    APTR wd_Descendant

    ; sprite data information for your own Pointer
    ; set these AFTER you Open the Window by calling SetPointer()
    APTR wd_Pointer
    BYTE wd_PtrHeight
    BYTE wd_PtrWidth
    BYTE wd_XOffset
    BYTE wd_YOffset

    ; the IDCMP Flags and User's and Intuition's Message Ports
    ULONG wd_IDCMPFlags
    APTR wd_UserPort
    APTR wd_WindowPort
    APTR wd_MessageKey

    BYTE wd_DetailPen
    BYTE wd_BlockPen

    ; the CheckMark is a pointer to the imagery that will be used when
    ; rendering MenuItems of this Window that want to be checkmarked
    ; if this is equal to NULL, you'll get the default imagery
    APTR wd_CheckMark

    ; if non-null, Screen title when Window is active
    APTR wd_ScreenTitle

    ; These variables have the mouse coordinates relative to the
    ; inner-Window of WFLG_GIMMEZEROZERO Windows.  This is compared with the
    ; MouseX and MouseY variables, which contain the mouse coordinates
    ; relative to the upper-left corner of the Window, WFLG_GIMMEZEROZERO
    ; notwithstanding
    WORD wd_GZZMouseX
    WORD wd_GZZMouseY
    ; these variables contain the width and height of the inner-Window of
    ; WFLG_GIMMEZEROZERO Windows
    WORD wd_GZZWidth
    WORD wd_GZZHeight

    APTR wd_ExtData

    ; general-purpose pointer to User data extension
    APTR wd_UserData
    APTR wd_WLayer	; stash of Window.RPort->Layer

    ; NEW 1.2: need to keep track of the font that OpenWindow opened,
    ; in case user SetFont's into RastPort
    APTR  wd_IFont

    ; (V36) another flag word (the Flags field is used up).
    ; At present, all flag values are system private.
    ; Until further notice, you may not change nor use this field.
    ULONG wd_MoreFlags

    ; ----- subsequent fields are INTUITION PRIVATE ---

    LABEL wd_Size
    LABEL wd_SIZEOF	; you should never use this: only Intuition allocates
