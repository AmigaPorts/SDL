/* Source: ADCD 2.1
 * Section: console-device-cmd-read
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/console-device-cmd-read.md
 */

    Read the next input, generally from the keyboard.  The form of
    this input is as an ANSI byte stream: i.e. either ASCII text
    or control sequences.  Raw input events received by the
    console device can be selectively filtered via the aSRE and aRRE
    control sequences (see the write command).  Keys are converted
    via the keymap associated with the unit, which is modified
    with AskKeyMap and SetKeyMap

    If, for example, raw keycodes had been enabled by writing
    <CSI>1{ to the console (where <CSI> is $9B or Esc[), keys
    would return raw keycode reports with the information from
    the input event itself, in the form:
    <CSI>1;0;<keycode>;<qualifiers>;0;0;<seconds>;<microseconds>q

    If there is no pending input, this command will not be
    satisfied, but if there is some input, but not as much as can
    fill io_Length, the request will be satisfied with the input
    currently available.
