/* Source: ADCD 2.1
 * Section: sana2-device-abortio
 * Library: amiga-mail
 * ADCD reference: amiga-mail/sana2-device-abortio.md
 */

    This is an exec.library call.

    This function aborts an ioRequest. If the request is active, it may or
    may not be aborted. If the request is queued it is removed. The
    request will be returned in the same way as if it had normally
    completed.  You must WaitIO() after AbortIO() for the request to
    return.
