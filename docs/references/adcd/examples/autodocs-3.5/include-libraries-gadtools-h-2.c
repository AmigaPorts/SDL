/* Source: ADCD 2.1
 * Section: include-libraries-gadtools-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-libraries-gadtools-h.md
 */

    UBYTE nm_Type;		/* See below */
    /* Compiler inserts a PAD byte here */
    STRPTR nm_Label;		/* Menu's label */
    STRPTR nm_CommKey;		/* MenuItem Command Key Equiv */
    UWORD nm_Flags;		/* Menu or MenuItem flags (see note) */
    LONG nm_MutualExclude;	/* MenuItem MutualExclude word */
    APTR nm_UserData;		/* For your own use, see note */
