/* Source: ADCD 2.1
 * Section: includes-dos-filehandler-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-dos-filehandler-i.md
 */

    BPTR	dn_Lock		; not used for devices -- leave null
    BSTR	dn_Handler	; filename to loadseg (if seglist is null)
    ULONG	dn_StackSize	; stacksize to use when starting task
    LONG	dn_Priority	; task priority when starting task
    BPTR	dn_Startup	; startup msg: FileSysStartupMsg for disks
    BPTR	dn_SegList	; code to run to start new task (if necessary).
