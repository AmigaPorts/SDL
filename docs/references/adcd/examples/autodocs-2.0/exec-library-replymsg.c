/* Source: ADCD 2.1
 * Section: exec-library-replymsg
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-replymsg.md
 */

    This function sends a message to its reply port.  This is usually
    done when the receiver of a message has finished and wants to
    return it to the sender (so that it can be re-used or deallocated,
    whatever).

    This call may be made from interrupts.
