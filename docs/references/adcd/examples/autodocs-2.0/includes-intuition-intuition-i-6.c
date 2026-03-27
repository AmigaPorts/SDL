/* Source: ADCD 2.1
 * Section: includes-intuition-intuition-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-intuition-i.md
 */

    STRUCT im_ExecMessage,MN_SIZE

    ; the Class bits correspond directly with the IDCMP Flags, except for the
    ; special bit IDCMP_LONELYMESSAGE (defined below)
    LONG im_Class

    ; the Code field is for special values like MENU number
    WORD im_Code

    ; the Qualifier field is a copy of the current InputEvent's Qualifier
    WORD im_Qualifier

    ; IAddress contains particular addresses for Intuition functions, like
    ; the pointer to the Gadget or the Screen
    APTR im_IAddress

    ; when getting mouse movement reports, any event you get will have the
    ; the mouse coordinates in these variables.  the coordinates are relative
    ; to the upper-left corner of your Window (WFLG_GIMMEZEROZERO
    ; notwithstanding)
    ; If the DELTAMOVE IDCMP flag is set, these values will be deltas from
    ; the last reported position.
    WORD im_MouseX
    WORD im_MouseY

    ; the time values are copies of the current system clock time.  Micros
    ; are in units of microseconds, Seconds in seconds.
    LONG im_Seconds
    LONG im_Micros

    ; the IDCMPWindow variable will always have the address of the Window of
    ; this IDCMP
    APTR im_IDCMPWindow

    ; system-use variable
    APTR im_SpecialLink

    LABEL  im_SIZEOF
