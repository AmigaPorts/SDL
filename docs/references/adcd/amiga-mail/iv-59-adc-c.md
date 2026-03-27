---
title: IV-59/adc.c
manual: amiga-mail
chapter: amiga-mail
section: iv-59-adc-c
functions: []
libraries: []
---

# IV-59/adc.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/*
sc link ignore=73 adc.c
quit

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


/****** AppWorkbench.demo/ADC *************************************************


    NAME
        ADC -- AppWorkbench - Complete and contained demo of how to use
               the AppWorkbench Interface.

    AUTHOR
        Fred Mitchell, Copyright © 1991-1999 Amiga, Inc.
        3.00    08 Jul 1991 - All known problems are rectified.

    FUNCTION
        Demonstrates use of AppIcons, AppMenu, and AppWindow.

    COMPILE
        sc link adc
******************************************************************************/

/* Includes */
#include <exec/types.h>
#include <intuition/intuition.h>
#include <workbench/icon.h>
#include <workbench/workbench.h>
#include <workbench/startup.h>
#include <dos.h>
#include <dos/dos.h>
#include <dos/dosextens.h>
#include <dos/dostags.h>

/* Defines  */
#define ASIZE   500     /* size of the arrays */

/* Structs, externs, and prototypes */

struct AppWindow *awin = NULL;
struct Window *win = NULL;

struct AppIcon *aicon = NULL;

struct AppMenuItem *amenu[ASIZE];
char *appName[ASIZE];
short  amicount = NULL;

struct Remember *key = NULL;
struct MsgPort *aport = NULL;   /* message port to be used with appicon system */

struct Library  *GfxBase,

```c
                *IntuitionBase,
                *IconBase,
                *WorkbenchBase,
                *GadToolsBase;
```
extern struct Library *DOSBase, *SysBase;

/* Prototypes   */

