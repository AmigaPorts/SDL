/* Source: ADCD 2.1
 * Section: includes-intuition-intuition-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-intuition-h.md
 */

    struct MenuItem *NextItem;	/* pointer to next in chained list */
    WORD LeftEdge, TopEdge;	/* position of the select box */
    WORD Width, Height;		/* dimensions of the select box */
    UWORD Flags;		/* see the defines below */

    LONG MutualExclude;		/* set bits mean this item excludes that */

    APTR ItemFill;		/* points to Image, IntuiText, or NULL */

    /* when this item is pointed to by the cursor and the items highlight
     *	mode HIGHIMAGE is selected, this alternate image will be displayed
     */
    APTR SelectFill;		/* points to Image, IntuiText, or NULL */

    BYTE Command;		/* only if appliprog sets the COMMSEQ flag */

    struct MenuItem *SubItem;	/* if non-zero, points to MenuItem for submenu */

    /* The NextSelect field represents the menu number of next selected
     *	item (when user has drag-selected several items)
     */
    UWORD NextSelect;
