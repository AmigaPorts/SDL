/* Source: ADCD 2.1
 * Section: 1-introduction-to-amiga-system-devices-using-a-device
 * Library: devices
 * ADCD reference: devices/1-introduction-to-amiga-system-devices-using-a-device.md
 */

      the I/O operation it initiates may take a short or long time.  Using
      [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) requires you to monitor the message port for a return
      message from the device.  In addition, some devices do not actually
      respond asynchronously even though you called SendIO(); they will
      return when the I/O operation is finished.
