/* Source: ADCD 2.1
 * Section: includes-intuition-intuition-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-intuition-h.md
 */

    struct Gadget *NextGadget;	/* next gadget in the list */

    WORD LeftEdge, TopEdge;	/* "hit box" of gadget */
    WORD Width, Height;		/* "hit box" of gadget */

    UWORD Flags;		/* see below for list of defines */

    UWORD Activation;		/* see below for list of defines */

    UWORD GadgetType;		/* see below for defines */

    /* appliprog can specify that the Gadget be rendered as either as Border
     * or an Image.  This variable points to which (or equals NULL if there's
     * nothing to be rendered about this Gadget)
     */
    APTR GadgetRender;

    /* appliprog can specify "highlighted" imagery rather than algorithmic
     * this can point to either Border or Image data
     */
    APTR SelectRender;

    struct IntuiText *GadgetText;   /* text for this gadget */

    /* MutualExclude, never implemented, is now declared obsolete.
     * There are published examples of implementing a more general
     * and practical exclusion in your applications.
     *
     * Starting with V36, this field is used to point to a hook
     * for a custom gadget.
     *
     * Programs using this field for their own processing will
     * continue to work, as long as they don't try the
     * trick with custom gadgets.
     */
    LONG MutualExclude;  /* obsolete */

    /* pointer to a structure of special data required by Proportional,
     * String and Integer Gadgets
     */
    APTR SpecialInfo;

    UWORD GadgetID;	/* user-definable ID field */
    APTR UserData;	/* ptr to general purpose User data (ignored by In) */
