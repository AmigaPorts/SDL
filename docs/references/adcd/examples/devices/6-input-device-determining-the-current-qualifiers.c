/* Source: ADCD 2.1
 * Section: 6-input-device-determining-the-current-qualifiers
 * Library: devices
 * ADCD reference: devices/6-input-device-determining-the-current-qualifiers.md
 */

        {
        /* Set input device base address in InputBase */
        InputBase = (struct Library *)InputIO->io_Device;

        /* Call the function */
        Quals = PeekQualifier();
        .
        .
        .
        CloseDevice(InputIO);
        }
