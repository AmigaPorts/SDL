---
title: exec.library/SetExcept
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-setexcept
functions: []
libraries: []
---

# exec.library/SetExcept

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetExcept -- define certain signals to cause exceptions
SYNOPSIS

```c
    oldSignals = SetExcept(newSignals, signalMask)
    D0                     D0          D1

    ULONG SetExcept(ULONG,ULONG);
```
FUNCTION

```c
    This function defines which of the task's signals will cause a
    private task exception.  When any of the signals occurs the task's
    exception handler will be dispatched.  If the signal occurred prior
    to calling SetExcept, the exception will happen immediately.

    The user function pointed to by the task's tc_ExceptCode gets
    called as:

        newExcptSet = <exceptCode>(signals, exceptData),SysBase
        D0                         D0       A1          A6

        signals - The set of signals that caused this exception.  These
            Signals have been disabled from the current set of signals
            that can cause an exception.

        exceptData - A copy of the task structure tc_ExceptData field.

        newExcptSet - The set of signals in NewExceptSet will be re-
            enabled for exception generation.  Usually this will be the
            same as the Signals that caused the exception.
```
INPUTS

    newSignals - the new values for the signals specified in
            signalMask.
    signalMask - the set of signals to be effected
RESULTS

    oldSignals - the prior exception signals
EXAMPLE

```c
    Get the current state of all exception signals:
        SetExcept(0,0)
    Change a few exception signals:
        SetExcept($1374,$1074)
```
SEE ALSO

```c
    [Signal](autodocs-2.0/exec-library-signal.md), [SetSignal](autodocs-2.0/exec-library-setsignal.md)
```
