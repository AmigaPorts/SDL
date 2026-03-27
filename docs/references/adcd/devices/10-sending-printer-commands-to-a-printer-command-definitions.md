---
title: 10 / Sending Printer Commands to a Printer / Command Definitions
manual: devices
chapter: devices
section: 10-sending-printer-commands-to-a-printer-command-definitions
functions: []
libraries: []
---

# 10 / Sending Printer Commands to a Printer / Command Definitions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following table describes the supported printer functions.

   Just Because We Have It Doesn't Mean You Do.
   --------------------------------------------
   Not all printers support every command.  Unsupported commands will
   either be ignored or simulated using available functions.

To transmit a command to the printer device, you can either formulate a
character stream containing the material shown in the "Escape Sequence"
column of the table below or send an [PRD_PRTCOMMAND](autodocs-2.0/printer-device-prd-prtcommand.md) device I/O command
to the printer device with the "Name" of the function you wish to
perform.

                     PRINTER DEVICE COMMAND FUNCTIONS

           Cmd     Escape                                          Defined
   Name    No.     Sequence   Function                               by:
   ----    ---     --------   --------                             -------
   aRIS    0       ESCc       Reset                                ISO
   aRIN    1       ESC#1      Initialize                           +++
   aIND    2       ESCD       Linefeed                             ISO
   aNEL    3       ESCE       Return,linefeed                      ISO
   aRI     4       ESCM       Reverse linefeed                     ISO
   aSGR0   5       ESC[0m     Normal char set                      ISO
   aSGR3   6       ESC[3m     Italics on                           ISO
   aSGR23  7       ESC[23m    Italics off                          ISO
   aSGR4   8       ESC[4m     Underline on                         ISO
   aSGR24  9       ESC[24m    Underline off                        ISO
   aSGR1   10      ESC[1m     Boldface on                          ISO
   aSGR22  11      ESC[22m    Boldface off                         ISO
   aSFC    12      ESC[nm     Set foreground color where n         ISO

```c
                              stands for a pair of ASCII digits,
                              3 followed by any number 0-9
                              (See ISOColor Table)
```
   aSBC    13      ESC[nm     Set background color where n         ISO

```c
                              stands for a pair of ASCII digits,
                              4 followed by any number 0-9
                              (See ISO Color Table)
```
   aSHORP0 14      ESC[0w     Normal pitch                         DEC
   aSHORP2 15      ESC[2w     Elite on                             DEC
   aSHORP1 16      ESC[1w     Elite off                            DEC
   aSHORP4 17      ESC[4w     Condensed fine on                    DEC
   aSHORP3 18      ESC[3w     Condensed off                        DEC
   aSHORP6 19      ESC[6w     Enlarged on                          DEC
   aSHORP5 20      ESC[5w     Enlarged off                         DEC
   aDEN6   21      ESC[6"z    Shadow print on                      DEC
   aDEN5   22      ESC[5"z    Shadow print off            (sort of)DEC
   aDEN4   23      ESC[4"z    Doublestrike on                      DEC
   aDEN3   24      ESC[3"z    Doublestrike off                     DEC
   aDEN2   25      ESC[2"z    NLQ on                               DEC
   aDEN1   26      ESC[1"z    NLQ off                              DEC

   aSUS2   27      ESC[2v     Superscript on                       +++
   aSUS1   28      ESC[1v     Superscript off                      +++
   aSUS4   29      ESC[4v     Subscript on                         +++
   aSUS3   30      ESC[3v     Subscript off                        +++
   aSUS0   31      ESC[0v     Normalize the line                   +++
   aPLU    32      ESCL       Partial line up                      ISO
   aPLD    33      ESCK       Partial line down                    ISO

   aFNT0   34      ESC(B      US char set or Typeface 0            DEC
   aFNT1   35      ESC(R      French char set or Typeface 1        DEC
   aFNT2   36      ESC(K      German char set or Typeface 2        DEC
   aFNT3   37      ESC(A      UK char set or Typeface 3            DEC
   aFNT4   38      ESC(E      Danish I char set or Typeface 4      DEC
   aFNT5   39      ESC(H      Swedish char set or Typeface 5       DEC
   aFNT6   40      ESC(Y      Italian char set or Typeface 6       DEC
   aFNT7   41      ESC(Z      Spanish char set or Typeface 7       DEC
   aFNT8   42      ESC(J      Japanese char set or Typeface 8      +++
   aFNT9   43      ESC(6      Norwegian char set or Typeface 9     DEC
   aFNT10  44      ESC(C      Danish II char set or Typeface 10    +++

```c
                              (See Suggested Typefaces Table)
```
   aPROP2  45      ESC[2p     Proportional on                      +++
   aPROP1  46      ESC[1p     Proportional off                     +++
   aPROP0  47      ESC[0p     Proportional clear                   +++
   aTSS    48      ESC[n E    Set proportional offset              ISO
   aJFY5   49      ESC[5 F    Auto left justify                    ISO
   aJFY7   50      ESC[7 F    Auto right justify                   ISO
   aJFY6   51      ESC[6 F    Auto full justify                    ISO
   aJFY0   52      ESC[0 F    Auto justify off                     ISO
   aJFY3   53      ESC[3 F    Letter space (justify)      (special)ISO
   aJFY1   54      ESC[1 F    Word fill(auto center)      (special)ISO

   aVERP0  55      ESC[0z     1/8" line spacing                    +++
   aVERP1  56      ESC[1z     1/6" line spacing                    +++
   aSLPP   57      ESC[nt     Set form length n                    DEC
   aPERF   58      ESC[nq     Perf skip n (n>0)                    +++
   aPERF0  59      ESC[0q     Perf skip off                        +++

   aLMS    60      ESC#9      Left margin set                      +++
   aRMS    61      ESC#0      Right margin set                     +++
   aTMS    62      ESC#8      Top margin set                       +++
   aBMS    63      ESC#2      Bottom margin set                    +++
   aSTBM   64      ESC[n;     nr Top and bottom margins            DEC
   aSLRM   65      ESC[n;     ns Left and right margins DEC
   aCAM    66      ESC#3      Clear margins +++

   aHTS    67      ESCH       Set horizontal tab                   ISO
   aVTS    68      ESCJ       Set vertical tabs                    ISO
   aTBC0   69      ESC[0g     Clear horizontal tab                 ISO
   aTBC3   70      ESC[3g     Clear all h. tabs                    ISO
   aTBC1   71      ESC[1g     Clear vertical tab                   ISO
   aTBC4   72      ESC[4g     Clear all v. tabs                    ISO
   aTBCALL 73      ESC#4      Clear all h. & v. tabs               +++
   aTBSALL 74      ESC#5      Set default tabs                     +++
   aEXTEND 75      ESC[n"x    Extended commands                    +++

   aRAW    76      ESC[n"r    Next n chars are raw                 +++

   Legend:
   ------
   ISO     indicates that the sequence has been defined by the

           International Standards Organization.  This is
           also very similar to ANSI x3.64.
   DEC     indicates a control sequence defined by Digital Equipment

           Corporation.
   +++     indicates a sequence unique to Amiga.

   n       stands for a decimal number expressed as a set of ASCII

           digits. In the aRAW string ESC[5"rHELLO, n is substituted by 5,
           the number of RAW characters you send to the printer.

           ISO Color Table            Suggested Typefaces
           ---------------            -------------------
           0  Black                   0   Default typeface
           1  Red                     1   Line Printer or equivalent
           2  Green                   2   Pica or equivalent
           3  Yellow                  3   Elite or equivalent
           4  Blue                    4   Helvetica or equivalent
           5  Magenta                 5   Times Roman or equivalent
           6  Cyan                    6   Gothic or equivalent
           7  White                   7   Script or equivalent
           8  NC                      8   Prestige or equivalent
           9  Default                 9   Caslon or equivalent
                                      10  Orator or equivalent
