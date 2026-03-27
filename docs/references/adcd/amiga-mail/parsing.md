---
title: Parsing
manual: amiga-mail
chapter: amiga-mail
section: parsing
functions: [ParsePattern, ParsePatternNoCase]
libraries: [dos.library]
---

# Parsing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When you want to use a string as an AmigaDOS wildcard pattern, the system
must first parse it.  The system builds a token string which the system
uses to match strings.  There are two functions in dos.library to parse
pattern matching strings:


```c
    LONG ParsePattern(UBYTE *SourcePattern, UBYTE *MyDestination,
                        LONG DestLength);

    LONG ParsePatternNoCase(UBYTE *SourcePattern, UBYTE *MyDestination,
                              LONG DestLength);
```
The ParsePattern() function creates a case sensitive token string, whereas
the ParsePatternNoCase() functions creates a case insensitive token
string.  Both functions require a pointer to a destination buffer
(MyDestination in the above prototype) to place the tokenized string in.
Since every character in the pattern can be expanded to two tokens (3 in
one case), this buffer should be at twice as as large as the original
pattern plus 2 bytes.  As a general rule, allocating a buffer three times
the size of the pattern will hold all patterns.  The third argument,
DestLength, indicates the size of the destination buffer provided.  These
functions will returns one of three values:


-1    if there is an error (if the buffer is too small to hold all the

```c
      tokens or the source string contains an invalid pattern),
```
1     if the wildcard pattern was parsed successfully and the pattern

      contains one of the special token characters.
0     if the wildcard pattern was parsed successfully and pattern

```c
      contained only alphanumeric characters (no special token
      characters)
```

---

## See Also

- [ParsePattern — dos.library](../autodocs/dos.library.md#parsepattern)
- [ParsePatternNoCase — dos.library](../autodocs/dos.library.md#parsepatternnocase)
