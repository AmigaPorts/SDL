---
title: 12 Serial Device / Setting Serial Parameters (SDCMD_SETPARAMS)
manual: devices
chapter: devices
section: 12-serial-device-setting-serial-parameters-sdcmd-setparams
functions: []
libraries: []
---

# 12 Serial Device / Setting Serial Parameters (SDCMD_SETPARAMS)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the serial device is opened, default values for baud rate and other
parameters are automatically filled in from the serial settings in
Preferences.  The parameters may be changed by using the
[SDCMD_SETPARAMS](autodocs-2.0/serial-device-sdcmd-setparams.md) command.  The flags are defined in the include file
devices/[serial.h](autodocs-2.0/includes-devices-serial-h.md).


```c
                   SERIAL DEVICE PARAMETERS ([IOExtSer](devices/12-serial-device-device-interface.md))
```
   IOExtSer
   Field Name   Serial Device Parameter It Controls
   ---------    -----------------------------------
   io_CtlChar   Control characters to use for xON, xOFF,

                INQ, ACK respectively.  Positioned within an unsigned
                longword in the sequence from low address to high as
                listed.  INQ and ACK handshaking is not currently
                supported.
   io_RBufLen   Recommended size of the buffer that the serial device

```c
                should allocate for incoming data.  For some hardware the
                buffer size will not be adjustable.  Changing the value
                may cause the device to allocate a new buffer, which might
                fail due to lack of memory. In this case the old buffer
                will continue to be used.

                For the built-in unit, the minimum size is 64 bytes.
                Out-of-range numbers will be truncated by the device.
                When you do an [SDCMD_SETPARAMS](autodocs-2.0/serial-device-sdcmd-setparams.md) command, the driver senses
                the difference between its current value and the value of
                buffer size you request.  All characters that may already
                be in the old buffer will be discarded.  Thus it is wise
                to make sure that you do not attempt buffer size changes
                (or any change to the serial device, for that matter)
                while any I/O is actually taking place.
```
   io_ExtFlags  An unsigned long that contains the flags SEXTF_MSPON and

```c
                SEXTF_MARK.  SEXTF_MSPON enables either mark or space
                parity.  SEXTF_MARK selects mark parity (instead of space
                parity).  Unused bits are reserved.
```
   io_Baud      The real baud rate you request.  This is an unsigned long

                value in the range of 1 to 4,294,967,295.  The device will
                reject your baud request if the hardware is unable to
                support it.

                For the built-in driver, any baud rate in the range of 110
                to about 1 megabaud is acceptable.  The built-in driver
                may round 110 baud requests to 112 baud. Although baud
                rates above 19,200 are supported by the hardware, software
                overhead will limit your ability to "catch" every single
                character that should be received.  Output data rate,
                however, is not software-dependent.
   io_BrkTime   If you issue a break command, this variable specifies how

```c
                long, in microseconds, the break condition lasts.  This
                value controls the break time for all future break
                commands until modified by another [SDCMD_SETPARAMS](autodocs-2.0/serial-device-sdcmd-setparams.md).
```
   io_TermArray A byte-array of eight termination characters, must be in

```c
                descending order.  If the EOFMODE bit is set in the serial
                flags, this array specifies eight possible choices of
                character to use as an end of file mark.  See the section
                above "[Ending a Read Or Write Using Termination Characters](devices/12-ending-a-read-or-write-using-termination-characters.md)"
                and the [SDCMD_SETPARAMS](autodocs-2.0/serial-device-sdcmd-setparams.md) summary page in the Autodocs.
```
   io_ReadLen   How many bits per read character; typically a value of 7

                or 8.  Generally must be the same as io_WriteLen.
   io_WriteLen  How many bits per write character; typically a value of 7

                or 8.  Generally must be the same as io_ReadLen.
   io_StopBits  How many stop bits are to be expected when reading a

```c
                character and to be produced when writing a character;
                typically 1 or 2. The built-in driver does not allow
                values above 1 if io_WriteLen is larger than 7.
```
 io_SerFlags    See the "[Serial Flags](devices/12-setting-serial-parameters-serial-flags-bits-for-io.md)" section below.

 io_Status      Contains status information filled in by the [SDCMD_QUERY](autodocs-2.0/serial-device-sdcmd-query.md)

                command.  Break status is cleared by the execution of
                SDCMD_QUERY.
You set the serial parameters by passing an [IOExtSer](devices/12-serial-device-device-interface.md) to the device with
[SDCMD_SETPARAMS](autodocs-2.0/serial-device-sdcmd-setparams.md) set in io_Command and with the flags and parameters set to
the values you want.

  SerialIO->io_SerFlags      &= ~SERF_PARTY_ON; /* set parity off */
  SerialIO->io_SerFlags      |= SERF_XDISABLED; /* set xON/xOFF disabled */
  SerialIO->io_Baud           = 9600;           /* set 9600 baud */
  SerialIO->IOSer.io_Command  = SDCMD_SETPARAMS;/* Set params command */
  if (DoIO((struct IORequest *)SerialIO))

```c
      printf("Error setting parameters!\n");
```
The above fragment modifies two bits in io_SerFlags and changes the baud
rate. If the parameters you request are unacceptable or out of range, the
[SDCMD_SETPARAMS](autodocs-2.0/serial-device-sdcmd-setparams.md) command will fail.  You are responsible for checking the
error code and informing the user.

   Proper Time for Parameter Changes.
   ----------------------------------
   A parameter change should not be performed while an I/O request is
   actually being processed because it might invalidate the request
   handling already in progress.  To avoid this, you should use
   [SDCMD_SETPARAMS](autodocs-2.0/serial-device-sdcmd-setparams.md) only when you have no serial I/O requests pending.

 [Serial Flags (Bit Definitions For io_SerFlags)](devices/12-setting-serial-parameters-serial-flags-bits-for-io.md)  

