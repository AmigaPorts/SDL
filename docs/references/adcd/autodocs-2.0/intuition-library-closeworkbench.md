---
title: intuition.library/CloseWorkBench
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-closeworkbench
functions: [CloseWorkBench, OpenWorkBench]
libraries: [intuition.library]
---

# intuition.library/CloseWorkBench

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CloseWorkBench -- Closes the Workbench screen.
SYNOPSIS

```c
    Success = CloseWorkBench()
    D0

    LONG CloseWorkBench( VOID );
```
FUNCTION
    This routine attempts to close the Workbench screen:
   -   Test whether or not any applications have opened windows on the
       Workbench, and return FALSE if so.  Otherwise ...
   -   Clean up all special buffers
   -   Close the Workbench screen
   -   Make the Workbench program mostly inactive (it will still
```c
       monitor disk activity)
```
   -   Return TRUE

INPUTS

    None
RESULT

    TRUE if the Workbench screen closed successfully
    FALSE if the Workbench was not open, or if it has windows
        open which are not Workbench drawers.
NOTES

    This routine has been drastically rewritten for V36.
    It is much more solid, although we haven't eliminated
    all the problem cases yet.
BUGS

```c
    The name of this function is improperly spelled.  It ought
    to have been CloseWorkbench().

    It might be more convenient to have it return TRUE if the
    Workbench wasn't opened when called.  The idea as it is now
    is probably this: if you want to free up the memory of the
    Workbench screen when your program begins, you can call
    CloseWorkBench().  The return value of that call indicates
    whether you should call [OpenWorkBench()](autodocs-2.0/intuition-library-openworkbench.md) when your program
    exits: if FALSE, that means either the the Workbench existed
    but you could not close it, or that it wasn't around to
    begin with, and you should not try to re-open it.

    We would prefer that you provide a user selection to attempt
    to open or close the Workbench screen from within your application,
    rather than your making assumptions like these.
```
SEE ALSO

```c
    [OpenWorkBench()](autodocs-2.0/intuition-library-openworkbench.md)
```

---

## See Also

- [CloseWorkBench — intuition.library](../autodocs/intuition.library.md#closeworkbench)
- [OpenWorkBench — intuition.library](../autodocs/intuition.library.md#openworkbench)
