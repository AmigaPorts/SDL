---
title: audio.device/BeginIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: audio-device-beginio-2
functions: []
libraries: []
---

# audio.device/BeginIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       BeginIO - dispatch a device command
   SYNOPSIS

```c
       BeginIO(iORequest);
                   A1
```
   FUNCTION

       BeginIO has the responsibility of dispatching all device commands.
       Immediate commands are always called directly, and all other commands
       are queued to make them single threaded.
   INPUTS

```c
       iORequest -- pointer to the I/O [Request](autodocs-3.5/intuition-library-request-2.md) for this command
```
