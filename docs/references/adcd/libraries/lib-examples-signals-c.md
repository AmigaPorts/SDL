---
title: Lib_examples/signals.c
manual: libraries
chapter: libraries
section: lib-examples-signals-c
functions: [Forbid, Permit]
libraries: [exec.library]
---

# Lib_examples/signals.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* signals.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 signals.c
Blink FROM LIB:c.o,signals.o TO signals LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
*/

#include <exec/types.h>
#include <exec/memory.h>
#include <dos/dos.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/alib_protos.h>
#include "stdio.h"

#ifdef LATTICE
int CXBRK(void) { return(0); }     /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

static UBYTE *VersTag = "$VER: signals 37.1 (28.3.91)";

void subtaskcode(void);    /* prototype for our subtask routine */

LONG  mainsignum = -1;
ULONG mainsig, wakeupsigs;
struct Task *maintask = NULL, *subtask = NULL;
UBYTE subtaskname[] = "RKM_signal_subtask";

void main(int argc, char **argv)
{
BOOL Done = FALSE, WaitingForSubtask = TRUE;

/* We must allocate any special signals we want to receive. */
mainsignum = AllocSignal(-1);
if(mainsignum == -1)
```c
    printf("No signals available\n");
```
else
```c
    {
    mainsig = 1L << mainsignum;    /* subtask can access this global */
    maintask = FindTask(NULL);     /* subtask can access this global */

    printf("We alloc a signal, create a task, wait for signals\n");
    subtask = CreateTask(subtaskname, 0L, subtaskcode, 2000);
    if(!subtask)
        printf("Can't create subtask\n");
    else
        {
        printf("After subtask signals, press CTRL-C or CTRL-D to exit\n");

        while((!Done)||(WaitingForSubtask))
            {
            /* Wait on the combined mask for all of the signals we are
             * interested in.  All processes have the CTRL_C thru CTRL_F
             * signals.  We're also Waiting on the mainsig we allocated
             * for our subtask to signal us with.  We could also Wait on
             * the signals of any ports/windows our main task created ... */

            wakeupsigs = Wait(mainsig | SIGBREAKF_CTRL_C | SIGBREAKF_CTRL_D);

            /* Deal with all signals that woke us up - may be more than one */
            if(wakeupsigs & mainsig)
                {
                printf("Signalled by subtask\n");
                WaitingForSubtask = FALSE;   /* OK to kill subtask now */
                }
            if(wakeupsigs & SIGBREAKF_CTRL_C)
                {
                printf("Got CTRL-C signal\n");
                Done = TRUE;
                }
            if(wakeupsigs & SIGBREAKF_CTRL_D)
                {
                printf("Got CTRL-D signal\n");
                Done = TRUE;
                }
            }
        Forbid();
        DeleteTask(subtask);
        Permit();
        }
    FreeSignal(mainsignum);
    }
```
}

void subtaskcode(void)

```c
    {
    Signal(maintask,mainsig);
    Wait(0L);    /* safe state in which this subtask can be deleted */
    }
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
