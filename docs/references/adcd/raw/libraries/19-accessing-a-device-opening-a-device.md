# 19 / Accessing a Device / Opening a Device


The device is opened by calling the [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) function.  In addition to
establishing the link to the device, OpenDevice() also initializes fields
in the I/O request.  OpenDevice() has this format:


```c
    return = OpenDevice(device_name,
                        unit_number,
      			(struct IORequest *)IORequest,
                        flags)
```
  * device_name is one of the following NULL-terminated strings for

```c
    system devices:

        [Audio](../Devices_Manual_guide/node001A.html).device     [Parallel](../Devices_Manual_guide/node000E.html).device  [Clipboard](../Devices_Manual_guide/node0065.html).device
        [Printer](../Devices_Manual_guide/node003E.html).device   [Console](../Devices_Manual_guide/node0080.html).device   [scsi](../Devices_Manual_guide/node0073.html).device
        [Gameport](../Devices_Manual_guide/node00AE.html).device  [Serial](../Devices_Manual_guide/node009A.html).device    [Input](../Devices_Manual_guide/node00CA.html).device
        [Timer](../Devices_Manual_guide/node00BD.html).device     [Keyboard](../Devices_Manual_guide/node00FC.html).device  [Trackdisk](../Devices_Manual_guide/node00DC.html).device
                         [Narrator](../Devices_Manual_guide/node0113.html).device
```
  * unit_number is refers to one of the logical units of the device.

    Devices with one unit always use unit 0.  Multiple unit devices like
    the trackdisk device and the timer device use the different units for
    specific purposes.
  * [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) is the structure [discussed above](../Libraries_Manual_guide/node029D.html).  Some of the devices have

```c
    their own I/O requests defined in their include files and others use
    standard I/O requests, ([IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28)).  Refer to the Amiga ROM Kernel
    Reference Manual: [Devices](../Devices_Manual_guide/node0000.html) for more information.
```
  * flags are bits set to indicate options for some of the devices. This

```c
    field is set to zero for devices which don't accept options when they
    are opened.  The flags for each device are explained in the Amiga ROM
    Kernel Reference Manual: [Devices](../Devices_Manual_guide/node0000.html).
```
  * return is an indication of whether the [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) was successful

```c
    with zero indicating success.  Never assume that a device will
    successfully open.  Check the return value and act accordingly.

    Zero Equals Success for [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html).
    -------------------------------------
    Unlike most Amiga system functions, OpenDevice() returns zero for
    success and a device-specific error value for failure.
```
