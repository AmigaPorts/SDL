---
title: II-77/Async.doc
manual: amiga-mail
chapter: amiga-mail
section: ii-77-async-doc
functions: [Close, IoErr, Open, Read]
libraries: [dos.library]
---

# II-77/Async.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

(c)  Copyright 1992-1999 Amiga, Inc.   All rights reserved.
The information contained herein is subject to change without notice,
and is provided "as is" without warranty of any kind, either expressed
or implied.  The entire risk as to the use of this information is
assumed by the user.

TABLE OF CONTENTS

asyncio/CloseAsync
asyncio/OpenAsync
asyncio/ReadAsync
asyncio/ReadAsyncChar
asyncio/WriteAsync
asyncio/WriteAsyncChar
asyncio/CloseAsync                                         asyncio/CloseAsync

   NAME

        CloseAsync -- close an async io file.
   SYNOPSIS

```c
        result = CloseAsync(file);

        LONG CloseAsync(struct AsyncFile *);
```
   FUNCTION

        Closes a file, flushing any pending writes.  Once this call has been
        made, the file can no longer be accessed.
   INPUTS

        file - the file to close.  May be NULL.
   RESULT

```c
        result - < 0 for an error, >= 0 for success.  Indicates whether closing
                 the file worked or not.  If the file was opened in read-mode,
                 then this call will always work.  In case of error,
                 dos.library/IoErr() can give more information.
```
   SEE ALSO

```c
        OpenAsync, dos.library/Close()
```
asyncio/OpenAsync                                           asyncio/OpenAsync

   NAME

        OpenAsync -- open a file for asynchronous IO.
   SYNOPSIS

```c
        file = OpenAsync(fileName, accessMode, bufferSize);

        struct AsyncFile OpenAsync(STRPTR, UBYTE, LONG);
```
   FUNCTION

```c
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
```
asyncio/ReadAsync                                           asyncio/ReadAsync

   NAME

        ReadAsync -- read bytes from an async file.
   SYNOPSIS

```c
        actualLength = ReadAsync(file,buffer,numBytes);

        LONG ReadAsync(struct AsyncFile *file, APTR buffer, LONG numBytes);
```
   FUNCTION

```c
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
```
asyncio/ReadCharAsync                                   asyncio/ReadCharAsync

   NAME

        ReadCharAsync -- read a single byte from an async file.
   SYNOPSIS

```c
        byte = ReadCharAsync(file);

        LONG ReadCharAsync(struct AsyncFile *file);
```
   FUNCTION

        This function reads a single byte from an async file.  The byte is
        returned, or -1 if there was an error reading, or if the end-of-file
        was reached.
   INPUTS

```c
        file - opened file to read from, as obtained from OpenAsync()
```
   RESULT

```c
        byte - the byte read, or -1 if no byte was read.  In case of error,
               dos.library/IoErr() can give more information.
```
   SEE ALSO

```c
        OpenAsync(), CloseAsync(), WriteCharAsync(), ReadAsync()
        dos.library/Read()
```
asyncio/WriteAsync                                         asyncio/WriteAsync

   NAME

        WriteAsync -- write data to an async file.
   SYNOPSIS

```c
        actualLength = WriteAsync(file,buffer,numBytes);

        LONG WriteAsync(struct AsyncFile *file, APTR buffer, LONG numBytes);
```
   FUNCTION

```c
        WriteAsync() writes bytes of data to an opened async file.  'numBytes'
        indicates the number of bytes of data to be transferred.  'buffer'
        points to the data to write.  The value returned is the length of
        information actually written.  So, when 'numBytes' is greater than
        zero, the value of 'numBytes' is the number of characters written.
        Errors are indicated by a value of -1.

    INPUTS
        file - an opened file, as obtained from OpenAsync()
        buffer - address of data to write
        numBytes - number of bytes to write to the file

    RESULT
        actualLength - number of bytes written, or -1 if error.  In case
                       of error, dos.library/IoErr() can give more
                       information.

    SEE ALSO
        OpenAsync(), CloseAsync(), ReadAsync(), WriteCharAsync(),
        dos.library/Write
```
asyncio/WriteCharAsync                                 asyncio/WriteCharAsync

   NAME

        WriteCharAsync -- write a single byte to an async file.
   SYNOPSIS

```c
        result = WriteCharAsync(file,byte);

        LONG WriteCharAsync(struct AsyncFile *, UBYTE byte);
```
   FUNCTION

        This function write a single byte to an async file.
   INPUTS

```c
        file - an opened async file, as obtained from OpenAsync()
        byte - byte of data to add to the file
```
   RESULT

```c
        result - 1 if the byte was written, -1 if there was an error.  In
                 case of error, dos.library/IoErr() can give more information.
```
   SEE ALSO

```c
        OpenAsync(), CloseAsync(), ReadAsync(), WriteCharAsync(),
        dos.library/Write
```

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [Read — dos.library](../autodocs/dos.library.md#read)
