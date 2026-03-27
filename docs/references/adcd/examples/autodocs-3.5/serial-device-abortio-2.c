/* Source: ADCD 2.1
 * Section: serial-device-abortio-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/serial-device-abortio-2.md
 */

      This is an exec.library call.

      This function attempts to aborts a specified read or write request.
      If the request is active, it is stopped immediately. If the request is
      queued, it is painlessly removed.  The request will be returned
      in the same way any completed request it.

      After AbortIO(), you must generally do a [WaitIO()](../Includes_and_Autodocs_3._guide/node0247.html).
