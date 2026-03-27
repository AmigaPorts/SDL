# 1 Introduction to Amiga System Devices / Accessing a Device


Accessing a device requires obtaining a message port, allocating memory
for a specialized message packet called an I/O request, setting a pointer
to the message port in the I/O request, and finally, establishing the link
to the device itself by opening it.  An example of how to do this will be
provided later in this chapter.

The message port is used by the device to return messages to you.  A
message port is obtained by calling the [CreateMsgPort()](../Includes_and_Autodocs_2._guide/node0345.html) or [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html)
function.  You must delete the message port when you are finished by
calling the [DeleteMsgPort()](../Includes_and_Autodocs_2._guide/node0349.html) or [DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html) function.

For pre-V36 versions of the operating system (before Release 2.0), use the
amiga.lib functions [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html) and [DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html); for V36 and higher, use
the Exec functions [CreateMsgPort()](../Includes_and_Autodocs_2._guide/node0345.html) and [DeleteMsgPort()](../Includes_and_Autodocs_2._guide/node0349.html). [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html) and
[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html) are upward compatible, you can use them with V36/V37;
[CreateMsgPort()](../Includes_and_Autodocs_2._guide/node0345.html) and [DeleteMsgPort()](../Includes_and_Autodocs_2._guide/node0349.html) are not backward compatible, however.

The I/O request is used to send commands and data from your application to
the device.  The I/O request consists of fields used to hold the command
you wish to execute and any parameters it requires.  You set up the fields
with the appropriate information and send it to the device by using Exec
I/O functions.

At least four methods exist for creating an I/O request:

   *  Declaring it as a structure.  The memory required will be allocated

      at compile time.
   *  Declaring it as a pointer and calling the [AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html) function.  You

```c
      will have to call the [FreeMem()](../Includes_and_Autodocs_2._guide/node0355.html) function to release the memory when
      you are done.
```
   *  Declaring it as a pointer and calling the [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html) function.

```c
      This function not only allocates the memory for the request, it also
      puts the message port in the I/O request.  You will have to call the
      [DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html) function to delete the I/O request when you are done.
      This is the pre-V36 method (used in 1.3 and earlier versions of the
      operating system), but is upward compatible.
```
   *  Declaring it as a pointer and calling the [CreateIORequest()](../Includes_and_Autodocs_2._guide/node0344.html) function.

```c
      This function not only allocates the memory for the request, it also
      puts the message port in the I/O request.  You will have to call the
      [DeleteIORequest()](../Includes_and_Autodocs_2._guide/node0348.html) function to delete the I/O request when you are
      done.  This is the V36/V37 method; it is not backwards compatible.
```
The message port pointer in the I/O request tells the device where to
respond with messages for your application.  You must set a pointer to the
message port in the I/O request if you declare it as a structure or
allocate memory for it using [AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html).

The device is opened by calling the [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) function.  In addition to
establishing the link to the device, OpenDevice() also initializes fields
in the I/O request.  OpenDevice() has this format:

  return = OpenDevice(device_name,unit_number,

```c
                     (struct IORequest *)IORequest,flags)
```
where:

   *  device_name is one of the following NULL-terminated strings for

      system devices:

        audio.device        keyboard.device    serial.device
        clipboard.device    narrator.device    timer.device
        console.device      parallel.device    trackdisk.device
        gameport.device     printer.device     input.device
        scsi.device
   *  unit_number refers to one of the logical units of the device. Devices

      with one unit always use unit 0.  Multiple unit devices like the
      trackdisk device and the timer device use the different units for
      specific purposes.  The device chapters discuss the units in detail.
   *  [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line20) is the structure discussed above.  Some of the devices have

```c
      their own I/O requests defined in their include files and others use
      standard I/O requests, ([IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line29)).  The device chapters list the I/O
      request that each device requires.
```
   *  flags are bits set to indicate options for some of the devices.  This

      field is set to zero for devices which don't accept options when they
      are opened.  The device chapters and autodocs list the flags values
      and uses.
   *  return is an indication of whether the [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) was successful

      with zero indicating success.  Never assume that a device will
      successfully open.  Check the return value and act accordingly.
   Zero Equals Success for OpenDevice().
   -------------------------------------
   Unlike most Amiga system functions, [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) returns zero for
   success and a device-specific error value for failure.

