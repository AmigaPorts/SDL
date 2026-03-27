/* Source: ADCD 2.1
 * Section: serial-device-sdcmd-break
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/serial-device-sdcmd-break.md
 */

    This command sends a break signal (serial line held low for an
    extended period) out the serial port. For the built-in port,
    This is accomplished by setting the UARTBRK bit of regisrer ADKCON.

    After a duration (user specifiable via setparams, default 250000
    microseconds) the bit is reset and the signal discontinued.
    If the QUEUEDBRK bit of io_SerFlags is set in the io_Request
    block, the request is placed at the back of the write-request
    queue and executed in turn. If the QUEUEDBRK bit is not set,
    the break is started immediately, control returns to the
    caller, and the timer discontinues the signal after the
    duration is completed. Be aware that calling BREAK may
     affect other commands such as ABORT, FLUSH, STOP, START, etc...
