/* Source: ADCD 2.1
 * Section: includes-resources-filesysres-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-resources-filesysres-i.md
 */

    ULONG   fse_Type		; device node type: zero
    CPTR    fse_Task		; standard dos "task" field
    BPTR    fse_Lock		; not used for devices: zero
    BSTR    fse_Handler		; filename to loadseg (if SegList is null)
    ULONG   fse_StackSize	; stacksize to use when starting task
    LONG    fse_Priority	; task priority when starting task
    BPTR    fse_Startup		; startup msg: FileSysStartupMsg for disks
    BPTR    fse_SegList		; code to run to start new task
    BPTR    fse_GlobalVec	; BCPL global vector when starting task
    ; no more entries need exist than those implied by fse_PatchFlags
