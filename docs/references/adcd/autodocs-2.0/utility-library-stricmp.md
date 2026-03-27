---
title: utility.library/Stricmp
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-stricmp
functions: [Strnicmp]
libraries: [utility.library]
---

# utility.library/Stricmp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    Stricmp --  Case-insensitive string compare. (V37)
```
SYNOPSIS

```c
    res = Stricmp(string1, string2)
    D0              A0       A1

    LONG Stricmp(char *, char *);
```
FUNCTION

    Stricmp compares two strings, ignoring case.  It handles all
    internationalization issues.  If the strings have different lengths,
    the shorter is treated as if it were extended with zeros.
INPUTS

    string1, string2 - strings to be compared
RESULT

    res - negative if string1 is below string2, 0 if they're the same, and
          positive if string1 is above string2.
NOTES

    Commodore is planning a localization library which will take care
    of most details pertaining to system integration into different
    cultures, locales, and territories.

    This function will automatically be replaced by a localized version
    whenever the locale.library is loaded in memory. As such, the
    collating order may change depending on the locale currently
    defined by the user. Take this fact into consideration when using
    this function, and do not rely on obtaining specific collating
    sequences.
BUGS

SEE ALSO

```c
    [Strnicmp()](autodocs-2.0/utility-library-strnicmp.md)
```

---

## See Also

- [Strnicmp — utility.library](../autodocs/utility.library.md#strnicmp)
