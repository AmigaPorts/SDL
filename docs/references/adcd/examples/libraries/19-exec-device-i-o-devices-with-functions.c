/* Source: ADCD 2.1
 * Section: 19-exec-device-i-o-devices-with-functions
 * Library: libraries
 * ADCD reference: libraries/19-exec-device-i-o-devices-with-functions.md
 */

    successful (returns 0), the address of the device base may be found
    in the [io_Device](../Includes_and_Autodocs_2._guide/node0094.html#line28) field of the I/O request structure. Consult the
    include file for the structure you are using to determine the full
    name of the io_Device field.  The base address is only valid while
    the device is open.
