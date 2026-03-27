---
title: Lib_examples/appicon.c
manual: libraries
chapter: libraries
section: lib-examples-appicon-c
functions: [CreateMsgPort, GetDefDiskObject]
libraries: [exec.library, icon.library]
---

# Lib_examples/appicon.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* The example listed here shows how to create an AppIcon and obtain
 * arguments from Workbench when the user drops other icons on top of
 * it. The AppIcon will appear as a disk icon named "TestAppIcon" on the
 * Workbench screen.  (All AppIcons appear on the Workbench screen or
 * window.)
 *
 * For convenience, this example code uses GetDefDiskObject() to create
 * the icon imagery for the AppIcon.  Applications should never do this.
 * Use your own custom imagery for AppIcons instead.
 */

/* appicon.c - Compiled under SAS C 5.10 with lc -L appicon.c               */
/* Requires Kickstart version 37 or later.  Works from the Shell (CLI) only */

#include <exec/types.h>          /* Need this for the Amiga variable types  */
#include <workbench/workbench.h> /* This has DiskObject and AppIcon structs */
#include <workbench/startup.h>   /* This has WBStartup and WBArg structs    */
#include <exec/libraries.h>      /* Need this to check library versions     */

#include <clib/icon_protos.h>    /* Icon (DiskObject) function prototypes   */
#include <clib/exec_protos.h>    /* Exec message, port and library functions*/
#include <clib/wb_protos.h>      /* AppIcon function protos                 */

#ifdef LATTICE
int CXBRK(void) { return(0); }   /* Disable SAS Lattice CTRL/C handling */
int chkabort(void) { return(0); }/* really */
#endif

extern struct Library *SysBase;
struct Library *IconBase;
struct Library *WorkbenchBase;

void main(int argc, char **argv)
{
struct DiskObject   *dobj=NULL;
struct MsgPort    *myport=NULL;
struct AppIcon   *appicon=NULL;
struct AppMessage *appmsg=NULL;

LONG dropcount=0L;
ULONG x;
BOOL success=0L;

/* Get the the right version of the Icon Library, initialize IconBase */
if(IconBase = OpenLibrary("icon.library",37))
  {
  /* Get the the right version of the Workbench Library */
  if (WorkbenchBase=OpenLibrary("workbench.library",37))
```c
    {
    /* This is the easy way to get some icon imagery */
    /* Real applications should use custom imagery   */
    dobj=GetDefDiskObject(WBDISK);
    if(dobj!=0)
      {
      /* The type must be set to NULL for a WBAPPICON */
      dobj->do_Type=NULL;

      /* The CreateMsgPort() function is in Exec version 37 and later only */
      myport=CreateMsgPort();
      if(myport)
        {
        /* Put the AppIcon up on the Workbench window */
        appicon=AddAppIconA(0L,0L,"TestAppIcon",myport,NULL,dobj,NULL);
        if(appicon)
          {
          /* For the sake of this example, we allow the AppIcon */
          /* to be activated only five times.                   */
          printf("Drop files on the Workbench AppIcon\n");
          printf("Example exits after 5 drops\n");

          while(dropcount<5)
            {
            /* Here's the main event loop where we wait for */
            /* messages to show up from the AppIcon         */
            WaitPort(myport);

            /* Might be more than one message at the port... */
            while(appmsg=(struct AppMessage *)GetMsg(myport))
              {
              if(appmsg->am_NumArgs==0L)
                {
                /* If NumArgs is 0 the AppIcon was activated directly */
                printf("User activated the AppIcon.\n");
                printf("A Help window for the user would be good here\n");
                }
              else if(appmsg->am_NumArgs>0L)
                {
                /* If NumArgs is >0 the AppIcon was activated by */
                /* having one or more icons dropped on top of it */
                printf("User dropped %ld icons on the AppIcon\n",
                                              appmsg->am_NumArgs);
                for(x=0;x<appmsg->am_NumArgs;x++)
                  {
                  printf("#%ld name='%s'\n",x+1,appmsg->am_ArgList[x].wa_Name);
                  }
                }
              /* Let Workbench know we're done with the message */
              ReplyMsg((struct Message *)appmsg);
              }
            dropcount++;
            }
          success=RemoveAppIcon(appicon);
          }
        /* Clear away any messages that arrived at the last moment */
        while(appmsg=(struct AppMessage *)GetMsg(myport))
            ReplyMsg((struct Message *)appmsg);
        DeleteMsgPort(myport);
        }
      FreeDiskObject(dobj);
      }
    CloseLibrary(WorkbenchBase);
    }
```
  CloseLibrary(IconBase);
  }
}

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [GetDefDiskObject — icon.library](../autodocs/icon.library.md#getdefdiskobject)
