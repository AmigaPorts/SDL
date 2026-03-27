/* Source: ADCD 2.1
 * Section: 9-event-message-classes-and-flags-other-flags
 * Library: libraries
 * ADCD reference: libraries/9-event-message-classes-and-flags-other-flags.md
 */

    IDCMP_RAWKEY messages give the raw keycodes from the keyboard. The
    numeric value of the keycode is sent in the [Code](../Libraries_Manual_guide/node01D9.html#line33) field. Separate
    codes are returned for key down and key up.  Qualifier codes, such as
    Shift or Alt and whether this key is a repeat, may be found in the
    [Qualifier](../Libraries_Manual_guide/node01D9.html#line45) field of the message.

    In general, the application should not assume any correspondence
    between the keycode and the key value.  Character positions on the
    keyboard change from country to country, and the application should
    respect the keymap set by the user.

    Programs using IDCMP_RAWKEY messages should perform their own key
    mapping by calling the console.device function [RawKeyConvert()](../Includes_and_Autodocs_2._guide/node050A.html), or
    the keymap.library function [MapRawKey()](../Libraries_Manual_guide/node046D.html).  (The latter is a bit more
    convenient, but is only available under V36 and higher).  The Autodoc
    for the MapRawKey() function shows how you can process so-called dead
    keys.  A dead key is a key combination that has no immediate effect,
    but instead modifies a subsequent keystroke.  For example, on the
    default keymap, Alt-F is a dead key for the acute accent mark.  The
    sequence of Alt-F followed by the E key yields an é with an acute
    accent.

    For an example of key mapping using the [RawKeyConvert()](../Includes_and_Autodocs_2._guide/node050A.html) call, see the
    [rawkey.c](../Devices_Manual_guide/node0191.html) example in the "Intuition Mouse and Keyboard" chapter.

    The application can assume that certain keys will always return the
    same raw keycode, these keys do not have to be mapped.  In general
    these keys are in the high part of the keymap, above hex 40, and
    includes all non-alphanumeric keys.  The fixed keys include the
    function keys, backspace, delete, help and cursor keys.
