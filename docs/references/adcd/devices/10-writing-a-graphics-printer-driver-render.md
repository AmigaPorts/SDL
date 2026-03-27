---
title: 10 / Writing A Graphics Printer Driver / Render()
manual: devices
chapter: devices
section: 10-writing-a-graphics-printer-driver-render
functions: [AllocMem]
libraries: [exec.library]
---

# 10 / Writing A Graphics Printer Driver / Render()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This function is the main printer-specific code module and consists of
seven parts referred to here as cases:

   *  Pre-Master initialization (Case 5)

   *  Master initialization (Case 0)

   *  Putting the pixels in a buffer (Case 1)

   *  Dumping a pixel buffer to the printer (Case 2)

   *  Closing down (Case 4)

   *  Clearing and initializing the pixel buffer (Case 3)

   *  Switching to the next color(Case 6)  (special case for multi-color

```c
      printers)
```
   State Your Case.
   ----------------
   The numbering of the cases reflects the value of each step as a case
   in a C-language switch statement.  It does not denote the order that
   the functions are executed; the order in which they are listed above
   denotes that.

For each case, Render() receives four long variables as parameters:
ct, x,  y and status.  These parameters are described
below for each of the seven cases that Render() must handle.

Pre-Master initialization (Case 5)
----------------------------------
Parameters:


```c
         ct - 0 or pointer to the [IODRPReq](devices/10-printer-device-device-interface.md) structure passed to PCDumpRPort
         x  - io_Special flag from the IODRPReq structure
         y  - 0
```
When the printer device is first opened, Render() is called with ct set to
0, to give the driver a chance to set up the density values before the
actual graphic dump is called.

The parameter passed in x will be the io_Special flag which contains the
density and other SPECIAL flags. The only flags used at this point are the
DENSITY flags, all others should be ignored. Never call PWrite() during
this case.  When you are finished handling this case, return PDERR_NOERR.

Master initialization (Case 0).
-------------------------------
Parameters:


```c
         ct - pointer to a [IODRPReq](devices/10-printer-device-device-interface.md) structure
         x  - width (in pixels) of printed picture
         y  - height (in pixels) of printed picture
```
   Everything is A-OK.
   -------------------
   At this point the printer device has already checked that the values
   are within range for the printer.  This is done by checking values
   listed in printertag.asm.

The x and y value should be used to allocate enough memory for a command
and data buffer for the printer. If the allocation fails,
PDERR_BUFFERMEMORY should be returned. In general, the buffer needs to be
large enough for the commands and data required for one pass of the print
head. These typically take the following form:


       <start gfx cmd> <data> <end gfx cmd>
The <start gfx cmd> should contain any special, one-time initializations
that the printer might require such as:

   *  Carriage Return - some printers start printing graphics without

      returning the printhead. Sending a CR assures that printing will
      start from the left edge.
   *  Unidirectional - some printers which have a bidirectional mode

      produce non-matching vertical lines during a graphics dump, giving a
      wavy result. To prevent this, your driver should set the printer to
      unidirectional mode.
   *  Clear margins - some printers force graphic dumps to be done within

      the text margins, thus they should be cleared.
   *  Other commands - enter the graphics mode, set density, etc.

   Multi-Pass? Don't Forget the Memory.
   ------------------------------------
   In addition to the memory for commands and data, a multi-pass color
   printer must allocate enough buffer space for each of the different
   color passes.

The printer should never be reset during the master initialization case
This will cause problems during multiple dumps. Also, the pointer to the
[IODRPReq](devices/10-printer-device-device-interface.md) structure in ct should not be used except for those rare printers
which require it to do the dump themselves. Return the PDERR_TOOKCONTROL
error in that case so that the printer device can exit gracefully.

   PDERR_TOOKCONTROL, An Error in Name Only.
   -----------------------------------------
   The printer device error code, PDERR_TOOKCONTROL, is not an error at
   all, but an internal indicator that the printer driver is doing the
   graphic dump entirely on its own. The printer device can assume the
   dump has been done.  The calling application will not be informed of
   this, but will receive PDERR_NOERR instead.

The example render.c functions listed at the end of this chapter use
double buffering to reduce the dump time which is why the [AllocMem()](autodocs-2.0/exec-library-allocmem.md) calls
are for BUFSIZE times two, where BUFSIZE represents the amount of memory
for one entire print cycle. However, contrary to the example source code,
allocating the two buffers independently of each other is recommended. A
request for one large block of contiguous memory might be refused.  Two
smaller requests are more likely to be granted.

Putting the pixels in a buffer (Case 1).
----------------------------------------
Parameters:


```c
         ct - pointer to a PrtInfo structure.
         x  - PCM color code (if the printer is PCC_MULTI_PASS).
         y  - printer row # (the range is 0 to pixel height - 1).
```
In this case, you are passed an entire row of YMCB intensity values
(Yellow, Magenta, Cyan, Black).  To handle this case, you call the
[Transfer()](devices/10-writing-a-graphics-printer-driver-transfer.md) function in the transfer.c module.  You should return
PDERR_NOERR after handling this case. The PCM-defines for the x parameter
from the file devices/[prtgfx.h](autodocs-2.0/includes-devices-prtgfx-h.md) are PCMYELLOW, PCMMAGENTA, PCMCYAN and
PCMBLACK.

Dumping a pixel buffer to the printer (Case 2).
-----------------------------------------------
Parameters:


```c
         ct - 0
         x  - 0
         y  - # of rows sent (the range is 1 to NumRows).
```
At this point the data can be Run Length Encoded (RLE) if your printer
supports it. If the printer doesn't support RLE, the data should be
white-space stripped. This involves scanning the buffer from end to
beginning for the position of the first occurrence of a non-zero value.
Only the data from the beginning of the buffer to this position should be
sent to the printer.  This will significantly reduce print times.

The value of y can be used to advance the paper the appropriate number of
pixel lines if your printer supports that feature. This helps prevent
white lines from appearing between graphic dumps.

You can also do post-processing on the buffer at this point. For
example, if your printer uses the hexadecimal number $03 as a command and
requires the sequence $03 $03 to send $03 as data, you would probably want
to scan the buffer and expand any $03s to $03 $03 during this case. Of
course, you'll need to allocate space somewhere in order to expand the
buffer.

The error from PWrite() should be returned after this call.

Clearing and initializing the pixel buffer (Case 3)
---------------------------------------------------
Parameters:


         ct - 0
         x  - 0
         y  - 0
The printer driver does not send blank pixels so you must initialize
the buffer to the value your printer uses for blank pixels (usually 0).
Clearing the buffer should be the same for all printers. Initializing the
buffer is  printer specific, and it includes placing the printer-specific
control codes in the buffer before and after the data.

This call is made before each Case 2 call. Clear your active print buffer
- remember you are double buffering - and initialize it if necessary.
After this call, PDERR_NOERR should be returned.

Closing Down (Case 4).
----------------------
Parameters:


```c
         ct - error code
         x  - io_Special flag from the [IODRPReq](devices/10-printer-device-device-interface.md) structure
         y  - 0
```
This call is made at the end of the graphic dump or if the graphic dump
was cancelled for some reason.  At this point you should free the printer
buffer memory. You can determine if memory was allocated by checking that
the value of PD->pd_PrintBuf is not NULL. If memory was allocated, you
must wait for the print buffers to clear (by calling PBothReady) and then
deallocate the memory. If the printer - usually a page oriented
printer - requires a page eject command, it can be given here. Before you
do, though, you should check the [SPECIAL_NOFORMFEED](devices/10-dumping-a-rastport-to-a-printer-printer-special-flags.md) bit in x. Don't issue
the command if it is set.

If the error condition in ct is PDERR_CANCEL, you should not PWrite().
This error indicates that the user is trying to cancel the dump for
whatever reason. Each additional PWrite() will generate another printer
trouble requester. Obviously, this is not desirable.

During this render case PWrite() could be used to:

   *  reset the line spacing.  If the printer doesn't have an advance 'n'

```c
      dots command, then you'll probably advance the paper by changing the
      line spacing. If you do, set it back to either 6 or 8 lpi (depending
      on Preferences) when you are finished printing.
```
   *  set bidirectional mode if you selected unidirectional mode in render

      Case 0.
   *  set black text; some printers print the text in the last color used,

      even if it was in graphics mode.
   *  restore the margins if you cancelled the margins in render Case 0.

   *  any other command needed to exit the graphics mode, eject the page,

      etc.
Either PDERR_NOERR or the error from PWrite() should be returned after
this call.

Switching to the next color (Case 6)
------------------------------------
This call provides support for printers which require that colors be sent
in separate passes. When this call is made, you should instruct the
printer to advance its color panel. This case is only needed for printers
of the type PCC_MULTI_PASS, such as the CalComp ColorMaster.

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
