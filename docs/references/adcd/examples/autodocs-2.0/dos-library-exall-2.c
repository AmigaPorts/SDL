/* Source: ADCD 2.1
 * Section: dos-library-exall
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-exall.md
 */

        If this field is NULL then all filenames will be returned.  If
        this field is non-null then it is interpreted as a pointer to
        a string that is used to pattern match all file names before
        accepting them and putting them into the buffer.  The default
        AmigaDOS caseless pattern match routine is used.  This string
        MUST have been parsed by ParsePatternNoCase()!
