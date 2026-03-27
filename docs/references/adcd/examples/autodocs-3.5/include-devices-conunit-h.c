/* Source: ADCD 2.1
 * Section: include-devices-conunit-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-devices-conunit-h.md
 */

    struct  MsgPort cu_MP;
    /* ---- read only variables */
    struct  Window *cu_Window;	/* intuition window bound to this unit */
    WORD    cu_XCP;		/* character position */
    WORD    cu_YCP;
    WORD    cu_XMax;		/* max character position */
    WORD    cu_YMax;
    WORD    cu_XRSize;		/* character raster size */
    WORD    cu_YRSize;
    WORD    cu_XROrigin;	/* raster origin */
    WORD    cu_YROrigin;
    WORD    cu_XRExtant;	/* raster maxima */
    WORD    cu_YRExtant;
    WORD    cu_XMinShrink;	/* smallest area intact from resize process */
    WORD    cu_YMinShrink;
    WORD    cu_XCCP;		/* cursor position */
    WORD    cu_YCCP;

    /* ---- read/write variables (writes must must be protected) */
    /* ---- storage for AskKeyMap and SetKeyMap */
    struct  KeyMap cu_KeyMapStruct;
    /* ---- tab stops */
    UWORD   cu_TabStops[MAXTABS]; /* 0 at start, 0xffff at end of list */

    /* ---- console rastport attributes */
    BYTE    cu_Mask;
    BYTE    cu_FgPen;
    BYTE    cu_BgPen;
    BYTE    cu_AOLPen;
    BYTE    cu_DrawMode;
    BYTE    cu_Obsolete1;	/* was cu_AreaPtSz -- not used in V36 */
    APTR    cu_Obsolete2;	/* was cu_AreaPtrn -- not used in V36 */
    UBYTE   cu_Minterms[8];	/* console minterms */
    struct  TextFont *cu_Font;
    UBYTE   cu_AlgoStyle;
    UBYTE   cu_TxFlags;
    UWORD   cu_TxHeight;
    UWORD   cu_TxWidth;
    UWORD   cu_TxBaseline;
    WORD    cu_TxSpacing;

    /* ---- console MODES and RAW EVENTS switches */
    UBYTE   cu_Modes[(PMB_AWM+7)/8];	/* one bit per mode */
    UBYTE   cu_RawEvents[(IECLASS_MAX+8)/8];
