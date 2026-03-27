---
title: 14 Workbench and Icon Library / Workbench Environment
manual: libraries
chapter: libraries
section: 14-workbench-and-icon-library-workbench-environment
functions: []
libraries: []
---

# 14 Workbench and Icon Library / Workbench Environment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

On the Amiga there are at least two ways to start a program running:

  * By activating a tool or project icon in Workbench (an icon is

```c
    activated by pointing to it with the mouse and double-clicking
    the mouse select button.)
```
  * By typing the name of an executable file at the Shell (also

```c
    known as the CLI or Command Line Interface)
```
In the Workbench environment, a program is run as a separate process.  A
process is simply a task with additional information needed to use DOS
library.

By default, a Workbench program does not have a window to which its output
will go.  Therefore, stdin and stdout do not point to legal file handles.
This means you cannot use stdio functions such as [printf()](autodocs-2.0/amiga-lib-printf.md) if your program
is started from Workbench unless you first set up a stdio window.

Some compilers have options or defaults to provide a stdio window for
programs started from Workbench.  In Release 2, applications can use an
auto console window for stdio when started from Workbench by opening
"CON:0/0/640/200/auto/close/wait" as a file.  An auto console window will
only open if stdio input or output occurs.  This can also be handled in
the startup code module that comes with your compiler.

 [Argument Passing In Workbench](libraries/14-workbench-environment-argument-passing-in-workbench.md) 
 [WBStartup Message](libraries/14-workbench-environment-wbstartup-message.md) 
 [Example of Parsing Workbench Arguments](libraries/lib-examples-prargs-c.md) 

