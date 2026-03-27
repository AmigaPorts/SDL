/* Source: ADCD 2.1
 * Section: includes-intuition-sghooks-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-sghooks-h.md
 */

    /* display specifications	*/
    struct TextFont *Font;	/* must be an open Font (not TextAttr)	*/
    UBYTE	Pens[2];	/* color of text/backgroun		*/
    UBYTE	ActivePens[2];	/* colors when gadget is active		*/

    /* edit specifications	*/
    ULONG	InitialModes;	/* initial mode flags, below		*/
    struct Hook *EditHook;	/* if non-NULL, must supply WorkBuffer	*/
    UBYTE	*WorkBuffer;	/* must be as large as StringInfo.Buffer*/

    ULONG	Reserved[4];	/* set to 0				*/
