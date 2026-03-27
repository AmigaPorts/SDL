---
title: icon.library (basename: _IconBase)
manual: amiga-mail
chapter: amiga-mail
section: icon-library-basename-iconbase
functions: []
libraries: []
---

# icon.library (basename: _IconBase)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

DeleteDiskObject(name)(a0)              - Delete a Workbench disk object
                                          from disk.
GetDefDiskObject(type)(d0)              - Read default wb disk object from
```c
                                          disk.       (V36)
```
GetDiskObjectNew(name)(a0)              - Read in a Workbench disk object
                                          from disk.
PutDefDiskObject(diskObject)(a0)        - Write disk object as the default

```c
                                          for its type.  (V36)
```
