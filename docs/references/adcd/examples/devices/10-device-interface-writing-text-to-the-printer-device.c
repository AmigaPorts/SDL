/* Source: ADCD 2.1
 * Section: 10-device-interface-writing-text-to-the-printer-device
 * Library: devices
 * ADCD reference: devices/10-device-interface-writing-text-to-the-printer-device.md
 */

    PrintIO->ios.io_Length  = -1;
    PrintIO->ios.io_Data    =
         (APTR)"I went to a fight and a hockey game broke out."
    PrintIO->ios.io_Command = CMD_WRITE;
    DoIO((struct IORequest *)PrintIO);
