# 9 Intuition Input and Output Methods / Console Device I/O


A program receives its input stream either directly from Intuition or via
another mechanism known as the console device.

The console device may be used both as a source for input and as a
mechanism for output.  Often, it is convenient to use only the console
device for input and output.  In particular, character-based programs can
open the console and use it for all I/O without worrying about windows,
bitmaps, or message ports.

The console device gives the program "cooked" input data, including key
code conversions to ASCII and conversions of Intuition generated events,
such as [IDCMP_CLOSEWINDOW](../Libraries_Manual_guide/node01DD.html#line12), to ANSI escape sequences.

The console device output provides features such as automatic line
wrapping and scrolling.  If an application just wants to output text, it
may choose to use the console device, which provides formatted text with
little fuss.

If the application is not character-based, it may be better for the it to
use an IDCMP for input and render graphics and text directly through
Intuition and the graphics library primitives.

If necessary, it is possible to open both the console device and an IDCMP
for input.  Such a program might need ASCII input, formatted output and
the IDCMP verification functions (for example, to verify that it has
finished writing to the window before the user can bring up a requester).

For more information on the console device, see the "[Console Device](../Devices_Manual_guide/node0080.html)"
chapter of the Amiga ROM Kernel Reference Manual: Devices.

