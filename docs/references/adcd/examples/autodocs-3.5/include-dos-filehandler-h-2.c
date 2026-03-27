/* Source: ADCD 2.1
 * Section: include-dos-filehandler-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-dos-filehandler-h.md
 */

    BPTR	dn_Lock;	/* not used for devices -- leave null */
    BSTR	dn_Handler;	/* filename to loadseg (if seglist is null) */
    ULONG	dn_StackSize;	/* stacksize to use when starting task */
    LONG	dn_Priority;	/* task priority when starting task */
    BPTR	dn_Startup;	/* startup msg: FileSysStartupMsg for disks */
    BPTR	dn_SegList;	/* code to run to start new task (if necessary).
