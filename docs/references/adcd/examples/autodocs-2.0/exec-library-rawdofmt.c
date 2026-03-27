/* Source: ADCD 2.1
 * Section: exec-library-rawdofmt
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-rawdofmt.md
 */

    perform "C"-language-like formatting of a data stream, outputting
    the result a character at a time.  Where % formatting commands are
    found in the FormatString, they will be replaced with the
    corresponding element in the DataStream.  %% must be used in the
    string if a % is desired in the output.

    Under V36, RawDoFmt() returns a pointer to the end of the DataStream
    (The next argument that would have been processed).  This allows
    multiple formatting passes to be made using the same data.
