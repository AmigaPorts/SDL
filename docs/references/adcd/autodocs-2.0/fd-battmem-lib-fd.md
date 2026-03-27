---
title: FD/battmem_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-battmem-lib-fd
functions: []
libraries: []
---

# FD/battmem_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "battmem.resource"
##base _BattMemBase
##bias 6
##public
ObtainBattSemaphore()()
ReleaseBattSemaphore()()
ReadBattMem(buffer,offset,length)(a0,d0/d1)
WriteBattMem(buffer,offset,length)(a0,d0/d1)
##end

