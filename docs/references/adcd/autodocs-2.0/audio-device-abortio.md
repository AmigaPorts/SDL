---
title: audio.device/AbortIO
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-abortio
functions: []
libraries: []
---

# audio.device/AbortIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AbortIO - abort a device command
SYNOPSIS

```c
    AbortIO(iORequest);
                A1
```
FUNCTION

    AbortIO tries to abort a device command.  It is allowed to be
    unsuccessful.  If the Abort is successful, the io_Error field of the
    iORequest contains an indication that IO was aborted.
INPUTS

    iORequest -- pointer to the I/O Request for the command to abort
