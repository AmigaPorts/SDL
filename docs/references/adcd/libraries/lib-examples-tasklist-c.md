---
title: Lib_examples/tasklist.c
manual: libraries
chapter: libraries
section: lib-examples-tasklist-c
functions: [Disable, Enable]
libraries: [exec.library]
---

# Lib_examples/tasklist.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* tasklist.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 tasklist.c
Blink FROM LIB:c.o,tasklist.o TO tasklist LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit

tasklist.c - Snapshots and prints the ExecBase task list
*/
#include <exec/types.h>
#include <exec/lists.h>
#include <exec/nodes.h>
#include <exec/memory.h>
#include <exec/execbase.h>

#include <clib/alib_protos.h>
#include <clib/exec_protos.h>

#include <stdio.h>
#include <string.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }   /* disable SAS/C CTRL-C handing */
int chkabort(void) {return(0); }
#endif

static UBYTE *VersTag = "$VER: tasklist 37.2 (31.3.92)";
extern struct ExecBase *SysBase;

/* Use extended structure to hold task information */
struct TaskNode {
```c
    struct Node tn_Node;
    ULONG tn_TaskAddress;
    ULONG tn_SigAlloc;
    ULONG tn_SigWait;
    UBYTE tn_Name[32];
```
};




void main(int argc, char **argv)
{
```c
    struct List *ourtasklist;
    struct List *exectasklist;
    struct Task *task;
    struct TaskNode *node, *tnode, *rnode = NULL;
    struct Node *execnode;

    /* Allocate memory for our list */
    if (ourtasklist = AllocMem(sizeof(struct List), MEMF_CLEAR)) {
        /* Initialize list structure (ala NewList()) */
        ourtasklist->lh_Head = (struct Node *)&ourtasklist->lh_Tail;
        ourtasklist->lh_Tail = 0;
        ourtasklist->lh_TailPred = (struct Node *)&ourtasklist->lh_Head;

        /* Make sure tasks won't switch lists or go away */
        Disable();

        /* Snapshot task WAIT list */
        exectasklist = &(SysBase->TaskWait);
        for (execnode = exectasklist->lh_Head;
                 execnode->ln_Succ; execnode = execnode->ln_Succ)
        {
            if (tnode = AllocMem(sizeof(struct TaskNode), MEMF_CLEAR))
            {
                /* Save task information we want to print */
                strncpy(tnode->tn_Name, execnode->ln_Name, 32);
                tnode->tn_Node.ln_Pri = execnode->ln_Pri;
                tnode->tn_TaskAddress = (ULONG)execnode;
                tnode->tn_SigAlloc = ((struct Task *)execnode)->tc_SigAlloc;
                tnode->tn_SigWait = ((struct Task*)execnode)->tc_SigWait;
                AddTail(ourtasklist, (struct Node *)tnode);
            }
            else break;
        }

        /* Snapshot task READY list */
        exectasklist = &(SysBase->TaskReady);
        for (execnode = exectasklist->lh_Head;
                 execnode->ln_Succ; execnode = execnode->ln_Succ)
        {
            if (tnode = AllocMem(sizeof(struct TaskNode), MEMF_CLEAR))
            {
                /* Save task information we want to print */
                strncpy(tnode->tn_Name, execnode->ln_Name, 32);
                tnode->tn_Node.ln_Pri = execnode->ln_Pri;
                tnode->tn_TaskAddress = (ULONG)execnode;
                tnode->tn_SigAlloc = ((struct Task *)execnode)->tc_SigAlloc;
                tnode->tn_SigWait = ((struct Task*)execnode)->tc_SigWait;
                AddTail(ourtasklist, (struct Node *)tnode);
                if(!rnode)  rnode = tnode;  /* first READY task */
            }
            else
                break;
        }

        /* Re-enable interrupts and taskswitching */
        Enable();

        /* Print now (printing above would have defeated a Forbid or Disable) */
        printf("Pri Address     SigAlloc    SigWait    Taskname\n");

        node = (struct TaskNode *)(ourtasklist->lh_Head);
        printf("\nWAITING:\n");
        while (tnode = (struct TaskNode *)node->tn_Node.ln_Succ)
        {
            if(tnode == rnode)
                printf("\nREADY:\n");  /* we set rnode above */
            printf("%02d  0x%08lx  0x%08lx  0x%08lx %s\n",
                    node->tn_Node.ln_Pri, node->tn_TaskAddress, node->tn_SigAlloc,
                    node->tn_SigWait, node->tn_Name);

            /* Free the memory, no need to remove the node, referenced once only */
            FreeMem(node,sizeof(struct TaskNode));
            node = tnode;
        }
        FreeMem(ourtasklist, sizeof(struct List));

        /* Say who we are */
        printf("\nTHIS TASK:\n");
        task = FindTask(NULL);
        printf("%02d  0x%08lx  0x%08lx  0x%08lx %s\n",
                task->tc_Node.ln_Pri, task, task->tc_SigAlloc,
                task->tc_SigWait, task->tc_Node.ln_Name);

    }
```
}

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Enable — exec.library](../autodocs/exec.library.md#enable)
