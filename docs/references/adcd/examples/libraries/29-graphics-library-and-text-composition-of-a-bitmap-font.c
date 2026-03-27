/* Source: ADCD 2.1
 * Section: 29-graphics-library-and-text-composition-of-a-bitmap-font
 * Library: libraries
 * ADCD reference: libraries/29-graphics-library-and-text-composition-of-a-bitmap-font.md
 */

    #define  MAXFONTNAME    32      /* font name including ".font" */

    struct DiskFontHeader {
        /* the following 8 bytes are not actually considered a part of */
        /* the DiskFontHeader, but immediately precede it. The         */
        /* NextSegment is supplied by the linker/loader, and the       */
        /* ReturnCode is the code at the beginning of the font in case */
        /* someone runs it...                                          */
        /*   ULONG dfh_NextSegment;               actually a BPTR      */
        /*   ULONG dfh_ReturnCode;                MOVEQ #0,D0 : RTS    */
        /* here then is the official start of the DiskFontHeader...    */
        struct Node dfh_DF;            /* node to link disk fonts */
        UWORD dfh_FileID;            /* DFH_ID */
        UWORD dfh_Revision;          /* the font revision */
        LONG  dfh_Segment;           /* the segment address when loaded */
        char  dfh_Name[MAXFONTNAME]; /* the font name (null terminated) */
        struct TextFont dfh_TF;        /* loaded TextFont structure */
    };

    /* unfortunately, this needs to be explicitly typed */
    /* used only if dfh_TF.tf_Style FSB_TAGGED bit is set */
    #define dfh_TagList     dfh_Segment     /* destroyed during loading */
