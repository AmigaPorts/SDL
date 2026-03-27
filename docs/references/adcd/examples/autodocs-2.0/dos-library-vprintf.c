/* Source: ADCD 2.1
 * Section: dos-library-vprintf
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-vprintf.md
 */

    Writes the formatted string and values to [Output()](../Includes_and_Autodocs_2._guide/node02D8.html).  This routine is
    assumed to handle all internal buffering so that the formatting string
    and resultant formatted values can be arbitrarily long.  Any secondary
    error code is returned in [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).  This routine is buffered.

    Note: [RawDoFmt](../Includes_and_Autodocs_2._guide/node036C.html) assumes 16 bit ints, so you will usually need 'l's in
    your formats (ex: %ld versus %d).
