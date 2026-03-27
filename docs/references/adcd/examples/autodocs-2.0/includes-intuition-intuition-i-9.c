/* Source: ADCD 2.1
 * Section: includes-intuition-intuition-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-intuition-i.md
 */

    ; extensions for V36
    ; if the NewWindow Flag WFLG_NW_EXTENDED is set, then
    ; this field is assumed to point to an array (or chain of arrays)
    ; of TagItem structures.  See also ExtNewScreen for another
    ; use of TagItems to pass optional data.
    ;
    ; see below for tag values and the corresponding data

    APTR	enw_Extension	; pointer to TagItem array
    LABEL enw_SIZEOF
