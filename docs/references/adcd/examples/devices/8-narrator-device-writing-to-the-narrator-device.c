/* Source: ADCD 2.1
 * Section: 8-narrator-device-writing-to-the-narrator-device
 * Library: devices
 * ADCD reference: devices/8-narrator-device-writing-to-the-narrator-device.md
 */

    VoiceIO->message.io_Command = CMD_WRITE;
    VoiceIO->message.io_Offset  = 0;
    VoiceIO->message.io_Data    = PhonBuffer;
    VoiceIO->message.io_Length  = strlen(PhonBuffer);
    DoIO((struct IORequest *)VoiceIO);
