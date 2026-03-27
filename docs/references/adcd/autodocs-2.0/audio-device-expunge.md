---
title: audio.device/Expunge
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-expunge
functions: []
libraries: []
---

# audio.device/Expunge

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    EXPUNGE - indicate a desire to remove the Audio device
FUNCTION

```c
    The Expunge routine is called when a user issues a [RemDevice](autodocs-2.0/exec-library-remdevice.md) call.  By
    the time it is called, the device has already been removed from the
    device list, so no new opens will succeed.  The existence of any other
    users of the device, as determined by the device open count being
    non-zero, will cause the Expunge to be deferred.  When the device is
    not in use, or no longer in use, the Expunge is actually performed.
```
