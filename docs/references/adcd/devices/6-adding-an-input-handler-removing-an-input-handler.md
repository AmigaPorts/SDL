---
title: 6 / Adding an Input Handler / Removing An Input Handler
manual: devices
chapter: devices
section: 6-adding-an-input-handler-removing-an-input-handler
functions: []
libraries: []
---

# 6 / Adding an Input Handler / Removing An Input Handler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You remove a handler from the handler chain by passing an [IOStdReq](devices/6-input-device-device-interface.md) to the
device [IND_REMHANDLER](autodocs-2.0/input-device-ind-remhandler.md) set in io_Command and a pointer to the Interrupt
structure used to add the handler.

   struct Interrupt *InputHandler;
   struct IOStdReq  *InputIO;

   InputIO->io_Data=(APTR)InputHandler;   /* Which handler to REM */
   InputIO->io_Command=IND_REMHANDLER;    /* The REM command */
   DoIO((struct IORequest *)InputIO);     /* Send the command */

