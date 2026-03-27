---
title: Lib_examples/appwindow.c
manual: libraries
chapter: libraries
section: lib-examples-appwindow-c
functions: [CreateMsgPort]
libraries: [exec.library]
---

# Lib_examples/appwindow.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* This example shows how to create an AppWindow and obtain arguments
 * from Workbench when the user drops an icon into it.  The AppWindow
 * will appear on the Workbench screen with the name "AppWindow" and
 * will run until the window's close gadget is selected.  If any icons
 * are dropped into the AppWindow, the program prints their arguments in
 * the Shell window.
 */

/* appwindow.c - Compiled under SAS C 5.10 with lc -L appwindow.c           */
/* Requires Kickstart version 37 or later.  Works from the Shell (CLI) only */

#include <exec/types.h>          /* Need this for the Amiga variable types  */
#include <workbench/workbench.h> /* This has DiskObject and AppWindow       */
#include <workbench/startup.h>   /* This has WBStartup and WBArg structs    */
#include <exec/libraries.h>      /* Need this to check library versions     */

#include <stdio.h>

#include <clib/intuition_protos.h>
#include <clib/exec_protos.h>
#include <clib/wb_protos.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }   /* Disable SAS Lattice CTRL/C handling */
int chkabort(void) { return(0); }/* really */
#endif

struct Library      *IntuitionBase;
struct Library      *WorkbenchBase;

void main(int argc, char **argv)
{
  struct MsgPort *awport;
  struct Window  *win;
  struct AppWindow *appwin;
  struct IntuiMessage *imsg;
  struct AppMessage *amsg;
  struct WBArg   *argptr;

  ULONG           winsig, appwinsig, signals, id = 1, userdata = 0;
  BOOL            done = FALSE;
  int             i;

  if (IntuitionBase = OpenLibrary("intuition.library", 37))
```c
    {
    if (WorkbenchBase = OpenLibrary("workbench.library", 37))
      {
      /* The CreateMsgPort() function is in Exec version 37 and later only */
      if (awport = CreateMsgPort())
         {
         if (win = OpenWindowTags(NULL,
                                  WA_Width, 200,        WA_Height, 50,
                                  WA_IDCMP, CLOSEWINDOW,
                                  WA_Flags, WINDOWCLOSE | WINDOWDRAG,
                                  WA_Title, "AppWindow",
                                  TAG_DONE))
          {
          if (appwin = AddAppWindow(id, userdata, win, awport, NULL))
            {
            printf("AppWindow added... Drag files into AppWindow\n");
            winsig    = 1L << win->UserPort->mp_SigBit;
            appwinsig = 1L << awport->mp_SigBit;

            while (! done)
              {
              /* Wait for IDCMP messages and AppMessages */
              signals = Wait( winsig | appwinsig );

              if(signals & winsig)      /* Got an IDCMP message */
                {
                while (imsg = (struct IntuiMessage *) GetMsg(win->UserPort))
                  {
                  if (imsg->Class = CLOSEWINDOW)   done = TRUE;
                  ReplyMsg((struct Message *) imsg);
                  }
                }
              if(signals & appwinsig)   /* Got an AppMessage */
                {
                while (amsg = (struct AppMessage *) GetMsg(awport))
                  {
                  printf("AppMsg: Type=%ld, ID=%ld, NumArgs=%ld\n",
                           amsg->am_Type, amsg->am_ID, amsg->am_NumArgs);
                  argptr = amsg->am_ArgList;
                  for (i = 0; i < amsg->am_NumArgs; i++)
                    {
                    printf("   arg(%ld): Name='%s', Lock=%lx\n",
                             i, argptr->wa_Name, argptr->wa_Lock);
                    argptr++;
                    }
                  ReplyMsg((struct Message *) amsg);
                  }
                }
              }     /* done */
            RemoveAppWindow(appwin);
            }
          CloseWindow(win);
```
	  }
```c
        /* Make sure there are no more outstanding messages */
        while(amsg = (struct AppMessage *)GetMsg(awport))
              ReplyMsg((struct Message *)amsg);
        DeleteMsgPort(awport);
        }
      CloseLibrary(WorkbenchBase);
      }
    CloseLibrary(IntuitionBase);
    }
```
}

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
