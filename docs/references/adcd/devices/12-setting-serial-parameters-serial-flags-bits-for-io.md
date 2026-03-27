---
title: 12 / Setting Serial Parameters / Serial Flags (Bits For io_SerFlags)
manual: devices
chapter: devices
section: 12-setting-serial-parameters-serial-flags-bits-for-io
functions: [OpenDevice]
libraries: [exec.library]
---

# 12 / Setting Serial Parameters / Serial Flags (Bits For io_SerFlags)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are additional serial device parameters which are controlled by
flags set in the io_SerFlags field of the [IOExtSer](devices/12-serial-device-device-interface.md) structure.  The default
state of all of these flags is zero. SERF_SHARED and SERF_7WIRE must
always be set before [OpenDevice()](autodocs-2.0/serial-device-opendevice.md). The flags are defined in the include
file [serial.h](autodocs-2.0/includes-devices-serial-h.md).


```c
                        SERIAL FLAGS (IO_SERFLAGS)
```
   Flag Name            Effect on Device Operation
   --------             ---------------------------
   SERF_XDISABLED       Disable the XON/XOFF feature.  XON/XOFF must be

                        disabled during XModem transfers.
   SERF_EOFMODE         Set this bit if you want the serial device to

```c
                        check input characters against io_TermArray and to
                        terminate the read immediately if an end-of-file
                        character has been encountered. Note:  this bit
                        may be set and reset directly in the user's
                        [IOExtSer](devices/12-serial-device-device-interface.md) without a call to [SDCMD_SETPARAMS](autodocs-2.0/serial-device-sdcmd-setparams.md).
```
   SERF_SHARED          Set this bit if you want to allow other tasks to

```c
                        simultaneously access the serial port.  The
                        default is exclusive-access. Any number of tasks
                        may have shared access. Only one task may have
                        exclusive access.  If someone already has the port
                        for exclusive access, your [OpenDevice()](autodocs-2.0/serial-device-opendevice.md) call will
                        fail. This flag must be set before OpenDevice().
```
   SERF_RAD_BOOGIE      If set, this bit activates high-speed mode.

```c
                        Certain peripheral devices (MIDI, for example)
                        require high serial throughput.  Setting this bit
                        high causes the serial device to skip certain of
                        its internal checking code to speed throughput.
                        Use SERF_RAD_BOOGIE only when you have:

                        *  Disabled parity checking
                        *  Disabled XON/XOFF handling
                        *  Use 8-bit character length
                        *  Do not wish a test for a break signal

                        Note that the Amiga is a multitasking system and
                        has immediate processing of software interrupts.
                        If there are other tasks running, it is possible
                        that the serial driver may be unable to keep up
                        with high data transfer rates, even with this bit
                        set.
```
   SERF_QUEUEDBRK       If set, every break command that you transmit will

```c
                        be enqueued. This means that all commands will be
                        executed on a FIFO (first in, first out) basis.

                        If this bit is cleared (the default), a break
                        command takes immediate precedence over any serial
                        output already enqueued. When the break command
                        has finished, the interrupted request will
                        continue (if not aborted by the user).
```
   SERF_7WIRE           If set at [OpenDevice()](autodocs-2.0/serial-device-opendevice.md) time, the serial device

```c
                        will use seven-wire handshaking for RS-232-C
                        communications. Default is three-wire (pins 2, 3,
                        and 7).
```
   SERF_PARTY_ODD       If set, selects odd parity.  If clear, selects

                        even parity.
   SERF_PARTY_ON        If set, parity usage and checking is enabled. Also

```c
                        see the SERF_MSPON bit described under [io_ExtFlags](devices/12-serial-device-setting-serial-parameters-sdcmd-setparams.md)
                        above.
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
