/* Source: ADCD 2.1
 * Section: include-intuition-intuition-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-intuition-intuition-h.md
 */

    /* you initialize these variables, and then Intuition maintains them */
    UBYTE *Buffer;	/* the buffer containing the start and final string */
    UBYTE *UndoBuffer;	/* optional buffer for undoing current entry */
    WORD BufferPos;	/* character position in Buffer */
    WORD MaxChars;	/* max number of chars in Buffer (including NULL) */
    WORD DispPos;	/* Buffer position of first displayed character */

    /* Intuition initializes and maintains these variables for you */
    WORD UndoPos;	/* character position in the undo buffer */
    WORD NumChars;	/* number of characters currently in Buffer */
    WORD DispCount;	/* number of whole characters visible in Container */
    WORD CLeft, CTop;	/* topleft offset of the container */

    /* This unused field is changed to allow extended specification
     * of string gadget parameters.  It is ignored unless the flag
     * GACT_STRINGEXTEND is set in the Gadget's Activation field
     * or the GFLG_STRINGEXTEND flag is set in the Gadget Flags field.
     * (See GFLG_STRINGEXTEND for an important note)
     */
    /* struct Layer *LayerPtr;	--- obsolete --- */
    struct StringExtend *Extension;

    /* you can initialize this variable before the gadget is submitted to
     * Intuition, and then examine it later to discover what integer
     * the user has entered (if the user never plays with the gadget,
     * the value will be unchanged from your initial setting)
     */
    LONG LongInt;

    /* If you want this Gadget to use your own Console keymapping, you
     * set the GACT_ALTKEYMAP bit in the Activation flags of the Gadget,
     * and then set this variable to point to your keymap.  If you don't
     * set the GACT_ALTKEYMAP, you'll get the standard ASCII keymapping.
     */
    struct KeyMap *AltKeyMap;
