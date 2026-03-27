---
title: IV-3/ScreenDisplayModes.c
manual: amiga-mail
chapter: amiga-mail
section: iv-3-screendisplaymodes-c
functions: []
libraries: []
---

# IV-3/ScreenDisplayModes.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* ScreenDisplayModes.c - V36 Screen Displaymode selector example
; Compiled with SAS/C 6.56
sc NMINC STRMERGE NOSTKCHK LINK IGNORE=73 ScreenDisplayModes.c
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

#include <string.h>
#include <intuition/intuition.h>
#include <intuition/screens.h>
#include <libraries/gadtools.h>
#include <graphics/displayinfo.h>
#include <graphics/text.h>
#include <exec/memory.h>
#include <exec/ports.h>

#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>
#include <clib/graphics_protos.h>
#include <clib/gadtools_protos.h>
#include <clib/alib_protos.h>

#include <pragmas/exec_pragmas.h>
#include <pragmas/intuition_pragmas.h>
#include <pragmas/graphics_pragmas.h>
#include <pragmas/gadtools_pragmas.h>

#define SWITCH 888
#define QUIT   999

struct IntuitionBase *IntuitionBase;
struct GfxBase *GfxBase;
struct Library *GadToolsBase;
extern struct Library *SysBase;

void main(void);
void ShowDisplayModes(struct List * dlist);
struct Screen *OpenAScreen(struct DimensionInfo * di, UBYTE * name,
			   ULONG overscantype);
struct Window *OpenAWindow(struct Screen * screen, ULONG overscantype);

struct DisplayNode {
```c
    struct Node dn_Node;
    struct DimensionInfo dn_Dimensioninfo;
```
};

/* The workbench compatible pens we'll use for that New Look. */
static UWORD dri_Pens[] = {0, 1, 1, 2, 1, 3, 1, 0, 3, ~0};

/* Gadtools menu stuff */
struct NewMenu sdm_menu[] =
{
```c
    {NM_TITLE, "Project", 0, 0, 0, 0,},
    {NM_ITEM, "Switch Mode", "S", 0, 0, (void *) SWITCH,},
    {NM_ITEM, "Set Overscan", 0, 0, 0, 0,},
    {NM_SUB, "Text", 0, CHECKIT | CHECKED, ~1, (void *) OSCAN_TEXT,},
    {NM_SUB, "Standard", 0, CHECKIT, ~2, (void *) OSCAN_STANDARD,},
    {NM_SUB, "Max", 0, CHECKIT, ~4, (void *) OSCAN_MAX,},
    {NM_SUB, "Video", 0, CHECKIT, ~8, (void *) OSCAN_VIDEO,},
    {NM_ITEM, NM_BARLABEL, 0, CHECKIT, 0, 0,},
    {NM_ITEM, "Quit", "Q", 0, 0, (void *) QUIT,},
    {NM_END, NULL, 0, 0, 0, 0,},
```
};

UBYTE *OScanDescr[] = {NULL, "OSCAN_TEXT", "OSCAN_STANDARD",
			 "OSCAN_MAX", "OSCAN_VIDEO"};

struct EasyStruct failedES =
{
```c
    sizeof(struct EasyStruct), 0, "SDM",
    "%s",
    "OK",
```
};

void
main(void)
{
```c
    struct List *dlist;
    struct DisplayNode *dnode;
    struct DisplayNode *wnode, *nnode;

    ULONG modeID;
    ULONG skipID;

    ULONG result;
    struct DisplayInfo displayinfo;
    struct NameInfo nameinfo;

    /* Fails silently if not V36 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36)) {
        if (GfxBase = OpenLibrary("graphics.library", 36)) {
            if (GadToolsBase = OpenLibrary("gadtools.library", 36)) {
                if (dlist = AllocMem(sizeof(struct List), MEMF_CLEAR)) {
                    NewList(dlist);

                    /*
                     * Don't want duplicate entries in the list for the
                     * 'default monitor', so we'll skip the the videomode
                     * for which default.monitor is the alias.
                     */

                    /* INVALID_ID indicates the beginning and the end
```
		     * of the list of available keys.
		     */
```c
                    modeID = INVALID_ID;

                    GetDisplayInfoData(NULL, (UBYTE *) & displayinfo,
```
				       sizeof(struct DisplayInfo),
				       DTAG_DISP, LORES_KEY);
