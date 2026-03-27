/* Source: ADCD 2.1
 * Section: b-gadgetclass-new-methods-gm-goactive
 * Library: libraries
 * ADCD reference: libraries/b-gadgetclass-new-methods-gm-goactive.md
 */

    struct gpInput
    {
        ULONG             MethodID;    /* GM_GOACTIVE or GM_HANDLEINPUT */
        struct GadgetInfo *gpi_GInfo;
        struct InputEvent *gpi_IEvent; /* The input event that triggered */
                                       /* this method (can be NULL for   */
                                       /* GM_GOACTIVE).                  */
        LONG         *gpi_Termination; /* For GADGETUP IntuiMessage.Code */
        struct
        {
            WORD X;             /* Mouse position relative to upper      */
            WORD Y;             /* left corner of gadget (LeftEdge,      */
        } gpi_Mouse;            /* TopEdge).                             */
    };
