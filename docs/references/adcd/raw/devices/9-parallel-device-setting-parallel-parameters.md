# 9 Parallel Device / Setting Parallel Parameters


You can control the parallel parameters shown in the following table. The
parameter name within the parallel [IOExtPar](../Devices_Manual_guide/node0010.html#line7) data structure is shown below.
All of the fields described in this section are filled with defaults when
you call [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html).  Thus, you need not worry about any parameter that
you do not need to change.  The parameters are defined in the include file
devices/[parallel.h](../Includes_and_Autodocs_2._guide/node004A.html).

```c
                   PARALLEL PARAMETERS ([IOExtPar](../Devices_Manual_guide/node0010.html#line7))
```
   IOExtPar
   Field Name      Parallel Device Parameter It Controls
   ----------      -------------------------------------
   io_PExtFlags    Reserved for future use.

   io_PTermArray   A byte-array of eight termination characters, must

```c
                   be in descending order.  If EOFMODE is set in the
                   parallel flags, this array specifies eight possible
                   choices of characters to use as an end-of-file mark.
                   See the [section above](../Devices_Manual_guide/node0015.html) titled  "Ending A Read Or Write
                   with Termination Characters" and the [PDCMD_SETPARAMS](../Includes_and_Autodocs_2._guide/node04F4.html)
                   summary page in the Autodocs.
```
   io_Status       Contains status information.  It is filled in by the

```c
                   [PDCMD_QUERY](../Includes_and_Autodocs_2._guide/node04F3.html) command.
```
   io_ParFlags     See "[Parallel Flags](../Devices_Manual_guide/node0017.html)" below.

You set the parallel parameters by passing an [IOExtPar](../Devices_Manual_guide/node0010.html#line7) to the device with
[PDCMD_SETPARAMS](../Includes_and_Autodocs_2._guide/node04F4.html) set in io_Command and with the flags and parameters set to
the values you want.

   ParallelIO->io_ParFlags     &= ~PARF_EOFMODE;   /* Set EOF mode */
   ParallelIO->IOPar.io_Command = PDCMD_SETPARAMS; /* Set params command */
   if (DoIO(ParallelIO);

```c
       printf("Error setting parameters!\n");
```
The above code fragment modifies one bit in io_ParFlags, then sends the
command.

   Proper Time for Parameter Changes.
   ----------------------------------
   A parameter change should not be performed while an I/O request is
   actually being processed, because it might invalidate already active
   request handling.  Therefore you should use [PDCMD_SETPARAMS](../Includes_and_Autodocs_2._guide/node04F4.html) only when
   you have no parallel I/O requests pending.

 [Parallel Flags (Bit Definitions For Io_parflags)](../Devices_Manual_guide/node0017.html) 

