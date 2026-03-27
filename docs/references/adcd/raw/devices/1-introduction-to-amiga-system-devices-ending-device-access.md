# 1 Introduction to Amiga System Devices / Ending Device Access


You end device access by reversing the steps you took to access it.  This
means you close the device, deallocate the I/O request memory and delete
the message port.  In that order!

Closing a device is how you tell Exec that you are finished using a device
and any associated resources.  This can result in housecleaning being
performed by the device.  However, before you close a device, you might
have to do some housecleaning of your own.

A device is closed by calling the CloseDevice() function. The
CloseDevice() function does not return a value. It has this format:

  CloseDevice(IORequest)

where [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line20) is the I/O request used to open the device.

You should not close a device while there are outstanding I/O requests,
otherwise you can cause major and minor problems.  Let's begin with the
minor problem: memory.  If an I/O request is outstanding at the time you
close a device, you won't be able to reclaim the memory you allocated for
it.

The major problem: the device will try to respond to the I/O request.  If
the device tries to respond to an I/O request, and you've deleted the
message port (which is covered below), you will probably crash the system.

One solution would be to wait until all I/O requests you sent to the
device return.  This is not always practical if you've sent a few requests
and the user wants to exit the application immediately.

In that case, the only solution is to abort and remove any outstanding I/O
requests. You do this with the functions [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html) and [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html).  They
must be used together for cleaning up. AbortIO() will abort an I/O
request, but will not prevent a reply message from being sent to the
application requesting the abort. [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html) will wait for an I/O request to
complete and remove it from the message port.  This is why they must be
used together.

   Be Careful With AbortIO().
   --------------------------
   Do not [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html) an I/O request which has not been sent to a device.
   If you do, you may crash the system.

After the device is closed, you must deallocate the I/O request memory.
The exact method you use depends on how you allocated the memory in the
first place.  For [AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html) you call [FreeMem()](../Includes_and_Autodocs_2._guide/node0355.html), for [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html) you
call [DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html), and for [CreateIORequest()](../Includes_and_Autodocs_2._guide/node0344.html) you call [DeleteIORequest()](../Includes_and_Autodocs_2._guide/node0348.html).
If you allocated the I/O request memory at compile time, you naturally
have nothing to free.

Finally, you must delete the message port you created.  You delete the
message port by calling [DeleteMsgPort()](../Includes_and_Autodocs_2._guide/node0349.html) if you used [CreateMsgPort()](../Includes_and_Autodocs_2._guide/node0345.html), or
[DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html) if you used [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html).

Here is the checklist for gracefully exiting:

   1. Abort any outstanding I/O requests with [AbortIO()](../Includes_and_Autodocs_2._guide/node0323.html)

   2. Wait for the completion of any outstanding or aborted I/O requests

```c
      with [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html).
```
   3. Close the device with CloseDevice().

   4. Release the I/O request memory with either [DeleteIORequest()](../Includes_and_Autodocs_2._guide/node0348.html),

```c
      [DeleteExtIO()](../Includes_and_Autodocs_2._guide/node0152.html) or [FreeMem()](../Includes_and_Autodocs_2._guide/node0355.html) (as appropriate).
```
   5. Delete the message port with [DeleteMsgPort()](../Includes_and_Autodocs_2._guide/node0349.html) or [DeletePort()](../Includes_and_Autodocs_2._guide/node0153.html).

