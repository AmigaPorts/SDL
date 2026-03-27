/* Source: ADCD 2.1
 * Section: 21-exec-tasks-task-structure
 * Library: libraries
 * ADCD reference: libraries/21-exec-tasks-task-structure.md
 */

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
