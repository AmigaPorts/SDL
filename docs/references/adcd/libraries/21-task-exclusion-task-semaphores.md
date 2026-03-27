---
title: 21 / Task Exclusion / Task Semaphores
manual: libraries
chapter: libraries
section: 21-task-exclusion-task-semaphores
functions: []
libraries: []
---

# 21 / Task Exclusion / Task Semaphores

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Semaphores can be used for the purposes of mutual exclusion.  With this
method of locking, all tasks agree on a locking convention before
accessing shared data structures.  Tasks that do not require access are
not affected and will run normally, so this type of exclusion is
considered preferable to forbidding and disabling.  This form of exclusion
is explained in more detail in the "[Exec Semaphores](libraries/25-the-signal-semaphore-obtaining-a-signalsemaphore.md)" chapter.

