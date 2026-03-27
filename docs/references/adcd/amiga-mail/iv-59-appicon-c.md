---
title: IV-59/AppIcon.c
manual: amiga-mail
chapter: amiga-mail
section: iv-59-appicon-c
functions: [CreateMsgPort]
libraries: [exec.library]
---

# IV-59/AppIcon.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* Compile me with SAS/C 6.56
sc NMINC STRMERGE NOSTKCHK NODEBUG DATA=NEAR IGNORE=73 AppIcon.c
slink FROM LIB:c.o,AppIcon.o TO AppIcon LIBRARY LIB:sc.lib,LIB:Amiga.lib
quit
*/
/*
Copyright (c) 1991-1999 Amiga, Inc.

This example is provided in electronic form by Amiga, Inc.
for use with the Amiga Mail Volume II technical publication.
Amiga Mail Volume II contains additional information on the correct
usage of the techniques and operating system functions presented in
these examples.  The source and executable code of these examples may
only be distributed in free electronic form, via bulletin board or
as part of a fully non-commercial and freely redistributable
diskette.  Both the source and executable code (including comments)
must be included, without modification, in any copy.  This example
may not be published in printed form or distributed with any
commercial product. However, the programming techniques and support
routines set forth in these examples may be used in the development
of original executable software products for Amiga
computers.

All other rights reserved.

This example is provided "as-is" and is subject to change; no
warranties are made.  All use is at your own risk. No liability or
responsibility is assumed.
*/

#include <intuition/intuition.h>
#include <exec/memory.h>
#include <workbench/startup.h>
#include <workbench/workbench.h>

#include "appicon.h"

#ifdef LATTICE
#include <stdio.h>

/* disable SAS/C CTRL-C handing */
int
CXBRK(void)
{
```c
    return (0);
```
}
int
chkabort(void)
{
```c
    return (0);
```
}

#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>
#include <clib/wb_protos.h>
#endif

struct IntuitionBase *IntuitionBase;
struct WorkbenchBase *WorkbenchBase;

void            main(void);

void
main(void)
{
```c
    struct MsgPort *msgport;
    struct Window  *window;
    struct AppIcon *appicon;
    struct IntuiMessage *imsg;
    struct AppMessage *appmsg;
    struct WBArg   *argptr;

    ULONG           id = 1, userdata = 0;
    BOOL            ABORT = FALSE;
    UCOUNT          i;


    /* Open needed libraries. Fail silently if < 36 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36))
    {
        if (WorkbenchBase = OpenLibrary("workbench.library", 36))
        {
            if (msgport = CreateMsgPort())
            {
                if (window =
                    OpenWindowTags(NULL, WA_Left, 0, WA_Top, 1, WA_Width, 160,
                                   WA_Height, 50, WA_IDCMP, CLOSEWINDOW,
                                   WA_Flags, WINDOWCLOSE | WINDOWDRAG,
                                   WA_Title, "AppIcon", TAG_END))
                {

                    /* Add the icon to Workbench */
                    if (appicon = AddAppIcon(id, userdata, "AppIcon",
                        msgport, NULL, &AppIconDObj, NULL))
                    {
                        do
                        {
                            Wait(1 << window->UserPort->mp_SigBit |
                                1 << msgport->mp_SigBit);
                            while (imsg = (struct IntuiMessage *)
                                GetMsg(window->UserPort))
                            {
                                if (imsg->Class = CLOSEWINDOW)
                                    ABORT = TRUE;
                                ReplyMsg((struct Message *) imsg);
                            }
                            while (appmsg = (struct AppMessage *) GetMsg(msgport))
                            {
                                printf(
                       "ai: appmsg=%lx, Type=%ld, ID=%ld, UserData=%ld, NumArgs=%ld\n",
                                       appmsg, appmsg->am_Type, appmsg->am_ID,
                                       appmsg->am_UserData, appmsg->am_NumArgs);
                                argptr = appmsg->am_ArgList;

                                /*
                                 * If am->NumArgs is zero the user
                                 * double-clicked on our icon, otherwise one or
                                 * more icons were dropped on top of it.
                                 */
                                for (i = 0; i < appmsg->am_NumArgs; i++)
                                {
                                    printf("\targ(%ld): Name='%s', Lock=%lx\n",
                                    i, argptr->wa_Name, argptr->wa_Lock);
                                    argptr++;
                                }
                                ReplyMsg((struct Message *) appmsg);
                            }
                        } while (ABORT == FALSE);
                        /* Remove the AppIcon and clean up */
                        RemoveAppIcon(appicon);
                    }
                    else
                        printf("Couldn't add AppIcon\n");
                    CloseWindow(window);
                }
                else
                    printf("Couldn't open window\n");
                DeleteMsgPort(msgport);
            }
            else
                printf("Couldn't create messageport\n");
            CloseLibrary(WorkbenchBase);
        }
        else
            printf("Couldn't open workbench.library\n");
        CloseLibrary(IntuitionBase);
    }
    else
        printf("Couldn't open intuition.library\n");
```
}

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
