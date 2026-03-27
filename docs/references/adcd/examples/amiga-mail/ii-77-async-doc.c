/* Source: ADCD 2.1
 * Section: ii-77-async-doc
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-77-async-doc.md
 */

        The named file is opened and an async file handle returned.  If the
        accessMode is MODE_READ, an existing file is opened for reading.
        If the value is MODE_WRITE, a new file is created for writing.  If
        a file of the same name already exists, it is first deleted.  If
        accessMode is MODE_APPEND, an existing file is prepared for writing.
        Data written is added to the end of the file.  If the file does not
        exists, it is created.

        'fileName' is a filename and CANNOT be a simple device such as NIL:, a
        window specification such as CON: or RAW:, or "*".

        'bufferSize' specifies the size of the IO buffer to use.  There are
        in fact two buffers allocated, each of roughly (bufferSize/2) bytes
        in size.  The actual buffer size use can vary slightly as the size
        is rounded to speed up DMA.

        If the file cannot be opened for any reason, the value returned
        will be NULL, and a secondary error code will be available by
        calling the routine dos.library/IoErr().

    INPUTS
        name - name of the file to open
        accessMode - one of MODE_READ, MODE_WRITE, or MODE_APPEND
        bufferSize - size of IO buffer to use.  8192 is recommended as it
                     provides very good performance for relatively little
                     memory.

    RESULTS
        file - an async file handle or NULL for failure.  You should not access
               the fields in the AsyncFile structure, these are private to the
               async IO routines.  In case of failure, dos.library/IoErr() can
               give more information.

    SEE ALSO
        CloseAsync(), dos.library/Open()
