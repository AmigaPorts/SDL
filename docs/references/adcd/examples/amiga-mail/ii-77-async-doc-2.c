/* Source: ADCD 2.1
 * Section: ii-77-async-doc
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-77-async-doc.md
 */

        Read() reads bytes of information from an opened async file
        into the buffer given.  'numBytes' is the number of bytes to read from
        the file.

        The value returned is the length of the information actually read.
        So, when 'actualLength' is greater than zero, the value of
        'actualLength' is the the number of characters read.  Usually
        ReadAsync() will try to fill up your buffer before returning.  A value
        of zero means that end-of-file has been reached.  Errors are indicated
        by a value of -1.

    INPUTS
        file - opened file to read, as obtained from OpenAsync()
        buffer - buffer where to put bytes read
        numBytes - number of bytes to read into buffer

    RESULT
        actualLength - actual number of bytes read, or -1 if an error.  In
                       case of error, dos.library/IoErr() can give more
                       information.

    SEE ALSO
        OpenAsync(), CloseAsync(), WriteAsync(), ReadCharAsync(),
        dos.library/Read()
