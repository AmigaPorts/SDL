/* Source: ADCD 2.1
 * Section: exec-library-rawdofmt
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-rawdofmt.md
 */

    FormatString - a "C"-language-like NULL terminated format string,
    with the following supported % options:

     %[flags][width.limit][length]type

    flags  - only one allowed. '-' specifies left justification.
    width  - field width.  If the first character is a '0', the
             field will be padded with leading 0's.
      .    - must follow the field width, if specified
    limit  - maximum number of characters to output from a string.
             (only valid for %s).
    length - size of input data defaults to WORD for types d, x,
             and c, 'l' changes this to long (32-bit).
    type   - supported types are:
                    b - BSTR, data is 32-bit BPTR to byte count followed
                        by a byte string, or NULL terminated byte string.
                        A NULL BPTR is treated as an empty string.
                        (Added in V36 exec)
                    d - decimal
                    u - unsigned decimal (Added in V37 exec)
                    x - hexadecimal
                    s - string, a 32-bit pointer to a NULL terminated
                        byte string.  In V36, a NULL pointer is treated
                        as an empty string
                    c - character

    DataStream - a stream of data that is interpreted according to
             the format string.  Often this is a pointer into
             the task's stack.
    PutChProc  - the procedure to call with each character to be
             output, called as:

    PutChProc(Char,  PutChData);
              D0-0:8 A3

            the procedure is called with a NULL Char at the end of
            the format string.

    PutChData - a value that is passed through to the PutChProc
            procedure.  This is untouched by RawDoFmt, and may be
            modified by the PutChProc.