void _main(void);
void ProcessIcon(struct Window *win,
```c
                 struct AppMessage *am);
```
UBYTE *BSTRtoSTR(ULONG b);
void ShutDown(void);
void warning(char *s);
void warning2(char *r, char *s);
void fatal(char *s);
void fatal2(char *r, char *s);
struct Window *MakeWindow(struct Remember **key);
void UpdateWindow(struct Window *win);
void FreePid(struct ProcID *pid);

/* Icon data    */
USHORT	chip	BlackHoleGadData1[] = {
/* Plane 0 */
	0x0000,0x01ff,0xf087,0xff00,0x0000,0x0000,0x01ff,0xb807,
	0xfc00,0x0000,0x0000,0x007f,0xbc07,0x7c00,0x0000,0x0000,
	0x000f,0xfc03,0xfc00,0x0000,0x0000,0x0007,0xfe23,0xfc00,
	0x0000,0x0000,0x0001,0xfe03,0xfc00,0x0000,0x0000,0x0220,
	0x7f07,0xfc00,0x0000,0x0000,0x0000,0x7f03,0xfc00,0x0000,
	0x0000,0x0000,0x3f07,0x9800,0x0000,0x0000,0x0000,0x3f03,
	0xf800,0x0000,0x0000,0x7ff0,0x0e07,0xf000,0x0000,0x0000,
	0xfffc,0x0e87,0xf000,0x0000,0x0033,0xeffe,0x0e1f,0xf000,
	0x0000,0x00ff,0xf7ff,0x7d0f,0xc200,0x3000,0x01ff,0xffff,
	0x3c9f,0xc000,0x3000,0x03ff,0xffff,0xabff,0x8000,0x7000,
	0x07ff,0x7e53,0xbeff,0x0000,0xf000,0x0f3e,0x7807,0xf7fe,
	0x0871,0xf000,0x13ff,0xe007,0x5b00,0x00e2,0xe000,0x01f3,
	0xc018,0xffd0,0x01e7,0xc000,0x03a3,0x800d,0x5b60,0x03ff,
	0xe400,0x07c7,0x087f,0xf7c0,0x1f7e,0x7800,0x0780,0x00ff,
	0xbee5,0x3ffc,0xf000,0x0700,0x01f9,0xca7f,0xffff,0xe000,
	0x0600,0x03f8,0x9eff,0xffff,0xc000,0x0600,0x27f4,0x3f7f,
	0xf7fe,0x8000,0x0000,0x0ff0,0xf83f,0xfbfc,0x0000,0x0000,
	0x0ff0,0x781f,0xff80,0x0000,0x0000,0x0fe0,0x7a07,0xff00,
	0x0000,0x0000,0x0fe0,0x7c00,0x0000,0x0000,0x0000,0x1ae0,
	0x7f00,0x0000,0x0000,0x0000,0x3fe0,0x7f00,0x2000,0x0000,
	0x0000,0x3fe0,0x3f84,0x0000,0x0000,0x0000,0x1fc0,0x3fc0,
	0x0000,0x0000,0x0000,0x3fe4,0x3ff0,0x0000,0x0000,0x0000,
	0x3fe0,0x3fff,0x0000,0x0000,0x0000,0x3ff0,0x3eff,0x8000,
	0x0000,0x0000,0x7ff0,0x9dff,0xc000,0x0000,
/* Plane 1 */
	0x0000,0x003c,0xf027,0x9f00,0x0000,0x0000,0x007f,0xf807,
	0xfc00,0x0000,0x0000,0x0057,0xcc43,0x7c00,0x0000,0x0000,
	0x0003,0xcd01,0xfc00,0x0000,0x0000,0x0100,0x0e01,0xec00,
	0x0000,0x0000,0x0000,0x0e01,0xfc00,0x0000,0x0000,0x0080,
	0x0701,0xfc00,0x0000,0x0000,0x0000,0x4101,0xfc00,0x0000,
	0x0000,0x0080,0x2103,0xf800,0x0000,0x0000,0x0002,0x1943,
	0x3800,0x0000,0x0000,0x7ff0,0x2986,0x0000,0x0000,0x0040,
	0xf88e,0x5984,0x1000,0x0000,0x0033,0xf801,0x090c,0xf000,
	0x0000,0x00fe,0xf800,0xfa68,0xc000,0x3000,0x01ff,0xf000,
	0xd3b8,0xd000,0x3000,0x03ff,0xf87e,0x54f0,0x8500,0x7000,
	0x07ff,0x704f,0x41e3,0x0000,0xf000,0x0f3e,0x600f,0x0802,
	0x0071,0xf000,0x03df,0xc000,0xa4fe,0x00f3,0xe000,0x01b3,
	0x805f,0x0071,0x00e6,0xc000,0x03e7,0x8032,0xa4e0,0x01fd,
	0xe000,0x07c7,0x0060,0x0848,0x037a,0x7800,0x0780,0x00cf,
	0xc179,0x07fc,0xf000,0x0700,0x518b,0xb5bf,0x0fff,0xe000,
	0x0600,0x071c,0xe500,0x07ff,0xc000,0x0600,0x0712,0x4f80,
	0x0fbe,0x8000,0x0000,0x0f10,0x9c40,0x0ffc,0x0000,0x0000,
	0x0c10,0x9e38,0x8f81,0x0000,0x0000,0x0902,0x8847,0xff00,
	0x0000,0x0000,0x0f80,0x4c00,0x8000,0x0000,0x0000,0x1fa0,
	0x4700,0x0000,0x0000,0x0000,0x3fc0,0x4100,0x8000,0x0000,
	0x0000,0x3fc0,0x0000,0x0000,0x0000,0x0000,0x1fc0,0x3880,
	0x4000,0x0000,0x0000,0x37c0,0x6180,0x0000,0x0000,0x0000,
	0x3fc1,0x21e3,0x0000,0x0000,0x0000,0x3fd0,0x37ff,0x8000,
	0x0000,0x0000,0x7f82,0x1ffc,0xc000,0x0000,
};

USHORT	chip	BlackHoleGadData2[] = {
/* Plane 0 */
	0x000b,0xfc00,0x9ff0,0x7fc0,0x0000,0x0043,0xc090,0x0fe5,
	0x1380,0x0000,0x000f,0x8003,0x0370,0x0300,0x0000,0x0027,
	0x0080,0x0362,0x03c0,0x0000,0x0002,0x0fcc,0x5ee0,0x07c0,
	0x0000,0x000c,0x1ffa,0x4ef0,0x07e0,0x2000,0x0008,0x3efe,
	0x00fc,0x2365,0x0000,0x0018,0x7fff,0xc075,0xa020,0x0000,
	0x403c,0x0f2b,0xc0bc,0x0034,0x0000,0x24de,0x098f,0x44f0,
	0x0019,0x0000,0x817e,0x1387,0xc0e3,0x001c,0x4000,0x0064,
	0x0380,0xc073,0x3a1f,0x0000,0x0000,0xc311,0x63c1,0x9e0e,
	0x0000,0x8080,0x0501,0xe6c1,0xfe06,0x0200,0x0100,0x2a01,
	0xff80,0xfe06,0x4400,0x0180,0x09c1,0xdf00,0x5405,0x0000,
	0x2548,0x0db1,0xfd04,0x2801,0x0800,0x0384,0x97ff,0xd700,
	0xf801,0x0000,0xa200,0x1fd6,0xffe3,0x7201,0x8800,0x2302,
	0x3e8f,0xbbe6,0xf081,0x8800,0x2300,0xbd07,0xfedf,0xf000,
	0x8a00,0x0100,0x7e0b,0xd7ff,0xd243,0x8000,0x2100,0xe843,
	0x7f1b,0x7025,0x4800,0x0140,0xd403,0xf707,0x0003,0x0000,
	0x44c0,0xfe0d,0xff00,0x8801,0x0000,0x80c1,0xfe3f,0x8b01,
	0xc002,0x0200,0x00c1,0xf36c,0x0621,0xa600,0x0000,0x01f1,
	0x9b7c,0x0e03,0x004c,0x0000,0x0471,0x81be,0x0fc3,0x00f9,
	0x0200,0x0131,0x837a,0x8bb7,0x40f6,0x4800,0x0040,0x837e,
	0x07dd,0xe1f8,0x0400,0x0009,0x8a5a,0x01fa,0xfef0,0x0000,
	0x014f,0x907c,0x41ff,0xf860,0x0000,0x080f,0xc03f,0xc4bf,
	0xf0c0,0x0000,0x0007,0xc09a,0xc447,0xe180,0x0000,0x0005,
	0xa01d,0x9004,0x0110,0x0000,0x0007,0xf03f,0xf110,0x0348,
	0x0000,0x0007,0xfebf,0xfa04,0x7f80,0x0000,
/* Plane 1 */
	0x0083,0x3c7f,0x9c70,0x7fc0,0x0000,0x0007,0xce7f,0x8c6a,
	0xd380,0x0000,0x001f,0xbfed,0x003f,0xc200,0x0000,0x0007,
	0x70fc,0x02ef,0xe3c0,0x0000,0x0002,0xcfcc,0x5d8b,0xe7c0,
	0x0000,0x0005,0x9824,0x0a17,0xe7e0,0x6000,0x000b,0x3886,
	0x5e0f,0xd360,0x0000,0x0018,0x7841,0xdf9d,0xf824,0x0000,
	0x003c,0x0e91,0xd684,0x78b4,0x0000,0x23de,0x6889,0x7ab0,
	0x18dc,0x0000,0x416e,0xf374,0x16a1,0x00dd,0x4000,0x0064,
	0xe379,0x9eb7,0x3a5e,0x0000,0x8001,0x634d,0x7981,0x9e4e,
	0x0000,0x8003,0xc574,0xa65f,0xf266,0x0000,0x0023,0xe93d,
	0xbfbf,0x62f6,0x4400,0x09e7,0xe9c5,0x003b,0xf5f1,0x2000,
	0x4767,0xc931,0x01eb,0x39e1,0x0000,0x07f3,0x9e4a,0x291c,
	0x09c1,0x0000,0x8267,0xd430,0x00c3,0x9341,0x9800,0x836d,
	0xa086,0x446e,0x176d,0x8200,0x3305,0xa366,0x009a,0x57cc,
	0x8200,0x0107,0x41fa,0x2827,0xfb9f,0xc000,0x010f,0xbb9b,
	0x0113,0x3fcd,0xc400,0x091e,0x8fb1,0x017f,0x0fcf,0x2000,
	0x44d8,0x81f9,0xfb79,0x0f88,0x0000,0x00c1,0xfebb,0x224d,
	0xcf80,0x0200,0x00c1,0xf36a,0x26dd,0xad00,0x0200,0x00f1,
	0x9be1,0xf93f,0x0e4c,0x0000,0x0571,0x8133,0xba5f,0x1ee9,
	0x0400,0x0071,0xb323,0x3027,0x5cf7,0x8800,0x0040,0xbb53,
	0xf72e,0xe1f8,0x0000,0x0049,0xbe65,0xf144,0x3ef0,0x0000,
	0x000f,0x8f40,0xac82,0x3860,0x0000,0x0c0c,0xdf23,0x40d8,
	0x30c0,0x0000,0x0004,0xcfd5,0xc447,0xe180,0x0000,0x0004,
	0xa7d4,0x905c,0x0120,0x0000,0x0007,0xf7f9,0xf1fd,0x83c0,
	0x0000,0x0007,0xf930,0x9ff8,0x7c80,0x0000,
};

struct	Image	BlackHoleGadI1 = {
	0, 0,				/* Top Corner */
	71, 38, 2,			/* Width, Height, Depth */
	&BlackHoleGadData1[0],		/* Image Data */
	0x0003, 0x0000,			/* PlanePick,PlaneOnOff */
	NULL				/* Next Image */
};

struct	Image	BlackHoleGadI2 = {
	0, 0,				/* Top Corner */
	71, 38, 2,			/* Width, Height, Depth */
	&BlackHoleGadData2[0],		/* Image Data */
	0x0003, 0x0000,			/* PlanePick,PlaneOnOff */
	NULL				/* Next Image */
};

struct Gadget gad =
   {
   NULL,			/* Next Gadget		   */
   NULL,NULL,		/* Left Edge, Top Edge	   */
   71,38,			/* Width, Height	   */
   GFLG_GADGHIMAGE, /* Flags		   */
   NULL,            /* Activation  */
   NULL,			/* Gadget Type		   */
   (APTR)&BlackHoleGadI1,   /* Gadget Render	   */
   (APTR)&BlackHoleGadI2,   /* Select Render	   */
   NULL,                    /* Gadget Text		   */
   NULL,                    /* Mutual Exclude	   */
   NULL,                    /* Special Info		   */
   };

void main()
{
```c
    /* Automatic variables  */
    ULONG sig;
    struct DiskObject *dob = NULL;
    struct AppMessage *am;
    struct IntuiMessage *tim, im;
    struct FileInfoBlock *fib = NULL;
    BOOL alive = TRUE;

    if (!(IntuitionBase = (void *) OpenLibrary("intuition.library", 37)))
        fatal("Can't open Intuition.library");

    if (!(GfxBase = (void *) OpenLibrary("graphics.library", 37)))
        fatal("Can't open graphics.library");

    if (!(IconBase = (void *) OpenLibrary("icon.library", 37)))
        fatal("Can't open icon.library");

    if (!(WorkbenchBase = (void *) OpenLibrary("workbench.library", 37)))
        fatal("Can't open workbench.library");

    fib = (struct FileInfoBlock *) calloc(sizeof(*fib), 1);  /* allocate the FileInfoBlock */

    win = MakeWindow(&key);
    aport = (void *) CreatePort(NULL, 0);
    awin = (struct AppWindow *) AddAppWindow(0, win, win, aport, NULL);    /* setup appwindow */
    if (!win || !aport || !awin)
        fatal2("ADC: General Failure.", "Could be Low Memory condition.");

    /* setup disk object    */
    dob = (struct DiskObject *) calloc(sizeof(*dob), 1);
    dob->do_Magic = NULL;
    dob->do_Version = NULL;
    dob->do_Gadget = gad;
    dob->do_Type = NULL;
    dob->do_DefaultTool = NULL;
    dob->do_ToolTypes = NULL;
    dob->do_CurrentX = dob->do_CurrentY = NO_ICON_POSITION;
    dob->do_DrawerData = NULL;
    dob->do_ToolWindow = NULL;
    dob->do_StackSize = 0;

    if (!(aicon = (struct AppIcon *) AddAppIcon(NULL, NULL, "Application", aport, NULL, dob, TAG_END)))
        fatal("ADC: Could not create AppIcon");
    amenu[amicount++] = (void *) AddAppMenuItem(NULL, "Quit", "Quit AppDemo", aport, NULL);

    while (alive)
    {
        sig = (1 << aport->mp_SigBit) |
                ((win) ? (1 << win->UserPort->mp_SigBit) : NULL);
        sig = Wait(sig);

        /* App Messages   */
        if (sig & (1 << aport->mp_SigBit)) /* an app signal */
        {
            while (am = (struct AppMessage *) GetMsg(aport))
            {
                switch(am->am_Type)
                {
                case AMTYPE_APPWINDOW:   /* something was dropped in the window  */
                    ProcessIcon(win, am);
                    break;

                case AMTYPE_APPICON:     /* icon was double-clicked */
                    if (!am->am_NumArgs) /* Double-Clicked  */
                    {
                        if (!win) /* is our (app) window open? */
                        {
                            if (!(win = MakeWindow(&key)))
                            {
                                warning("ADC: Cannot open window!");
                                break;
                            }

                            if (!(awin = (struct AppWindow *) AddAppWindow(NULL, NULL, win, aport, NULL)))
                            {
                                warning("ADC: Cannot make window an AppWindow!");
                                CloseWindow(win); win = NULL;
                            }
                        }
                        WindowToFront(win);
                        ActivateWindow(win);
                        UpdateWindow(win);
                    }
                    else /* Icons dropped on AppIcon    */
                        ProcessIcon(win, am);

                    break;

                case AMTYPE_APPMENUITEM: /* menu item was selected */
                    if (!stricmp(am->am_UserData, "quit"))
                        alive = FALSE;

                    else /* we have something real */
                    {
                        SystemTags(am->am_UserData, SYS_Input, Open("nil:", MODE_NEWFILE),
                                                    SYS_Output, Open("CON:////Application_Output/CLOSE/AUTO/WAIT", MODE_NEWFILE),
                                                    SYS_Asynch, TRUE,
                                                    NP_StackSize, 30000,    /* Let's be generous    */
                                                    NP_Priority, 0,
                                                    NP_Cli, FALSE,
                                                    TAG_END, NULL);
                    }
                    break;

                default:
                    break;
                }
                ReplyMsg(am);
            }
        }

        /* Window Messages    */
        if (win && (sig & (1 << win->UserPort->mp_SigBit))) /* an IDCMP signal */
        {
            while (win && (tim = (struct IntuiMessage*) GetMsg(win->UserPort)))
            {
                im = *tim;
                ReplyMsg(tim);
                switch (im.Class)
                {
                case CLOSEWINDOW:
                    UpdateWindow(win);
                    RemoveAppWindow(awin); awin = NULL;
                    CloseWindow(win); win = NULL;
                    break;

                case NEWSIZE:
                case REFRESHWINDOW:
                    UpdateWindow(win);
                    break;

                default:
                    break;
                }
            }
        }
    }

    ShutDown();
```
}

void ProcessIcon(struct Window *win, struct AppMessage *am)
{
```c
    UBYTE buf[256], *name;  /* general work buffer & pointer */
    struct FileInfoBlock *fib = (struct FileInfoBlock *) calloc(1, sizeof(*fib));
    int i;

    if (fib)
    {
        for (i = 0; i < am->am_NumArgs; ++i)    /* until list exhausted */
        {
            if (am->am_ArgList[i].wa_Lock)
            {
                if (Examine(am->am_ArgList[i].wa_Lock, fib))
                {
                    if (!NameFromLock(am->am_ArgList[i].wa_Lock, buf, sizeof(buf)))
                        fatal("ADC: GetPath failed!!");

                    if (buf[strlen(buf)-1] != ':') /* do we need to add a slash?    */
                    {
                        buf[strlen(buf)+1] = NULL;
                        buf[strlen(buf)] = '/';
                    }

                    /* append name to path
                    */
                    if (amicount < ASIZE)
                    {
                        appName[amicount] = name = (char*) strdup(am->am_ArgList[i].wa_Name);
                        strcat(buf, am->am_ArgList[i].wa_Name);
                        amenu[amicount] = (struct AppMenu*) AddAppMenuItem(amicount, strdup(buf), name, aport, NULL);
                        ++amicount;
                    }
                    else
                        warning2("ADC: Array Overflow - Cannot add", am->am_ArgList[i].wa_Name);
                }
                else
                    warning2("ADCCant find directory for", am->am_ArgList[i].wa_Name);
            }
            else
                warning2("ADC: Entry Without Lock!!", am->am_ArgList[i].wa_Name);
        }
        UpdateWindow(win);

        free(fib);
    }
```
}

UBYTE *BSTRtoSTR(b)
ULONG b;
{
```c
    UBYTE *bstr, *str, *s;
    int c;

    bstr = BADDR(b);
    str = s = (UBYTE*) calloc(1, (c = *bstr++) + 1);
    while(c--)
        *s++ = *bstr++;

    return str;
```
}

void ShutDown()
{
```c
    int i;

    for (i = 0; i < amicount; ++i)
        if (!RemoveAppMenuItem(amenu[i]))
            warning("ADC: RemoveAppMenuItem failed!");
    amicount = 0;

    if (aicon)
    {
        if (!RemoveAppIcon(aicon))
            warning("ADC: RemoveAppIcon failed!");
        aicon = NULL;
    }

    if (awin)
    {
        if (!RemoveAppWindow(awin))
            warning("ADC: RemoveAppWindow Failed!");
        awin = NULL;
    }
    if (win)
        CloseWindow(win), win = NULL;

    if (aport)
        DeletePort(aport), aport = NULL;

    FreeRemember(&key, TRUE);

    if (GfxBase)        CloseLibrary(GfxBase),       GfxBase = NULL;
    if (IntuitionBase)  CloseLibrary(IntuitionBase), IntuitionBase = NULL;
    if (IconBase)       CloseLibrary(IconBase),      IconBase = NULL;
    if (WorkbenchBase)  CloseLibrary(WorkbenchBase), WorkbenchBase = NULL;

    exit(0);
```
}

struct NewWindow newwin = {

```c
    100, 100,   /* LeftEdge, TopEdge */
    300, 150,   /* Width, Height */
    1, 2,       /* DetailPen, BlockPen */
    CLOSEWINDOW | NEWSIZE | MOUSEBUTTONS | VANILLAKEY,  /* IDCMPFlags */
    WINDOWSIZING | WINDOWDRAG | WINDOWCLOSE | WINDOWDEPTH | SMART_REFRESH | GIMMEZEROZERO, /* Flags */
    NULL,       /* FirstGadget */
    NULL,       /* CheckMark */
    NULL,       /* Title */
    NULL,       /* Screen */
    NULL,       /* BitMap */
    50, 50, -1, -1, /* MinWidth, MinHeight, MaxWidth, MaxHeight */
    WBENCHSCREEN    /* Type */
    };
```
struct Window *MakeWindow(key) /* standard window creation */
struct Remember **key;
{
```c
    struct Window *win;

    if (win = (struct Window*) OpenWindow(&newwin))
        SetWindowTitles(win, "AppDemo", "Application Launcher by Fred Mitchell");

    return win;
```
}

void UpdateWindow(win)  /* display list of programs in window */
struct Window *win;
{
```c
    short height, i;

    if (win)
    {
        SetRast(win->RPort, 0);
        SetAPen(win->RPort, 1);
        SetDrMd(win->RPort, JAM1);
        height = win->RPort->Font->tf_YSize + 2;

        for (i = 1; i < amicount; ++i)
        {
            Move(win->RPort, 0, height * i);
            Text(win->RPort, appName[i], strlen(appName[i]));
        }

        /* update newwindow structure with new size/location    */
        newwin.LeftEdge = win->LeftEdge;
        newwin.TopEdge  = win->TopEdge;
        newwin.Width    = win->Width;
        newwin.Height   = win->Height;
    }
```
}

void FreePid(pid)   /* free the list of ProcessID's */
struct ProcID *pid;
{
```c
    if (pid->nextID)
        FreePid(pid->nextID);

    /* free(pid); ...*/
```
}

/* Warning and Fatal Routines   */

static int _GetResponse(struct Window *win)
{
```c
    int ret = (int) win;

    if ((BOOL) win != 0 && (BOOL) win != 1)
    {
        while ((ret = SysReqHandler(win, NULL, TRUE)) == -2)
            ;
        FreeSysRequest(win);
    }
    return ret;
```
}

void fatal(m)  /* Program bug detected - could be fatal! */
char *m;    /* message */
{
```c
    struct EasyStruct es;

    es.es_StructSize = sizeof(es);
    es.es_Flags = NULL;
    es.es_Title = "<FATAL ERROR>";
    es.es_TextFormat = "Fatal Error: %s";
    es.es_GadgetFormat = "OK";

    _GetResponse((struct Window*) BuildEasyRequest(NULL, &es, NULL, m));
    ShutDown();
```
}

void fatal2(m, n)  /* Program bug detected - could be fatal! */
char *m, *n;    /* message */
{
```c
    struct EasyStruct es;

    es.es_StructSize = sizeof(es);
    es.es_Flags = NULL;
    es.es_Title = "<FATAL ERROR>";
    es.es_TextFormat = "Fatal Error: %s\n%s";
    es.es_GadgetFormat = "OK";

    _GetResponse((struct Window*) BuildEasyRequest(NULL, &es, NULL, m, n));
    ShutDown();
```
}

void warning(m) /* Far less serious - non-fatal error */
char *m;    /* message */
{
```c
    struct EasyStruct es;

    es.es_StructSize = sizeof(es);
    es.es_Flags = NULL;
    es.es_Title = "Warning";
    es.es_TextFormat = "Error: %s";
    es.es_GadgetFormat = "Continue";

    _GetResponse((struct Window*) BuildEasyRequest(NULL, &es, NULL, m));
```
}

void warning2(m, n) /* Far less serious - non-fatal error */
char *m, *n;    /* messages */
{
```c
    struct EasyStruct es;

    es.es_StructSize = sizeof(es);
    es.es_Flags = NULL;
    es.es_Title = "Warning";
    es.es_TextFormat = "Error: %s\n%s";
    es.es_GadgetFormat = "Continue";

    _GetResponse((struct Window*) BuildEasyRequest(NULL, &es, NULL, m, n));
```
}