```c
                    if (displayinfo.PropertyFlags & DIPF_IS_PAL)
                        skipID = PAL_MONITOR_ID;
                    else
                        skipID = NTSC_MONITOR_ID;
                    while ((modeID = NextDisplayInfo(modeID)) != INVALID_ID) {
                        if ((modeID & MONITOR_ID_MASK) != skipID) {
```
			    /*
			     * For this example,only 'named' keys are accepted.  Others
			     * which have no description are left out
 			     * even though they may be available.
 			     * HAM and EXTRAHALFBRIGHT are examples of this.
 			     * If needed a name could be made like '320x400 HAM Interlace'.
 			     */

```c
                            if (result = GetDisplayInfoData(NULL,
```
							    (UBYTE *) & nameinfo,
							    sizeof(struct NameInfo),
							    DTAG_NAME,
							    modeID)) {
```c
                                result = GetDisplayInfoData(NULL,
```
							    (UBYTE *) & displayinfo,
							    sizeof(struct DisplayInfo),
							    DTAG_DISP,
							    modeID);
```c
                                if (!(displayinfo.NotAvailable)) {
                                    if (dnode =
```
					(struct DisplayNode *)
					AllocMem(sizeof(struct DisplayNode),
						 MEMF_CLEAR)) {
```c
                                        result = GetDisplayInfoData(NULL,
```
						   (UBYTE *) &
						   (dnode->dn_Dimensioninfo),
						   sizeof(struct DimensionInfo),
						   DTAG_DIMS,
						   modeID);
                                        /* to keep it short: if NOMEM,
					 * just don't copy
					 */
```c
                                        if (dnode->dn_Node.ln_Name
```
					    = AllocMem(strlen(nameinfo.Name)
						       + 1, MEMF_CLEAR))
```c
                                            strcpy(dnode->dn_Node.ln_Name,
```
						   nameinfo.Name);
```c
                                        AddTail(dlist, (struct Node *) dnode);
                                    } else {
                                        EasyRequest(NULL, &failedES, NULL,
```
						    "Out of memory");
```c
                                        /* Force modeID to INVALID to break */
                                        modeID = INVALID_ID;
                                    }
                                }
                            }
                        }
                    }
                    ShowDisplayModes(dlist);

                    wnode = (struct DisplayNode *) dlist->lh_Head;
                    while (nnode = (struct DisplayNode *)
```
			   (wnode->dn_Node.ln_Succ)) {

```c
                        if (wnode->dn_Node.ln_Name)
                            FreeMem(wnode->dn_Node.ln_Name,
```
				    strlen(wnode->dn_Node.ln_Name) +1);
```c
                        Remove((struct Node *) wnode);
                        FreeMem(wnode, sizeof(struct DisplayNode));
                        wnode = nnode;
                    }
                    FreeMem(dlist, sizeof(struct List));
                } else
                    EasyRequest(NULL, &failedES, NULL, "Out of memory");
                CloseLibrary(GadToolsBase);
            }
            CloseLibrary(GfxBase);
        }
        CloseLibrary(IntuitionBase);
    }
```
}

