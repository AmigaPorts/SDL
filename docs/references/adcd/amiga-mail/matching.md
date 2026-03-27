---
title: Matching
manual: amiga-mail
chapter: amiga-mail
section: matching
functions: [IoErr, MatchPattern, MatchPatternNoCase]
libraries: [dos.library]
---

# Matching

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once a pattern is parsed, it can be compared to a string using either the
case sensitive MatchPattern() or the case insensitive MatchPatternNoCase()
functions.  These functions have the following synopsis:


```c
    BOOL MatchPattern(UBYTE *mytokenpattern, UBYTE *mystring);
    BOOL MatchPatternNoCase (UBYTE *mytokenpattern, UBYTE *mystring);
```
These functions will compare the wildcard pattern string, mytokenpattern
(created by ParsePattern/NoCase()), to mystring.  If mystring matches the
pattern in mytokenpattern, these routines return TRUE, otherwise they
return FALSE.

Because these routines are recursive, they can use a lot of stack space,
although they will not use more than 1500 bytes of stack space.  Make sure
the stack space is at least 1500 bytes before calling these routines.

In V36, these routines did not perform any stack checking.  This was added
in V37.  If either of these functions detect a stack overflow, they will
return 0 and IoErr() will return ERROR_TOO_MANY_LEVELS.  If IoErr()
returns 0, there was simply no match.  The [Pattern.c](amiga-mail/ii-37-pattern-c.md) example at the end of
this article shows how to use the parse and match functions and allows you
to test and experiment with patterns.

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [MatchPattern — dos.library](../autodocs/dos.library.md#matchpattern)
- [MatchPatternNoCase — dos.library](../autodocs/dos.library.md#matchpatternnocase)
