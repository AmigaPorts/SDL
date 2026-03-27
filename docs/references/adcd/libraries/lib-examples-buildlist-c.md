---
title: Lib_examples/buildlist.c
manual: libraries
chapter: libraries
section: lib-examples-buildlist-c
functions: []
libraries: []
---

# Lib_examples/buildlist.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* buildlist.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 buildlist.c
Blink FROM LIB:c.o,buildlist.o TO buildlist LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit

** The code below demonstrates the concepts and functions discussed in this
** chapter by building an application-defined Exec List.
**
** buildlist.c - example which uses an application-specific Exec list
*/

#include <exec/types.h>
#include <exec/lists.h>
#include <exec/nodes.h>
#include <exec/memory.h>

#include <clib/alib_protos.h>
#include <clib/exec_protos.h>

#include <string.h>
#include <stdio.h>

#ifdef LATTICE
int CXBRK(void)  { return(0); }  /* Disable Lattice CTRL/C handling */
void chkabort(void) { return; }  /* really */
#endif

/* Our function prototypes */
VOID AddName(struct List *, UBYTE *);
VOID FreeNameNodes(struct List *);
VOID DisplayNameList(struct List *);
VOID DisplayName(struct List *, UBYTE *);

struct NameNode {
```c
    struct Node nn_Node;        /* System Node structure */
    UBYTE  nn_Data[62];         /* Node-specific data */
```
};

#define NAMENODE_ID   100       /* The type of "NameNode" */

VOID main(VOID)
{
```c
    struct  List    *NameList;    /* Note that a MinList would also work */

    if (!( NameList = AllocMem(sizeof(struct List),MEMF_CLEAR)) )
        printf("Out of memory\n");
    else {
        NewList(NameList);        /* Important: prepare header for use */

        AddName(NameList,"Name7");   AddName(NameList,"Name6");
        AddName(NameList,"Name5");   AddName(NameList,"Name4");
        AddName(NameList,"Name2");   AddName(NameList,"Name0");

        AddName(NameList,"Name7");   AddName(NameList,"Name5");
        AddName(NameList,"Name3");   AddName(NameList,"Name1");

        DisplayName(NameList,"Name5");
        DisplayNameList(NameList);

        FreeNameNodes(NameList);
        FreeMem(NameList,sizeof(struct List));  /* Free list header */
    }
```
}

/* Allocate a NameNode structure, copy the given name into the structure,
 * then add it the specified list.  This example does not provide an
 * error return for the out of memory condition.
*/
VOID AddName(struct List *list, UBYTE *name)
{
```c
    struct NameNode *namenode;

    if (!( namenode = AllocMem(sizeof(struct NameNode),MEMF_CLEAR) ))
        printf("Out of memory\n");
    else {
        strcpy(namenode->nn_Data,name);
        namenode->nn_Node.ln_Name = namenode->nn_Data;
        namenode->nn_Node.ln_Type = NAMENODE_ID;
        namenode->nn_Node.ln_Pri  = 0;
        AddHead((struct List *)list,(struct Node *)namenode);
    }
```
}

/*
 * Free the entire list, including the header.  The header is not updated
 * as the list is freed.  This function demonstrates how to avoid
 * referencing freed memory when deallocating nodes.
 */
VOID FreeNameNodes(struct List *list)
{

```c
    struct NameNode *worknode;
    struct NameNode *nextnode;

    worknode = (struct NameNode *)(list->lh_Head); /* First node */
    while (nextnode = (struct NameNode *)(worknode->nn_Node.ln_Succ)) {
        FreeMem(worknode,sizeof(struct NameNode));
        worknode = nextnode;
    }
```
}

/*
 * Print the names of each node in a list.
 */
VOID DisplayNameList(struct List *list)
{
struct Node *node;

```c
    if (list->lh_TailPred == (struct Node *)list)
        printf("List is empty.\n");
    else {
        for (node = list->lh_Head ; node->ln_Succ ; node = node->ln_Succ)
            printf("%lx -> %s\n",node,node->ln_Name);
    }
```
}

/*
 * Print the location of all nodes with a specified name.
 */
VOID DisplayName(struct List *list, UBYTE *name)
{
struct Node *node;

```c
    if (node = FindName(list,name)) {
        while (node) {
            printf("Found a %s at location %lx\n",node->ln_Name,node);
            node = FindName((struct List *)node,name);
        }
    } else printf("No node with name %s found.\n",name);
```
}

