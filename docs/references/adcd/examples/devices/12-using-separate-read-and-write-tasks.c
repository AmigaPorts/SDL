/* Source: ADCD 2.1
 * Section: 12-using-separate-read-and-write-tasks
 * Library: devices
 * ADCD reference: devices/12-using-separate-read-and-write-tasks.md
 */

    {

    /* Copy over the entire old IO request, then stuff the
     * new Message port pointer.
     */

    CopyMem( SerialIO, SerialWriteIO, sizeof(struct IOExtSer) );
    SerialWriteIO->IOSer.io_Message.mn_ReplyPort = SerialWriteMP;

    SerialWriteIO->IOSer.io_Command  = CMD_WRITE;
    SerialWriteIO->IOSer.io_Length = -1;
    SerialWriteIO->IOSer.io_Data = (APTR)"A poet's food is love and fame";
    DoIO(SerialWriteIO);
    }
