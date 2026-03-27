---
title: FD/console_lib.fd
manual: autodocs-2.0
chapter: autodocs-2.0
section: fd-console-lib-fd
functions: []
libraries: []
---

# FD/console_lib.fd

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* "console.device"
##base _ConsoleDevice
##bias 42
##public
CDInputHandler(events,consoleDevice)(a0/a1)
RawKeyConvert(events,buffer,length,keyMap)(a0/a1,d1/a2)
##private
*--- functions in V36 or higher (distributed as Release 2.0) ---
consolePrivate1()()
consolePrivate2()()
consolePrivate3()()
consolePrivate4()()
##end

