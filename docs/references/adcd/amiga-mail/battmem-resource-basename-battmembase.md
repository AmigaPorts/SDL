---
title: battmem.resource (basename: _BattMemBase)
manual: amiga-mail
chapter: amiga-mail
section: battmem-resource-basename-battmembase
functions: []
libraries: []
---

# battmem.resource (basename: _BattMemBase)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ObtainBattSemaphore()()                 - Obtain access to nonvolatile
```c
                                          ram. (V36)
```
ReadBattMem(buffer,offset,length)(a0,d0/d1)
```c
                                        - Read a bitstring from
                                          nonvolatile ram.  (V36)
```
ReleaseBattSemaphore()()                - Allow nonvolatile ram to others.
```c
                                           (V36)
```
WriteBattMem(buffer,offset,length)(a0,d0/d1)

```c
                                        - Write a bitstring to nonvolatile
                                          ram.  (V36)
```
