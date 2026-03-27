/* Source: ADCD 2.1
 * Section: include-datatypes-datatypes-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-datatypes-datatypes-h.md
 */

    /* Libraries that are already opened for your use */
    struct Library		*dthc_SysBase;
    struct Library		*dthc_DOSBase;
    struct Library		*dthc_IFFParseBase;
    struct Library		*dthc_UtilityBase;

    /* File context */
    BPTR			 dthc_Lock;		/* Lock on the file */
    struct FileInfoBlock	*dthc_FIB;		/* Pointer to a FileInfoBlock */
    BPTR			 dthc_FileHandle;	/* Pointer to the file handle (may be NULL) */
    struct IFFHandle		*dthc_IFF;		/* Pointer to an IFFHandle (may be NULL) */
    STRPTR			 dthc_Buffer;		/* Buffer */
    ULONG			 dthc_BufferLength;	/* Length of the buffer */
