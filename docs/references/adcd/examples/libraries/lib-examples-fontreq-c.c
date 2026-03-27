/* Source: ADCD 2.1
 * Section: lib-examples-fontreq-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-fontreq-c.md
 */

    struct FontRequester *fr;

    if (AslBase = OpenLibrary("asl.library", 37L))
    {
        if (fr = (struct FontRequester *)
            AllocAslRequestTags(ASL_FontRequest,
                /* tell the requester to use my custom mode names */
                ASL_ModeList, modelist,

                /* Supply initial values for requester */
                ASL_FontName, (ULONG)"topaz.font",
                ASL_FontHeight, 11L,
                ASL_FontStyles, FSF_BOLD | FSF_ITALIC,
                ASL_FrontPen,  0x00L,
                ASL_BackPen,   0x01L,

                /* Only display font sizes between 8 and 14, inclusive. */
                ASL_MinHeight, 8L,
                ASL_MaxHeight, 14L,

                /* Give all the gadgetry, but only display fixed width fonts */
                ASL_FuncFlags, FONF_FRONTCOLOR | FONF_BACKCOLOR |
                    FONF_DRAWMODE | FONF_STYLES | FONF_FIXEDWIDTH,
                TAG_DONE))
        {
            /* Pop up the requester */
            if (AslRequest(fr, NULL))
            {
                /* The user selected something,  report their choice */
                printf("%s\n  YSize = %d  Style = 0x%x   Flags = 0x%x\n"
                       "  FPen = 0x%x   BPen = 0x%x   DrawMode = 0x%x\n",
                               fr->fo_Attr.ta_Name,
                               fr->fo_Attr.ta_YSize,
                               fr->fo_Attr.ta_Style,
                               fr->fo_Attr.ta_Flags,
                               fr->fo_FrontPen,
                               fr->fo_BackPen,
                               fr->fo_DrawMode);
            }
            else
                /* The user cancelled the requester, or some kind of error
                ** occurred preventing the requester from opening. */
                printf("Request Cancelled\n");
            FreeAslRequest(fr);
        }
        CloseLibrary(AslBase);
    }
