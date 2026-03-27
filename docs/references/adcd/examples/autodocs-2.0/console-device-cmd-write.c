/* Source: ADCD 2.1
 * Section: console-device-cmd-write
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/console-device-cmd-write.md
 */

    Codes are specified in the standard fashion for ANSI documents,
    as the two 4 bit nibbles that comprise the character code,
    high nibble first, separated by a slash.  Thus 01/11 (ESC) is
    a character with the hex value 1B (or the decimal value 27).

    A character on the Amiga falls into one of the following four
    ranges:
    00/ 0-01/15     C0: ASCII control characters.  See below.
    02/ 0-07/15     G0: ASCII graphic characters.  These characters
                    have an image that is displayed.  Note that the
                    DEL character is displayed by the Console Device:
                    it is not treated as control character here.
    08/ 0-09/15     C1: ANSI 3.41 control characters.  See below.
    10/ 0-15/15     G1: ECMA 94 Latin 1 graphic characters.

    Independent Control Functions (no introducer) --
    Code    Name    Definition
    -----   ---     ----------------------------------------------
    00/ 7   BEL     BELL: actually an Intuition [DisplayBeep()](../Includes_and_Autodocs_2._guide/node020C.html)
    00/ 8   BS      BACKSPACE
    00/ 9   HT      HORIZONTAL TAB
    00/10   LF      LINE FEED
    00/11   VT      VERTICAL TAB
    00/12   FF      FORM FEED
    00/13   CR      CARRIAGE RETURN
    00/14   SO      SHIFT OUT: causes all subsequent G0 (ASCII)
                    characters to be shifted to G1 (ECMA 94/1)
                    characters.
    00/15   SI      SHIFT IN: cancels the effect of SHIFT OUT.
    01/11   ESC     ESCAPE

    Code or Esc Name Definition
    -----   --- ---- ---------------------------------------------
    08/ 4   D   IND  INDEX: move the active position down one line.
    08/ 5   E   NEL  NEXT LINE
    08/ 8   H   HTS  HORIZONTAL TABULATION SET
    08/13   M   RI   REVERSE INDEX
    09/11   [   CSI  CONTROL SEQUENCE INTRODUCER: see next list

    ISO Compatible Escape Sequences (introduced by Esc) --
    Esc   Name Definition
    ----- ---- ---------------------------------------------------
    c     RIS  RESET TO INITIAL STATE: reset the console display.

    Control Sequences, with the number of indicated parameters.
    i.e. <CSI><parameters><control sequence letter(s)>.  Note the
    last entries consist of a space and a letter.  CSI is either
    9B or Esc[.  A minus after the number of parameters (#p)
    indicates less is valid.  Parameters are separated by
    semicolons, e.g. Esc[14;80H sets the cursor position to row
    14, column 80.
    CSI #p  Name Definition
    --- --- ---- -------------------------------------------------
    @   1-  ICH  INSERT CHARACTER
    A   1-  CUU  CURSOR UP
    B   1-  CUD  CURSOR DOWN
    C   1-  CUF  CURSOR FORWARD
    D   1-  CUB  CURSOR BACKWARD
    E   1-  CNL  CURSOR NEXT LINE
    F   1-  CPL  CURSOR PRECEDING LINE
    H   2-  CUP  CURSOR POSITION
    I   1-  CHT  CURSOR HORIZONTAL TABULATION
    J   1-  ED   ERASE IN DISPLAY (only to end of display)
    K   1-  EL   ERASE IN LINE (only to end of line)
    L   1-  IL   INSERT LINE
    M   1-  DL   DELETE LINE
    P   1-  DCH  DELETE CHARACTER
    R   2   CPR  CURSOR POSITION REPORT (in Read stream only)
    S   1-  SU   SCROLL UP
    T   1-  SD   SCROLL DOWN
    W   n   CTC  CURSOR TABULATION CONTROL
    Z   1-  CBT  CURSOR BACKWARD TABULATION
    f   2-  HVP  HORIZONTAL AND VERTICAL POSITION
    g   1-  TBC  TABULATION CLEAR
    h   n   SM   SET MODE: see modes below.
    l   n   RM   RESET MODE: see modes below.
    m   n   SGR  SELECT GRAPHIC RENDITION
    n   1-  DSR  DEVICE STATUS REPORT
    t   1-  aSLPP SET PAGE LENGTH (private Amiga sequence)
    u   1-  aSLL SET LINE LENGTH (private Amiga sequence)
    x   1-  aSLO SET LEFT OFFSET (private Amiga sequence)
    y   1-  aSTO SET TOP OFFSET (private Amiga sequence)
    {   n   aSRE SET RAW EVENTS (private Amiga sequence)
    |   8   aIER INPUT EVENT REPORT (private Amiga Read sequence)
    }   n   aRRE RESET RAW EVENTS (private Amiga sequence)
    ~   1   aSKR SPECIAL KEY REPORT (private Amiga Read sequence)
     p  1-  aSCR SET CURSOR RENDITION (private Amiga sequence)
     q  0   aWSR WINDOW STATUS REQUEST (private Amiga sequence)
     r  4   aWBR WINDOW BOUNDS REPORT (private Amiga Read sequence)
     v  1   aRAV RIGHT AMIGA V PRESS (private Amiga Read sequence-V37)

    Modes, set with <CSI><mode-list>h, and cleared with
    <CSI><mode-list>l, where the mode-list is one or more of the
    following parameters, separated by semicolons --
    Mode    Name Definition
    ------- ---- -------------------------------------------------
    20      LNM  LINEFEED NEWLINE MODE: if a linefeed is a newline
    >1      ASM  AUTO SCROLL MODE: if scroll at bottom of window
    ?7      AWM  AUTO WRAP MODE: if wrap at right edge of window
