---
title: IV-17/extscreen.c
manual: amiga-mail
chapter: amiga-mail
section: iv-17-extscreen-c
functions: [GetDisplayInfoData, GetVPModeID]
libraries: [graphics.library]
---

# IV-17/extscreen.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* extscreen.c - Usage of NS_EXTENDED & NW_EXTENDED.  Compiled with SAS/C 6.56
sc NMINC STRMERGE NOSTKCHK LINK IGNORE=73 extscreen.c
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
#include <graphics/gfxbase.h>
#include <graphics/displayinfo.h>
#include <intuition/screens.h>

#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>
#include <clib/graphics_protos.h>

#include <stdio.h>
#include <stdlib.h>


struct IntuitionBase *IntuitionBase;
struct GfxBase *GfxBase;
extern struct ExecBase *SysBase;


/* To get that New Look we'll use Workbench compatible pen numbers.
 * The end of the pen array is indicated with ~0.
 * Note that the screen depth should comply with the pen numbers used.
 * I.e. specifying pen number 3 on a one bitplane screen will obviously
 * not give the desired effect.
 * A description of the pen array can be found in intuition/screens.h.
 */

static UWORD    dri_Pens[] =
{ 0, 1, 1, 2, 1, 3, 1, 0, 3, ~0};

/* zoom/zip/zap/zop array to illustrate NW_EXTENDED */
static UWORD    zoomdata[] =
{ 30, 30, 200, 100};

/* Old style requester to be compatible with < V36 */
struct IntuiText reqtext[] = {
```c
    { 0,1, JAM1, 10,10, NULL, NULL, NULL},
    { 0,1, JAM1, 6,3, NULL, "Continue", NULL},
```
};

/* local protos */
void            main(void);
BOOL CheckPAL(STRPTR screenname);

