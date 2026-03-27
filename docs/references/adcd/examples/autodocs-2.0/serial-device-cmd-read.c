/* Source: ADCD 2.1
 * Section: serial-device-cmd-read
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/serial-device-cmd-read.md
 */

    This command causes a stream of characters to be read in from
    the serial port buffer.  The number of characters is specified
    in io_Length.

    The Query function can be used to check how many characters
    are currently waiting in the serial port buffer.  If more characters
    are requested than are currently available, the ioRequest
    will be queued until it can be satisfied.


    The best way to handle reads is to first Query to get the number
    of characters currently in the buffer.  Then post a read request
    for that number of characters (or the maximum size of your buffer).

    If zero characters are in the buffer, post a request
    for 1 character.  When at least one is ready, the device will return
    it.  Now start over with another Query.

    Before the program exits, it must be sure to [AbortIO()](../Includes_and_Autodocs_2._guide/node04CA.html) then [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)
    any outstanding ioRequests.
