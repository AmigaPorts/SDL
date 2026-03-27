/* Source: ADCD 2.1
 * Section: 4-console-device-writing-to-the-console-device
 * Library: devices
 * ADCD reference: devices/4-console-device-writing-to-the-console-device.md
 */

    UBYTE *outstring= "Make it so.";

    ConsIO->io_Data = outstring;
    ConsIO->io_Length = strlen(outstring);
    ConsIO->io_Command = CMD_WRITE;
    DoIO(ConsIO);
