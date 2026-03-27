/* Source: ADCD 2.1
 * Section: includes-intuition-screens-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-screens-h.md
 */

    WORD LeftEdge, TopEdge, Width, Height, Depth;  /* screen dimensions */

    UBYTE DetailPen, BlockPen;	/* for bar/border/gadget rendering	*/

    UWORD ViewModes;		/* the Modes for the ViewPort (and View) */

    UWORD Type;			/* the Screen type (see defines above)	*/

    struct TextAttr *Font;	/* this Screen's default text attributes */

    UBYTE *DefaultTitle;	/* the default title for this Screen	*/

    struct Gadget *Gadgets;	/* UNUSED:  Leave this NULL		*/

    /* if you are opening a CUSTOMSCREEN and already have a BitMap
     * that you want used for your Screen, you set the flags CUSTOMBITMAP in
     * the Type field and you set this variable to point to your BitMap
     * structure.  The structure will be copied into your Screen structure,
     * after which you may discard your own BitMap if you want
     */
    struct BitMap *CustomBitMap;
