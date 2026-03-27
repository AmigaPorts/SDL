---
title: translator.library/Translate
manual: autodocs-2.0
chapter: autodocs-2.0
section: translator-library-translate
functions: []
libraries: []
---

# translator.library/Translate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Translate -- Convert an English string into narrator device phonemes.
SYNOPSIS

```c
    rtnCode = Translate(inString, inLength, outBuffer, outLength)
    D0                  A0        D0        A1         D1

    LONG Translate( STRPTR inString, LONG inLength, STRPTR outBuffer,
                    LONG outlen );
```
FUNCTION

    The translate function converts an English string into
    a string of phonetic codes suitable as input to the
    narrator device.
INPUTS

    inString  - pointer to English string
    inLength  - length of English string
    outBuffer - a char array which will hold the phonetic codes
    outLength - the length of the output array
RESULTS

```c
    rtnCode - zero if no error has occured.
              The only error that can occur is overflowing the outBuffer.
              If Translate() determines that an overflow will occur, it
              will stop the translation at a word boundary before the
              overflow happens.  If this occurs, rtnCode will be a
              negative number whose absolute value indicates where in
              inString Translate() stopped.  The user can then use the
              offset -rtnCode from the beginning of inString in a
              subsequent Translate() call to continue the translation.
```
SEE ALSO

```c
    [narrator.device/CMD_WRITE](autodocs-2.0/narrator-device-cmd-write.md)
```
