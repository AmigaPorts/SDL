# 4 / Communicating with Intuition / The Console Device


An alternative to the message system used by the IDCMP is the console
device.  The console device gives your application input data translated
to ASCII characters or ANSI escape sequences.  Raw (untranslated) input is
also available through the console device as ANSI escape sequences.

The console device also provides for convenient output of control codes
and non-proportional (mono-spaced) text to the window.  Output is
character based, and includes capabilities such as automatic line wrapping
and scrolling.  The console device automatically formats and interprets
the output stream.  Output is kept within the window boundaries
automatically so the application need not worry about overwriting the
border (no [GimmeZeroZero](../Libraries_Manual_guide/node010F.html) window required).

The console device must be opened by the application before it is used.
See the chapter entitled "[Intuition Input and Output Methods](../Libraries_Manual_guide/node01D5.html)" or refer to
the "[Console Device](../Devices_Manual_guide/node0080.html)" chapter of the Amiga ROM Kernel Reference Manual:
Devices for more information about using the console device with your
Intuition windows.

