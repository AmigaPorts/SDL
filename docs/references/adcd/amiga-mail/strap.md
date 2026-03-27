---
title: Strap
manual: amiga-mail
chapter: amiga-mail
section: strap
functions: [FindResident, InitResident, OpenDevice]
libraries: [exec.library]
---

# Strap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* romboot.library is gone.

* audio.device cannot be OpenDevice()ed by a boot block program because
  it is not yet InitResident()ed.  If OpenDevice() of audio.device fails
  during strap, you must FindResident()/InitResident() audio.device, and
  then try OpenDevice() again.

* Boot from other floppies (+5,-10,-20,-30) is possible.

* Undocumented system stack and register usage at Diag and Boot time
  have changed.

---

## See Also

- [FindResident — exec.library](../autodocs/exec.library.md#findresident)
- [InitResident — exec.library](../autodocs/exec.library.md#initresident)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
