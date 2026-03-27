/* Source: ADCD 2.1
 * Section: dos-library-getprompt
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-getprompt.md
 */

    Extracts the prompt string from the CLI structure and puts it
    into the buffer.  If the buffer is too small, the string is truncated
    appropriately and a failure code returned.  If no CLI structure is
    present, a null string is returned in the buffer, and failure from
    the call (with [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) == ERROR_OBJECT_WRONG_TYPE);
