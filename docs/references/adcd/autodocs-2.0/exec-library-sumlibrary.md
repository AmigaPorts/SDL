---
title: exec.library/SumLibrary
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-sumlibrary
functions: [Alert]
libraries: [exec.library]
---

# exec.library/SumLibrary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SumLibrary -- compute and check the checksum on a library
SYNOPSIS

```c
    SumLibrary(library)
               A1

    void SumLibrary(struct [Library](autodocs-2.0/includes-exec-libraries-h.md) *);
```
FUNCTION

```c
    SumLibrary computes a new checksum on a library.  It can also be
    used to check an old checksum.  If an old checksum does not match,
    and the library has not been marked as changed, then the system
    will call [Alert()](autodocs-2.0/exec-library-alert.md).

    This call could also be periodically made by some future
    system-checking task.
```
INPUTS

    library - a pointer to the library to be changed
NOTE

    An alert will occur if the checksum fails.
SEE ALSO

```c
    [SetFunction](autodocs-2.0/exec-library-setfunction.md)
```

---

## See Also

- [Alert — exec.library](../autodocs/exec.library.md#alert)
