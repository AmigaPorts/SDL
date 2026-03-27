/* Source: ADCD 2.1
 * Section: include-intuition-screens-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-intuition-screens-h.md
 */

    struct Screen *NextScreen;		/* linked list of screens */
    struct Window *FirstWindow;		/* linked list Screen's Windows */

    WORD LeftEdge, TopEdge;		/* parameters of the screen */
    WORD Width, Height;			/* parameters of the screen */

    WORD MouseY, MouseX;		/* position relative to upper-left */

    UWORD Flags;			/* see definitions below */

    UBYTE *Title;			/* null-terminated Title text */
    UBYTE *DefaultTitle;		/* for Windows without ScreenTitle */

    /* Bar sizes for this Screen and all Window's in this Screen */
    /* Note that BarHeight is one less than the actual menu bar
     * height.	We're going to keep this in V36 for compatibility,
     * although V36 artwork might use that extra pixel
     *
     * Also, the title bar height of a window is calculated from the
     * screen's WBorTop field, plus the font height, plus one.
     */
    BYTE BarHeight, BarVBorder, BarHBorder, MenuVBorder, MenuHBorder;
    BYTE WBorTop, WBorLeft, WBorRight, WBorBottom;

    struct TextAttr *Font;		/* this screen's default font	   */

    /* the display data structures for this Screen */
    struct ViewPort ViewPort;		/* describing the Screen's display */
    struct RastPort RastPort;		/* describing Screen rendering	   */
    struct BitMap BitMap;		/* SEE WARNING ABOVE!		   */
    struct Layer_Info LayerInfo;	/* each screen gets a LayerInfo    */

    /* Only system gadgets may be attached to a screen.
     *	You get the standard system Screen Gadgets automatically
     */
    struct Gadget *FirstGadget;

    UBYTE DetailPen, BlockPen;		/* for bar/border/gadget rendering */

    /* the following variable(s) are maintained by Intuition to support the
     * DisplayBeep() color flashing technique
     */
    UWORD SaveColor0;

    /* This layer is for the Screen and Menu bars */
    struct Layer *BarLayer;

    UBYTE *ExtData;

    UBYTE *UserData;	/* general-purpose pointer to User data extension */

    /**** Data below this point are SYSTEM PRIVATE ****/
