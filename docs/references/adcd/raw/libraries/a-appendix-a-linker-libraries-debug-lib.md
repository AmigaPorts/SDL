# A Appendix A: Linker Libraries / Debug.lib


This link library contains standard I/O (stdio) style functions for
communicating with a serial terminal connected to the Amiga via its
built-in serial port.  Typically this  terminal will be a 9600-baud, 8
data-bits, one stop-bit connection to an external terminal or an Amiga
running a terminal package.  The debug.lib functions allow you to output
messages and prompt for input (even from within low level task or
interrupt code) without disturbing the Amiga's display and or current
state (other than the serial hardware itself).

No matter how badly the system may have crashed, these functions can
usually get a message out.  A similar debugging library (currently called
ddebug.lib) is available for sending debugging output to the parallel
port.  This is useful for debugging serial applications. Ddebug.lib is not
documented here.  It contains functions similar to debug.lib but with
names starting with `D' instead of `K'.

Debug.lib is a link library that provides useful diagnostic functions that
are handy for developing code.  It includes the following functions:

[KCmpStr()](../Includes_and_Autodocs_2._guide/node0174.html)

    Compare two null-terminated strings.
[KGetChar()](../Includes_and_Autodocs_2._guide/node0175.html)

    Get a character from the console.
[KGetNum()](../Includes_and_Autodocs_2._guide/node0176.html)

    Get a number from the console.
[KMayGetChar()](../Includes_and_Autodocs_2._guide/node0177.html)

    Return a character if present, but don't wait.
[KPrintF()](../Includes_and_Autodocs_2._guide/node0178.html)

    Print formatted data to the console.
[KPutChar()](../Includes_and_Autodocs_2._guide/node0179.html)

    Put a character to the console.
[KPutStr()](../Includes_and_Autodocs_2._guide/node017A.html)

    Put a string to the console.
Please refer to the Amiga ROM Kernel Reference Manual: Includes and
Autodocs for a detailed description of the functions.

