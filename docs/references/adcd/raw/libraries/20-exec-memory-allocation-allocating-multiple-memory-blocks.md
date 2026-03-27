# 20 Exec Memory Allocation / Allocating Multiple Memory Blocks


Exec provides the routines [AllocEntry()](../Includes_and_Autodocs_2._guide/node0331.html) and [FreeEntry()](../Libraries_Manual_guide/node02B2.html#line5) to allocate
multiple memory blocks in a single call. AllocEntry() accepts a data
structure called a MemList, which contains the information about the size
of the memory blocks to be allocated and the requirements, if any, that
you have regarding the allocation. The MemList structure is found in the
include file <exec/[memory.h](../Includes_and_Autodocs_2._guide/node0089.html#line54)> and is defined as follows:


```c
    struct MemList
    {
        struct Node     ml_Node;
        UWORD           ml_NumEntries;      /* number of MemEntrys */
        struct MemEntry ml_ME[1];           /* where the MemEntrys begin*/
    };
```
Node

```c
    allows you to link together multiple MemLists.  However, the node is
    ignored by the routines [AllocEntry()](../Includes_and_Autodocs_2._guide/node0331.html) and [FreeEntry()](../Libraries_Manual_guide/node02B2.html#line5).
```
ml_NumEntries

    tells the system how many MemEntry sets are contained in this
    MemList.  Notice that a MemList is a variable-length structure and
    can contain as many sets of entries as you wish.
The [MemEntry](../Includes_and_Autodocs_2._guide/node0089.html#line39) structure looks like this:


```c
    struct MemEntry
    {
        union {
            ULONG   meu_Reqs;   /* the AllocMem requirements */
            APTR    meu_Addr;   /* address of your memory */
            } me_Un;
        ULONG   me_Length;      /* the size of this request */
    };
```
 [Sample Code for Allocating Multiple Memory Blocks](../Libraries_Manual_guide/node02B2.html) 
 [Result of Allocating Multiple Memory Blocks](../Libraries_Manual_guide/node02B3.html) 
 [Multiple Memory Blocks and Tasks](../Libraries_Manual_guide/node02B4.html) 
 [Summary of Multiple Memory Blocks Allocation Routines](../Libraries_Manual_guide/node02B5.html) 

