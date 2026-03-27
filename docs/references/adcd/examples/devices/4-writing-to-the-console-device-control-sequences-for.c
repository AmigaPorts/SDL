/* Source: ADCD 2.1
 * Section: 4-writing-to-the-console-device-control-sequences-for
 * Library: devices
 * ADCD reference: devices/4-writing-to-the-console-device-control-sequences-for.md
 */

                      ANSI CONSOLE CONTROL SEQUENCES

                                              Sequence of Characters
    Console Command                           (in Hexadecimal Form)
    ---------------                           ---------------------
    BELL                                       07
    (Flash the display
     ie; do an Intuition DisplayBeep())

    BACKSPACE                                  08
    (move left one column)

    HORIZONTAL TAB                             09
    (move right one tab stop)

    LINEFEED                                   0A
    (move down one text line as
     specified by the mode function)

    VERTICAL TAB                               0B
    (move up one text line)

    FORMFEED                                   0C
    (clear the console's window)

    CARRIAGE RETURN                            0D
    (move to first column)

    SHIFT IN                                   OE
    (undo SHIFT OUT)

    SHIFT OUT                                  0F
    (set MSB of each character
     before displaying)

    ESC                                        1B
    (escape; can be part of the
     control sequence introducer)

    INDEX                                      84
    (move the active position down
     one line)

    NEXT LINE                                  85
    (go to the beginning of the next
     line)

    HORIZONTAL TABULATION SET                  88
    (Set a tab at the active cursor
     position)

    REVERSE INDEX                              8D
    (move the active position up one
     line)

    CSI                                        9B
    (control sequence introducer)

    RESET TO INITIAL STATE 1B                  63

    INSERT [N] CHARACTERS 9B [N]               40
    (insert one or more spaces,
     shifting the remainder of the line
     to the right)

    CURSOR UP [N] CHARACTER POSITIONS          9B [N] 41
    (default = 1)

    CURSOR DOWN [N] CHARACTER POSITIONS        9B [N] 42
    (default = 1)

    CURSOR FORWARD [N] CHARACTER POSITIONS     9B [N] 43
    (default = 1)

    CURSOR BACKWARD [N] CHARACTER              9B [N] 44
    (default = 1)

    CURSOR NEXT LINE [N]                       9B [N] 45
    (to column 1)

    CURSOR PRECEDING LINE [N]                  9B [N] 46
    (to column 1)

    CURSOR POSITION                            9B [N] [3B M] 48
    (where N is row, M is column, and
    semicolon (hex 3B) must be present
    as a separator, or if row is left
    out, so the console device can tell
    that the number after the semicolon
    actually represents the column number)

    CURSOR HORIZONTAL TABULATION               9B [N] 49
    (move cursor forward to Nth tab
     position)

    ERASE IN DISPLAY                           9B 4A
    (only to end of display)

    ERASE IN LINE                              9B 4B
    (only to end of line)

    INSERT LINE                                9B 4C
    (above the line containing the
     cursor)

    DELETE LINE                                9B 4D
    (remove current line, move
     all lines up one position to
     fill gap, blank bottom line)

    DELETE CHARACTER [N]                       9B [N] 50
    (that cursor is sitting on
     and to the right if
    [N] is specified)

    SCROLL UP [N] LINES                        9B [N] 53
    (Remove line(s) from top of window,
     move all other lines up, blanks [N]
     bottom lines)

    SCROLL DOWN [N] LINES                      9B [N] 54
    (Remove line(s) from bottom of
     window, move all other lines down,
     blanks [N] top lines)

    CURSOR TABULATION CONTROL                  9B [N] 57
    (where N = 0 set tab, 2 = clear tab,
     5 = clear all tabs.)

    CURSOR BACKWARD TABULATION                 9B [N] 5A
    (move cursor backward to Nth
     tab position.)

    SET LINEFEED MODE                          9B 32 30 68
    (cause LINEFEED to respond
     as RETURN-LINEFEED)

    RESET NEWLINE MODE                         9B 32 30 6C
    (cause LINEFEED to respond
     only as LINEFEED)

    DEVICE STATUS REPORT                       9B 36 6E
    (cause console device to
     insert a CURSOR POSITION REPORT
     into your read stream; see
     "[Reading from the Console Device](../Devices_Manual_guide/node008F.html)"
     for more information)

    SELECT GRAPHIC RENDITION                  9B N 3B 3N 3B 4N 3B >N 6D
    (select text style, character color,      (See note below).
     character cell color,background color)
