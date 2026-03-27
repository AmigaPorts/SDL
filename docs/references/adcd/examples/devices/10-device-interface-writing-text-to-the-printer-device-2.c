/* Source: ADCD 2.1
 * Section: 10-device-interface-writing-text-to-the-printer-device
 * Library: devices
 * ADCD reference: devices/10-device-interface-writing-text-to-the-printer-device.md
 */

    UBYTE *outbuffer;

    PrintIO->ios.io_Length   = strlen(outbuffer);
    PrintIO->ios.io_Data     = (APTR)outbuffer;
    PrintIO->ios.io_Command  = PRD_RAWWRITE;
    DoIO((struct IORequest *)PrintIO);
