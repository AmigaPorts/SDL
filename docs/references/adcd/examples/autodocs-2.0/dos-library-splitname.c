/* Source: ADCD 2.1
 * Section: dos-library-splitname
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-splitname.md
 */

    This routine splits out the next piece of a name from a given file
    name.  Each piece is copied into the buffer, truncating at size-1
    characters.  The new position is then returned so that it may be
    passed in to the next call to splitname.  If the separator is not
    found within 'size' characters, then size-1 characters plus a null will
    be put into the buffer, and the position of the next separator will
    be returned.

    If a a separator cannot be found, -1 is returned (but the characters
    from the old position to the end of the string are copied into the
    buffer, up to a maximum of size-1 characters).  Both strings are
    null-terminated.

    This function is mainly intended to support handlers.
