/* Source: ADCD 2.1
 * Section: 34-keymap-library-keyboard-layout
 * Library: libraries
 * ADCD reference: libraries/34-keymap-library-keyboard-layout.md
 */

    60        Shift (left of space bar)
    61        Shift (right of space bar)
    62        Caps Lock
    63        Ctrl
    64        (Left) Alt
    65        (Right) Alt
    66        Amiga (left of space bar)            Left Amiga
    67        Amiga (right of space bar)           Right Amiga
    68        Left mouse button (not converted)    Inputs are only for the
    69        Right mouse button (not converted)   mouse connected to
    6A        Middle mouse button (not converted)  Intuition, (currently
    6B        (undefined)                          gameport one).
    6C        (undefined)
    6D        (undefined)
    6E        (undefined)
    6F        (undefined)
    70-7F     (undefined)
    80-F8     Up transition (release or unpress key of one
              of the above keys) (80 for 00, F8 for 7F)
    F9        Last key code was bad
              (was sent in order to resynchronize)
    FA        Keyboard buffer overflow
    FB        (undefined, reserved for
              keyboard processor catastrophe)
    FC        Keyboard selftest failed
    FD        Power-up key stream start.
              Keys pressed or stuck at power-up
              will be sent between FD and FE.
    FE        Power-up key stream end
    FF        (undefined, reserved)
    FF        Mouse event, movement only,
              no button change (not converted)


    Notes about the preceding table:

    1) "<CSI>" is the Control Sequence Introducer, value hex 9B.

    2) "(undefined)" indicates that the current keyboard design should not
       generate this number.  If you are using [SetKeyMap()](../Libraries_Manual_guide/node046C.html#line6) to change the
       key map, the entries for these numbers must still be included.

    3) "(not converted)" refers to mouse button events. You must use the
       sequence "<CSI>2{" to inform the console driver that you wish to
       receive mouse events; otherwise these will not be transmitted.

    4) "(RESERVED)" indicates that these key codes have been reserved for
       national keyboards.  The $2B code key will be between the
       double-quote (") and Return keys. The $30 code key will be between
       the Shift and Z keys.


          +---------------------------------------------------------------+
          | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
          | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |
          | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 |
          | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |
          |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
          | 00| 01| 02| 03| 04| 05| 06| 07| 08| 09| 0a| 0b| 0c| 0d| 0e| 0f|
