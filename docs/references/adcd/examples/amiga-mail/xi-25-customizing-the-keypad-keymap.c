/* Source: ADCD 2.1
 * Section: xi-25-customizing-the-keypad-keymap
 * Library: amiga-mail
 * ADCD reference: amiga-mail/xi-25-customizing-the-keypad-keymap.md
 */

    DC.B        0,0,$A0,$20     ;key 0x40: nil, nil, the Alted-space key maps to $A0 which
                                ;  is the ANSI Non-Breakable Space (NBSP), the plain space
                                ;  key maps to $20 which is the space character.
    DC.B        0,0,0,$08       ;key 0x41: Back Space key only
    DC.L        newkey42        ;key 0x42: definition for string to output for Tab key
        ...                     ;(other keys)
