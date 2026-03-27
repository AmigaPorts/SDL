---
title: 14 Workbench and Icon Library / Workbench and the Startup Code Module
manual: libraries
chapter: libraries
section: 14-workbench-and-icon-library-workbench-and-the-startup
functions: []
libraries: []
---

# 14 Workbench and Icon Library / Workbench and the Startup Code Module

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Standard startup code handles the detail work of interfacing with the
arguments and environment of Workbench and the Shell (or CLI).  This
section describes the behavior of standard startup modules such as the
ones supplied with SAS (Lattice) C and Manx Aztec C.

The environment for a program started from Workbench is quite different
from the environment for a program started from the Shell.  The Shell does
not create a new process for a program; it jumps to the program's code and
the program shares the process with the Shell.  Programs run under the
Shell have access to all the Shell's environment, including the ability to
modify that environment.  (Programs run from the Shell should be careful
to restore all values that existed on startup.) Workbench starts a program
as a new DOS process, explicitly passing the execution environment to the
program.

 [Workbench Startup](libraries/14-workbench-and-the-startup-code-module-workbench-startup.md)    [Shell Startup](libraries/14-workbench-and-the-startup-code-module-shell-startup.md) 

