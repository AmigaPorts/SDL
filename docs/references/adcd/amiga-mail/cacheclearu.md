---
title: CacheClearU
manual: amiga-mail
chapter: amiga-mail
section: cacheclearu
functions: [CacheClearE, CacheClearU]
libraries: [exec.library]
---

# CacheClearU

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

exec.library/CacheClearU                          exec.library/CacheClearU

NAME

```c
    CacheClearU - User callable simple cache clearing (V37)
```
SYNOPSIS

```c
    CacheClearU()

    void CacheClearU();
```
FUNCTION

```c
    Flush out the contents of any CPU instruction and data caches.
    If dirty data cache lines are present, push them to memory first.

    Caches must be cleared after *any* operation that could cause
    invalid or stale data.  The most common cases are DMA and modifying
    instructions using the processor.  See the CacheClearE() autodoc
    for a more complete description.

    Some examples of when the cache needs clearing:
                    Self modifying code
                    Building Jump tables
                    Run-time code patches
                    Relocating code for use at different addresses.
                    Loading code from disk
```
SEE ALSO

    exec/execbase.i, CacheControl, CacheClearE

---

## See Also

- [CacheClearE — exec.library](../autodocs/exec.library.md#cachecleare)
- [CacheClearU — exec.library](../autodocs/exec.library.md#cacheclearu)
