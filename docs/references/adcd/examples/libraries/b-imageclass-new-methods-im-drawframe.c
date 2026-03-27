/* Source: ADCD 2.1
 * Section: b-imageclass-new-methods-im-drawframe
 * Library: libraries
 * ADCD reference: libraries/b-imageclass-new-methods-im-drawframe.md
 */

    {
        ULONG           MethodID;    /* IM_DRAWFRAME */
        struct RastPort *imp_RPort;  /* RastPort to render into */
        struct
        {
            WORD X;                  /* X and Y offset relative to the */
            WORD Y;           /* image's IA_Left and IA_Top attributes */
        } imp_Offset;
        ULONG    imp_State;  /* Visual state of image (see defines below)*/
        struct DrawInfo *imp_DrInfo;
                    /* DrawInfo describing target RastPort (can be NULL) */
        struct
        {
            WORD Width;   /* scale, clip, restrict, etc. to these bounds */
            WORD Height;
        } imp_Dimensions;
    };
