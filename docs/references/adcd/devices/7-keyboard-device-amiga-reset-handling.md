---
title: 7 Keyboard Device / Amiga Reset Handling
manual: devices
chapter: devices
section: 7-keyboard-device-amiga-reset-handling
functions: []
libraries: []
---

# 7 Keyboard Device / Amiga Reset Handling

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 When a user presses the Ctrl key and both left- and right-Amiga keys
simulataneously (the reset sequence), the keyboard device senses this and
calls a prioritized chain of reset-handlers. These might be thought of as
clean-up routines that "must" be performed before reset is allowed to
occur. For example, if a disk write is in progress, the system should
finish that before resetting the hardware so as not to corrupt the
contents of the disk.

It is important to note that not all Amigas handle reset processing in the
same way.  On the A500, the reset key sequence sends a hardware reset
signal and never goes through the reset handlers.  Also some of the early
A2000s (i.e., German keyboards with the function keys the same size as the
Esc key) do not handle the reset via the reset handlers.  It is thus
recommended that your application not rely on the reset handler abilities
of the keyboard device.

 [Adding A Reset Handler (KBD_ADDRESETHANDLER)](devices/7-amiga-reset-handling-adding-a-reset-handler-kbd.md) 
 [Removing A Reset Handler (KBD_REMRESETHANDLER)](devices/7-amiga-reset-handling-removing-a-reset-handler-kbd.md) 
 [Ending A Reset Task (KBD_RESETHANDLERDONE)](devices/7-amiga-reset-handling-ending-a-reset-task-kbd.md) 

