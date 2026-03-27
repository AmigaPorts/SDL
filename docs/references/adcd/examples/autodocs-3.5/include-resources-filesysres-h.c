/* Source: ADCD 2.1
 * Section: include-resources-filesysres-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-resources-filesysres-h.md
 */

    ULONG   fse_Type;		/* device node type: zero */
    CPTR    fse_Task;		/* standard dos "task" field */
    BPTR    fse_Lock;		/* not used for devices: zero */
    BSTR    fse_Handler;	/* filename to loadseg (if SegList is null) */
    ULONG   fse_StackSize;	/* stacksize to use when starting task */
    LONG    fse_Priority;	/* task priority when starting task */
    BPTR    fse_Startup;	/* startup msg: FileSysStartupMsg for disks */
    BPTR    fse_SegList;	/* code to run to start new task */
    BPTR    fse_GlobalVec;	/* BCPL global vector when starting task */
    /* no more entries need exist than those implied by fse_PatchFlags */
