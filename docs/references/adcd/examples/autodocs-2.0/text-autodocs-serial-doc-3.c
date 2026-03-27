/* Source: ADCD 2.1
 * Section: text-autodocs-serial-doc
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/text-autodocs-serial-doc.md
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
