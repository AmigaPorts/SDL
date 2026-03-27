---
title: 4 Console Device / Reading from the Console Device
manual: devices
chapter: devices
section: 4-console-device-reading-from-the-console-device
functions: [DoIO, SendIO]
libraries: [exec.library]
---

# 4 Console Device / Reading from the Console Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Reading input from the console device returns an ANSI 3.64 standard byte
stream.  This stream may contain normal characters and/or RAW input event
information.  You may also request other RAW input events using the SET
RAW EVENTS and RESET RAW EVENTS control sequences discussed below.  See
"[Selection of Raw Input Events.](devices/4-console-device-selecting-raw-input-events.md)".

Generally, console reads are performed asynchronously so that your program
can respond to other events and other user input (such as menu selections)
when the user is not typing on the keyboard. To perform asynchronous I/O,
an I/O request is sent to the console using the [SendIO()](autodocs-2.0/exec-library-sendio.md) function (rather
than a synchronous [DoIO()](autodocs-2.0/exec-library-doio.md) which would wait until the read request returned
with a character).

You read from the console device by passing an I/O request to the device
with a pointer to the read buffer set in io_Data, the number of bytes in
the buffer set in io_Length and [CMD_READ](autodocs-2.0/console-device-cmd-read.md) set in io_Command.

   #define READ_BUFFER_SIZE 25
   char ConsoleReadBuffer[READ_BUFFER_SIZE];

   ConsIO->io_Data = (APTR)ConsoleReadBuffer;
   ConsIO->io_Length = READ_BUFFER_SIZE;
   ConsIO->io_Command = CMD_READ;
   SendIO(ConsIO);

   You May Get Less Than You Bargained For.
   ----------------------------------------
   A request for more than one character may be satisfied by the receipt
   of only one character.  If you request more than one character, you
   will have to examine the io_Actual field of the request when it
   returns to determine how many characters you have actually received.

After sending the read request, your program can wait on a combination of
signal bits including that of the reply port you created. The following
fragment demonstrates waiting on both a queued console read request, and
Window IDCMP messages:

   ULONG conreadsig = 1 << ConsoleMP->mp_SigBit;
   ULONG windowsig = 1 << win->UserPort->mp_SigBit;

   /* A character, or an IDCMP msg, or both will wake us up */
   ULONG signals = Wait(conreadsig | windowsig);

   if (signals & conreadsig)

```c
       {
       /* Then check for a character */
       };
```
   if (signals & windowsig)

```c
       {
       /* Then check window messages */
       };
```
 [Information About The Input Stream](devices/4-reading-from-the-console-device-information-about-the.md) 
 [Cursor Position Report](devices/4-reading-from-the-console-device-cursor-position-report.md) 
 [Window Bounds Report](devices/4-reading-from-the-console-device-window-bounds-report.md) 

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
