---
title: II-65: Writing a UserShell
manual: amiga-mail
chapter: amiga-mail
section: ii-65-writing-a-usershell
functions: []
libraries: []
---

# II-65: Writing a UserShell

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by Randell Jesup


One of the features of Release 2.0 is that the OS allows the user to
change the system default shell, or the UserShell.  Any time the user
opens a shell with NewShell, executes a script, RUNs a command, or
indirectly calls System() with SYS_UserShell, the OS will call the
UserShell instead of the BootShell (by default the system sets up the
BootShell as the UserShell).

Creating UserShells is not easy, and requires doing a fairly large number
of things for no apparent reason (the reasons are there, they're just not
obvious to the outsider).  This article will attempt to give you the
information you need in order to create a usable, system-friendly
UserShell.

 [Initialization](amiga-mail/initialization.md) 
 [A Word About the Shell's I/O Handles](amiga-mail/a-word-about-the-shell-s-i-o-handles.md) 
 [The Main Shell Loop](amiga-mail/the-main-shell-loop.md) 
 [Finding a Program](amiga-mail/finding-a-program.md) 
 [Running a Program](amiga-mail/running-a-program.md) 
 [Cleanup](amiga-mail/cleanup.md) 
 [Installing the New User Shell](amiga-mail/installing-the-new-user-shell.md) 
 [Credits](amiga-mail/credits.md) 

 [myshell.c](amiga-mail/ii-65-myshell-c.md) 

