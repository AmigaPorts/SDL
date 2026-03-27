---
title: 1 Introduction to Amiga System Devices / What is a Device?
manual: devices
chapter: devices
section: 1-introduction-to-amiga-system-devices-what-is-a-device
functions: []
libraries: []
---

# 1 Introduction to Amiga System Devices / What is a Device?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An Amiga device is a software module that accepts commands and data and
performs I/O operations based on the commands it receives.  In most cases,
a device interacts with either internal or external hardware. Generally,
an Amiga device runs as a separate task which is capable of processing
your commands while your application attends to other things.

Device I/O is based on the Exec messaging system.  The philosophy behind
the devices is that I/O operations should be consistent and uniform.  You
print a file in the same manner as you play an audio sample, i.e., you
send the device in question a WRITE command and the address of the buffer
holding the data you wish to write.

The result is that the interface presented to the programmer is
essentially device independent and accessible from any computer language.
This greatly expands the power the Amiga computer brings to the programmer
and, ultimately, to the user.

Devices support two types of commands: Exec standard commands like READ
and WRITE, and device specific commands like the trackdisk device MOTOR
command which controls the floppy drive motor.  The Exec standard commands
are supported by most Amiga devices.  You should keep in mind, however,
that supporting standard commands does not mean that all devices execute
them in exactly the same manner.

This manual contains a chapter about each of the Amiga devices.  The
chapters cover how you use a device and the commands it supports.  In
addition, the Amiga ROM Kernel Reference Manual: [Includes and Autodocs](autodocs-2.0/includes-and-autodocs-2-0.md)
contains expanded explanations of the commands and the include files for
each device, and the Amiga ROM Kernel Reference Manual: Libraries contains
chapters on [Exec](libraries/exec-library.md).  The command explanations list the data, flags, and
other information required by a device to execute a command.  The Exec
chapters provide detailed discussions of its operation.  Both are very
useful manuals to have on your desk when you are programming the devices.

