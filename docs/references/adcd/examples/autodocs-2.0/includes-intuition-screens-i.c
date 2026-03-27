/* Source: ADCD 2.1
 * Section: includes-intuition-screens-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-screens-i.md
 */

    ; rendering pen number indexes into DrawInfo.dri_Pens[]
    ENUM
    EITEM	DETAILPEN	; compatible Intuition rendering pens
    EITEM	BLOCKPEN,
    EITEM	TEXTPEN		; text on background (pen = 0)
    EITEM	SHINEPEN	; bright edge on bas-relief
    EITEM	SHADOWPEN	; dark edge
    EITEM	FILLPEN		; active window fill
    EITEM	FILLTEXTPEN	; text over FILLPEN
    EITEM	BACKGROUNDPEN	; always color 0
    EITEM	HIGHLIGHTTEXTPEN  ; highlighted text, against BACKGROUNDPEN
    EITEM	NUMDRIPENS
