---
title: FD/disk_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-disk-lib-fd
functions: []
libraries: []
---

# FD/disk_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "disk.resource"
##base _DiskBase
##bias 6
##public
AllocUnit(unitNum)(d0)
FreeUnit(unitNum)(d0)
GetUnit(unitPointer)(a1)
GiveUnit()()
GetUnitID(unitNum)(d0)
*------ new for V37 ------
ReadUnitID(unitNum)(d0)
##end

