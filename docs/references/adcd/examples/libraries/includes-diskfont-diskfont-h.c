/* Source: ADCD 2.1
 * Section: includes-diskfont-diskfont-h
 * Library: libraries
 * ADCD reference: libraries/includes-diskfont-diskfont-h.md
 */

    char    tfc_FileName[MAXFONTPATH-2];
    UWORD   tfc_TagCount;	/* including the TAG_DONE tag */
    /*
     *	if tfc_TagCount is non-zero, tfc_FileName is overlayed with
     *	Text Tags starting at:	(struct TagItem *)
     *	    &tfc_FileName[MAXFONTPATH-(tfc_TagCount*sizeof(struct TagItem))]
     */
    UWORD   tfc_YSize;
    UBYTE   tfc_Style;
    UBYTE   tfc_Flags;
