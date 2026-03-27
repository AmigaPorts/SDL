/* Source: ADCD 2.1
 * Section: any-sana2-protocol-copytobuff
 * Library: amiga-mail
 * ADCD reference: amiga-mail/any-sana2-protocol-copytobuff.md
 */

    This function first does any initialization and/or allocation
    required to prepare the abstract data structure pointed at by 'to'
    to be filled with 'n' bytes of data from 'from'.  It then executes
    the copy operation.

    If, for example, there is not enough memory available to prepare
    the abstract data structure, the call is failed and FALSE is returned.

    The buffer management scheme should be such that any memory needed
    to fulfill CopyToBuff() calls is already allocated from the system
    before the call to CopyToBuff() is made.
