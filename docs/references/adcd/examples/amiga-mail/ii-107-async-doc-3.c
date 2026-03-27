/* Source: ADCD 2.1
 * Section: ii-107-async-doc
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-107-async-doc.md
 */

        WriteAsync() writes bytes of data to an opened async file. 'numBytes'
        indicates the number of bytes of data to be transferred. 'buffer'
        points to the data to write. The value returned is the length of
        information actually written. So, when 'numBytes' is greater than
        zero, the value of 'numBytes' is the number of characters written.
        Errors are indicated by a return value of -1.

    INPUTS
        file - an opened file, as obtained from OpenAsync()
        buffer - address of data to write
        numBytes - number of bytes to write to the file

    RESULT
        actualLength - number of bytes written, or -1 if error. In case
                       of error, dos.library/IoErr() can give more
                       information.

    SEE ALSO
        OpenAsync(), CloseAsync(), ReadAsync(), WriteCharAsync(),
        dos.library/Write()
