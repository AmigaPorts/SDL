---
title: printer.device/PRD_QUERY
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-prd-query-2
functions: []
libraries: []
---

# printer.device/PRD_QUERY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PRD_QUERY -- query printer port/line status

   FUNCTION
	This command returns the status of the printer port's lines and
	registers.  Since the printer port uses either the serial or
	parallel port for i/o, the actual status returned is either the
	serial or parallel port's status.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	PRD_QUERY
	io_Data		ptr to 2 UBYTES where result will be stored.

   RESULTS
```c
     io_Data          BIT  ACTIVE  FUNCTION (SERIAL DEVICE)

             LSB       0    low    reserved
                       1    low    reserved
                       2    low    reserved
                       3    low    Data Set Ready
                       4    low    Clear To Send
                       5    low    Carrier Detect
                       6    low    Ready To Send
                       7    low    Data Terminal Ready
             MSB       8    high   read buffer overflow
                       9    high   break sent (most recent output)
                      10    high   break received (as latest input)
                      11    high   transmit x-OFFed
                      12    high   receive x-OFFed
                   13-15           reserved


     io_Data          BIT  ACTIVE  FUNCTION (PARALLEL DEVICE)

                       0     hi     printer busy (offline)
                       1     hi     paper out
                       2     hi     printer selected
```
				     (WARNING: the bit 2 line is also connected
				      to the serial port's ring indicator pin
				      on the A500 and A2000)

                     3-7            reserved

     io_Actual       1-parallel, 2-serial
