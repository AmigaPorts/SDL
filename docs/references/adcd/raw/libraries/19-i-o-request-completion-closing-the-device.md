# 19 / / I/O Request Completion / Closing the Device


You end device access by reversing the steps you did to access it. This
means you close the device, deallocate the I/O request memory and delete
the message port.  In that order!

Closing a device is how you tell Exec that you are finished using a device
and any associated resources.  This can result in housecleaning being
performed by the device.  However, before you close a device, you might
have to do some housecleaning of your own.

A device is closed by calling the [CloseDevice()](../Includes_and_Autodocs_2._guide/node033F.html) function.  The
CloseDevice() function does not return a value.  It has this format:


```c
    CloseDevice(IORequest);
```
where [IORequest](../Libraries_Manual_guide/node029D.html) is the I/O request used to open the device.

You should not close a device while there are outstanding I/O requests,
otherwise you can cause major and minor problems.  Let's begin with the
minor problem: memory.  If an I/O request is outstanding at the time you
close a device, you won't be able to reclaim the memory you allocated for
it.

The major problem: the device will try to respond to the I/O request. If
the device tries to respond to an I/O request, and you've deleted the
message port (which is covered below), you will probably crash the system.

One solution would be to wait until all I/O requests you sent to the
device return.  This is not always practical if you've sent a few requests
and the user wants to exit the application immediately.

In that case, the only solution is to abort and remove any outstanding I/O
requests.  You do this with the functions [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html) and [WaitIO()](../Libraries_Manual_guide/node02A0.html#line48).  They
must be used together for cleaning up.  AbortIO() will abort an I/O
request, but will not prevent a reply message from being sent to the
application requesting the abort.  WaitIO() will wait for an I/O request
to complete and remove it from the message port.  This is why they must be
used together.


```c
    Be Careful With [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)!
    --------------------------
    Do not AbortIO() an I/O request which has not been sent to a
    device.  If you do, you may crash the system.
```
