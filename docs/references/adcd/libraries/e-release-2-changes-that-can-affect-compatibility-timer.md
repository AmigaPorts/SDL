---
title: E / Release 2 Changes That Can Affect Compatibility / Timer Device
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility-timer
functions: []
libraries: []
---

# E / Release 2 Changes That Can Affect Compatibility / Timer Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * The most common mistake programmers make with timer.device is to send

```c
    off a particular [timerequest](autodocs-2.0/includes-devices-timer-h.md) before the previous use of that
    timerequest has completed.  Use IO_Torture to catch this.
```
  * IO_QUICK requests may be deferred and be replied as documented.

  * VBLANK timer requests, as documented, now wait at least as long as

    the full number of VBlanks you asked for.  Previously, a partial
    vertical blank could count towards your requested number.  The new
    behavior is more correct and matches the docs, but it can cause
    VBlank requests to now take up to 1 VBlank longer under 2.0 as
    compared to 1.3. For example, a 1/10 second request, may take 6-7
    Vblanks instead of 5-6 VBlanks, or about 15% longer.
