---
title: 12 Serial Device / Alternative Modes for Serial Input or Output
manual: devices
chapter: devices
section: 12-serial-device-alternative-modes-for-serial-input-or
functions: [CheckIO, DoIO, Remove, SendIO, Wait, WaitIO]
libraries: [exec.library]
---

# 12 Serial Device / Alternative Modes for Serial Input or Output

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As an alternative to [DoIO()](autodocs-2.0/exec-library-doio.md) you can use an asynchronous I/O request to
transmit the command.  Asynchronous requests are initiated with [SendIO()](autodocs-2.0/exec-library-sendio.md).
Your task can continue to execute while the device processes the command.
You can occasionally do a [CheckIO()](autodocs-2.0/exec-library-checkio.md) to see if the I/O has completed.  The
write request in this example will be processed while the example
continues to run:


```c
    SerialIO->IOSer.io_Length   = -1;
    SerialIO->IOSer.io_Data     = (APTR)"Save the whales! ";
    SerialIO->IOSer.io_Command  = CMD_WRITE;
    SendIO((struct IORequest *)SerialIO);

    printf("CheckIO %lx\n",CheckIO((struct IORequest *)SerialIO));
    printf("The device will process the request in the background\n");
    printf("CheckIO %lx\n",CheckIO((struct IORequest *)SerialIO));
    WaitIO((struct IORequest *)SerialIO);  /* Remove message and cleanup */
```
Most applications will want to wait on multiple signals.  A typical
application will wait for menu messages from Intuition at the same time as
replies from the serial device.  The following fragment demonstrates
waiting for one of three signals.  The [Wait()](autodocs-2.0/exec-library-wait.md) will wake up if the read
request ever finishes, or if the user presses Ctrl-C or Ctrl-F from the
Shell.  This fragment may be inserted into the above complete example.


```c
    /* Precalculate a wait mask for the CTRL-C, CTRL-F and message
     * port signals.  When one or more signals are received,
     * Wait() will return.  Press CTRL-C to exit the example.
     * Press CTRL-F to wake up the example without doing anything.
     * NOTE: A signal may show up without an associated message!
     */

    WaitMask = SIGBREAKF_CTRL_C|
                SIGBREAKF_CTRL_F|
                 1L << SerialMP->mp_SigBit;

    SerialIO->IOSer.io_Command  = CMD_READ;
    SerialIO->IOSer.io_Length   = READ_BUFFER_SIZE;
    SerialIO->IOSer.io_Data     = (APTR)&SerialReadBuffer[0];
    SendIO(SerialIO);

    printf("Sleeping until CTRL-C, CTRL-F, or serial input\n");

    while (1)
           {
           Temp = Wait(WaitMask);
           printf("Just woke up (YAWN!)\n");

           if (SIGBREAKF_CTRL_C & Temp)
               break;

           if (CheckIO(SerialIO) ) /* If request is complete... */
               {
               WaitIO(SerialIO);   /* clean up and remove reply */
               printf("%ld bytes received\n",SerialIO->IOSer.io_Actual);
               break;
               }
           }
    AbortIO(SerialIO);  /* Ask device to abort request, if pending */
    WaitIO(SerialIO);   /* Wait for abort, then clean up */
```
   WaitIO() vs. Remove().
   ----------------------
   The [WaitIO()](autodocs-2.0/exec-library-waitio.md) function is used above, even if the request is already
   known to be complete.  WaitIO() on a completed request simply removes
   the reply and cleans up.  The [Remove()](autodocs-2.0/exec-library-remove.md) function is not acceptable for
   clearing the reply port; other messages may arrive while the function
   is executing.

 [High Speed Operation](devices/12-alternative-modes-for-serial-input-or-output-high-speed.md) 
 [Use Of BeginIO() With The Serial Device](devices/12-use-of-beginio-with-the-serial-device.md) 
 [Ending A Read Or Write Using Termination Characters](devices/12-ending-a-read-or-write-using-termination-characters.md) 
 [Using Separate Read And Write Tasks](devices/12-using-separate-read-and-write-tasks.md) 

---

## See Also

- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
