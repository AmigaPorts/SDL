/* Source: ADCD 2.1
 * Section: includes-libraries-gadtools-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-libraries-gadtools-h.md
 */

    {
    WORD ng_LeftEdge, ng_TopEdge;	/*  gadget position */
    WORD ng_Width, ng_Height;		/*  gadget size */
    UBYTE *ng_GadgetText;		/*  gadget label */
    struct TextAttr *ng_TextAttr;	/*  desired font for gadget label */
    UWORD ng_GadgetID;			/*  gadget ID */
    ULONG ng_Flags;			/*  see below */
    APTR ng_VisualInfo;			/*  Set to retval of GetVisualInfo() */
    APTR ng_UserData;			/*  gadget UserData */
    };
