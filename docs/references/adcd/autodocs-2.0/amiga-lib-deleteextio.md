---
title: amiga.lib/DeleteExtIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-deleteextio
functions: []
libraries: []
---

# amiga.lib/DeleteExtIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    DeleteExtIO - return memory allocated for extended IO request
SYNOPSIS

```c
    DeleteExtIO(ioReq);

    VOID DeleteExtIO(struct [IORequest](autodocs-2.0/includes-exec-io-h.md) *);
```
FUNCTION

```c
    Frees up an IO request as allocated by [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).
```
INPUTS

```c
    ioReq - the [IORequest](autodocs-2.0/includes-exec-io-h.md) block to be freed, or NULL.
```
SEE ALSO

```c
    [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)
```
