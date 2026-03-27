/* Source: ADCD 2.1
 * Section: 5-device-interface-closing-the-gameport-device
 * Library: devices
 * ADCD reference: devices/5-device-interface-closing-the-gameport-device.md
 */

    if (!(CheckIO(GameIO)))
        {
        AbortIO(GameIO);  /* Ask device to abort request, if pending */
        }
    WaitIO((GameIO);   /* Wait for abort, then clean up */
    CloseDevice(GameIO);
