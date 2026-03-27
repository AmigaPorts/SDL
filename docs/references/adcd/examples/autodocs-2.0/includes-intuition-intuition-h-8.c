/* Source: ADCD 2.1
 * Section: includes-intuition-intuition-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-intuition-h.md
 */

    struct Window *NextWindow;		/* for the linked list in a screen */

    WORD LeftEdge, TopEdge;		/* screen dimensions of window */
    WORD Width, Height;			/* screen dimensions of window */

    WORD MouseY, MouseX;		/* relative to upper-left of window */

    WORD MinWidth, MinHeight;		/* minimum sizes */
    UWORD MaxWidth, MaxHeight;		/* maximum sizes */

    ULONG Flags;			/* see below for defines */

    struct Menu *MenuStrip;		/* the strip of Menu headers */

    UBYTE *Title;			/* the title text for this window */

    struct Requester *FirstRequest;	/* all active Requesters */

    struct Requester *DMRequest;	/* double-click Requester */

    WORD ReqCount;			/* count of reqs blocking Window */

    struct Screen *WScreen;		/* this Window's Screen */
    struct RastPort *RPort;		/* this Window's very own RastPort */

    /* the border variables describe the window border.  If you specify
     * WFLG_GIMMEZEROZERO when you open the window, then the upper-left of
     * the ClipRect for this window will be upper-left of the BitMap (with
     * correct offsets when in SuperBitMap mode; you MUST select
     * WFLG_GIMMEZEROZERO when using SuperBitMap).  If you don't specify
     * ZeroZero, then you save memory (no allocation of RastPort, Layer,
     * ClipRect and associated Bitmaps), but you also must offset all your
     * writes by BorderTop, BorderLeft and do your own mini-clipping to
     * prevent writing over the system gadgets
     */
    BYTE BorderLeft, BorderTop, BorderRight, BorderBottom;
    struct RastPort *BorderRPort;


    /* You supply a linked-list of Gadgets for your Window.
     * This list DOES NOT include system gadgets.  You get the standard
     * window system gadgets by setting flag-bits in the variable Flags (see
     * the bit definitions below)
     */
    struct Gadget *FirstGadget;

    /* these are for opening/closing the windows */
    struct Window *Parent, *Descendant;

    /* sprite data information for your own Pointer
     * set these AFTER you Open the Window by calling SetPointer()
     */
    UWORD *Pointer;	/* sprite data */
    BYTE PtrHeight;	/* sprite height (not including sprite padding) */
    BYTE PtrWidth;	/* sprite width (must be less than or equal to 16) */
    BYTE XOffset, YOffset;	/* sprite offsets */

    /* the IDCMP Flags and User's and Intuition's Message Ports */
    ULONG IDCMPFlags;	/* User-selected flags */
    struct MsgPort *UserPort, *WindowPort;
    struct IntuiMessage *MessageKey;

    UBYTE DetailPen, BlockPen;	/* for bar/border/gadget rendering */

    /* the CheckMark is a pointer to the imagery that will be used when
     * rendering MenuItems of this Window that want to be checkmarked
     * if this is equal to NULL, you'll get the default imagery
     */
    struct Image *CheckMark;

    UBYTE *ScreenTitle;	/* if non-null, Screen title when Window is active */

    /* These variables have the mouse coordinates relative to the
     * inner-Window of WFLG_GIMMEZEROZERO Windows.  This is compared with the
     * MouseX and MouseY variables, which contain the mouse coordinates
     * relative to the upper-left corner of the Window, WFLG_GIMMEZEROZERO
     * notwithstanding
     */
    WORD GZZMouseX;
    WORD GZZMouseY;
    /* these variables contain the width and height of the inner-Window of
     * WFLG_GIMMEZEROZERO Windows
     */
    WORD GZZWidth;
    WORD GZZHeight;

    UBYTE *ExtData;

    BYTE *UserData;	/* general-purpose pointer to User data extension */

    /** 11/18/85: this pointer keeps a duplicate of what
     * Window.RPort->Layer is _supposed_ to be pointing at
     */
    struct Layer *WLayer;

    /* NEW 1.2: need to keep track of the font that
     * OpenWindow opened, in case user SetFont's into RastPort
     */
    struct TextFont *IFont;

    /* (V36) another flag word (the Flags field is used up).
     * At present, all flag values are system private.
     * Until further notice, you may not change nor use this field.
     */
    ULONG	MoreFlags;

    /**** Data beyond this point are Intuition Private.  DO NOT USE ****/
