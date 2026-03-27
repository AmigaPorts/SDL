---
title: 9 Parallel Device / Setting Parallel Parameters
manual: devices
chapter: devices
section: 9-parallel-device-setting-parallel-parameters
functions: [OpenDevice]
libraries: [exec.library]
---

# 9 Parallel Device / Setting Parallel Parameters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can control the parallel parameters shown in the following table. The
parameter name within the parallel [IOExtPar](devices/9-parallel-device-device-interface.md) data structure is shown below.
All of the fields described in this section are filled with defaults when
you call [OpenDevice()](autodocs-2.0/exec-library-opendevice.md).  Thus, you need not worry about any parameter that
you do not need to change.  The parameters are defined in the include file
devices/[parallel.h](autodocs-2.0/includes-devices-parallel-h.md).

```c
                   PARALLEL PARAMETERS ([IOExtPar](devices/9-parallel-device-device-interface.md))
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
                   See the [section above](devices/9-parallel-device-ending-a-read-or-write-with-termination.md) titled  "Ending A Read Or Write
                   with Termination Characters" and the [PDCMD_SETPARAMS](autodocs-2.0/parallel-device-pdcmd-setparams.md)
                   summary page in the Autodocs.
```
   io_Status       Contains status information.  It is filled in by the

```c
                   [PDCMD_QUERY](autodocs-2.0/parallel-device-pdcmd-query.md) command.
```
   io_ParFlags     See "[Parallel Flags](devices/9-setting-parallel-parameters-parallel-flags-bits-for-io.md)" below.

You set the parallel parameters by passing an [IOExtPar](devices/9-parallel-device-device-interface.md) to the device with
[PDCMD_SETPARAMS](autodocs-2.0/parallel-device-pdcmd-setparams.md) set in io_Command and with the flags and parameters set to
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
   request handling.  Therefore you should use [PDCMD_SETPARAMS](autodocs-2.0/parallel-device-pdcmd-setparams.md) only when
   you have no parallel I/O requests pending.

 [Parallel Flags (Bit Definitions For Io_parflags)](devices/9-setting-parallel-parameters-parallel-flags-bits-for-io.md) 

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
