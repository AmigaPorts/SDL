---
title: E / Release 2 Changes That Can Affect Compatibility / Trackdisk Device
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility-trackdisk
functions: []
libraries: []
---

# E / Release 2 Changes That Can Affect Compatibility / Trackdisk Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * Private trackdisk structures have changed.  See [trackdisk.doc](autodocs-2.0/trackdisk-doc.md) for a

```c
    compatible [REMCHANGEINT](autodocs-2.0/trackdisk-device-td-remchangeint.md).
```
  * Buffer is freeable, so low memory open failure is possible.

  * Do not disable interrupts (any of them), then expect trackdisk to

    function while they are disabled.
