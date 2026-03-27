---
title: utility.library/ToLower
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-tolower
functions: []
libraries: []
---

# utility.library/ToLower

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ToLower - Convert a character to lowercase. (V37)
```
SYNOPSIS

```c
    char = ToLower(char)
    D0              D0

    char ToLower(char);
```
FUNCTION

    Converts a character to lowercase, handling international character
    sets.
INPUTS

    char - character to be converted.
RESULT

    char - lowercase version of input character.
NOTES

    Commodore is planning a localization library which will take care
    of most details pertaining to system integration into different
    cultures, locales, and territories.

    This function will automatically be replaced by a localized version
    whenever the locale.library is loaded in memory. As such, the
    resulting converted character may change depending on the locale
    currently defined by the user. Take this fact into consideration when
    using this function, and do not rely on obtaining specific
    conversions.
BUGS

SEE ALSO

