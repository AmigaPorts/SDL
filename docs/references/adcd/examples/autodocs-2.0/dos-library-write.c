/* Source: ADCD 2.1
 * Section: dos-library-write
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-write.md
 */

    Write() writes bytes of data to the opened file 'file'. 'length'
    indicates the length of data to be transferred; 'buffer' is a
    pointer to the buffer. The value returned is the length of
    information actually written. So, when 'length' is greater than
    zero, the value of 'length' is the number of characters written.
    Errors are indicated by a value of -1.

    Note: this is an unbuffered routine (the request is passed directly
    to the filesystem.)  Buffered I/O is more efficient for small
    reads and writes; see [FPutC()](../Includes_and_Autodocs_2._guide/node02AC.html).
