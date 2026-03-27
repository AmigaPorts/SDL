# amigaguide.library/GetAmigaGuideMsg



   NAME

```c
        GetAmigaGuideMsg - Receive async AmigaGuide message.    (V34)
```
   SYNOPSIS

```c
        msg = GetAmigaGuideMsg (handle);
        d0                       a0

        struct [AmigaGuideMsg](../Includes_and_Autodocs_3._guide/node05D2.html#line88) *GetAmigaGuideMsg (AMIGAGUIDECONTEXT);
```
   FUNCTION

        This function returns a SIPC message from the AmigaGuide system,
        if there is a message available.
   INPUTS

        handle - Handle to a AmigaGuide system.
   EXAMPLE


```c
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
```
   RETURNS

        msg -- Pointer to a SIPC message or NULL if no message was
            available.
   SEE ALSO

```c
        [OpenAmigaGuideAsyncA()](../Includes_and_Autodocs_3._guide/node000F.html), [AmigaGuideSignal()](../Includes_and_Autodocs_3._guide/node0008.html), [ReplyAmigaGuideMsg()](../Includes_and_Autodocs_3._guide/node0011.html)
```