void main(void)
{
```c
    struct ExtNewScreen xnewscreen;
    struct ExtNewWindow xnewwindow;
    struct Screen  *screen;
    struct Window  *window;
    struct IntuiMessage *msg;
    struct DisplayInfo displayinfo;
    struct TagItem  taglist[3];
    BOOL OpenA2024 = FALSE;
    BOOL IsV36 = FALSE;
    BOOL IsPAL;

    if (IntuitionBase = OpenLibrary("intuition.library", 33))
    {
        if (GfxBase = (struct GfxBase *) OpenLibrary("graphics.library", 33))
        {

            /* V36 check if a 10 Hz A2024 screen can be opened. If this has to be
             * done in V35 (Jumpstart), start by checking the library version
             * ofcourse. Next simply open the screen with A2024 parameters. If this
             * fails there are a couple of possibilities. The system may have run
             * out of memory or even though the user is running V35 s/he hasn't set
             * up Hedley mode. Logical step in case of failure is to try again with
             * regular parameters. Depending on the nature of the program, this could
             * be done everytime the program starts, or according to some kind of
             * user preferences setting.
             */


            /* Check for V36>. If present check Hedley (A2024) availability */
            if (GfxBase->LibNode.lib_Version >= 36)
            {
                IsV36 = TRUE;
                /* Use GetDisplayInfoData() with the DTAG_DISP to get the display info,
                 * containing availability. Note that availability means that the user
                 * admonitor'ed A2024, not necessarily that there is a physical A2024
                 * out there.
                 */
                if(GetDisplayInfoData(NULL, (UBYTE *)&displayinfo,
                    sizeof(struct DisplayInfo), DTAG_DISP, A2024TENHERTZ_KEY))
                    if (displayinfo.NotAvailable == 0)
                        OpenA2024 = TRUE;
            }
            else
            {
                /* Check if V35. If it is indicate I want the  tags added to open a
                 * A2024 screen. Note that this still doesn't mean I can actually open
                 * in Hedley mode.
                 */
                if (GfxBase->LibNode.lib_Version == 35)
                    OpenA2024 = TRUE;
            }

            /* Use a separate CheckPAL() function to see if how the use has set up
             * the system.
             */
            IsPAL = CheckPAL("Workbench");

            /* Build taglist, this is completely ignored in V33/V34 and V35 doesn't
             * recognize tags other than those A2024 ones.
             */

            /* Pass the A2024 tags. Note that with V36 it is easy to pass the
             * displaymodeid as a tag (SA_DisplayID) that that is not V35 compatible.
             * Also for V35 compatability this must be the first tag. */

            if (OpenA2024)
            {
                taglist[0].ti_Tag = NSTAG_EXT_VPMODE;
                taglist[0].ti_Data = VPF_A2024 | VPF_TENHZ;
            }
            else
            {
                /* With V36 Intuition fully supports overscan. We'll pass the
                 * Overscantype used by Workbench as a tag, and specify
                 * STDSCREENWIDTH/HEIGHT in the Width and Height fields of
                 * the ExtNewScreen structure.
                 */
                taglist[0].ti_Tag = SA_Overscan;
                taglist[0].ti_Data = OSCAN_TEXT;
            }

            /* Indicate we want the New Look if this system is running V36 by
             * specifying the SA_Pens tag and passing the pen array as data.
             */
            taglist[1].ti_Tag = SA_Pens;
            taglist[1].ti_Data = (ULONG) dri_Pens;


            /* End the taglist with TAG_DONE */
            taglist[2].ti_Tag = TAG_DONE;



            /* If V36, the overscan mode will give us the right offsets */
            xnewscreen.LeftEdge = 0;
            xnewscreen.TopEdge = 0;

            /* Width = 1008 if A2024, 640 if < V35, STDSCREENWIDTH if V36> */
            xnewscreen.Width = (OpenA2024) ? 1008 : (IsV36) ? STDSCREENWIDTH : 640;

            /* Height=1024 if A2024 & PAL, 800 if A2024 & NTSC, else STDSCREENHEIGHT */
            xnewscreen.Height = (OpenA2024) ? ((IsPAL) ? 1024 : 800) : STDSCREENHEIGHT;


            xnewscreen.Depth = 2;
            xnewscreen.DetailPen = 0;
            xnewscreen.BlockPen = 1;

            /* Set viewmodes to 0 if going to attempt to open in Hedley mode */
            xnewscreen.ViewModes = (OpenA2024) ? 0 : HIRES | LACE;

            /* Use NS_EXTENDED to tell V35 tags are on their way */
            xnewscreen.Type = CUSTOMSCREEN | NS_EXTENDED;

            /* Default font */
            xnewscreen.Font = NULL;

            xnewscreen.DefaultTitle =
                     (OpenA2024) ? "VPF_A2024|VPF_TENHZ" : "HIRES|LACE";
            xnewscreen.Gadgets = NULL;

            /* Pass the taglist as a V35 compatible extension. V34 will ignore this */
            xnewscreen.Extension = taglist;

            if ((screen = OpenScreen(&xnewscreen)) == NULL)
            {
                /* Can't open screen. Might be V35 A2024 failure. Try with something
                 * simpler.
                 */
                xnewscreen.Width = (IsV36) ? STDSCREENWIDTH : 640;
                xnewscreen.Height = STDSCREENHEIGHT;
                xnewscreen.ViewModes = HIRES | LACE;
                xnewscreen.DefaultTitle = "HIRES|LACE";
                /* Get rid of A2024 tags, keep the others. */
                taglist[0].ti_Tag = SA_Overscan;
                taglist[0].ti_Data = OSCAN_TEXT;
                OpenA2024 = FALSE;
                screen = OpenScreen(&xnewscreen);
                /* If it still fails, give up */
            }

            /* If screen opened, open a simple ExtNewWindow on it and wait */
            if (screen)
            {
                /* Give me a zoom gadget on my window. */
                taglist[0].ti_Tag = WA_Zoom,
                taglist[0].ti_Data = (ULONG) zoomdata;
                taglist[1].ti_Tag = TAG_DONE;

                xnewwindow.LeftEdge = 0;
                xnewwindow.TopEdge = screen->BarHeight + 1;
                xnewwindow.Width = screen->Width;
                xnewwindow.Height = screen->Height - xnewwindow.TopEdge;
                xnewwindow.DetailPen = 0;
                xnewwindow.BlockPen = 1;
                xnewwindow.IDCMPFlags = CLOSEWINDOW;
                xnewwindow.Flags =
                    WINDOWSIZING | WINDOWDRAG | WINDOWDEPTH | WINDOWCLOSE |
                      NW_EXTENDED | SMART_REFRESH | NOCAREREFRESH | ACTIVATE;
                xnewwindow.FirstGadget = NULL;
                xnewwindow.CheckMark = NULL;
                xnewwindow.Title = "Close to exit.";
                xnewwindow.Screen = screen;
                xnewwindow.BitMap = NULL;
                xnewwindow.MinWidth = 100;
                xnewwindow.MinHeight = 50;
                xnewwindow.MaxWidth = ~0;
                xnewwindow.MaxHeight = ~0;
                xnewwindow.Type = CUSTOMSCREEN;
                /* The window extension is completely ignored if not V36 */
                xnewwindow.Extension = taglist;

                if (window = OpenWindow(&xnewwindow))
                {
                    WaitPort(window->UserPort);
                    while (msg = (struct IntuiMessage *)GetMsg(window->UserPort))
                        ReplyMsg((struct Message *)msg);
                    CloseWindow(window);
                }


                else
                {
                    reqtext[0].IText = "Can't open window";
                    AutoRequest(NULL, &reqtext[0], NULL, &reqtext[1],
                                NULL, GADGETUP, 320, 60);
                }
                CloseScreen(screen);
            }
            else
            {
                reqtext[0].IText = "Can't open screen";
                AutoRequest(NULL, &reqtext[0], NULL, &reqtext[1],
                            NULL, GADGETUP, 320, 60);
            }
            CloseLibrary((struct Library *) GfxBase);
        }
        CloseLibrary(IntuitionBase);
    }
```
}








