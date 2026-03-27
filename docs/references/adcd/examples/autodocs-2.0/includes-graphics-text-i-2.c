/* Source: ADCD 2.1
 * Section: includes-graphics-text-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-graphics-text-i.md
 */

    BITDEF  FP,ROMFONT,0	; font is in rom
    BITDEF  FP,DISKFONT,1	; font is from diskfont.library
    BITDEF  FP,REVPATH,2	; designed path is reversed (e.g. left)
    BITDEF  FP,TALLDOT,3	; designed for hires non-interlaced
    BITDEF  FP,WIDEDOT,4	; designed for lores interlaced
    BITDEF  FP,PROPORTIONAL,5	; character sizes vary from tf_XSize
    BITDEF  FP,DESIGNED,6	; size is "designed", not constructed
