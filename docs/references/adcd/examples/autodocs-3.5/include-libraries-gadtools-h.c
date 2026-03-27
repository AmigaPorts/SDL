/* Source: ADCD 2.1
 * Section: include-libraries-gadtools-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-libraries-gadtools-h.md
 */

    WORD ng_LeftEdge, ng_TopEdge;	/* gadget position */
    WORD ng_Width, ng_Height;		/* gadget size */
    UBYTE *ng_GadgetText;		/* gadget label */
    struct TextAttr *ng_TextAttr;	/* desired font for gadget label */
    UWORD ng_GadgetID;			/* gadget ID */
    ULONG ng_Flags;			/* see below */
    APTR ng_VisualInfo;			/* Set to retval of GetVisualInfo() */
    APTR ng_UserData;			/* gadget UserData */
