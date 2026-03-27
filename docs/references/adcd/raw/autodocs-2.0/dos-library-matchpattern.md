# dos.library/MatchPattern



NAME

```c
    MatchPattern --  Checks for a pattern match with a string (V36)
```
SYNOPSIS

```c
    match = MatchPattern(pat, str)
    D0                   D1   D2

    BOOL MatchPattern(STRPTR, STRPTR)
```
FUNCTION

```c
    Checks for a pattern match with a string.  The pattern must be a
    tokenized string output by [ParsePattern()](../Includes_and_Autodocs_2._guide/node02DB.html).  This routine is
    case-sensitive.

    NOTE: this routine is highly recursive.  You must have at least
    1500 free bytes of stack to call this (it will cut off it's
    recursion before going any deeper than that and return failure).
    That's _currently_ enough for about 100 levels deep of #, (, ~, etc.
```
INPUTS

```c
    pat - Special pattern string to match as returned by [ParsePattern()](../Includes_and_Autodocs_2._guide/node02DB.html)
    str - String to match against given pattern
```
RESULT

```c
    match - success or failure of pattern match.  On failure,
            [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) will return 0 or ERROR_TOO_MANY_LEVELS (starting
            with V37 - before that there was no stack checking).
```
SEE ALSO

```c
    [ParsePattern()](../Includes_and_Autodocs_2._guide/node02DB.html), [MatchPatternNoCase()](../Includes_and_Autodocs_2._guide/node02D0.html), [MatchFirst()](../Includes_and_Autodocs_2._guide/node02CD.html), [MatchNext()](../Includes_and_Autodocs_2._guide/node02CE.html)
```
