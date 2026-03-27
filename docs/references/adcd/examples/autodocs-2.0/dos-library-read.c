/* Source: ADCD 2.1
 * Section: dos-library-read
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-read.md
 */

    Data can be copied using a combination of Read() and [Write()](../Includes_and_Autodocs_2._guide/node0310.html).
    Read() reads bytes of information from an opened file (represented
    here by the argument 'file') into the buffer given. The argument
    'length' is the length of the buffer given.

    The value returned is the length of the information actually read.
    So, when 'actualLength' is greater than zero, the value of
    'actualLength' is the the number of characters read. Usually Read
    will try to fill up your buffer before returning. A value of zero
    means that end-of-file has been reached. Errors are indicated by a
    value of -1.

    Note: this is an unbuffered routine (the request is passed directly
    to the filesystem.)  Buffered I/O is more efficient for small
    reads and writes; see [FGetC()](../Includes_and_Autodocs_2._guide/node02A2.html).
