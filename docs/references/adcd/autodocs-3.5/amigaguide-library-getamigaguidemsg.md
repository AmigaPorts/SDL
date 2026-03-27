---
title: amigaguide.library/GetAmigaGuideMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-getamigaguidemsg
functions: []
libraries: []
---

# amigaguide.library/GetAmigaGuideMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
        GetAmigaGuideMsg - Receive async AmigaGuide message.    (V34)
```
   SYNOPSIS

```c
        msg = GetAmigaGuideMsg (handle);
        d0                       a0

        struct [AmigaGuideMsg](autodocs-3.5/include-libraries-amigaguide-h.md) *GetAmigaGuideMsg (AMIGAGUIDECONTEXT);
```
   FUNCTION

        This function returns a SIPC message from the AmigaGuide system,
        if there is a message available.
   INPUTS

        handle - Handle to a AmigaGuide system.
   EXAMPLE


```c
        [AMIGAGUIDECONTEXT](autodocs-3.5/include-libraries-amigaguide-h.md) handle;
        struct [AmigaGuideMsg](autodocs-3.5/include-libraries-amigaguide-h.md) *agm;

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
        [OpenAmigaGuideAsyncA()](autodocs-3.5/amigaguide-library-openamigaguideasyncamigaguide-library.md), [AmigaGuideSignal()](autodocs-3.5/amigaguide-library-amigaguidesignal.md), [ReplyAmigaGuideMsg()](autodocs-3.5/amigaguide-library-replyamigaguidemsg.md)
```
