# 9 Parallel Device / Ending A Read or Write with Termination Characters


Reads and writes from the parallel device may terminate early if an error
occurs or if an end-of-file is sensed.  For example, if a break is
detected on the line, any current read request will be returned with the
error ParErr_DetectedBreak. The count of characters read to that point
will be in the io_Actual field of the request.

You can specify a set of possible end-of-file characters that the parallel
device is to look for in the input or output stream using the
[PDCMD_SETPARAMS](../Includes_and_Autodocs_2._guide/node04F4.html) command. These are contained in an io_PTermArray that you
provide. io_PTermArray is used only when the PARF_EOFMODE flag is selected
(see [Parallel Flags](../Devices_Manual_guide/node0017.html) below).

If EOF mode is selected, each input data character read into or written
from the user's data block is compared against those in io_PTermArray. If
a match is found, the [IOExtPar](../Devices_Manual_guide/node0010.html#line7) is terminated as complete, and the count of
characters transferred (including the termination character) is stored in
io_Actual.

To keep this search overhead as efficient as possible, the parallel device
requires that the array of characters be in descending order. The array
has eight bytes and all must be valid (that is, do not pad with zeros
unless zero is a valid EOF character). Fill to the end of the array with
the lowest value termination character. When making an arbitrary choice of
EOF character(s), you will get the quickest response from the lowest
value(s) available.


```c
     [Terminate_Parallel.c](../Devices_Manual_guide/node015F.html) 
```
The read will terminate before the io_Length number of characters is read
if a "Q", "E", or "A" is detected.

   It's Usually For Output.
   ------------------------
   Most applications for the parallel device use the device for output,
   hence the termination feature is usually done on the output stream.

