---
title: The 2.0 Con-handler
manual: amiga-mail
chapter: amiga-mail
section: the-2-0-con-handler
functions: [Input, Open, Output]
libraries: [dos.library]
---

# The 2.0 Con-handler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The 2.0 con-handler (CON:) has many new enhancements that allow
programs to further customize their console windows. An application
requests these new features by appending keywords to the end of the
CON: specification string for Open().  These keywords may appear in
any order after the title string in the CON: specification.

These new keywords are:


```c
    AUTO            Don't open CON: window until/unless input or
                        output occurs
    CLOSE           Put a close gadget on the CON: window
    WAIT            Hold off Close until user clicks Close or types CTRL-\
    WINDOW  0xaddr  Use specified window (may be on a custom screen)
    SCREEN  name    Open on specified public screen
```
The additional CON: keywords BACKDROP, NODRAG, NOBORDER, NOSIZE,
SIMPLE, and SMART, allow control of other attributes of a CON: window.

An AUTO/CLOSE/WAIT CON: window is perfect for 2.0-specific C startup
code and for asynchronous System() startup of arbitrary commands.
Because of the ``auto con'' feature (AUTO), the system will never open
the CON: window of a program that doesn't do any stdio (example:
Calculator).  If a command does stdio input or output, the window will
not open until stdio occurs. If the window opens, the wait feature
(WAIT) causes the window to stay open until the user types CTRL-\ (end
of file) or clicks the Close gadget.  The CLOSE keyword tells the
con-handler to put a close gadget on the CON: window.

Example: ``CON:/0/0/640/200/My Title/AUTO/CLOSE/WAIT''

The SCREEN keyword along with a public screen name allows an
application to open a CON: window on that public screen.  Alternately,
an application can use the WINDOW keyword to attach a console to an
already open Intuition window.  The hex address of the Intuition
window must follow the WINDOW keyword.  This makes it possible for
System()-launched programs to do their stdio in a window on a custom
screen.

The example code, [SystemTest.c](amiga-mail/ii-1-systemtest-c.md), provides two simple subroutines for
executing external commands, and demonstrates the following 2.0
features:

   o Synchronous System() command execution using the calling
```c
       program's Input()/Output().
```
   o Synchronous System() command execution in a custom screen window.
   o Asynchronous System() command startup with an AUTO/CLOSE/WAIT window.
   o OpenScreenTags and OpenWindowTags for a 2.0 New Look window.

---

## See Also

- [Input — dos.library](../autodocs/dos.library.md#input)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [Output — dos.library](../autodocs/dos.library.md#output)
