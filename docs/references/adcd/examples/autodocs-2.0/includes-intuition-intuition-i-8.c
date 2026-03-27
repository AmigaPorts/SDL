/* Source: ADCD 2.1
 * Section: includes-intuition-intuition-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-intuition-i.md
 */

    WORD nw_LeftEdge		; initial Window dimensions
    WORD nw_TopEdge		; initial Window dimensions
    WORD nw_Width		; initial Window dimensions
    WORD nw_Height		; initial Window dimensions

    BYTE nw_DetailPen		; for rendering the detail bits of the Window
    BYTE nw_BlockPen		; for rendering the block-fill bits

    LONG nw_IDCMPFlags		; initial IDCMP state

    LONG nw_Flags		; see the Flag definition under Window

    ; You supply a linked-list of Gadgets for your Window.
    ; This list DOES NOT include system Gadgets.  You get the standard
    ; system Window Gadgets by setting flag-bits in the variable Flags (see
    ; the bit definitions under the Window structure definition)
    APTR	nw_FirstGadget

    ; the CheckMark is a pointer to the imagery that will be used when
    ; rendering MenuItems of this Window that want to be checkmarked
    ; if this is equal to NULL, you'll get the default imagery
    APTR nw_CheckMark

    APTR nw_Title		; title text for the Window

    ; the Screen pointer is used only if you've defined a CUSTOMSCREEN and
    ; want this Window to open in it.  If so, you pass the address of the
    ; Custom Screen structure in this variable.  Otherwise, this variable
    ; is ignored and doesn't have to be initialized.
    APTR nw_Screen

    ; WFLG_SUPER_BITMAP Window?  If so, put the address of your BitMap
    ; structure in this variable.  If not, this variable is ignored and
    ; doesn't have to be initialized
    APTR nw_BitMap

    ; the values describe the minimum and maximum sizes of your Windows.
    ; these matter only if you've chosen the WFLG_SIZEGADGET Gadget option,
    ; which means that you want to let the User to change the size of
    ; this Window.  You describe the minimum and maximum sizes that the
    ; Window can grow by setting these variables.  You can initialize
    ; any one these to zero, which will mean that you want to duplicate
    ; the setting for that dimension (if MinWidth == 0, MinWidth will be
    ; set to the opening Width of the Window).
    ; You can change these settings later using SetWindowLimits().
    ; If you haven't asked for a GTYP_SIZING Gadget, you don't have to
    ; initialize any of these variables.
    WORD nw_MinWidth
    WORD nw_MinHeight
    WORD nw_MaxWidth
    WORD nw_MaxHeight

    ; the type variable describes the Screen in which you want this Window to
    ; open.  The type value can either be CUSTOMSCREEN or one of the
    ; system standard Screen Types such as WBENCHSCREEN.  See the
    ; type definitions under the Screen structure
    ; A new possible value for this field is PUBLICSCREEN, which
    ; defines the window as a 'visitor' window.  See below for
    ; additional information provided.
    WORD nw_Type

    LABEL nw_SIZE
    LABEL nw_SIZEOF
