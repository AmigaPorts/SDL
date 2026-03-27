# 10 / Printer Device Access / Writing To Prt:


Once you've opened it, you can print by calling the AmigaDOS [Write()](../Includes_and_Autodocs_2._guide/node0310.html)
standard I/O routine.


```c
    actual_length = Write(file, dataLocation, length);

    where

    file is a file handle.
```
dataLocation
   is a pointer to the first character in the output stream you wish to
   write.  This stream can contain the standard escape sequences as
   shown in the command table below. The printer command aRAW (see the
   [Printer Device Command Functions](../Devices_Manual_guide/node004A.html#line11) table below) can be used in the
   stream if character translation is not desired.

length
   is the length of the output stream.

actual_length
   is the actual length of the write. For the printer device, if there
   are no errors, this will be the same as the length of write
   requested. The only exception is if you specify a value of -1 for
   length. In this case, -1 for length means that a null (0) terminated
   stream is being written to the printer device. The device returns the
   count of characters written prior to encountering the null.  If it
   returns a value of -1 in actual_length, there has been an error.

   -1 = STOP!
   ----------
   If a -1 is returned by [Write()](../Includes_and_Autodocs_2._guide/node0310.html), do not do any additional printing.

