/* Source: ADCD 2.1
 * Section: 19-accessing-a-device-opening-a-device
 * Library: libraries
 * ADCD reference: libraries/19-accessing-a-device-opening-a-device.md
 */

    with zero indicating success.  Never assume that a device will
    successfully open.  Check the return value and act accordingly.

    Zero Equals Success for [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html).
    -------------------------------------
    Unlike most Amiga system functions, OpenDevice() returns zero for
    success and a device-specific error value for failure.
