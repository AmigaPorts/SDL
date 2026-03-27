/* Source: ADCD 2.1
 * Section: text-autodocs-serial-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-serial-doc.md
 */

      This is an exec.library call.

      This function attempts to aborts a specified read or write request.
      If the request is active, it is stopped immediately. If the request is
      queued, it is painlessly removed.  The request will be returned
      in the same way any completed request it.

      After AbortIO(), you must generally do a WaitIO().
