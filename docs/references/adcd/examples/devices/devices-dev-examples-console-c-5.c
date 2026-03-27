/* Source: ADCD 2.1
 * Section: devices-dev-examples-console-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-console-c.md
 */

    {
    BYTE error;

    writereq->io_Data = (APTR) window;
    writereq->io_Length = sizeof(struct Window);
    error = OpenDevice("console.device", 0, writereq, 0);
    readreq->io_Device = writereq->io_Device; /* clone required parts */
    readreq->io_Unit   = writereq->io_Unit;
    return(error);
    }
