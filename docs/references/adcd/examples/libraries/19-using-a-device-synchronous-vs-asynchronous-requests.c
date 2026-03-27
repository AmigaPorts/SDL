/* Source: ADCD 2.1
 * Section: 19-using-a-device-synchronous-vs-asynchronous-requests
 * Library: libraries
 * ADCD reference: libraries/19-using-a-device-synchronous-vs-asynchronous-requests.md
 */

      * [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html) not only waits for the return of the I/O request, it
        also takes care of all the message handling functions.  This is
        very convenient, but you can pay for this convenience: your
        application will hang if the I/O request does not return.

      * [Wait()](../Libraries_Manual_guide/node02D4.html) waits for a signal to be sent to the message port.  It
        will awaken your task when the signal arrives, but you are
        responsible for all of the message handling.

      * [WaitPort()](../Libraries_Manual_guide/node02F1.html#line9) waits for the message port to be non-empty.  It
        returns a pointer to the message in the port, but you are
        responsible for all of the message handling.
