/* Source: ADCD 2.1
 * Section: dos-library-getvar
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-getvar.md
 */

    LV_VAR is the only type that can be global.
    Under V36, we documented (and it returned) the size of the variable,
    not the number of characters transferred.  For V37 this was changed
    to the number of characters put in the buffer, and the total size
    of the variable is put in [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).
