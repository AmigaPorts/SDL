---
title: dos.library/MatchFirst
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-matchfirst
functions: [IoErr, MatchEnd, MatchFirst, MatchNext, ParsePattern]
libraries: [dos.library]
---

# dos.library/MatchFirst

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    MatchFirst -- Finds file that matches pattern (V36)
```
SYNOPSIS

```c
    error = MatchFirst(pat, AnchorPath)
    D0                 D1       D2

    LONG MatchFirst(STRPTR, struct [AnchorPath](autodocs-2.0/includes-dos-dosasl-h.md) *)
```
FUNCTION

```c
    Locates the first file or directory that matches a given pattern.
    MatchFirst() is passed your pattern (you do not pass it through
    [ParsePattern()](autodocs-2.0/dos-library-parsepattern.md) - MatchFirst() does that for you), and the control
    structure.  MatchFirst() normally initializes your [AnchorPath](autodocs-2.0/includes-dos-dosasl-h.md)
    structure for you, and returns the first file that matched your
    pattern, or an error.  Note that [MatchFirst()/MatchNext()](autodocs-2.0/dos-library-matchnext.md) are unusual
    for Dos in that they return 0 for success, or the error code (see
    [<dos/dos.h>](autodocs-2.0/includes-dos-dos-h.md)), instead of the application getting the error code
    from [IoErr()](autodocs-2.0/dos-library-ioerr.md).

    When looking at the result of [MatchFirst()/MatchNext()](autodocs-2.0/dos-library-matchnext.md), the ap_Info
    field of your [AnchorPath](autodocs-2.0/includes-dos-dosasl-h.md) has the results of an [Examine()](autodocs-2.0/dos-library-examine.md) of the object.
    You normally get the name of the object from fib_FileName, and the
    directory it's in from ap_Current->an_Lock.  To access this object,
    normally you would temporarily [CurrentDir()](autodocs-2.0/dos-library-currentdir.md) to the lock, do an action
    to the file/dir, and then [CurrentDir()](autodocs-2.0/dos-library-currentdir.md) back to your original directory.
    This makes certain you affect the right object even when two volumes
    of the same name are in the system.  You can use ap_Buf (with
    ap_Strlen) to get a name to report to the user.

    To initialize the [AnchorPath](autodocs-2.0/includes-dos-dosasl-h.md) structure (particularily when reusing
    it), set ap_BreakBits to the signal bits (CDEF) that you want to take
    a break on, or NULL, if you don't want to convenience the user.
    ap_Flags should be set to any flags you need or all 0's otherwise.
    ap_FoundBreak should be cleared if you'll be using breaks.

    If you want to have the FULL PATH NAME of the files you found,
    allocate a buffer at the END of this structure, and put the size of
    it into ap_Strlen.  If you don't want the full path name, make sure
    you set ap_Strlen to zero.  In this case, the name of the file, and
    stats are available in the ap_Info, as per usual.

    Then call MatchFirst() and then afterwards, [MatchNext()](autodocs-2.0/dos-library-matchnext.md) with this
    structure.  You should check the return value each time (see below)
    and take the appropriate action, ultimately calling [MatchEnd()](autodocs-2.0/dos-library-matchend.md) when
    there are no more files or you are done.  You can tell when you are
    done by checking for the normal AmigaDOS return code
    ERROR_NO_MORE_ENTRIES.

    Note: patterns with trailing slashes may cause [MatchFirst()/MatchNext()](autodocs-2.0/dos-library-matchnext.md)
    to return with an ap_Current->an_Lock on the object, and a filename
    of the empty string ("").

    See [ParsePattern()](autodocs-2.0/dos-library-parsepattern.md) for more information on the patterns.
```
INPUTS

```c
    pat        - Pattern to search for
    [AnchorPath](autodocs-2.0/includes-dos-dosasl-h.md) - Place holder for search.  MUST be longword aligned!
```
RESULT

```c
    error - 0 for success or error code.  (Opposite of most Dos calls!)
```
BUGS

```c
    In V36, there were a number of bugs with [MatchFirst()/MatchNext()](autodocs-2.0/dos-library-matchnext.md).
    One was that if you entered a directory with a name like "df0:l"
    using DODIR, it would re-lock the full string "df0:l", which can
    cause problems if the disk has changed.  It also had problems
    with patterns such as #?/abc/def - the ap_Current->an_Lock would
    not be on the directory def is found in.  ap_Buf would be correct,
    however.  It had similar problems with patterns with trailing
    slashes.  These have been fixed for V37 and later.

    A bug that has not been fixed for V37 concerns a pattern of a
    single directory name (such as "l").  If you enter such a directory
    via DODIR, it re-locks l relative to the current directory.  Thus
    you must not change the current directory before calling [MatchNext()](autodocs-2.0/dos-library-matchnext.md)
    with DODIR in that situation.  If you aren't using DODIR to enter
    directories you can ignore this.  This may be fixed in some upcoming
    release.
```
SEE ALSO

```c
    [MatchNext()](autodocs-2.0/dos-library-matchnext.md), [ParsePattern()](autodocs-2.0/dos-library-parsepattern.md), [Examine()](autodocs-2.0/dos-library-examine.md), [CurrentDir()](autodocs-2.0/dos-library-currentdir.md), [Examine()](autodocs-2.0/dos-library-examine.md),
    [MatchEnd()](autodocs-2.0/dos-library-matchend.md), [ExNext()](autodocs-2.0/dos-library-exnext.md), [<dos/dosasl.h>](autodocs-2.0/includes-dos-dosasl-h.md)
```

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [MatchEnd — dos.library](../autodocs/dos.library.md#matchend)
- [MatchFirst — dos.library](../autodocs/dos.library.md#matchfirst)
- [MatchNext — dos.library](../autodocs/dos.library.md#matchnext)
- [ParsePattern — dos.library](../autodocs/dos.library.md#parsepattern)
