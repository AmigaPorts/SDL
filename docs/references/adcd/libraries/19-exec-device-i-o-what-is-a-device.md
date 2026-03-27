---
title: 19 Exec Device I/O / What is a Device?
manual: libraries
chapter: libraries
section: 19-exec-device-i-o-what-is-a-device
functions: []
libraries: []
---

# 19 Exec Device I/O / What is a Device?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An Amiga device is a software module that accepts commands and data and
performs I/O operations based on the commands it receives.  In most cases,
it interacts with either internal or external hardware, (the exceptions
are the clipboard device and ramdrive device which simply use memory).
Generally, an Amiga device runs as a separate task which is capable of
processing your commands while your application attends to other things.




```c
                  Table 19-1: Amiga System Devices

    Amiga Device  Purpose
    ------------  -------
    [Audio](devices/2-audio-device.md)         Controls the use of the audio hardware.
    [Clipboard](devices/3-clipboard-device.md)     Manages the cutting and pasting of common data blocks
    [Console](devices/4-console-device.md)       Provides the line-oriented user interface.
    [Gameport](devices/5-gameport-device.md)      Controls the two mouse/joystick ports.
    [Input](devices/6-input-device.md)         Processes input from the gameport and keyboard devices.
    [Keyboard](devices/7-keyboard-device.md)      Controls the keyboard.
    [Narrator](devices/8-narrator-device.md)      Produces the Amiga synthesized speech.
    [Parallel](devices/9-parallel-device.md)      Controls the parallel port.
    [Printer](devices/10-printer-device.md)       Converts a standard set of printer control codes to
                  printer specific codes.
    [SCSI](devices/11-scsi-device.md)          Controls the Small Computer Standard Interface hardware.
    [Serial](devices/12-serial-device.md)        Controls the serial port.
    [Timer](devices/13-timer-device.md)         Provides timing functions to measure time intervals and
                  send interrupts.
    [Trackdisk](devices/14-trackdisk-device.md)     Controls the Amiga floppy disk drives.
```
The philosophy behind the devices is that I/O operations should be
consistent and uniform.  You print a file in the same manner as you play
an audio sample, i.e., you send the device in question a [WRITE](libraries/19-exec-device-i-o-using-a-device.md) command and
the address of the buffer holding the data you wish to write.

The result is that the interface presented to the programmer is
essentially device independent and accessible from any computer language.
This greatly expands the power the Amiga brings to the programmer and,
ultimately, to the user.

Devices support two types of commands: Exec standard commands like [READ](libraries/19-exec-device-i-o-using-a-device.md)
and [WRITE](libraries/19-exec-device-i-o-using-a-device.md), and device specific commands like the trackdisk device [MOTOR](libraries/19-exec-device-i-o-using-a-device.md)
command which controls the floppy drive motor, and the keyboard device
[READMATRIX](libraries/19-exec-device-i-o-using-a-device.md) command which returns the state of each key on the keyboard.
You should keep in mind, however, that supporting standard commands does
not mean that all devices execute them in exactly the same manner.

This chapter contains an introduction to the Exec and amiga.lib functions
that are used when accessing Amiga devices.  Consult the Amiga ROM Kernel
Manual: [Devices](devices/contents-2.md) volume for chapters on each of the Amiga devices and the
commands they support.  In addition, the Amiga ROM Kernel Reference
Manual: Includes and Autodocs contains Autodocs summarizing the commands
of each device, and listings of the device include files.  Both are very
useful manuals to have around when you are programming the devices.

