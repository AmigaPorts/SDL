/* Source: ADCD 2.1
 * Section: include-prefs-icontrol-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-prefs-icontrol-h.md
 */

    LONG  ic_Reserved[4];	/* System reserved		*/
    UWORD ic_TimeOut;		/* Verify timeout		*/
    WORD  ic_MetaDrag;		/* Meta drag mouse event	*/
    ULONG ic_Flags;		/* IControl flags (see below)	*/
    UBYTE ic_WBtoFront;		/* CKey: WB to front		*/
    UBYTE ic_FrontToBack;	/* CKey: front screen to back	*/
    UBYTE ic_ReqTrue;		/* CKey: Requester TRUE		*/
    UBYTE ic_ReqFalse;		/* CKey: Requester FALSE	*/
