/* Source: ADCD 2.1
 * Section: exec-library-checkio
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-checkio.md
 */

    This function determines the current state of an I/O request and
    returns FALSE if the I/O has not yet completed.  This function
    effectively hides the internals of the I/O completion mechanism.

    CheckIO() will NOT remove the returned [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) from the reply port.
    This is best performed with [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html). If the request has already
    completed, [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html) will return quickly. Use of the [Remove()](../Includes_and_Autodocs_2._guide/node0373.html)
    function is dangerous, since other tasks may still be adding things
    to your message port; a [Disable()](../Includes_and_Autodocs_2._guide/node034A.html) would be required.

    This function should NOT be used to busy loop (looping until IO is
    complete).  [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html) is provided for that purpose.
