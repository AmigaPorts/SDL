/* Source: ADCD 2.1
 * Section: includes-dos-dosextens-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-dos-dosextens-i.md
 */

    BPTR     dol_Next	     ; bptr to next device on lis
    LONG     dol_Type	     ; see DLT below
    APTR     dol_Task	     ; ptr to handler task
    BPTR     dol_Lock

    STRUCT	dol_VolumeDate,0	; creation date (UNION)
    STRUCT	dol_AssignName,0	; name for assign path (UNION)
    BSTR	dol_Handler		; file name to load if seglist is null
    STRUCT	dol_List,0		; List of directories assigned (UNION)
    LONG	dol_StackSize		; stacksize to use when starting process
    LONG	dol_Priority		; task priority when starting process

    STRUCT	dol_LockList,0		; outstanding locks (UNION)
    ULONG	dol_Startup		; startup msg: FileSysStartupMsg
