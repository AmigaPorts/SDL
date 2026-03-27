/* Source: ADCD 2.1
 * Section: 4-set-graphic-rendition-implementation-notes
 * Library: devices
 * ADCD reference: devices/4-set-graphic-rendition-implementation-notes.md
 */

                     AMIGA CONSOLE CONTROL SEQUENCES

        Console Command             Sequence of Characters(in Hex Format)
    ----------------------          -------------------------------------
    ENABLE SCROLL(default)                     9B 3E 31 68

    DISABLE SCROLL                             9B 3E 31 6C

    AUTOWRAP ON (default)                      9B 3F 37 68

    AUTOWRAP OFF                               9B 3F 37 6C

    SET PAGE LENGTH                            9B <length> 74
    (in character raster lines, causes
     console to recalculate,using
     current font, how many text lines
     will fit on the page)

    SET LINE LENGTH                            9B <width> 75
    (in character positions, using
     current font, how many characters
     should be placed on each line)

    SET LEFT OFFSET                            9B <offset> 78
    (in raster columns, how far from
     the left of the window should
     the text begin)

    SET TOP OFFSET                             9B <offset> 79
    (in raster lines, how far
     from the top of the window's
     RastPort should the topmost
     line of the character begin)

    SET RAW EVENTS                             9B <events> 7B
    (set the raw input events that
     will trigger an INPUT EVENT
     REPORT. see the
     "[Selecting Raw Input Events](../Devices_Manual_guide/node0094.html)"
     section below  for more details.)

    INPUT EVENT REPORT                         9B <parameters> 7C
    (returned by the console device
     in response to a raw event
     set by the SET RAW EVENT sequence.
     See the "[Input Event Reports](../Devices_Manual_guide/node0095.html)"
     section below for more details.)

    RESET RAW EVENTS                           9B <events> 7D
    (reset the raw events set by
     the SET RAW EVENT sequence. See the
     "[Selecting Raw Input Events](../Devices_Manual_guide/node0094.html)"
     section below.)

    SPECIAL KEY REPORT                         9B <keyvalue> 7E
    (returned by the console device
     whenever HELP, or one of the
     function keys or arrow keys is
     pressed.  Some sequences do not end
     with 7E)

    SET CURSOR RENDITION                       9B N 20 70
    (make the cursor visible or invisible:
     Note-turning off the cursor increases
     text output speed)

        Invisible:                             9B 30 20 70
        Visible:                               9B 20 70

    WINDOW STATUS REQUEST                      9B 30 20 71
    (ask the console device to tell you
     the current bounds of the window,
     in upper and lower row and column
     character positions.  User may have
     resized or repositioned it.See
     "[Window Bounds Report](../Devices_Manual_guide/node0092.html)" below.)

    WINDOW BOUNDS REPORT                       9B 31 3B 31 3B <bot margin>
    (returned by the console device in         3B <right margin> 72
     response to a WINDOW STATUS REQUEST
     sequence)

    RIGHT AMIGA V PRESS                        9B 30 20 76
    (returned by the console device when
     the user presses RIGHT-AMIGA-V.  See
     the "[Copy and Paste Support](../Devices_Manual_guide/node0093.html)" section
     below for more details.)
