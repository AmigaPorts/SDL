/* Source: ADCD 2.1
 * Section: devices-dev-examples-simple-timer-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-simple-timer-c.md
 */

    {
    tp = tr->tr_node.io_Message.mn_ReplyPort;

    if (tp != 0)
        DeletePort(tp);

    CloseDevice( (struct IORequest *) tr );
    DeleteExtIO( (struct IORequest *) tr );
    }
