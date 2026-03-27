/* Source: ADCD 2.1
 * Section: devices-apps-play8svx-play8svx-c
 * Library: devices
 * ADCD reference: devices/devices-apps-play8svx-play8svx-c.md
 */

    {
    /* queue the next piece of sample */
    reqn = req ^ 1;	/* alternate IO blocks 0 and 1 */
    aio[reqn]->ioa_Request.io_Command             =CMD_WRITE;
    aio[reqn]->ioa_Request.io_Flags               =ADIOF_PERVOL;
    aio[reqn]->ioa_Data                           =samptr;
    aio[reqn]->ioa_Length = (size > MAXSAMPLE) ? MAXSAMPLE : size;
    aio[reqn]->ioa_Period                         =period;
    aio[reqn]->ioa_Volume                         =volume;
    aio[reqn]->ioa_Cycles                         =1;
    BeginIO((struct IORequest*)aio[reqn]);

    /* Wait for previous request to finish */
    WaitIO(aio[req]);
    /* decrement size */
    size = (size > MAXSAMPLE) ? size-MAXSAMPLE : 0;
    req = reqn;		/* switch between aio[0] and aio[1] */
    }
