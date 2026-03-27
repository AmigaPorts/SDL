/* Source: ADCD 2.1
 * Section: includes-graphics-text-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-graphics-text-i.md
 */

    BITDEF  FS,UNDERLINED,0	; underlined (under baseline)
    BITDEF  FS,BOLD,1		; bold face text (ORed w/ shifted right 1)
    BITDEF  FS,ITALIC,2		; italic (slanted 1:2 right)
    BITDEF  FS,EXTENDED,3	; extended face (must be designed)

    BITDEF  FS,COLORFONT,6	; this uses ColorTextFont structure
    BITDEF  FS,TAGGED,7		; the TextAttr is really an TTextAttr,
