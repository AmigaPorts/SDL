# 12 Serial Device / Alternative Modes for Serial Input or Output


As an alternative to [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html) you can use an asynchronous I/O request to
transmit the command.  Asynchronous requests are initiated with [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html).
Your task can continue to execute while the device processes the command.
You can occasionally do a [CheckIO()](../Includes_and_Autodocs_2._guide/node033E.html) to see if the I/O has completed.  The
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
waiting for one of three signals.  The [Wait()](../Includes_and_Autodocs_2._guide/node038A.html) will wake up if the read
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
   The [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html) function is used above, even if the request is already
   known to be complete.  WaitIO() on a completed request simply removes
   the reply and cleans up.  The [Remove()](../Includes_and_Autodocs_2._guide/node0373.html) function is not acceptable for
   clearing the reply port; other messages may arrive while the function
   is executing.

 [High Speed Operation](../Devices_Manual_guide/node00A2.html) 
 [Use Of BeginIO() With The Serial Device](../Devices_Manual_guide/node00A3.html) 
 [Ending A Read Or Write Using Termination Characters](../Devices_Manual_guide/node00A4.html) 
 [Using Separate Read And Write Tasks](../Devices_Manual_guide/node00A5.html) 

