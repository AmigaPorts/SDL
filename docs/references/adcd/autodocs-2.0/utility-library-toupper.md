---
title: utility.library/ToUpper
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-toupper
functions: []
libraries: []
---

# utility.library/ToUpper

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ToUpper - Convert a character to uppercase. (V37)
```
SYNOPSIS

```c
    char = ToUpper(char)
    D0              D0

    char ToUpper(char);
```
FUNCTION

    Converts a character to uppercase, handling international character
    sets.
INPUTS

    char - character to be converted.
RESULT

    char - uppercase version of input character.
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

