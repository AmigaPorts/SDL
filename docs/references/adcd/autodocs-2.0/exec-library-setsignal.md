---
title: exec.library/SetSignal
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-setsignal
functions: []
libraries: []
---

# exec.library/SetSignal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetSignal -- define the state of this task's signals
SYNOPSIS

```c
    oldSignals = SetSignal(newSignals, signalMask)
    D0                     D0          D1

    ULONG SetSignal(ULONG,ULONG);
```
FUNCTION

    This function can query or modify the state of the current task's
    received signal mask.  Setting the state of signals is considered
    dangerous.  Reading the state of signals is safe.
INPUTS

    newSignals - the new values for the signals specified in
                 signalSet.
    signalMask - the set of signals to be affected.
RESULTS

    oldSignals - the prior values for all signals
EXAMPLES

```c
    Get the current state of all signals:
        SetSignal(0L,0L);
    Clear the CTRL-C signal:
        SetSignal(0L,SIGBREAKF_CTRL_C);


    Check if the CTRL-C signal was pressed:

        #include [<libraries/dos.h>](autodocs-2.0/includes-libraries-dos-h.md)

        /* Check & clear CTRL_C signal */
        if(SetSignal(0L,SIGBREAKF_CTRL_C) & SIGBREAKF_CTRL_C)
            {
            printf("CTRL-C pressed!n");
            }
```
SEE ALSO

```c
    [Signal](autodocs-2.0/exec-library-signal.md), Wait
```
