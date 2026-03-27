---
title: Installing the New User Shell
manual: amiga-mail
chapter: amiga-mail
section: installing-the-new-user-shell
functions: []
libraries: []
---

# Installing the New User Shell

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

After you have compiled your creation, you need to put its seglist on the
resident list under the name ``shell''.  Adding it to the resident list is
a simple:


    Resident shell <shell-file> SYSTEM
Now anything that calls the user shell (like NewShell, Execute(), and
System()) will call your shell.  Note that under 2.04, the Shell icon
actually runs sys:System/CLI, which calls the BootShell (the default
UserShell) and not the current UserShell.

If you need to restore the BootShell as the UserShell, compile and run the
program [RestoreShell.c](amiga-mail/ii-65-restoreshell-c.md) at the end of this article

