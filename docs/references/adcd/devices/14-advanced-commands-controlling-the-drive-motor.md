---
title: 14 / Advanced Commands / Controlling The Drive Motor
manual: devices
chapter: devices
section: 14-advanced-commands-controlling-the-drive-motor
functions: []
libraries: []
---

# 14 / Advanced Commands / Controlling The Drive Motor

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ETD_MOTOR and [TD_MOTOR](autodocs-2.0/trackdisk-device-td-motor.md) give you control of the motor. When the trackdisk
device executes this command, the old state of the motor is returned in
io_Actual. If io_Actual is zero, then the motor was off.  Any other value
implies that the motor was on.  If the motor is just being turned on, the
device will delay the proper amount of time to allow the drive to come up
to speed. Normally, turning the drive on is not necessary - the device
does this automatically if it receives a request when the motor is off.

However, turning the motor off is the programmer's responsibility. In
addition, the standard instructions to the user are that it is safe to
remove a disk if, and only if, the motor is off (that is, if the disk
light is off).

You control the drive motor by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to the device with
TD_MOTOR or ETD_MOTOR set in io_Command and the state you want to put the
motor in set in io_Length.  If io_Length is set to 1, the trackdisk device
will turn on the motor; a 0 will turn it off. For ETD_MOTOR, you must also
set iotd_Count to the current diskchange number.

   DiskIO->iotd_Req.io_Length = 1;          /* Turn on the drive motor */
   DiskIO->iotd_Req.io_Command = TD_MOTOR;
   DoIO((struct IORequest *)DiskIO);

