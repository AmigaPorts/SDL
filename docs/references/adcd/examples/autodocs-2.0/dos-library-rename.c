/* Source: ADCD 2.1
 * Section: dos-library-rename
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-rename.md
 */

    Rename() attempts to rename the file or directory specified as
    'oldName' with the name 'newName'. If the file or directory
    'newName' exists, Rename() fails and returns an error. Both
    'oldName' and the 'newName' can contain a directory specification.
    In this case, the file will be moved from one directory to another.

    Note: it is impossible to Rename() a file from one volume to
    another.