void
ShowDisplayModes(struct List * dlist)
{
```c
    struct Screen *screen;
    struct Window *window;
    struct Gadget *glist, *gadget, *hitgadget;
    struct DrawInfo *drawinfo;
    struct TextFont *defaultfont;
    struct TextAttr *textattr;
    struct IntuiMessage *imsg;
    struct NewGadget *ng;
    struct Menu *menu;
    struct MenuItem *item;
    void *vi;
    ULONG iclass, icode, code;
    struct DisplayNode *dnode;
    struct DimensionInfo *dimensioninfo;
    ULONG overscantype = OSCAN_TEXT;
    ULONG curmode = 0;
    BOOL ABORT = TRUE, OK;
    int i;


    if (ng = AllocMem(sizeof(struct NewGadget), MEMF_CLEAR)) {
        if (textattr = AllocMem(sizeof(struct TextAttr), MEMF_CLEAR)) {
            if (textattr->ta_Name = AllocMem(48, MEMF_CLEAR)) {

                dnode = (struct DisplayNode *) dlist->lh_Head;

                if (menu = CreateMenus(sdm_menu, TAG_DONE)) {
                    do {
                        dimensioninfo = &(dnode->dn_Dimensioninfo);
                        OK = FALSE;
                        if (screen = OpenAScreen(dimensioninfo,
```
						 dnode->dn_Node.ln_Name,
						 overscantype)) {
```c
                            drawinfo = GetScreenDrawInfo(screen);
                            defaultfont = drawinfo->dri_Font;
                            strcpy(textattr->ta_Name,
```
				   defaultfont->tf_Message.mn_Node.ln_Name);

```c
                            textattr->ta_YSize = defaultfont->tf_YSize;
                            textattr->ta_Style = defaultfont->tf_Style;
                            textattr->ta_Flags = defaultfont->tf_Flags;

                            if (window = OpenAWindow(screen, overscantype)) {
                                vi = GetVisualInfo(screen, TAG_END);
                                if (LayoutMenus(menu, vi, TAG_DONE)) {
                                    if (gadget = CreateContext(&glist)) {
                                        ng->ng_LeftEdge =
```
					  window->BorderLeft + 10;
```c
                                        ng->ng_TopEdge =
```
					  window->BorderTop + 10;
```c
                                        ng->ng_Width =
```
					  window->Width -
					    (window->BorderLeft + 10) -
					      (window->BorderRight + 10);
```c
                                        ng->ng_Height =
```
					  window->Height -
					    (window->BorderTop + 10) -
					      (window->BorderBottom + 10) -
						(4 + defaultfont->tf_YSize + 2);
```c
                                        ng->ng_TextAttr = textattr;
                                        ng->ng_GadgetText = NULL;
                                        ng->ng_VisualInfo = vi;
                                        ng->ng_GadgetID = 1;
                                        ng->ng_Flags = PLACETEXT_ABOVE;
                                        gadget =
```
					  CreateGadget(LISTVIEW_KIND, gadget,
						       ng, GTLV_Labels, dlist,
						       GTLV_ShowSelected, NULL,
						       GTLV_Selected, curmode,
						       TAG_END);

```c
                                        ng->ng_TopEdge +=
```
					  gadget->Height +
					    defaultfont->tf_YSize + 10;
```c
                                        ng->ng_Width = 80;
                                        ng->ng_LeftEdge =
```
					  ((window->Width - window->BorderLeft
					    - window->BorderRight) / 2) - 30;
```c
                                        ng->ng_Height = defaultfont->tf_YSize + 8;
                                        ng->ng_GadgetID = 2;
                                        ng->ng_GadgetText = "OK";
                                        ng->ng_VisualInfo = vi;
                                        ng->ng_Flags = PLACETEXT_IN;
                                        gadget =
```
					  CreateGadget(BUTTON_KIND, gadget,
						       ng, TAG_END);

```c
                                        AddGList(window, glist, -1, -1, NULL);
                                        RefreshGList(glist, window, NULL, -1);
                                        GT_RefreshWindow(window, NULL);
                                        SetMenuStrip(window, menu);
                                        ABORT = FALSE;
                                    } else
                                        EasyRequest(window, &failedES, NULL,
```
						    "Can't create gadget context");
```c
                                } else
                                    EasyRequest(window, &failedES, NULL,
```
						"Can't layout menus");

```c
                                do {
                                    WaitPort(window->UserPort);
                                    while (imsg = GT_GetIMsg(window->UserPort)) {
                                        iclass = imsg->Class;
                                        icode = imsg->Code;
                                        hitgadget =
```
					  (struct Gadget *) imsg->IAddress;
```c
                                        GT_ReplyIMsg(imsg);

                                        switch (iclass) {
                                        case GADGETUP:
                                            if (hitgadget->GadgetID == 1) {
                                                dnode =
```
						  (struct DisplayNode *)
						    dlist->lh_Head;
