/* Source: ADCD 2.1
 * Section: text-autodocs-serial-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-serial-doc.md
 */

       This command allows the caller to change parameters for the
       serial device. Except for xON-xOFF enable/disable, it will
       reject a setparams call if any reads or writes are active
       or pending.
          Note specifically:

    1. Valid input for io_Baud is between 112 and 292000 baud inclusive;
       asynchronous i/o above 32KB (especially on a busy system) may
       be ambitious.
    2. The EOFMODE and QUEUEDBRK bits of io_SerFlags can be set/reset
       in the io_Rqst block without a call to SetParams. The SHARED
       and 7WIRE bits of io_SerFlags can be used in OpenDevice calls.
       ALL OTHER PARAMETERS CAN ONLY BE CHANGED BY THE SetParams
       COMMAND.
    3. RBufLen must be at least 64.  The buffer may be any multiple of
