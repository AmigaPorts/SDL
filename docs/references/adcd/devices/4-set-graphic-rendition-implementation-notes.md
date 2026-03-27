---
title: 4 / / Set Graphic Rendition Implementation Notes
manual: devices
chapter: devices
section: 4-set-graphic-rendition-implementation-notes
functions: []
libraries: []
---

# 4 / / Set Graphic Rendition Implementation Notes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Previous versions of the operating system did not support the global
background color sequence as is listed above.  Instead, the background
color was set by setting the character cell color and then clearing the
screen (e.g., a FORMFEED).

In fact, vacated areas of windows (vacated because of an ERASE or SCROLL)
were filled in with the character cell color.  This is no longer the case.
Now, when an area is vacated, it is filled in with the global background
color.

SMART_REFRESH windows are a special case:

Under V33-V34:
   The cell color had to be set and a FORMFEED (clear window) needed to
   be sent on resize or immediately to clear the window and set the
   background color.

   For example, if you took a CLI window and sent the sequence to set the
   cell color to something other than the default,the background color
   would not be changed immediately (contrary to what was expected).

   If you then sent a FORMFEED,the background color would change,but if you
   resized the window larger, you would note that the newly revealed areas
   were filled in with PEN 0.

Under V36-V37 (non-character mapped):
   You need to set the global background color and do a FormFeed.  The
   background color will then be used to fill the window, but like
   V33-V34, if you make the window larger, the vacated areas will be
   filled in with PEN 0.

Under V36-V37 (character mapped):
   You need to set the global background color, the window is redrawn
   immediately (because we have the character map) and will be correctly
   redrawn with the global background color on subsequent resizes.

The sequences in the next table are not ANSI standard sequences, they are
private Amiga sequences. In these command descriptions, length, width, and
offset are comprised of one or more ASCII digits, defining a decimal value.


```c
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
     "[Selecting Raw Input Events](devices/4-console-device-selecting-raw-input-events.md)"
     section below  for more details.)

    INPUT EVENT REPORT                         9B <parameters> 7C
    (returned by the console device
     in response to a raw event
     set by the SET RAW EVENT sequence.
     See the "[Input Event Reports](devices/4-console-device-input-event-reports.md)"
     section below for more details.)

    RESET RAW EVENTS                           9B <events> 7D
    (reset the raw events set by
     the SET RAW EVENT sequence. See the
     "[Selecting Raw Input Events](devices/4-console-device-selecting-raw-input-events.md)"
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
     "[Window Bounds Report](devices/4-reading-from-the-console-device-window-bounds-report.md)" below.)

    WINDOW BOUNDS REPORT                       9B 31 3B 31 3B <bot margin>
    (returned by the console device in         3B <right margin> 72
     response to a WINDOW STATUS REQUEST
     sequence)

    RIGHT AMIGA V PRESS                        9B 30 20 76
    (returned by the console device when
     the user presses RIGHT-AMIGA-V.  See
     the "[Copy and Paste Support](devices/4-console-device-copy-and-paste-support.md)" section
     below for more details.)
```
   Give Back What You Take.
   ------------------------
   The console device normally handles the SET PAGE LENGTH, SET LINE
   LENGTH, SET LEFT OFFSET, and SET TOP OFFSET functions automatically.
   To allow it to do so again after setting your own values, send the
   functions without a parameter.

