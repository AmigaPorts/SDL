---
title: Lib_examples/appmenuitem.c
manual: libraries
chapter: libraries
section: lib-examples-appmenuitem-c
functions: [CreateMsgPort]
libraries: [exec.library]
---

# Lib_examples/appmenuitem.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* This example shows how to create an AppMenuItem.  The example adds a
 * menu item named "Browse Files" to the Workbench Tools menu.  (All
 * AppMenuItems appear in the Workbench Tools menu.)  When the menu item
 * is activated, the example program receives a message from Workbench
 * and then attempts to start up an instance of the More program. (The
 * More program is in the Utilities directory of the Workbench disk.)
 *
 * The example starts up the More program as a separate, asynchronous
 * process using the new SystemTags() function of Release 2 AmigaDOS.
 * For more about the SystemTags() function refer to the AmigaDOS
 * Manual, 3rd Edition from Bantam Books.  When the AppMenuItem has been
 * activated five times, the program exits after freeing any system
 * resources it has used.
 */

/* appmenuitem.c - Compiled under SAS C 5.10 with lc -L appmenuitem.c       */
/* Requires Kickstart version 37 or later.  Works from the Shell (CLI) only */

#include <exec/types.h>          /* Need this for the Amiga variable types  */
#include <workbench/workbench.h> /* This has DiskObject and AppIcon structs */
#include <workbench/startup.h>   /* This has WBStartup and WBArg structs    */
#include <exec/libraries.h>
#include <dos/dostags.h>
#include <stdio.h>
#include <clib/dos_protos.h>
#include <clib/exec_protos.h>    /* Exec message, port and library functions*/
#include <clib/wb_protos.h>      /* AppMenuItem function protos             */

#ifdef LATTICE
int CXBRK(void) { return(0); }   /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }/* really */
#endif

extern struct Library *SysBase;
struct Library *WorkbenchBase;

void main(int argc, char **argv)
{
struct MsgPort      *myport=NULL;
struct AppMenuItem *appitem=NULL;
struct AppMessage   *appmsg=NULL;
LONG result, x, count=0L;
BOOL success=0L;
BPTR file;

if (WorkbenchBase = OpenLibrary("workbench.library",37))
  {
  /* The CreateMsgPort() function is in Exec version 37 and later only */
  if(myport = CreateMsgPort())
```c
    {
    /* Add our own AppMenuItem to the Workbench Tools Menu */
    appitem=AddAppMenuItemA(0L,                   /* Our ID# for item */
                    (ULONG)"SYS:Utilities/More",  /* Our UserData     */
                           "Browse Files",        /* MenuItem Text    */
                            myport,NULL);         /* MsgPort, no tags */
    if(appitem)
      {
      printf("Select Workbench Tools demo menuitem 'Browse Files'\n");

      /* For this example, we allow the AppMenuItem to be selected */
      /* only once, then we remove it and exit                     */
      WaitPort(myport);
      while((appmsg=(struct AppMessage *)GetMsg(myport)) && (count<1))
        {
        /* Handle messages from the AppMenuItem - we have only one  */
        /* item so we don't have to check its appmsg->am_ID number. */
        /* We'll System() the command string that we passed as      */
        /* userdata when we added the menu item.                    */
        /* We find our userdata pointer in appmsg->am_UserData      */

        printf("User picked AppMenuItem with %ld icons selected\n",
                                                appmsg->am_NumArgs);
        for(x=0;x<appmsg->am_NumArgs;x++)
           printf("  #%ld name='%s'\n",x+1,appmsg->am_ArgList[x].wa_Name);

        count++;
        if( file=Open("CON:0/40/640/150/AppMenu Example/auto/close/wait",
                         MODE_OLDFILE)  )     /* for any stdio output */
          {
          result=SystemTags((UBYTE *)appmsg->am_UserData,SYS_Input,file,
                                                         SYS_Output,NULL,
                                                         SYS_Asynch,TRUE,
                                                         TAG_DONE);
          /* If Asynch System() itself fails, we must close file */
          if(result == -1) Close(file);
          }
        ReplyMsg((struct Message *)appmsg);
        }
      success=RemoveAppMenuItem(appitem);
      }

    /* Clear away any messages that arrived at the last moment */
    /* and let Workbench know we're done with the messages     */
    while(appmsg=(struct AppMessage *)GetMsg(myport))
      {
      ReplyMsg((struct Message *)appmsg);
      }
    DeleteMsgPort(myport);
    }
```
  CloseLibrary(WorkbenchBase);
  }
}

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
