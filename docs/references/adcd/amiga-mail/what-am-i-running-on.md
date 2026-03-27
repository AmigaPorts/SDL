---
title: What Am I Running On?
manual: amiga-mail
chapter: amiga-mail
section: what-am-i-running-on
functions: [FindResident]
libraries: [exec.library]
---

# What Am I Running On?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

It is possible for applications to detect if they are running on an
A570 or on a CDTV player.  There is an A570-specific module called
"A690ID".  A title can test to see if this module is present using the
exec.library function FindResident().  If the "A690ID" module is
present, the title is running on an A570-equipped A500.

---

## See Also

- [FindResident — exec.library](../autodocs/exec.library.md#findresident)
