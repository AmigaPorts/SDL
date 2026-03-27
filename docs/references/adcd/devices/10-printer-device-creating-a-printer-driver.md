---
title: 10 Printer Device / Creating a Printer Driver
manual: devices
chapter: devices
section: 10-printer-device-creating-a-printer-driver
functions: [CloseDevice, LoadSeg, OpenDevice]
libraries: [dos.library, exec.library]
---

# 10 Printer Device / Creating a Printer Driver

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Creating the printer-dependent modules for the printer device involves
writing the data structures and code, compiling and assembling them, and
linking to produce an Amiga binary object file. The modules a driver
contains varies depending on whether the printer is non-graphics or
graphics capable.

All drivers contain these modules:

   macros.i        -  include file for init.asm,contains printer device
                      macro definitions
   printertag.asm  -  printer specific capabilities such as density,
                      character sets and color
   init.asm        -  opens the various libraries required by the printer
                      driver.  This will be the same for all printers
   data.c          -  contains printer device RAW commands and the extended
                      character set supported by the printer
   dospecial.c     -  printer specific special processing required for

                      printer device commands like aSLRM and aSFC
Graphic printer drivers require these additional modules:

   render.c        -  printer specific processing to do graphics output
                      and fill the output buffer
   transfer.c      -  printer specific processing called by render.c
                      to output the buffer to the printer.  Code it in
                      assembly if speed is important
   density.c       -  printer specific processing to construct the proper

                      print density commands
The first piece of the printer driver is the PrinterSegment structure
described in devices/[prtbase.h](autodocs-2.0/includes-devices-prtbase-h.md) (this is pointed to by the BPTR returned by
the [LoadSeg()](autodocs-2.0/dos-library-loadseg.md) of the object file). The PrinterSegment contains the
[PrinterExtendedData](autodocs-2.0/includes-devices-prtbase-h.md) (PED) structures (also described in devices/prtbase.h)
at the beginning of the object.  The PED structure contains data
describing the capabilities of the printer, as well as pointers to code
and other data. Here is the assembly code for a sample PrinterSegment,
which would be linked to the beginning of the sequence of files as
printertag.asm.


```c
     [printertag.asm](devices/devices-dev-examples-printertag-asm.md) 
```
The printer name should be the brand name of the printer that is available
for use by programs wishing to be specific about the printer name in any
diagnostic or instruction messages. The four functions at the top of the
structure are used to initialize this printer-dependent code:

   (*(PED->ped_Init))(PD) ;

      This is called when the printer-dependent code is loaded and provides
      a pointer to the printer device for use by the printer-dependent
      code. It can also be used to open up any libraries or devices needed
      by the printer-dependent code.
   (*(PED->ped_Expunge))() ;

      This is called immediately before the printer-dependent code is
      unloaded, to allow it to close any resources obtained at
      initialization time.
   (*(PED->ped_Open))(ior) ;

```c
      This is called in the process of an [OpenDevice()](autodocs-2.0/exec-library-opendevice.md) call, after the
      Preferences are read and the correct primitive I/O device (parallel
      or serial) is opened.  It must return zero if the open is successful,
      or non-zero to terminate the open and return an error to the user.
```
   (*(PED->ped_Close))(ior) ;

```c
      This is called in the process of a [CloseDevice()](autodocs-2.0/exec-library-closedevice.md) call to allow the
      printer-dependent code to close any resources obtained at open time.
```
The pd_ variable provided as a parameter to the initialization call is a
pointer to the [PrinterData](autodocs-2.0/includes-devices-prtbase-h.md) structure described in devices/prtbase.h. This
is also the same as the io_Device entry in printer I/O requests.

   pd_SegmentData

      This points back to the PrinterSegment, which contains the PED.
   pd_PrintBuf

      This is available for use by the printer-dependent code - it is not
      otherwise used by the printer device.
   (*pd_PWrite)(data, length);

      This is the interface routine to the primitive I/O device.  This
      routine uses two I/O requests to the primitive device, so writes are
      double-buffered. The data parameter points to the byte data to send,
      and the length is the number of bytes.
   (*pd_PBothReady)();

      This waits for both primitive I/O requests to complete.  This is
      useful if your code does not want to use double buffering.  If you
      want to use the same data buffer for successive pd_PWrites, you must
      separate them with a call to this routine.
   pd_Preferences

      This is the copy of Preferences in use by the printer device,
      obtained when the printer was opened.
The timeout field is the number of seconds that an I/O request from the
printer device to the primitive I/O device (parallel or serial) will
remain posted and unsatisfied before the timeout requester is presented to
the user. The timeout value should be long enough to avoid the requester
during normal printing.

The PrintMode field is a flag which indicates whether text has been
printed or not (1 means printed, 0 means not printed). This flag is used
in drivers for page oriented printers to indicate that there is no
alphanumeric data waiting for a formfeed.

 [Writing Alphanumeric Printer Drivers](devices/10-creating-a-printer-driver-writing-alphanumeric-printer.md) 
 [Writing A Graphics Printer Driver](devices/10-creating-a-printer-driver-writing-a-graphics-printer.md) 
 [Testing The Printer Driver](devices/10-creating-a-printer-driver-testing-the-printer-driver.md) 

---

## See Also

- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
