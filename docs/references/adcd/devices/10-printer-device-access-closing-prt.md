---
title: 10 / Printer Device Access / Closing Prt:
manual: devices
chapter: devices
section: 10-printer-device-access-closing-prt
functions: []
libraries: []
---

# 10 / Printer Device Access / Closing Prt:

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the printer I/O is complete, you should close PRT:. Don't keep the
device open when you are not using it.  The user may have changed the
printer settings by using the Workbench Preferences tool.  There's also
the possibility the printer has been turned off and on again causing the
printer to switch to its own default settings. Every time the printer
device is opened, it reads the current Preferences settings. Hence, by
always opening the printer device just before printing and always closing
it afterwards, you ensure that your application is using the current
Preferences settings.

Close(file);

   In DOS, You Must Be A Process.
   ------------------------------
   Printer I/O through the DOS must be done by a process, not by a task.
   DOS utilizes information in the process control block and would
   become confused if a simple task attempted to perform these
   activities. Printer I/O using the printer device directly, however,
   can be performed by a task.

The remainder of this chapter will deal with using the printer device
directly.

