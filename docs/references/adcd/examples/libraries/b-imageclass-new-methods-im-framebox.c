/* Source: ADCD 2.1
 * Section: b-imageclass-new-methods-im-framebox
 * Library: libraries
 * ADCD reference: libraries/b-imageclass-new-methods-im-framebox.md
 */

    struct impFrameBox
    {
        ULONG           MethodID;         /* IM_FRAMEBOX  */
        struct IBox     *imp_ContentsBox; /* The object fills in this  */
                                          /* structure with the        */
                                          /* dimensions of a rectangle */
                                          /* big enough to frame...    */
        struct IBox     *imp_FrameBox;    /* <------- this rectangle.  */
        struct DrawInfo *imp_DrInfo;      /* imp_DrInfo can be NULL.   */
        ULONG           imp_FrameFlags;
    };
    #define FRAMEF_SPECIFY  (1<<0)  /* Make do with the dimensions */
                                    /* passed in FrameBox.         */
