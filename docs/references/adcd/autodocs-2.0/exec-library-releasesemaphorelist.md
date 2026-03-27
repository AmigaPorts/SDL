---
title: exec.library/ReleaseSemaphoreList
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-releasesemaphorelist
functions: [ObtainSemaphoreList, ReleaseSemaphoreList]
libraries: [exec.library]
---

# exec.library/ReleaseSemaphoreList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ReleaseSemaphoreList -- make a list of semaphores available
SYNOPSIS

```c
    ReleaseSemaphoreList(list)
                         A0

    void ReleaseSemaphoreList(struct [List](autodocs-2.0/includes-exec-lists-h.md) *);
```
FUNCTION

```c
    ReleaseSemaphoreList() is the inverse of [ObtainSemaphoreList()](autodocs-2.0/exec-library-obtainsemaphorelist.md). It
    releases each element in the semaphore list.

    Needless to say, havoc breaks out if the task releases more times
    than it has obtained.
```
INPUT
   list -- a list of signal semaphores

SEE ALSO

```c
    [ObtainSemaphoreList()](autodocs-2.0/exec-library-obtainsemaphorelist.md)
```

---

## See Also

- [ObtainSemaphoreList — exec.library](../autodocs/exec.library.md#obtainsemaphorelist)
- [ReleaseSemaphoreList — exec.library](../autodocs/exec.library.md#releasesemaphorelist)
