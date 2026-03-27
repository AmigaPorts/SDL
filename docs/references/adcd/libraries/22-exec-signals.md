---
title: 22 Exec Signals
manual: libraries
chapter: libraries
section: 22-exec-signals
functions: []
libraries: []
---

# 22 Exec Signals

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Tasks often need to coordinate with other concurrent system activities
(like other tasks and interrupts).  This coordination is handled by Exec
through the synchronized exchange of specific event indicators called
signals.

This is the primary mechanism responsible for all intertask communication
and synchronization on the Amiga.  This signal mechanism operates at a low
level and is designed for high performance.  Signals are used extensively
by the Exec message system as a way to indicate the arrival of an
inter-task message.  The message system is described in more detail in the
"[Exec Messages and Ports](libraries/24-exec-messages-and-ports-messages.md)" chapter.


```c
    Not for Beginners.
    ------------------
    This chapter concentrates on details about signals that most
    applications do not need to understand for general Amiga programming.
    For a general overview of signals, see the "[Introduction to Exec](libraries/17-introduction-to-exec-signals.md)"
    chapter of this manual.
```
 [The Signal System](libraries/22-exec-signals-the-signal-system.md)    [Function Reference](libraries/22-exec-signals-function-reference.md) 

