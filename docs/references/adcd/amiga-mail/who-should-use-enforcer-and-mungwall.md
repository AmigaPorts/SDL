---
title: Who Should Use Enforcer and Mungwall
manual: amiga-mail
chapter: amiga-mail
section: who-should-use-enforcer-and-mungwall
functions: []
libraries: []
---

# Who Should Use Enforcer and Mungwall

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you are developing Amiga software, it is extremely important that
you invest in a MMU, or at the very least make sure that your software
is tested on machines with  Enforcer and Mungwall (also test with
Enforcer alone as Mungwall can hide certain types of bugs).  If you are
programming in assembly, you should also test with Scratch by Bill
Hawes to catch improper usage of CPU registers.

Enforcer and Mungwall are not just for developers and QA departments.
Anyone who uses software can help find bugs in it with Enforcer.
During normal usage, they can catch hidden software problems.  Many
people at Commodore run Enforcer all of the time.  As more and more
people begin running these tools, they will become less tolerant of
software that causes Enforcer and Mungwall hits.

At a small developer meeting at a recent Amiga trade show, CATS was
disappointed to discover that, although the majority of the audience
believed that they needed Enforcer, a relatively small percentage of
them owned the equipment necessary to run it (i.e.,  an MMU).  If you
don't have an MMU, get one.  The investment in an A3000, 68030 card, or
68020+MMU card will quickly pay for itself.  It significantly cuts down
development time because it quickly catches bugs that are otherwise
hard to track down.

