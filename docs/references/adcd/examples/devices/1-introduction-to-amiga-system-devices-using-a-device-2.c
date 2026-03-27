/* Source: ADCD 2.1
 * Section: 1-introduction-to-amiga-system-devices-using-a-device
 * Library: devices
 * ADCD reference: devices/1-introduction-to-amiga-system-devices-using-a-device.md
 */

      an I/O request to a device.  When the quick I/O flag (IOF_QUICK) is
      set in the I/O request, a device is allowed to take certain shortcuts
      in performing and completing a request.  If the request can complete
      immediately, the device will not return a reply message and the quick
      I/O flag will remain set.  If the request cannot be completed
      immediately, the QUICK_IO flag will be clear.  [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) normally
      requests quick I/O; [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) does not.
