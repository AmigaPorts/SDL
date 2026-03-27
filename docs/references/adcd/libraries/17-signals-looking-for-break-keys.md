---
title: 17 / Signals / Looking for Break Keys
manual: libraries
chapter: libraries
section: 17-signals-looking-for-break-keys
functions: []
libraries: []
---

# 17 / Signals / Looking for Break Keys

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One common usage of signals on the Amiga is for processing a user break.
As was mentioned earlier, the OS reserves 16 of a tasks 32 signals for
system use.  Four of those 16 signals are used to tell a task about the
Control-C, D, E, and F break keys.  An application can process these
signals.  Usually, only CLI-based programs receive these signals because
the Amiga's console handler is about the only user input source that sets
these signals when it sees the Control-C, D, E, and F key presses.

The signal masks for each of these key presses are defined in <dos/[dos.h](autodocs-2.0/includes-dos-dos-h.md)>:


    SIGBREAKF_CTRL_C
    SIGBREAKF_CTRL_D
    SIGBREAKF_CTRL_E
    SIGBREAKF_CTRL_F
Note that these are bit masks and not bit numbers.

