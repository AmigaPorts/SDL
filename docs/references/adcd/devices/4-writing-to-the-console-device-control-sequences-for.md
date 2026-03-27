---
title: 4 / Writing to the Console Device / Control Sequences For Window Output
manual: devices
chapter: devices
section: 4-writing-to-the-console-device-control-sequences-for
functions: [DisplayBeep]
libraries: [intuition.library]
---

# 4 / Writing to the Console Device / Control Sequences For Window Output

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following table lists functions that the console device supports,
along with the character stream that you must send to the console to
produce the effect.  For more information on the control sequences,
consult the [console.doc](autodocs-2.0/console-doc.md) of the Amiga ROM Kernel Reference Manual: Includes
and Autodocs. The table uses the second form of <CSI>, that is, the hex
value 0x9B, to minimize the number of characters to be transmitted to
produce a function.

A couple of notes about the table. If an item is enclosed in square
brackets, it is optional and may be omitted.  For example, for INSERT [N]
CHARACTERS the value for N is shown as optional.  The console device
responds to such optional items by treating the value of N as 1 if it is
not specified. The value of N or M is always a decimal number, having one
or more ASCII digits to express its value.


```c
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
     "[Reading from the Console Device](devices/4-console-device-reading-from-the-console-device.md)"
     for more information)

    SELECT GRAPHIC RENDITION                  9B N 3B 3N 3B 4N 3B >N 6D
    (select text style, character color,      (See note below).
     character cell color,background color)
```
For SELECT GRAPHIC RENDITION, any number of parameters, in any order,
are valid. They are separated by semicolons.

The parameters follow:


```c
    <text style> =

        0  Plain text                      8   Concealed mode
        1  Boldface                        22  Normal color, not bold (V36)
        2  faint (secondary color)         23  Italic off (V36)
        3  Italic                          24  Underscore off (V36)
        4  Underscore                      27  Reversed off (V36)
        7  Reversed character/cell colors  28  Concealed off (V36)

    <character color> =

        30-37  System colors 0-7 for character color.
        39     Reset to default character color
               Transmitted as two ASCII characters.

    <character cell color> =

        40-47  System colors 0-7 for character cell color.
        39     Reset to default character color
               Transmitted as two ASCII characters.

    <background color> =

        >0-7System colors 0-7 for background color.(V36)
        You must specify the ">" in order for this to
        be recognized and it must be the last parameter.
```
For example, to select bold face, with color 3 as the character color, and
color 0 as the character cell color and the background color, send the hex
sequence:


    9B 31 3B 33 33 3B 34 30 3B 3E 30 6D
representing the ASCII sequence:


```c
    <CSI>1;33;40;>0m
```
where <CSI> is the control sequence introducer, here used as the single
character value 0x9B.

   Go Easy On The Eyes.
   --------------------
   In most cases, the character cell color and the background color
   should be the same.

 [Set Graphic Rendition Implementation Notes](devices/4-set-graphic-rendition-implementation-notes.md) 

---

## See Also

- [DisplayBeep — intuition.library](../autodocs/intuition.library.md#displaybeep)
