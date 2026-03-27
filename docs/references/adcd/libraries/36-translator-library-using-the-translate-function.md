---
title: 36 Translator Library / Using the Translate Function
manual: libraries
chapter: libraries
section: 36-translator-library-using-the-translate-function
functions: []
libraries: []
---

# 36 Translator Library / Using the Translate Function

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once the library is open, you can call the translate function:


```c
    #define BUFLEN 500

    STRPTR EnglStr;                 /* pointer to sample input string */
    LONG EnglLen;                   /* input length */
    UBYTE PhonBuffer[BUFLEN];       /* place to put the translation */
    LONG rtnCode;                   /* return code from function */

    EnglStr = "This is Amiga speaking.";    /* a test string */
    EnglLen = strlen(EnglStr);
    rtnCode = Translate(EnglStr, EnglLen, (STRPTR)&PhonBuffer[0], BUFLEN);
```
The input string will be translated into its phonetic equivalent and can
be used to feed the narrator device. If you receive a non-zero return
code, you haven't provided enough output buffer space to hold the entire
translation. In this case, the [Translate()](autodocs-2.0/translator-library-translate.md) function breaks the translation
at the end of a word in the input stream and returns the position in the
input stream at which the translation ended. You can use the output
buffer, then call the Translate() function again, starting at this
original ending position, to continue the translation where you left off.
This method will sound smoothest if the ending position ends on sentence
boundaries.


```c
    [Translate()](autodocs-2.0/translator-library-translate.md) returns negative values.
    ------------------------------------
    To get the proper character offset, you must use -(rtnCode) as
    the starting point for a new translation.
```
