/* Source: ADCD 2.1
 * Section: 4-console-device-using-the-console-device-without-a-window
 * Library: devices
 * ADCD reference: devices/4-console-device-using-the-console-device-without-a-window.md
 */

                      (struct IORequest *)&ConsIO,0) )
       {
       /* Set the base address variable to the device library vector */
       ConsoleDevice = (struct ConsoleDevice *)ConsIO.io_Device;

                     .
                     .    (console device functions would be called here)
                     .

       CloseDevice(ConsIO);
       }
