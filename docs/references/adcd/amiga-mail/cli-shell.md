---
title: CLI / Shell
manual: amiga-mail
chapter: amiga-mail
section: cli-shell
functions: [Lock, Open]
libraries: [dos.library]
---

# CLI / Shell

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* Many more commands are now built-in (no longer in C:).  This can break
  installation scripts that copy C:commandname, and programs that try to
  Lock() or Open() C:commandname to check for the command's existence.

* The limit of 20 CLI processes is gone and the DOSBase CLI table has
  changed to accomodate this.  Under V36 and higher, you should use new
  2.0 functions rather than accessing the CLI table directly.

* Shell windows now have Close Gadgets.  The EOF character is passed for
  the Close Gadget of a Shell.  This is -1L with CON: getchar(), and the
  Close Gadget raw event ESC seq with RAW:.

* Shells now use the simple-refresh character-mapped console (see
  Console notes).

---

## See Also

- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [Open — dos.library](../autodocs/dos.library.md#open)
