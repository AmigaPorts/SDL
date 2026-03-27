---
title: narrator.device/AbortIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: narrator-device-abortio
functions: []
libraries: []
---

# narrator.device/AbortIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AbortIO - Abort an IO request
SYNOPSIS

```c
    AbortIO(IORequest)
               A1
```
FUNCTION

```c
    Exec library call to abort a specified READ or WRITE request.
    The [IORequest](autodocs-2.0/includes-exec-io-h.md) may be in the queue or currently active.  If
    currently active, the request is immediately stopped and then
    removed.
```
INPUTS

```c
    Pointer to the [IORequest](autodocs-2.0/includes-exec-io-h.md) block to be aborted.
```
RESULTS

```c
    io_Error field in the [IORequest](autodocs-2.0/includes-exec-io-h.md) block set to #IOERR_ABORTED.
```
SEE ALSO

