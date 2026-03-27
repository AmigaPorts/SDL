# 9 Parallel Device / Querying the Parallel Device


You query the parallel device by passing an [IOExtPar](../Devices_Manual_guide/node0010.html#line7) to the device with
[PDCMD_QUERY](../Includes_and_Autodocs_2._guide/node04F3.html) set in io_Command.  The parallel device will respond with the
status of the parallel port lines and registers.

   UWORD Parallel_Status;

   ParallelIO->IOPar.io_Command  = PDCMD_QUERY; /* indicate query */
   DoIO((struct IORequest *)ParallelIO);

   Parallel_Status = ParallelIO->io_Status;     /* store returned status */

The 8 status bits of the parallel device are returned in io_Status.


                       PARALLEL DEVICE STATUS BITS
   Bit    Active              Function
   ---    ------              --------

```c
    0       high        Printer busy toggle (offline)
    1       high        Paper out
    2       high        Printer Select on the A1000. On theA500 and A2000,
                        select is also connected to to the parallel port's
                        Ring Indicator. Be cautious when making cables.
    3        -          read=0; write=1
    4-7      -          (reserved)
```
The parallel device also returns error codes whenever an operation is
attempted.

   struct IOPArray Terminators =
   {
   0x51454141,   /* Q E A A */
   0x41414141    /* fill to end with lowest value,must be in desc. order */
   };

   ParallellIO->io_ParFlags != PARF_EOFMODE;        /* Set EOF mode flag */
   ParallelIO->io_PTermArray = Terminators;/* Set termination characters */
   ParallellIO->IOPar.io_Command  = PDCMD_SETPARAMS;   /* Set parameters */
   if (DoIO((struct IORequest *)ParallelIO))

```c
       printf("Set Params failed. Error: %ld ",ParallelIO->IOPar.io_Error);
```
The error is returned in the io_Error field of the [IOExtPar](../Devices_Manual_guide/node0010.html#line7) structure.


```c
                       PARALLEL DEVICE ERROR CODES

               Error              Value        Explanation
               -----              -----        -----------
              ParErr_DevBusy        1          Device in use
              ParErr_BufToBig       2          Out of memory
              ParErr_InvParam       3          Invalid parameter
              ParErr_LineErr        4          Parallel line error
              ParErr_NotOpen        5          Device not open
              ParErr_PortReset      6          Port Reset
              ParErr_InitErr        7          Initialization Error

     [Parallel.c](../Devices_Manual_guide/node0160.html) 
```
