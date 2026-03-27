# 21 Exec Tasks / Task Structure


Exec maintains task context and state information in a task-control data
structure. Like most Exec structures, Task structures are dynamically
linked onto various task queues through the use of an embedded Exec list
[Node](../Libraries_Manual_guide/node02D9.html#line19) structure (see the "[Exec Lists and Queues](../Libraries_Manual_guide/node02D9.html)" chapter).  Any task can
find its own task structure by calling [FindTask](../Libraries_Manual_guide/node02D0.html#line5)(NULL).  The C-language
form of this structure is defined in the <exec/[tasks.h](../Includes_and_Autodocs_2._guide/node008E.html#line23)> include file:


```c
    struct Task  {
        struct Node tc_Node;
        UBYTE       tc_Flags;
        UBYTE       tc_State;
        BYTE        tc_IDNestCnt;   /* intr disabled nesting */
        BYTE        tc_TDNestCnt;   /* task disabled nesting */
        ULONG       tc_SigAlloc;    /* sigs allocated */
        ULONG       tc_SigWait;     /* sigs we are waiting for */
        ULONG       tc_SigRecvd;    /* sigs we have received */
        ULONG       tc_SigExcept;   /* sigs we will take excepts for */
        UWORD       tc_TrapAlloc;   /* traps allocated */
        UWORD       tc_TrapAble;    /* traps enabled */
        APTR        tc_ExceptData;  /* points to except data */
        APTR        tc_ExceptCode;  /* points to except code */
        APTR        tc_TrapData;    /* points to trap code */
        APTR        tc_TrapCode;    /* points to trap data */
        APTR        tc_SPReg;       /* stack pointer */
        APTR        tc_SPLower;     /* stack lower bound */
        APTR        tc_SPUpper;     /* stack upper bound + 2*/
        VOID      (*tc_Switch)();   /* task losing CPU */
        VOID      (*tc_Launch)();   /* task getting CPU */
        struct List tc_MemEntry;    /* allocated memory */
        APTR        tc_UserData;    /* per task data */
    };
```
A similar assembly code structure is available in the <exec/[tasks.i](../Includes_and_Autodocs_2._guide/node0092.html#line27)>
include file.

Most of these fields are not relevant for simple tasks; they are used by
Exec for state and administrative purposes.  A few fields, however, are
provided for the advanced programs that support higher level environments
(as in the case of processes) or require precise control (as in devices).
The following sections explain these fields in more detail.

