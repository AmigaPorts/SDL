/* Source: ADCD 2.1
 * Section: 12-serial-device-alternative-modes-for-serial-input-or
 * Library: devices
 * ADCD reference: devices/12-serial-device-alternative-modes-for-serial-input-or.md
 */

    SerialIO->IOSer.io_Length   = -1;
    SerialIO->IOSer.io_Data     = (APTR)"Save the whales! ";
    SerialIO->IOSer.io_Command  = CMD_WRITE;
    SendIO((struct IORequest *)SerialIO);

    printf("CheckIO %lx\n",CheckIO((struct IORequest *)SerialIO));
    printf("The device will process the request in the background\n");
    printf("CheckIO %lx\n",CheckIO((struct IORequest *)SerialIO));
    WaitIO((struct IORequest *)SerialIO);  /* Remove message and cleanup */
