---
title: 1 / / Design / DOS System(), CreateNewProc(), and CON: Enhancements
manual: libraries
chapter: libraries
section: 1-design-dos-system-createnewproc-and-con-enhancements
functions: [CreateNewProc]
libraries: [dos.library]
---

# 1 / / Design / DOS System(), CreateNewProc(), and CON: Enhancements

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If your program currently uses the 1.3 AmigaDOS [Execute()](autodocs-2.0/dos-library-execute.md) or [CreateProc()](autodocs-2.0/dos-library-createproc.md)
functions, then it is definitely worth conditional code to use their V37
replacements when running under [Release 2](libraries/1-operating-system-versions-about-release-2.md).  The [System()](autodocs-2.0/dos-library-systemtaglist.md) function of
Release 2 allows you to pass a command line to AmigaDOS as if it had been
typed at a Shell window.  System() can run synchronously with return
values or asynchronously with automatic cleanup and it also sets up a
proper stdio environment when passed a DOS filehandle for SYS_Input and
NULL for SYS_Output.  In combination with enhanced Release 2 CON:
features, System() can provide a suitable execution environment on either
Workbench or a custom screen.  The [CreateNewProc()](autodocs-2.0/dos-library-createnewproc.md) function provides
additional control and ease in process creation.

CON: input and output in custom Intuition screens and windows is now
supported.  New options in the [Release 2](libraries/1-operating-system-versions-about-release-2.md) console handler (CON:) provide
the ability to open a CON: on any public Intuition screen, or to attach a
CON: to an existing Intuition window.  Additional options can add a close
gadget or create an AUTO console window which will only open if accessed
for read or write.  Add conditional code to use these system-supported
methods when running under Release 2 or later versions of the OS.  Note
that additional CON: option keywords can be easily removed under 1.3 at
runtime by terminating the CON: string with NULL after the window title.
Consult The AmigaDOS Manual by Bantam Books for additional information on
Release 2 CON: and DOS features.

---

## See Also

- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
