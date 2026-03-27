/* Source: ADCD 2.1
 * Section: includes-dos-filehandler-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-dos-filehandler-i.md
 */

    ULONG	fssm_Unit	; exec unit number for this device
    BSTR	fssm_Device	; null terminated bstring to the device name
    BPTR	fssm_Environ	; ptr to environment table (see above)
    ULONG	fssm_Flags	; flags for OpenDevice()
    LABEL	FileSysStartupMsg_SIZEOF
