/* Source: ADCD 2.1
 * Section: serial-device-beginio
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/serial-device-beginio.md
 */

    This is a direct function call to the device.  It is intended for
    more advanced programmers.  See exec's [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) and [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) for
    the normal method of calling devices.

    This function initiates a I/O request made to the serial
    device. Other than read or write, the functions are performed
    synchronously, and do not depend on any interrupt handling
    logic (or it's associated discontinuities), and hence should
    be performed as IO_QUICK.
    With some exceptions, reads and writes are merely initiated by
    BeginIO, and thusly return to the caller as begun, not completed.
    Completion is signalled via the standard [ReplyMsg](../Includes_and_Autodocs_2._guide/node0379.html) routine.
    Multiple requests are handled via FIFO queueing.
    One exception to this non-QUICK handling of reads and writes
    is for READS when:
      - IO_QUICK bit is set
      - There are no pending read requests
      - There is already enough data in the input buffer to satisfy
        this I/O Request immediately.
    In this case, the IO_QUICK flag is not cleared, and the request
    is completed by the time it returns to the caller. There is no
    [ReplyMsg](../Includes_and_Autodocs_2._guide/node0379.html) or signal bit activity in this case.
