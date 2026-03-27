---
title: Lib_examples/pubscreenbeep.c
manual: libraries
chapter: libraries
section: lib-examples-pubscreenbeep-c
functions: [GetScreenData]
libraries: [intuition.library]
---

# Lib_examples/pubscreenbeep.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* pubscreenbeep.c - Execute me to compile me with SAS 5.10
LC -b1 -cfistq -v -y -j73 pubscreenbeep.c
blink LIB:c.o pubscreenbeep.o TO pubscreenbeep LIB LIB:lc.lib LIB:amiga.lib
quit
*/

#include <exec/types.h>               /* Amiga data types.               */
#include <exec/libraries.h>
#include <intuition/intuition.h>      /* Lots of important Intuition     */
#include <intuition/screens.h>        /* structures we will be using.    */

#include <clib/exec_protos.h>         /* Function prototypes             */
#include <clib/intuition_protos.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }     /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }     /* really */
#endif

struct Library *IntuitionBase;        /* Intuition library base           */

/* Simple example of how to find a public screen to work with in Release 2.
 */

VOID main(int argc, char **argv)
{
struct Screen  *my_wbscreen_ptr;     /* Pointer to the Workbench screen */

/* Open the library before you call any functions */
IntuitionBase = OpenLibrary("intuition.library",0);
if (NULL != IntuitionBase)
   {
   if(IntuitionBase->lib_Version>=36)
```c
      {
      /* OK, we have the right version of the OS so we can use
      ** the new public screen functions of Release 2 (V36)
      */
      if(NULL!=(my_wbscreen_ptr=LockPubScreen("Workbench")))
          {
          /* OK found the Workbench screen.                      */
          /* Normally the program would be here.  A window could */
          /* be opened or the attributes of the screen copied    */
          DisplayBeep(my_wbscreen_ptr);

          UnlockPubScreen(NULL,my_wbscreen_ptr);
          }
      }
```
   else
```c
      {
      /* Prior to Release 2 (V36), there were no public screens,     */
      /* just Workbench.  In those older systems, windows can be     */
      /* opened on Workbench without locking or a pointer by setting */
      /* the Type=WBENCHSCREEN in struct NewWindow.  Attributes can  */
      /* be obtained by setting the Type argument to WBENCHSCREEN in */
      /* the call to GetScreenData().                                */
      }
```
   CloseLibrary(IntuitionBase);
   }
}

---

## See Also

- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
