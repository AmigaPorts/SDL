/* Source: ADCD 2.1
 * Section: includes-diskfont-diskfont-h
 * Library: libraries
 * ADCD reference: libraries/includes-diskfont-diskfont-h.md
 */

    /* the following 8 bytes are not actually considered a part of the	*/
    /* DiskFontHeader, but immediately preceed it. The NextSegment is	*/
    /* supplied by the linker/loader, and the ReturnCode is the code	*/
    /* at the beginning of the font in case someone runs it...		*/
    /*	 ULONG dfh_NextSegment;			\* actually a BPTR	*/
    /*	 ULONG dfh_ReturnCode;			\* MOVEQ #0,D0 : RTS	*/
    /* here then is the official start of the DiskFontHeader...		*/
    struct Node dfh_DF;		/* node to link disk fonts */
    UWORD   dfh_FileID;		/* DFH_ID */
    UWORD   dfh_Revision;	/* the font revision */
    LONG    dfh_Segment;	/* the segment address when loaded */
    char    dfh_Name[MAXFONTNAME]; /* the font name (null terminated) */
    struct TextFont dfh_TF;	/* loaded TextFont structure */
