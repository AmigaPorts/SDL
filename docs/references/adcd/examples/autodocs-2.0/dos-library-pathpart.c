/* Source: ADCD 2.1
 * Section: dos-library-pathpart
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-pathpart.md
 */

    This function returns a pointer to the character after the next-to-last
    component of a path specification, which will normally be the directory
    name.  If there is only one component, it returns a pointer to the
    beginning of the string.  The only real difference between this and
    [FilePart()](../Includes_and_Autodocs_2._guide/node02A4.html) is the handling of '/'.
