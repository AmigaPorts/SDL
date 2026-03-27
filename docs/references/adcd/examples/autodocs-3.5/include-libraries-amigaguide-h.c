/* Source: ADCD 2.1
 * Section: include-libraries-amigaguide-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-libraries-amigaguide-h.md
 */

    BPTR		 nag_Lock;			/* Lock on the document directory */
    STRPTR		 nag_Name;			/* Name of document file */
    struct Screen	*nag_Screen;			/* Screen to place windows within */
    STRPTR		 nag_PubScreen;			/* Public screen name to open on */
    STRPTR		 nag_HostPort;			/* Application's ARexx port name */
    STRPTR		 nag_ClientPort;		/* Name to assign to the clients ARexx port */
    STRPTR		 nag_BaseName;			/* Base name of the application */
    ULONG		 nag_Flags;			/* Flags */
    STRPTR		*nag_Context;			/* NULL terminated context table */
    STRPTR		 nag_Node;			/* Node to align on first (defaults to Main) */
    LONG		 nag_Line;			/* Line to align on */
    struct TagItem	*nag_Extens;			/* Tag array extension */
    VOID		*nag_Client;			/* Private! MUST be NULL */
