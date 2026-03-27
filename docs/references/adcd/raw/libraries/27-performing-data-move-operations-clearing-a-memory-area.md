# 27 / / Performing Data Move Operations / Clearing a Memory Area


For memory that is accessible to the blitter (that is, internal Chip
memory), the most efficient way to clear a range of memory is to use the
blitter. You use the blitter to clear a block of memory with the statement:


```c
    BltClear(memblock, bytecount, flags);
```
The memblock argument is a pointer to the location of the first byte to be
cleared and bytecount is the number of bytes to set to zero.  In general
the flags variable should be set to one to wait for the blitter operation
to complete.  Refer to the Amiga ROM Kernel Manual: [Includes and Autodocs](../Includes_and_Autodocs_2._guide/node0421.html)
for other details about the flag argument.