/* CheckPAL returns TRUE, if the the videomode of the specified public screen (or default videmode)
 * is PAL.
 * If the screenname is NULL, the default public screen will be used.
 */

BOOL CheckPAL(STRPTR screenname)
{
```c
    struct Screen *screen;
    ULONG modeID = LORES_KEY;
    struct DisplayInfo displayinfo;
    BOOL IsPAL;

    if (GfxBase->LibNode.lib_Version >= 36)
    {
    /*
     * We got V36, so lets use the new calls to find out what
     * kind of videomode the user (hopefully) prefers.
     */

        if (screen = LockPubScreen(screenname))
        {
            /*
             * Use graphics.library/GetVPModeID() to get the ModeID of the specified
             * screen.  Will use the default public screen (Workbench most of the time)
             * if NULL It is very_ unlikely that this would be invalid, heck it's
             * impossible.
             */
            if ((modeID = GetVPModeID(&(screen->ViewPort))) != INVALID_ID)
            {
                /*
                 * If the screen is in VGA mode, we can't tell whether the system is
                 * PAL or NTSC. So to be fullproof we fall back to the displayinfo of
                 * the default.monitor by inquiring about just the LORES_KEY
                 * displaymode if we don't know. The default.monitor reflects the
                 * initial video setup of the system, thus is an alias for either
                 * ntsc.monitor or pal.monitor. We only use the displaymode of the
                 * specified public screen if it's display mode is PAL or NTSC and NOT
                 * the default.
                 */

                if (!((modeID & MONITOR_ID_MASK) == NTSC_MONITOR_ID ||
                      (modeID & MONITOR_ID_MASK) == PAL_MONITOR_ID))
                    modeID = LORES_KEY;
            }
            UnlockPubScreen(NULL, screen);
        } /* if fails modeID = LORES_KEY. Can't lock screen,
           * so fall back on default monitor. */

        if (GetDisplayInfoData(NULL, (UBYTE *) & displayinfo,
            sizeof(struct DisplayInfo), DTAG_DISP, modeID))
        {
            if (displayinfo.PropertyFlags & DIPF_IS_PAL)
                IsPAL = TRUE;
            else
                IsPAL = FALSE;  /* Currently the default monitor is always either
                                 * PAL or NTSC.
                                 */
        }
    }
    else /* < V36. The enhancements to the videosystem in
          * V36 cannot be better expressed than
          * with the simple way to determine PAL in V34.
          */
        IsPAL= (GfxBase->DisplayFlags & PAL) ? TRUE : FALSE;

    return(IsPAL);
```
}

---

## See Also

- [GetDisplayInfoData — graphics.library](../autodocs/graphics.library.md#getdisplayinfodata)
- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
