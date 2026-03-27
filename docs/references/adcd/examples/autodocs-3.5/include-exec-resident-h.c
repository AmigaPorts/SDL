/* Source: ADCD 2.1
 * Section: include-exec-resident-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-exec-resident-h.md
 */

    UWORD rt_MatchWord;	/* word to match on (ILLEGAL)	*/
    struct Resident *rt_MatchTag; /* pointer to the above	*/
    APTR  rt_EndSkip;		/* address to continue scan	*/
    UBYTE rt_Flags;		/* various tag flags		*/
    UBYTE rt_Version;		/* release version number	*/
    UBYTE rt_Type;		/* type of module (NT_XXXXXX)	*/
    BYTE  rt_Pri;		/* initialization priority */
    char  *rt_Name;		/* pointer to node name	*/
    char  *rt_IdString;	/* pointer to identification string */
    APTR  rt_Init;		/* pointer to init code	*/
