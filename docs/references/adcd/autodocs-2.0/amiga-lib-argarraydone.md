---
title: amiga.lib/ArgArrayDone
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-argarraydone
functions: []
libraries: []
---

# amiga.lib/ArgArrayDone

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ArgArrayDone -- release the memory allocated by a previous call
                    to [ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md). (V36)
```
SYNOPSIS

```c
    ArgArrayDone();

    VOID ArgArrayDone(VOID);
```
FUNCTION

```c
    This function frees memory and does cleanup required after a
    call to [ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md). Don't call this until you are done using
    the ToolTypes argument strings.
```
SEE ALSO

```c
    [ArgArrayInit()](autodocs-2.0/amiga-lib-argarrayinit.md)
```
