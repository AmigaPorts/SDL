---
title: printer.device/CMD_WRITE
manual: autodocs-2.0
chapter: autodocs-2.0
section: printer-device-cmd-write
functions: []
libraries: []
---

# printer.device/CMD_WRITE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMD_WRITE -- send output to the printer
FUNCTION

```c
    This function causes a buffer of characters to be written to the
    current printer port (usually parallel or serial).  The number of
    characters is specified in io_Length, unless -1 is used, in which
    case output is sent until a 0x00 is encountered.

    The Printer device, like the Console device, maps ANSI X3.64 style
    7-bit printer control codes to the control code set of the current
    printer.  The ANSI codes supported can be found below.
```
NOTES

```c
    Not all printers will support all functions.  In particular you may
    not assume that the MARGINS or TABS can be set.  Close to half the
    supported printers don't fully implement one or the other.  If you
    want the features of margins or tabs you will need to fake it
    internally by sending out spaces.

    Note that the printer device may have already sent out a "set
    margins" command to the printer.  If you are faking your own
    margins, be sure to cancel the old ones first.  (use the "aCAM"
    command)

    Defaults are set up so that if a normal AmigaDOS text file
    is sent to PRT:, it has the greatest chance of working.
    (AmigaDOS text files are defined as follows:)
            tabs            - every 8
            CR (0x0D)       - moves to start of current line
            LF (0x0A)       - moves to start of next line
```
IO REQUEST

```c
    io_Message      mn_ReplyPort set
    io_Device       preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Unit         preset by [OpenDevice](autodocs-2.0/exec-library-opendevice.md)
    io_Command      CMD_WRITE
    io_Length       number of characters to process, or if -1,
                    process until 0x00 encountered
    io_Data         pointer to block of data to process
```
RESULTS

    io_Error : if CMD_WRITE succeeded, then io_Error will be zero.
               Otherwise io_Error will be non-zero.
SEE ALSO

```c
    printer.h, parallel.device, serial.device, [Preferences](autodocs-2.0/includes-intuition-preferences-h.md)
```
ANSI X3.64 style COMMANDS

```c
    aRIS         ESCc            hard reset
    aRIN         ESC#1           initialize to defaults
    aIND         ESCD            true linefeed (lf)
    aNEL         ESCE            return,lf
    aRI          ESCM            reverse lf              *

    aSGR0        ESC[0m          normal character set
    aSGR3        ESC[3m          italics on
    aSGR23       ESC[23m         italics off
    aSGR4        ESC[4m          underline on
    aSGR24       ESC[24m         underline off
    aSGR1        ESC[1m          boldface on
    aSGR22       ESC[22m         boldface off
    aSFC         SGR30-39        set foreground color
    aSBC         SGR40-49        set background color

    aSHORP0      ESC[0w          normal pitch
    aSHORP2      ESC[2w          elite on
    aSHORP1      ESC[1w          elite off
    aSHORP4      ESC[4w          condensed on
    aSHORP3      ESC[3w          condensed off
    aSHORP6      ESC[6w          enlarged on
    aSHORP5      ESC[5w          enlarged off

    aDEN6        ESC[6"z         shadow print on
    aDEN5        ESC[5"z         shadow print off
    aDEN4        ESC[4"z         doublestrike on
    aDEN3        ESC[3"z         doublestrike off
    aDEN2        ESC[2"z         Near Letter Quality (NLQ) on
    aDEN1        ESC[1"z         NLQ off

    aSUS2        ESC[2v          superscript on
    aSUS1        ESC[1v          superscript off
    aSUS4        ESC[4v          subscript on
    aSUS3        ESC[3v          subscript off
    aSUS0        ESC[0v          normalize the line      *
    aPLU         ESCL            partial line up         *
    aPLD         ESCK            partial line down       *

    aFNT0        ESC(B           US char set (default)   or Font 0
    aFNT1        ESC(R           French char set         or Font 1
    aFNT2        ESC(K           German char set         or Font 2
    aFNT3        ESC(A           UK char set             or Font 3
    aFNT4        ESC(E           Danish I char set       or Font 4
    aFNT5        ESC(H           Sweden char set         or Font 5
    aFNT6        ESC(Y           Italian char set        or Font 6
    aFNT7        ESC(Z           Spanish char set        or Font 7
    aFNT8        ESC(J           Japanese char set       or Font 8
    aFNT9        ESC(6           Norweign char set       or Font 9
    aFNT10       ESC(C           Danish II char set      or Font 10

    aPROP2       ESC[2p          proportional on         *
    aPROP1       ESC[1p          proportional off        *
    aPROP0       ESC[0p          proportional clear      *
    aTSS         ESC[n E         set proportional offset *
    aJFY5        ESC[5 F         auto left justify       *
    aJFY7        ESC[7 F         auto right justify      *
    aJFY6        ESC[6 F         auto full justify       *
    aJFY0        ESC[0 F         auto justify off        *
    aJFY3        ESC[3 F         letter space (justify)  *
    aJFY1        ESC[1 F         word fill(auto center)  *

    aVERP0       ESC[0z          1/8" line spacing
    aVERP1       ESC[1z          1/6" line spacing
    aSLPP        ESC[nt          set form length n
    aPERF        ESC[nq          set perforation skip to n lines (n>0)
    aPERF0       ESC[0q          perforation skip off

    aLMS         ESC#9           Left margin set         *
    aRMS         ESC#0           Right margin set        *
    aTMS         ESC#8           Top margin set          *
    aBMS         ESC#2           Bottom margin set       *
    aSTBM        ESC[Pn1;Pn2r    set T&B margins         *
    aSLRM        ESC[Pn1;Pn2s    set L&R margin          *
    aCAM         ESC#3           Clear margins

    aHTS         ESCH            Set horiz tab           *
    aVTS         ESCJ            Set vertical tabs       *
    aTBC0        ESC[0g          Clr horiz tab           *
    aTBC3        ESC[3g          Clear all h tab         *
    aTBC1        ESC[1g          Clr vertical tabs       *
    aTBC4        ESC[4g          Clr all v tabs          *
    aTBCALL      ESC#4           Clr all h & v tabs      *
    aTBSALL      ESC#5           Set default tabs (every 8)

    aEXTEND      ESC[Pn"x        Extended commands
                                 This is a mechanism for printer drivers
                                 to support extra commands which can be
                                 called by ANSI control sequences
    aRAW         ESC[Pn"r        Next 'Pn' chars are raw (ie. they are not
                                 parsed by the printer device, instead
                                 they are sent directly to the printer.


    (*) indicates that sending this command may cause unexpected results
        on a large number of printers.
```
