---
title: dos.library/UnLockDosList
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-unlockdoslist
functions: [AttemptLockDosList, LockDosList, Permit]
libraries: [dos.library, exec.library]
---

# dos.library/UnLockDosList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    UnLockDosList -- Unlocks the Dos [List](autodocs-2.0/includes-exec-lists-h.md) (V36)
```
SYNOPSIS

```c
    UnLockDosList(flags)
                    D1

    void UnLockDosList(ULONG)
```
FUNCTION

```c
    Unlocks the access on the Dos [Device](autodocs-2.0/includes-exec-devices-h.md) [List](autodocs-2.0/includes-exec-lists-h.md).  You MUST pass the same
    flags you used to lock the list.
```
INPUTS

```c
    flags - MUST be the same flags passed to (Attempt)LockDosList()
```
SEE ALSO

```c
    [AttemptLockDosList()](autodocs-2.0/dos-library-attemptlockdoslist.md), [LockDosList()](autodocs-2.0/dos-library-lockdoslist.md), [Permit()](autodocs-2.0/exec-library-permit.md)
```

---

## See Also

- [AttemptLockDosList — dos.library](../autodocs/dos.library.md#attemptlockdoslist)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