```c
                                                for (i = 0; i < icode; i++)
                                                dnode =
```
						  (struct DisplayNode *)
						    dnode->dn_Node.ln_Succ;
```c
                                                curmode = i;
                                            }
                                            if (hitgadget->GadgetID == 2)
                                                OK = TRUE;
                                            break;
                                        case MENUPICK:
                                            while ((icode != MENUNULL)
```
						   && (ABORT == FALSE)) {
```c
                                                item = ItemAddress(menu, icode);

                                                code = (ULONG) MENU_USERDATA(item);
                                                if (code == QUIT)
                                                    ABORT = TRUE;
                                                else if
                                                    (code == SWITCH)
                                                    OK = TRUE;
                                                else
                                                    overscantype = (ULONG) code;
                                                icode = item->NextSelect;
                                            }
                                            break;
                                        case CLOSEWINDOW:
                                            ABORT = TRUE;
                                            break;
                                        }
                                    }
                                } while (ABORT == FALSE && OK == FALSE);
                                ClearMenuStrip(window);
                                CloseWindow(window);
                                FreeVisualInfo(vi);
                                FreeGadgets(glist);
                            } else
                                EasyRequest(NULL, &failedES, NULL,
```
					    "Can't open window");
```c
                            FreeScreenDrawInfo(screen, drawinfo);
                            CloseScreen(screen);
                        } else
                            EasyRequest(NULL, &failedES, NULL,
```
					"Can't open screen");
```c
                    } while (ABORT == FALSE);
                    FreeMenus(menu);
                } else
                    EasyRequest(NULL, &failedES, NULL, "Can't create menus");
                FreeMem(textattr->ta_Name, 48);
            } else
                EasyRequest(NULL, &failedES, NULL, "Out of memory");
            FreeMem(textattr, sizeof(struct TextAttr));
        } else
            EasyRequest(NULL, &failedES, NULL, "Out of memory");
        FreeMem(ng, sizeof(struct NewGadget));
    } else
        EasyRequest(NULL, &failedES, NULL, "Out of memory");
```
}


/*
 * It's advised to use one of the overscan constants and
 * STDSCREENWIDTH and STDSCREENHEIGHT. For this example however, we'll
 * skip all that an use QueryOverscan to get the rectangle describing the
 * requested overscantype and pass that as the displayclip description.
 * Actually, since we pass the standard rectangle from the display database,
 * it is equivalent to the prefered:
 *
 * screen = OpenScreenTags(NULL,
 *                         SA_DisplayID, di->Header.DisplayID,
 *                         SA_Overscan, overscantype,
 *                         SA_Width, STDSCREENWIDTH,
 *                         SA_Height, STDSCREENHEIGHT,
 *                         SA_Title, name,
 *                         SA_Depth, 2,
 *                         SA_SysFont, 1,
 *                         SA_Pens, dri_Pens,
 *                         TAG_END);
 */

struct Screen *
OpenAScreen(struct DimensionInfo * di, UBYTE * name, ULONG overscantype)
{

```c
    struct Rectangle rectangle;

    /* Can't fail, already made sure it's a valid displayID */
    QueryOverscan(di->Header.DisplayID, &rectangle, overscantype);


    return (OpenScreenTags(NULL,
                           SA_DisplayID, di->Header.DisplayID,
                           SA_DClip, &rectangle,
                           SA_Title, name,
                           SA_Depth, 2,
                           SA_SysFont, 1,   /* Use the prefered WB screen font */
                           SA_Pens, dri_Pens,
                           TAG_END));
```
}

struct Window *
OpenAWindow(struct Screen * screen, ULONG overscantype)
{
```c
    return (OpenWindowTags(NULL,
                           WA_Top, screen->BarHeight + 1,
                           WA_Height, screen->Height - (screen->BarHeight + 1),
                           WA_CustomScreen, screen,
                           WA_IDCMP, CLOSEWINDOW | LISTVIEWIDCMP | MENUPICK,
                           WA_Flags, WINDOWCLOSE | ACTIVATE,
                           WA_Title, OScanDescr[overscantype],
                           TAG_END));
```
}

