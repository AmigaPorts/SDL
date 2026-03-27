/* Source: ADCD 2.1
 * Section: devices-dev-examples-console-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-console-c.md
 */

    {
    writereq->io_Command = CMD_WRITE;
    writereq->io_Data = (APTR)&character;
    writereq->io_Length = 1;
    DoIO(writereq);
    /* command works because DoIO blocks until command is done
     * (otherwise ptr to the character could become invalid)
     */
    }
