/* Source: ADCD 2.1
 * Section: dos-library-vfprintf
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-vfprintf.md
 */

    Writes the formatted string and values to the given file.  This
    routine is assumed to handle all internal buffering so that the
    formatting string and resultant formatted values can be arbitrarily
    long.  Any secondary error code is returned in [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).  This routine
    is buffered.
