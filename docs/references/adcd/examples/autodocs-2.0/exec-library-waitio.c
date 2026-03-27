/* Source: ADCD 2.1
 * Section: exec-library-waitio
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-waitio.md
 */

    This function waits for the specified I/O request to complete, then
    removes it from the replyport.  If the I/O has already completed,
    this function will return immediately.

    This function should be used with care, as it does not return until
    the I/O request completes; if the I/O never completes, this
    function will never return, and your task will hang.  If this
    situation is a possibility, it is safer to use the [Wait()](../Includes_and_Autodocs_2._guide/node038A.html) function.
    [Wait()](../Includes_and_Autodocs_2._guide/node038A.html) will return return when any of a specified set of signal is
    received.  This is how I/O timeouts can be properly handled.
