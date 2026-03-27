/* Source: ADCD 2.1
 * Section: includes-libraries-diskfont-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-libraries-diskfont-i.md
 */

    STRUCT  tfc_FileName,MAXFONTPATH-2
    UWORD   tfc_TagCount	; including the TAG_DONE tag
    ;
    ;	if tfc_TagCount is non-zero, tfc_FileName is overlayed with
    ;	Text Tags starting at:	(struct TagItem *)
    ;	    &tfc_FileName[MAXFONTPATH-(tfc_TagCount*sizeof(struct TagItem))]
    ;
    UWORD   tfc_YSize
    UBYTE   tfc_Style
    UBYTE   tfc_Flags
    LABEL   tfc_SIZEOF
