---
title: Using Enforcer and Mungwall Together
manual: amiga-mail
chapter: amiga-mail
section: using-enforcer-and-mungwall-together
functions: []
libraries: []
---

# Using Enforcer and Mungwall Together

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Alone, Mungwall can catch a large variety of memory-related software
problems.  If Mungwall and Enforcer are used together, they can catch
many more well-hidden bugs.  One bug that is hard to catch is when a
program either mistakenly reads memory that does not belong to the
program or reads its own memory without initializing the memory first.

These bugs are normally hard to catch because the behavior of the
errant program usually depends on how it reacts to the data that
happens to be stored in that memory.  This makes the behavior of the
bug erratic.  Sometimes the errant program may crash.  Sometimes the
errant program may write over another program's data, causing the other
program to crash.  At other times, no noticeable abnormality takes
place.

Mungwall and Enforcer together can help find these bugs.  Because
Mungwall fills freed memory with the same odd 32-bit values, when an
errant program mistakenly accesses memory,  the behavior of the bug
will be consistent while Mungwall is running.  Also, the values
Mungwall puts in memory are more likely to cause the errant program to
access Enforcer-protected memory, triggering an Enforcer hit.

