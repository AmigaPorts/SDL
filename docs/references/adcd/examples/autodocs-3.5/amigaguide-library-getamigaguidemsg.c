/* Source: ADCD 2.1
 * Section: amigaguide-library-getamigaguidemsg
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-library-getamigaguidemsg.md
 */

        [AMIGAGUIDECONTEXT](../Includes_and_Autodocs_3._guide/node05D2.html#line86) handle;
        struct [AmigaGuideMsg](../Includes_and_Autodocs_3._guide/node05D2.html#line88) *agm;

        /* get a AmigaGuide message */
        while (agm = GetAmigaGuideMsg(handle))
        {
            /* process the event */
            switch (agm->agm_Type)
            {
                case ToolCmdReplyID: /* a command has completed */
                    if (agm->agm_Pri_Ret)
                    {
                        /* An error occurred, the reason is in agm_Sec_Ret.
                         * The command string is in agm_Data
                         */
                    }
                    break;

                case ToolStatusID: /* status message */
                    if (agm->agm_Pri_Ret)
                    {
                        /* an error occurred, the reason is in agm_Sec_Ret */
                    }
                    break;

                default:
                    break;
            }

            /* reply to the AmigaGuide message */
            ReplyAmigaGuideMsg(agm);
        }
