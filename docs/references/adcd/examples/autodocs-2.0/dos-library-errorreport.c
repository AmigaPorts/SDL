/* Source: ADCD 2.1
 * Section: dos-library-errorreport
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-errorreport.md
 */

    Based on the request type, this routine formats the appropriate
    requester to be displayed.  If the code is not understood, it returns
    DOS_TRUE immediately.  Returns DOS_TRUE if the user selects CANCEL or
    if the attempt to put up the requester fails, or if the process
    pr_WindowPtr is -1.  Returns FALSE if the user selects Retry.  The
    routine will retry on DISKINSERTED for appropriate error codes.
    These return values are the opposite of what [AutoRequest](../Includes_and_Autodocs_2._guide/node01FF.html) returns.

    Note: this routine sets [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) to code before returning.
