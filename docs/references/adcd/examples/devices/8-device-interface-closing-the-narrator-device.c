/* Source: ADCD 2.1
 * Section: 8-device-interface-closing-the-narrator-device
 * Library: devices
 * ADCD reference: devices/8-device-interface-closing-the-narrator-device.md
 */

    if (!(CheckIO(VoiceIO)
        {
        AbortIO(VoiceIO);  /* Abort queued or in progress request */
        }
    WaitIO((struct IORequest *)VoiceIO); /* Wait for abort to do its job */
    CloseDevice(VoiceIO);                /* Close the device */
