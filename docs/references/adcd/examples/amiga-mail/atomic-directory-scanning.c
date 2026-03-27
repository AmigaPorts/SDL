/* Source: ADCD 2.1
 * Section: atomic-directory-scanning
 * Library: amiga-mail
 * ADCD reference: amiga-mail/atomic-directory-scanning.md
 */

    struct ExAllData *ed_Next; /* Pointer to the next structure */
    UBYTE *ed_Name;		            /* File name */
    LONG  ed_Type;             /* File type */
    ULONG ed_Size;             /* File size */
    ULONG ed_Prot;  /* Protection bits (FIBF_ definitions in <dos/dos.h> */
    ULONG ed_Days;  /* Date in three longwords, forming a DateStamp. */
    ULONG ed_Mins;
    ULONG ed_Ticks;
    UBYTE *ed_Comment;         /* File comment.  Cannot be used */
