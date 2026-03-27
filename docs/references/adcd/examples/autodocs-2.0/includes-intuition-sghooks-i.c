/* Source: ADCD 2.1
 * Section: includes-intuition-sghooks-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-sghooks-i.md
 */

    ; display specifications
    APTR	sex_Font	; must be an open Font (not TextAttr)
    STRUCT	sex_Pens,2	; color of text/background
    STRUCT	sex_ActivePens,2 ; colors when gadget is active

    ; edit specifications
    ULONG	sex_InitialModes ; initial mode flags, below
    APTR	sex_EditHook	; if non-NULL, must supply WorkBuffer
    APTR	sex_WorkBuffer	; must be as large as StringInfo.Buffer

    STRUCT	sex_Reserved,16	; set to 0
