---
title: serial.device/OpenDevice
manual: autodocs-2.0
chapter: autodocs-2.0
section: serial-device-opendevice
functions: [Forbid, OpenDevice, Permit]
libraries: [exec.library]
---

# serial.device/OpenDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    OpenDevice -- Request an opening of the serial device.
SYNOPSIS

```c
    error = OpenDevice("serial.device", unit, ioRequest, flags)
    D0                  A0              D0    A1         D1

      BYTE OpenDevice(STRPTR, ULONG, struct IOExtSer *, ULONG);
```
FUNCTION

```c
    This is an exec call.  Exec will search for the serial.device, and
    if found, will pass this call on to the device.

    Unless the shared-access bit (bit 5 of io_SerFlags) is set,
    exclusive use is granted and no other access to that unit is
    allowed until the owner closes it.  All the serial-specific fields
    in the ioRequest are initialized to their most recent values (or
    the [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) default, for the first time open).

    If support of 7-wire handshaking (i.e. RS232-C CTS/RTS protocol)
    is required, use the [serial.device/SDCMD_SETPARAMS](autodocs-2.0/serial-device-sdcmd-setparams.md) command.
     This feature should also be specified at inital OpenDevice() time.
```
INPUTS

```c
    "serial.device" - pointer to literal string "serial.device"
     unit           - Must be zero, or a user setable unit number.
                      (This field is used by multiple port controllers)
                      Zero specifies the default serial port.
    ioRequest       - pointer to an ioRequest block of size io_ExtSerSize
                      to be initialized by the serial.device.
                      (see [devices/serial.h](autodocs-2.0/includes-devices-serial-h.md) for the definition)
                      NOTE: use of io_SerFlags (see FUNCTION above)
                      IMPORTANT: The ioRequest block MUST be of size
                      io_ExtSerSize, and zeroed (with the exeptions as
                      noted)!
    flags           - Must be zero for future compatibility
```
RESULTS

    D0              - same as io_Error
    io_Error        - If the Open succeded, then io_Error will be null.
                      If the Open failed, then io_Error will be non-zero.
    io_Device       - A pointer to whatever device will handle the calls
                      for this unit.  This pointer may be different
                      depending on what unit is requested.
BUGS


```c
    If 7-wire handshaking is specified, a timeout "feature" is enabled.
    If the device holds off the computer for more than about 30-60
    seconds, the device will return the write request with the error
    SerErr_TimerErr.  Don't depend on this, however.  If you want a
    timeout, set up the timer.device and wait for either timer, or serial
    IO to complete.

    On open, the serial.device allocates the misc.resource for the
    serial port.  It does not return it until the serial.device is
    expunged from memory.  It should return it when no more openers
    exist.   This code can force a specified device to try and
    expunge.  Of course, if the device is in use nothing will happen:

      #include "exec/types.h"
      #include "exec/execbase.h"
      #include "proto/exec.h"

      void FlushDevice(char *);
      extern struct [ExecBase](autodocs-2.0/includes-exec-execbase-h.md) *SysBase;

      void main()
      {
              FlushDevice("serial.device");   /* or parallel.device */
      }

      /*
       * Attempts to flush the named device out of memory.
       * If it fails, no status is returned; examination of
       * the problem will reveal that information has no
       * valid use after the [Permit()](autodocs-2.0/exec-library-permit.md).
       */
      void FlushDevice(name)
      char  *name;
      {
      struct [Device](autodocs-2.0/includes-exec-devices-h.md) *result;

          Forbid();
          if( result=(struct [Device](autodocs-2.0/includes-exec-devices-h.md) *)FindName(&SysBase->DeviceList,name) )
              RemDevice(result);
          Permit();
      }
```
SEE ALSO

```c
    [serial.device/CloseDevice](autodocs-2.0/serial-device-closedevice.md)
    [serial.device/SDCMD_SETPARAMS](autodocs-2.0/serial-device-sdcmd-setparams.md)
    [devices/serial.h](autodocs-2.0/includes-devices-serial-h.md)
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
