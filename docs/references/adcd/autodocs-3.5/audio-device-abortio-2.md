---
title: audio.device/AbortIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: audio-device-abortio-2
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

```c
       iORequest -- pointer to the I/O [Request](autodocs-3.5/intuition-library-request-2.md) for the command to abort
```
