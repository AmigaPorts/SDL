/* Source: ADCD 2.1
 * Section: dos-library-getvar
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-getvar.md
 */

    len -   Size of environment variable.  -1 indicates that the
            variable was not defined (if [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) returns
            ERROR_OBJECT_NOT_FOUND - it returns ERROR_BAD_NUMBER if
            you specify a size of 0).  If the value would overflow
            the user buffer, the buffer is truncated.  The buffer
            returned is null-terminated (even if GVF_BINARY_VAR is
            used).  The number of characters put in the buffer (not
            including '0') is returned, and [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) will return the
            the size of the variable.
