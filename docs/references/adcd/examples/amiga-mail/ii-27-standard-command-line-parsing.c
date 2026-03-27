/* Source: ADCD 2.1
 * Section: ii-27-standard-command-line-parsing
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-27-standard-command-line-parsing.md
 */

    strings (or integers as this modifier can be used with the /N
    modifier), returning them as an array of strings.  Any arguments not
    considered to be part of another option will be added to this option.
    Only one /M should appear in a template.  Example: for a template
    ``Dir/M,All/S'' the command-line ``foo bar all qwe'' will set the
    boolean ``all'', and return an array consisting of ``foo'', ``bar'',
    and ``qwe''.  The entry in the array will be a pointer to an array of
    string pointers, the last of which will be NULL.
