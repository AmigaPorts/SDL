/* Source: ADCD 2.1
 * Section: 19-using-a-device-i-o-request-completion
 * Library: libraries
 * ADCD reference: libraries/19-using-a-device-i-o-request-completion.md
 */

    SerialIO->IOSer.io_Length   = sizeof(ReadBuffer);
    SerialIO->IOSer.io_Data     = ReadBuffer;
    SerialIO->IOSer.io_Command  = CMD_READ;
    if (DoIO((struct IORequest *)SerialIO)
        printf("Read failed.  Error: %ld\n",SerialIO->IOSer.io_Error);
