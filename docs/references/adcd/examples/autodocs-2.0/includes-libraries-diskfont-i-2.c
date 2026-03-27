/* Source: ADCD 2.1
 * Section: includes-libraries-diskfont-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-libraries-diskfont-i.md
 */

    ; the following 8 bytes are not actually considered a part of the
    ; DiskFontHeader, but immediately preceed it.  The NextSegment is supplied
    ; by the linker/loader, and the ReturnCode is the code at the beginning
    ; of the font in case someone runs it...
    ; ULONG dfh_NextSegment	; actually a BPTR
    ; ULONG dfh_ReturnCode	; MOVEQ #0,D0 : RTS
    ; here then is the official start of the DiskFontHeader...
    STRUCT  dfh_DF,LN_SIZE	; node to link disk fonts
    UWORD   dfh_FileID		; DFH_ID
    UWORD   dfh_Revision	; the font revision in this version
    LONG    dfh_Segment		; the segment address when loaded
    STRUCT  dfh_Name,MAXFONTNAME ; the font name (null terminated)
    STRUCT  dfh_TF,tf_SIZEOF	; loaded TextFont structure
    LABEL   dfh_SIZEOF
