# 1 Introduction Amiga System Devices / Synchronous vs. Asynchronous Requests


As stated above, you can send I/O requests to a device synchronously or
asynchronously.  The choice of which to use is largely a function of your
application.

Synchronous requests use the [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) function.  [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) will not return
control to your application until the I/O request has been satisfied by
the device.  The advantage of this is that you don't have to monitor the
message port for the device reply because [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) takes care of all the
message handling. The disadvantage is that your application will be tied
up while the I/O request is being processed, and should the request not
complete for some reason, [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) will not return and your application will
hang.

Asynchronous requests use the [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) and [BeginIO()](../Includes_and_Autodocs_2._guide/node0141.html) functions. Both
return to your application almost immediately after you call them.  This
allows you to do other operations, including sending more I/O requests to
the device.

   Do Not Touch!
   -------------
   When you use [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) or [BeginIO()](../Includes_and_Autodocs_2._guide/node0141.html), the I/O request you pass to the
   device and any associated data buffers should be considered
   read-only. Once you send it to the device, you must not modify it in
   any way until you receive the reply message from the device or abort
   the request (though you must still wait for a reply). Any exceptions
   to this rule are documented in the autodoc for the device.

Sending multiple asynchronous I/O requests to a device can be tricky
because devices require them to be unique and initialized.  This means
you can't use an I/O request that's still in the queue, but you need the
fields which were initialized in it when you opened the device.  The
solution is to copy the initialized I/O request to another I/O request(s)
before sending anything to the device.

Regardless of what you do while you are waiting for an asynchronous I/O
request to return, you need to have some mechanism for knowing when the
request has been done.  There are two basic methods for doing this.

The first involves putting your application into a wait state until the
device returns the I/O request to the message port of your application.
You can use the [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html), [Wait()](../Includes_and_Autodocs_2._guide/node038A.html) or [WaitPort()](../Includes_and_Autodocs_2._guide/node038C.html) function to wait for the
return of the I/O request.

[WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html) not only waits for the return of the I/O request, it also takes
care of all the message handling functions.  This is very convenient, but
you can pay for this convenience: your application will hang in the
unlikely event that the I/O request does not return.

[Wait()](../Includes_and_Autodocs_2._guide/node038A.html) waits for a signal to be sent to the message port.  It will awaken
your task when the signal arrives, but you are responsible for all of the
message handling.

[WaitPort()](../Includes_and_Autodocs_2._guide/node038C.html) waits for the message port to be non-empty.  It returns a
pointer to the message in the port, but you are responsible for all of the
message handling.

The second method to detect when the request is complete involves using
the [CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html) function.  CheckIO() takes an I/O request as its argument
and returns an indication of whether or not it has been completed. When
CheckIO() returns the completed indication, you will still have to remove
the I/O request from the message port.

