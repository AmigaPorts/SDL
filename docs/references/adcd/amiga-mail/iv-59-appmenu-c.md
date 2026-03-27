---
title: IV-59/AppMenu.c
manual: amiga-mail
chapter: amiga-mail
section: iv-59-appmenu-c
functions: [CreateMsgPort]
libraries: [exec.library]
---

# IV-59/AppMenu.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* AppMenu.c - Execute me to compile me with SAS/C 6.56
sc NMINC STRMERGE NOSTKCHK NODEBUG DATA=NEAR IGNORE=73 AppMenu.c
slink FROM LIB:c.o,AppMenu.o TO AppMenu LIBRARY LIB:sc.lib,LIB:Amiga.lib
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

#ifdef LATTICE

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
#include <clib/dos_protos.h>
#include <clib/alib_stdio_protos.h>
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
    struct AppMenuItem *appmenuitem;
    struct IntuiMessage *imsg;
    struct AppMessage *appmsg;
    struct WBArg   *argptr;

    ULONG           id = 1, userdata = 0, i;
    BOOL            ABORT = FALSE;

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
                                   WA_Title, "AppMenu", TAG_END))
                {

                    /* Use our window to attach an menu item to the Tools menu. */
                    if (appmenuitem = AddAppMenuItem(id, userdata,
                                                     "AppMenuItem", msgport, NULL))
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
                                 * The AppMessage type will be MTYPE_APPMENU,
                                 * the ID & userdata are what we supplied when
                                 * the window was designed as an AppWindow.
                                 * Since there are no Workbench arguments for
                                 * menu operations, NumArgs will always be 0.
                                 */
                                printf(
                       "am: appmsg=%lx, Type=%ld, ID=%ld, UserData=%ld, NumArgs=%ld\n",
                                       appmsg, appmsg->am_Type, appmsg->am_ID,
                                       appmsg->am_UserData, appmsg->am_NumArgs);
                                argptr = appmsg->am_ArgList;
                                for (i = 0; i < appmsg->am_NumArgs; i++)
                                {

                                    /*
                                     * The lock will be on the directory in
                                     * which the file resides. If there is no
                                     * filename, either a volume or window was
                                     * dropped on us.
                                     */
                                    printf("\targ(%ld): Name='%s', Lock=%lx\n", i,
                                           argptr->wa_Name, argptr->wa_Lock);
                                    /* Point to next argument */
                                    argptr++;
                                }

                                ReplyMsg((struct Message *) appmsg);
                            }
                        } while (ABORT == FALSE);
                        /* remove the AppMenu and close down */
                        RemoveAppMenuItem(appmenuitem);
                    }
                    else
                        printf("Couldn't add AppMenuItem\n");
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
