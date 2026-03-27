/* Source: ADCD 2.1
 * Section: dos-library-namefromlock
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-namefromlock.md
 */

    Returns a fully qualified path for the lock.  This routine is
    guaranteed not to write more than len characters into the buffer.  The
    name will be null-terminated.  NOTE: if the volume is not mounted,
    the system will request it (unless of course you set pr_WindowPtr to
    -1).  If the volume is not mounted or inserted, it will return an
    error.  If the lock passed in is NULL, "SYS:" will be returned. If
    the buffer is too short, an error will be returned, and [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) will
    return ERROR_LINE_TOO_LONG.
