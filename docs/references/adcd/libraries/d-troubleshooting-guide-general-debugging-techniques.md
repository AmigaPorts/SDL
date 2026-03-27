---
title: D Troubleshooting Guide / General Debugging Techniques
manual: libraries
chapter: libraries
section: d-troubleshooting-guide-general-debugging-techniques
functions: []
libraries: []
---

# D Troubleshooting Guide / General Debugging Techniques

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Narrow the search

```c
    Use methodical testing procedures, and debugging messages if
    necessary, to locate the problem area.  Low level code can be
    debugged using [KPrintF()](autodocs-2.0/debug-lib-kprintf.md) serial (or dprintf() parallel) messages.
    Check the initial values, allocation, use, and freeing of all
    pointers and structures used in the problem area.  Check that all of
    your system and internal function calls pass correct initialized
    arguments, and that all possible error returns are checked for and
    handled.
```
Isolate the problem

    If errors cannot be found, simplify your code to the smallest
    possible example that still functions.  Often you will find that this
    smallest example will not have the problem.  If so, add back the
    other features of your code until the problem reappears, then debug
    that section.
Use debugging tools

    A variety of debugging tools are available to help locate faulty
    code. Some of these are source level and other debuggers, crash
    interceptors, vital watchdog and memory invalidation tools like
    Enforcer and MungWall.
