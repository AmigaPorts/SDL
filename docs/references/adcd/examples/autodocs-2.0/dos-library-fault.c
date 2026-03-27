/* Source: ADCD 2.1
 * Section: dos-library-fault
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-fault.md
 */

    This routine obtains the error message text for the given error code.
    The header is prepended to the text of the error message, followed
    by a colon.  Puts a null-terminated string for the error message into
    the buffer.  By convention, error messages should be no longer than 80
    characters (+1 for termination), and preferably no more than 60.
    The value returned by [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) is set to the code passed in.  If there
    is no message for the error code, the message will be "Error code
    <number>n".
