/* Source: ADCD 2.1
 * Section: 12-use-of-beginio-with-the-serial-device
 * Library: devices
 * ADCD reference: devices/12-use-of-beginio-with-the-serial-device.md
 */

        /* The device cleared the QuickIO bit.  QuickIO could not happen
         * for some reason; the device processed the command normally.
         * In this case BeginIO() acted exactly like SendIO().
         */
        printf("Regular I/O\n");
