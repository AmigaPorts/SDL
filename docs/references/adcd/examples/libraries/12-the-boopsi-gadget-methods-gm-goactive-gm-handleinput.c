/* Source: ADCD 2.1
 * Section: 12-the-boopsi-gadget-methods-gm-goactive-gm-handleinput
 * Library: libraries
 * ADCD reference: libraries/12-the-boopsi-gadget-methods-gm-goactive-gm-handleinput.md
 */

    struct gpInput /* Used by GM_GOACTIVE and GM_HANDLEINPUT */
    {
        ULONG             MethodID;
        struct GadgetInfo *gpi_GInfo;
        struct InputEvent *gpi_IEvent;
                             /* The input event that triggered this method
                              * (for GM_GOACTIVE, this can be NULL)      */
        LONG              *gpi_Termination;
                             /* For GADGETUP IntuiMessage.Code           */
        struct
        {
            WORD X;          /* Mouse position relative to upper         */
            WORD Y;          /* left corner of gadget (LeftEdge,TopEdge) */
        } gpi_Mouse;
    };
