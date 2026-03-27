# CacheClearU


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
