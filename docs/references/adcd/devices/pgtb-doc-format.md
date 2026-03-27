---
title: PGTB.doc / Format
manual: devices
chapter: devices
section: pgtb-doc-format
functions: []
libraries: []
---

# PGTB.doc / Format

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    'PGTB'       - chunk identifier
    length       - longword for length of chunk

    'FAIL'       - subfield giving environment at time of crash
    length       - longword length of subfield
    NameLen      - length of program name in longwords (BSTR)
    Name         - program name packed in longwords
    Environment  - copy of AttnFlags field from ExecBase,
                   gives type of processor, and existence of
                   math chip
    VBlankFreq   - copy of VBlankFrequency field from ExecBase
    PowerSupFreq - copy of PowerSupplyFrequency field from ExecBase
                   above fields may be used to determine whether
                   machine was PAL or NTSC
    Starter      - non-zero = CLI, zero = WorkBench
    GURUNum      - exception number of crash
    SegCount     - number of segments for program
    SegList      - copy of seglist for program
                   (Includes all seglist pointers, paired with
                    sizes of the segments)

    'REGS'       - register dump subfield
    length       - length of subfield in longwords
    GURUAddr     - PC at time of crash
    Flags        - copy of Condition Code Register
    DDump        - dump of data registers
    ADump        - dump of address registers

    'VERS'       - revision of program which created this file
    length       - length of subfield in longwords
    version      - main version of writing program
    revision     - minor revision level of writing program
    TBNameLen    - length of name of writing program
    TBName       - name of writing program packed in longwords (BSTR)

    'STAK'       - stack dump subfield
    length       - length of subfield in longwords
    (type)       - tells type of stack subfield, which can be any of
                   the following:

    -----------------------------------------------------------
    Info            - value 0
    StackTop        - address of top of stack
    StackPtr        - stack pointer at time of crash
    StackLen        - number of longwords on stack

    -----------------------------------------------------------
    Whole stack     - value 1
                      only used if total stack to be dumped is 8k
                      or less in size
    Stack           - dump of stack from current to top

    -----------------------------------------------------------
    Top 4k          - value 2
                      if stack used larger than 8k, this part
                      is a dump of the top 4k
    Stack           - dump of stack from top - 4k to top

    -----------------------------------------------------------
    Bottom 4k       - value 3
                      if stack used larger than 8k, this part
                      is a dump of the bottom 4k
    Stack           - dump of stack from current to current + 4k
```
In other words, we will dump a maximum of 8k of stack data.  This does NOT
mean the stack must be less than 8k in size to dump the entire stack, just
that the amount of stack USED be less than 8k.


```c
    'UDAT'       - Optional User DATa chunk.  If the user assigns
                   a function pointer to the label "_ONGURU", the
                   catcher will call this routine prior to closing
                   the SnapShot file, passing one parameter on the
                   stack - an AmigaDOS file pointer to the SnapShot
                   file.  Spec for the _ONGURU routine:

                         void <function name>(fp)
                         long fp;

                   In other words, your routine must be of type 'void'
                   and must take one parameter, an AmigaDOS file
                   handle (which AmigaDOS wants to see as a LONG).
    length       - length of the UserDATa chunk, calculated after the
                   user routine terminates.
```
