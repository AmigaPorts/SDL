/* Source: ADCD 2.1
 * Section: includes-intuition-intuition-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-intuition-i.md
 */

    ; you initialize these variables, and then Intuition maintains them
    APTR  si_Buffer	; the buffer containing the start and final string
    APTR  si_UndoBuffer	; optional buffer for undoing current entry
    WORD si_BufferPos	; character position in Buffer
    WORD si_MaxChars	; max number of chars in Buffer (including NULL)
    WORD si_DispPos	; Buffer position of first displayed character

    ; Intuition initializes and maintains these variables for you
    WORD si_UndoPos	; character position in the undo buffer
    WORD si_NumChars	; number of characters currently in Buffer
    WORD si_DispCount	; number of whole characters visible in Container
    WORD si_CLeft	; topleft offset of the container
    WORD si_CTop	; topleft offset of the container

    ; unused field is changed to allow extended specification
    ; of string gadget parameters.  It is ignored unless the flag
    ; GACT_STRINGEXTEND is set in the Gadget's Activation field
    ; or the GFLG_STRINGEXTEND flag is set in the Gadget Flags field.
    ; (See GFLG_STRINGEXTEND for an important note)
    ;APTR  si_LayerPtr	; --- obsolete ---
    APTR  si_Extension

    ; you can initialize this variable before the gadget is submitted to
    ; Intuition, and then examine it later to discover what integer
    ; the user has entered (if the user never plays with the gadget,
    ; the value will be unchanged from your initial setting)
    LONG  si_LongInt	; the LONG return value of a GACT_LONGINT String Gad.

    ; If you want this Gadget to use your own Console keymapping, you
    ; set the GACT_ALTKEYMAP bit in the Activation flags of the Gadget, and
    ; then set this variable to point to your keymap.  If you don't set the
    ; GACT_ALTKEYMAP, you'll get the standard ASCII keymapping.
    APTR si_AltKeyMap

    LABEL si_SIZEOF
