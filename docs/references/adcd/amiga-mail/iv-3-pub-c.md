---
title: IV-3/Pub.c
manual: amiga-mail
chapter: amiga-mail
section: iv-3-pub-c
functions: []
libraries: []
---

# IV-3/Pub.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* Pub.c -  V36 Simple public screen example.
;   Compiled with SAS/C 6.56
sc NMINC STRMERGE NOSTKCHK LINK IGNORE=73 Pub.c
quit

Copyright (c) 1990-1999 Amiga, Inc.

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
#include <intuition/screens.h>
#include <graphics/displayinfo.h>
#include <libraries/gadtools.h>
#include <exec/memory.h>
#include <dos/dosextens.h>

#include <clib/exec_protos.h>
#include <clib/gadtools_protos.h>
#include <clib/intuition_protos.h>

#include <pragmas/exec_pragmas.h>
#include <pragmas/gadtools_pragmas.h>
#include <pragmas/intuition_pragmas.h>

struct IntuitionBase *IntuitionBase;
struct Library *GadToolsBase;
extern struct Library *SysBase;

static UWORD dri_Pens[] =
{0, 1, 1, 2, 1, 3, 1, 0, 3, ~0};

/* Gadtools menu stuff */
#define QUIT 1
struct NewMenu sdm_menu[] =
{
```c
    {NM_TITLE, "Project", 0, 0, 0, 0,},
    {NM_ITEM, "Quit", "Q", 0, 0, (void *) QUIT,},
    {NM_END, NULL, 0, 0, 0, 0,},
```
};

struct EasyStruct failedES =
{
```c
    sizeof(struct EasyStruct), 0, "AMPub",
    "%s",
    "OK",
```
};

void main(void);

void
main(void)
{

```c
    struct Screen *pubscreen;
    struct Window *window;
    struct Menu *menu;
    void *vi;

    struct IntuiMessage *msg;
    UBYTE defaultpubname[MAXPUBSCREENNAME];
    UWORD oldstatus;
    UWORD oldmodes;
    ULONG signal, wsignal, lastsignal, allocsignal;
    ULONG oserror;
    BOOL ABORT = FALSE;
    BOOL CLOSEDOWN = FALSE;
    struct Task *task;

    /* Fails silently if not V36 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36)) {
        if (GadToolsBase = OpenLibrary("gadtools.library", 36)) {
            if ((allocsignal = AllocSignal(-1)) != -1) {
                lastsignal = 1 << allocsignal;

                /* We'll use our task address to get signaled when the last
                 * visitor window leaves. */
                task =
                  (struct Task *)&((struct Process *)FindTask(NULL))->pr_Task;

                /* Get the name of the currently default
                 * public screen (normally WB) */
                GetDefaultPubScreen(defaultpubname);

                /* Note that no checking is done to make sure the
                 * public screen name is unique.  If the public name is
                 * not unique, OSERR_PUBNOTUNIQUE is returned in an
                 * application supplied variable as data for the SA_ErrorCode
                 * tag.  In this case however, if OpenScreen fails, for
                 * whatever reason, we just bail out.
                 */

                if (pubscreen = OpenScreenTags(NULL,
                                 SA_DisplayID, HIRES_KEY,
                                 SA_Depth, 2,
                                 SA_Title,  "AmigaMail Test Public Screen",
                                 SA_PubName,"AmigaMail Test Public Screen",

                                 SA_PubSig, allocsignal,
                                 SA_PubTask, task,
                                          /* Normally you'd supply 0L, if you
                                          * the task which opened the screen to
                                          * be signaled.
                                          */
                                 SA_Pens, dri_Pens, SA_ErrorCode, &oserror,
                                 TAG_END)) {
                    if (menu = CreateMenus(sdm_menu, TAG_DONE)) {
                        if (window = OpenWindowTags(NULL,
                                      WA_Top, pubscreen->BarHeight + 1,
                                      WA_Height, pubscreen->Height
                                                 - (pubscreen->BarHeight + 1),
                                      WA_CustomScreen, pubscreen,
                                      WA_IDCMP, MENUPICK,
                                      WA_Flags, ACTIVATE|BACKDROP|
                                                    BORDERLESS|NOCAREREFRESH,
                                      TAG_END)) {

                            vi = GetVisualInfo(pubscreen, TAG_END);
                            if (LayoutMenus(menu, vi, TAG_DONE)) {
                                SetMenuStrip(window, menu);

                                /* Now we have a screen, named "AmigaMail Test
                                 * Public Screen", which is still marked
                                 * private, but ready to be made public.
                                 */
                                oldstatus = PubScreenStatus(pubscreen, 0);
                                /* Now it is really public. We'll make it the
                                 * default (and shanghai attempts to open
                                 * windows on the Workbench.
                                 */
                                SetDefaultPubScreen(
                                               "AmigaMail Test Public Screen");

                                oldmodes = SetPubScreenModes(SHANGHAI|
                                                             POPPUBSCREEN);

                                wsignal = 1 << window->UserPort->mp_SigBit;

                                do {
                                    signal = Wait(wsignal|lastsignal);
                                    /* The last visitor just left our screen */
                                    if (signal & lastsignal) {
                                        if (CLOSEDOWN)
                                            if ((oldstatus =
                                                 PubScreenStatus(pubscreen,
                                                           PSNF_PRIVATE)) & 1)
                                                ABORT = TRUE;
                                    }

                                    /* If not wsignal, this while-loop will not
                                     * be executed.
                                     */
                                    while(msg = (struct IntuiMessage *)
                                          GetMsg(window->UserPort)) {
                                    if (msg->Class == MENUPICK) {
                                            if ((UWORD)(MENU_USERDATA
                                                    (ItemAddress(menu,
                                                        msg->Code))) == QUIT) {
                                            /* If we can't make our screen
                                             * private again, we got
                                             * visitor window(s). Note
                                             * window(s) you open without
                                             * specifiying SA_PubScreenName,
                                             * are NOT considered visitor
                                             * windows.  So it's easy to try
                                             * to make your public screen
                                             * private again, without having
                                             * to close down your own windows
                                             * first.
                                             */

                                            if ((oldstatus =
                                                 PubScreenStatus(pubscreen,
                                                          PSNF_PRIVATE)) & 1) {
                                                ABORT = TRUE;
                                                }
                                            else {
                                                /* Close as soon as possible */
                                                     CLOSEDOWN = TRUE;
                                                    EasyRequest(window,
                                                                &failedES,
                                                                NULL,
                       "Can't make screen private.\nPlease close all windows");
                                                }
                                            }
                                        }
                                        ReplyMsg((struct Message *)msg);
                                    }
                                } while (ABORT == FALSE);

                                /* Restore orignal default */
                                SetDefaultPubScreen(defaultpubname);
                                ClearMenuStrip(window);
                                FreeVisualInfo(vi);
                            } else
                                EasyRequest(NULL,
                                            &failedES,
                                            NULL,
                                            "Can't layout menu's");
                            CloseWindow(window);
                        } else
                            EasyRequest(NULL,
                                        &failedES,
                                        NULL,
                                        "Can't open window");
                        FreeMenus(menu);
                    } else EasyRequest(NULL,
                                       &failedES,
                                       NULL,
                                       "Can't create menu's");
                    CloseScreen(pubscreen);
                } else
                    EasyRequest(NULL,
                                &failedES,
                                NULL,
                                "Can't open public screen");
                FreeSignal(allocsignal);
            } else
            EasyRequest(NULL, &failedES, NULL, "No signal available");
            CloseLibrary(GadToolsBase);
        }
    CloseLibrary(IntuitionBase);
    }
```
}

