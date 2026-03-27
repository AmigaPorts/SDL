---
title: D / Errors / Device-related Problems
manual: libraries
chapter: libraries
section: d-errors-device-related-problems
functions: []
libraries: []
---

# D / Errors / Device-related Problems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Device-related problems may caused by: improperly initialized port or I/O
request structures (use [CreatePort()](libraries/24-message-ports-creating-a-message-port.md) and [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)); use of a
too-small I/O request (see the device's <[.h](autodocs-2.0/includes-and-autodocs-2-0.md)> files and Autodocs for
information on the required type of I/O request); re-use of an I/O request
before it has returned from the device (use the debugging tool IO_Torture
to catch this); failure to abort and wait for an outstanding device
request before exiting; waiting on a signal/port/message allocated by a
different task.

