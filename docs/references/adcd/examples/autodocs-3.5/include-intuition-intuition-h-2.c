/* Source: ADCD 2.1
 * Section: include-intuition-intuition-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-intuition-intuition-h.md
 */

    struct Requester *OlderRequest;
    WORD LeftEdge, TopEdge;		/* dimensions of the entire box */
    WORD Width, Height;			/* dimensions of the entire box */
    WORD RelLeft, RelTop;		/* for Pointer relativity offsets */

    struct Gadget *ReqGadget;		/* pointer to a list of Gadgets */
    struct Border *ReqBorder;		/* the box's border */
    struct IntuiText *ReqText;		/* the box's text */
    UWORD Flags;			/* see definitions below */

    /* pen number for back-plane fill before draws */
    UBYTE BackFill;
    /* Layer in place of clip rect	*/
    struct Layer *ReqLayer;

    UBYTE ReqPad1[32];

    /* If the BitMap plane pointers are non-zero, this tells the system
     * that the image comes pre-drawn (if the appliprog wants to define
     * its own box, in any shape or size it wants!);  this is OK by
     * Intuition as long as there's a good correspondence between
     * the image and the specified Gadgets
     */
    struct BitMap *ImageBMap;	/* points to the BitMap of PREDRAWN imagery */
    struct Window *RWindow;	/* added.  points back to Window */

    struct Image  *ReqImage;	/* new for V36: drawn if USEREQIMAGE set */

    UBYTE ReqPad2[32];
