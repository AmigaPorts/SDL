---
title: 6 Input Device / Adding an Input Handler
manual: devices
chapter: devices
section: 6-input-device-adding-an-input-handler
functions: []
libraries: []
---

# 6 Input Device / Adding an Input Handler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You add an input-stream handler to the input chain by passing an [IOStdReq](devices/6-input-device-device-interface.md)
to the device with [IND_ADDHANDLER](autodocs-2.0/input-device-ind-addhandler.md) set in io_Command and a pointer to an
Interrupt structure set in io_Data.

   struct Interrupt *InputHandler;
   struct IOStdReq  *InputIO

   InputHandler->is_Code=ButtonSwap;         /* Address of code */
   InputHandler->is_Data=NULL;               /* User Value passed in A1 */
   InputHandler->is_Node.ln_Pri=100;         /* Priority in food chain */
   InputHandler->is_Node.ln_Name=NameString; /* Name of handler */

   InputIO->io_Data=(APTR)inputHandler;      /* Point to the structure */
   InputIO->io_Command=IND_ADDHANDLER;       /* Set command ... */
   DoIO((struct IORequest *)InputIO);        /* DoIO( ) the command */

Intuition is one of the input device handlers and normally distributes
most of the input events.

Intuition inserts itself at priority position 50. The console device sits
at priority position 0. You can choose the position in the chain at which
your handler will be inserted by setting the priority field in the
list-node part of the interrupt data structure you pass to this routine.

   Speed Saves.
   ------------
   Any processing time expended by a handler subtracts from the time
   available before the next event happens. Therefore, handlers for the
   input stream must be fast. For this reason it is recommended that the
   handlers be written in assembly.

 [Rules For Input Device Handlers](devices/6-adding-an-input-handler-rules-for-input-device-handlers.md) 
 [Removing An Input Handler](devices/6-adding-an-input-handler-removing-an-input-handler.md) 

