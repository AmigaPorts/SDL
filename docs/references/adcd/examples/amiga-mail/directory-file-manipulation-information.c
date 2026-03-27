/* Source: ADCD 2.1
 * Section: directory-file-manipulation-information
 * Library: amiga-mail
 * ADCD reference: amiga-mail/directory-file-manipulation-information.md
 */

    Entries - This field is maintained by the file system and
    indicates the actual number of entries present in the
    buffer after the action is complete.  Note that a value of
    zero is possible here as no entries may match the match
    string.

    LastKey - This field must be initialized to 0 by the
    calling application before using this packet for the first
    time.  This field is maintained by the file system as a
    state indicator of the current place in the list of entries
    to be examined.  The file system may test this field to
    determine if this is the first or a subsequent call to this
    action.

    MatchString - This field points to a pattern matching
    string parsed by ParsePattern() or ParsePatternNoCase().
    The string controls which directory entries are returned.
    If this field is NULL, then all entries are returned.
    Otherwise, this string is used to pattern match the names
    of all directory entries before putting them into the
    buffer.  The default AmigaDOS pattern match routine is used
    unless MatchFunc is not NULL (see below).  Note that it is
    not acceptable for the application to change this field
    between subsequent calls to this action for the same
    directory.

    MatchFunc - This field contains a pointer to an alternate
    pattern matching routine to validate entries.  If it is
    NULL then the standard AmigaDOS wild card routines will be
    used.  Otherwise, MatchFunc points to a hook function that
    is called in the following manner:
