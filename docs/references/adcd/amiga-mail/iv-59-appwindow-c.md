---
title: IV-59/AppWindow.c
manual: amiga-mail
chapter: amiga-mail
section: iv-59-appwindow-c
functions: [CreateMsgPort]
libraries: [exec.library]
---

# IV-59/AppWindow.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* AppWindow.c - Execute me to compile me with SAS/C 6.56
sc NMINC STRMERGE NOSTKCHK NODEBUG DATA=NEAR IGNORE=73 AppWindow.c
slink FROM LIB:c.o,AppWindow.o TO AppWindow LIBRARY LIB:sc.lib,LIB:amiga.lib
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

#include <exec/memory.h>
#include <intuition/intuition.h>
#include <workbench/startup.h>
#include <workbench/workbench.h>

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
#include <clib/icon_protos.h>
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
    struct AppWindow *appwindow;
    struct IntuiMessage *imsg;
    struct AppMessage *appmsg;
    struct WBArg   *argptr;

    ULONG           id = 1, userdata = 0;
    BOOL            ABORT = FALSE;
    UCOUNT          i;

    /* Open Intuition.library & Workbench.library. Fail silently if < 36 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36))
    {
        if (WorkbenchBase = OpenLibrary("workbench.library", 36))
        {
            /* Create the message port to which Workbench can send messages */
            if (msgport = CreateMsgPort())
            {
                if (window =
                    OpenWindowTags(NULL, WA_Left, 0, WA_Top, 1, WA_Width, 160,
                                   WA_Height, 50, WA_IDCMP, CLOSEWINDOW,
                                   WA_Flags, WINDOWCLOSE | WINDOWDRAG,
                                   WA_Title, "AppWindow", TAG_END))
                {

                    /*
                     * Turn the window we opened into an AppWindow. Provide an
                     * ID so you can tell possible more AppWindows apart.
                     */
                    if (appwindow = AddAppWindow(id, userdata, window, msgport, NULL))
                    {
                        do
                        {
                            /* Wait for either a CLOSEWINDOW or an AppMessage */
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

                                /*
                                 * The AppMessage type will be MTYPE_APPWINDOW,
                                 * the ID & userdata are what we supplied when
                                 * the window was designed as an AppWindow.
                                 * NumArgs allows us to process the Workbench
                                 * arguments properly.
                                 */
                                printf(
                       "aw: appmsg=%lx, Type=%ld, ID=%ld, UserData=%ld, NumArgs=%ld\n",
                                       appmsg, appmsg->am_Type, appmsg->am_ID,
                                       appmsg->am_UserData, appmsg->am_NumArgs);

                                /*
                                 * Get a pointer to the start of the Workbench
                                 * argument list.
                                 */
                                argptr = appmsg->am_ArgList;
                                for (i = 0; i < appmsg->am_NumArgs; i++)
                                {

                                    /*
                                     * The lock will be on the directory in
                                     * which the file resides. If there is no
                                     * filename, either a volume or window was
                                     * dropped on us.
                                     */
                                    printf("\targ(%ld): Name='%s', Lock=%lx\n",
                                           i, argptr->wa_Name, argptr->wa_Lock);
                                    /* Point to next argument */
                                    argptr++;
                                }
                                ReplyMsg((struct Message *) appmsg);
                            }
                        } while (ABORT == FALSE);
                        /* remove the appwindow status and close down */
                        RemoveAppWindow(appwindow);
                    }
                    else
                        printf("Couldn't AddAppWindow\n");
                    CloseWindow(window);
                }
                else
                    printf("Couldn't open window\n");
                DeleteMsgPort(msgport);
            }
            else
                printf("Coulnd't create messageport\n");
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
