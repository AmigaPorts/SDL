/* Source: ADCD 2.1
 * Section: devices-dev-examples-console-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-console-c.md
 */

    {
    writereq->io_Command = CMD_WRITE;
    writereq->io_Data = (APTR)string;
    writereq->io_Length = -1;  /* means print till terminating null */
    DoIO(writereq);
    }
