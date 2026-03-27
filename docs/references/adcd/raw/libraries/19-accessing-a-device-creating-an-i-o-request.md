# 19 / Accessing a Device / Creating an I/O Request


The I/O request is used to send commands and data from your application to
the device.  The I/O request consists of fields used to hold the command
you wish to execute and any parameters it requires.  You set up the fields
with the appropriate information and send it to the device by using Exec
I/O functions.  Different Amiga devices often require different I/O
request structures.  These structures all start with a simple [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) or
[IoStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28) structure (see <exec/[io.h](../Includes_and_Autodocs_2._guide/node0094.html)>) which may be followed by various
device-specific fields.  Consult the Autodoc and include file for each
device to determine the type and size I/O request required to access the
device.

I/O request structures are commonly created and deleted with the amiga.lib
functions [CreateExtIO()](../Libraries_Manual_guide/node04B0.html#line6) with [DeleteExtIO()](../Libraries_Manual_guide/node04B0.html#line6). These amiga.lib functions are
compatible with Release 2 and previous versions of the operating system.
Applications that already require V37 for other reasons may instead use
the new V37 ROM Exec functions [CreateIORequest()](../Includes_and_Autodocs_2._guide/node0344.html) and [DeleteIORequest()](../Includes_and_Autodocs_2._guide/node0348.html).
Any size and type of I/O request may be created with these functions.

Alternately, I/O requests can be created by declaring them as structures
initialized to zero, or by dynamically allocating cleared public memory
for them, but in these cases you will be responsible for the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19)
structure initializations which are normally handled by the above
functions.  The message port pointer in the I/O request tells the device
where to respond with messages for your application.  You must set a
pointer to the message port in the I/O request if you declare it as a
structure or allocate memory for it using [AllocMem()](../Libraries_Manual_guide/node02A7.html).

