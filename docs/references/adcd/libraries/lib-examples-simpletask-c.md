---
title: Lib_examples/simpletask.c
manual: libraries
chapter: libraries
section: lib-examples-simpletask-c
functions: [Forbid, Permit, RemTask]
libraries: [exec.library]
---

# Lib_examples/simpletask.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* simpletask.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 simpletask.c
Blink FROM LIB:c.o,simpletask.o TO simpletask LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit

simpletask.c - Uses the amiga.lib function CreateTask() to create a simple
subtask.  See the Includes and Autodocs manual for CreateTask() source code
*/
#include <exec/types.h>
#include <exec/memory.h>
#include <exec/tasks.h>
#include <libraries/dos.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>

#include <stdlib.h>
#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }   /* Disable Lattice CTRL/C handling */
int chkabort(void) {return(0);}
#endif

#define STACK_SIZE 1000L

/* Task name, pointers for allocated task struct and stack */
struct Task *task = NULL;
char *simpletaskname = "SimpleTask";

ULONG sharedvar;

/* our function prototypes */
void simpletask(void);
void cleanexit(UBYTE *,LONG);

void main(int argc,char **argv)
{
```c
    sharedvar = 0L;

    task = CreateTask(simpletaskname,0,simpletask,STACK_SIZE);
    if(!task)  cleanexit("Can't create task",RETURN_FAIL);

    printf("This program initialized a variable to zero, then started a\n");
    printf("separate task which is incrementing that variable right now,\n");
    printf("while this program waits for you to press RETURN.\n");
    printf("Press RETURN now: ");
    getchar();

    printf("The shared variable now equals %ld\n",sharedvar);

    /* We can simply remove the task we added because our simpletask does not make */
    /* any system calls which could cause it to be awakened or signalled later.    */
    Forbid();
    DeleteTask(task);
    Permit();
    cleanexit("",RETURN_OK);
```
}

void simpletask()
{
```c
    while(sharedvar < 0x8000000) sharedvar++;
    /* Wait forever because main() is going to RemTask() us */
    Wait(0L);
```
}

void cleanexit(UBYTE *s, LONG e)
{
```c
    if(*s) printf("%s\n",s);
    exit(e);
```
}

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [RemTask — exec.library](../autodocs/exec.library.md#remtask)
