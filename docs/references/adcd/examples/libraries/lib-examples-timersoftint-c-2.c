/* Source: ADCD 2.1
 * Section: lib-examples-timersoftint-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-timersoftint-c.md
 */

    struct timerequest *tr;

    /* Remove the message from the port. */
    tr = (struct timerequest *)GetMsg(tsidata->tsi_Port);

    /* Keep on going if main() hasn't set flag to OFF. */
    if ((tr) && (tsidata->tsi_Flag == ON))
    {
        /* increment counter and re-send timerequest--IMPORTANT: This         */
        /* self-perpetuating technique of calling BeginIO() during a software */
        /* interrupt may only be used with the audio and timer device.        */
        tsidata->tsi_Counter++;
        tr->tr_node.io_Command = TR_ADDREQUEST;
        tr->tr_time.tv_micro = MICRO_DELAY;
        BeginIO((struct IORequest *)tr);
    }
    /* Tell main() we're out of here. */
    else tsidata->tsi_Flag = STOPPED;
