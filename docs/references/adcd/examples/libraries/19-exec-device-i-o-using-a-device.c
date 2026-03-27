/* Source: ADCD 2.1
 * Section: 19-exec-device-i-o-using-a-device
 * Library: libraries
 * ADCD reference: libraries/19-exec-device-i-o-using-a-device.md
 */

    I/O request to a device.  When the QuickIO flag ([IOF_QUICK](../Includes_and_Autodocs_2._guide/node0094.html#line45)) is set in
    the I/O request, a device is allowed to take certain shortcuts in
    performing and completing a request.  If the request can complete
    immediately, the device will not return a reply message and the
    QuickIO flag will remain set.  If the request cannot be completed
    immediately, the QUICK_IO flag will be clear.  [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) normally
    requests QuickIO; [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) does not.
