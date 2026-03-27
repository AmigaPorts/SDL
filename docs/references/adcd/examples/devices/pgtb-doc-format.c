/* Source: ADCD 2.1
 * Section: pgtb-doc-format
 * Library: devices
 * ADCD reference: devices/pgtb-doc-format.md
 */

    'UDAT'       - Optional User DATa chunk.  If the user assigns
                   a function pointer to the label "_ONGURU", the
                   catcher will call this routine prior to closing
                   the SnapShot file, passing one parameter on the
                   stack - an AmigaDOS file pointer to the SnapShot
                   file.  Spec for the _ONGURU routine:

                         void <function name>(fp)
                         long fp;

                   In other words, your routine must be of type 'void'
                   and must take one parameter, an AmigaDOS file
                   handle (which AmigaDOS wants to see as a LONG).
    length       - length of the UserDATa chunk, calculated after the
                   user routine terminates.
