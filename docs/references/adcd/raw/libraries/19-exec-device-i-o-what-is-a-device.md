# 19 Exec Device I/O / What is a Device?


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
    [Audio](../Devices_Manual_guide/node001A.html)         Controls the use of the audio hardware.
    [Clipboard](../Devices_Manual_guide/node0065.html)     Manages the cutting and pasting of common data blocks
    [Console](../Devices_Manual_guide/node0080.html)       Provides the line-oriented user interface.
    [Gameport](../Devices_Manual_guide/node00AE.html)      Controls the two mouse/joystick ports.
    [Input](../Devices_Manual_guide/node00CA.html)         Processes input from the gameport and keyboard devices.
    [Keyboard](../Devices_Manual_guide/node00FC.html)      Controls the keyboard.
    [Narrator](../Devices_Manual_guide/node0113.html)      Produces the Amiga synthesized speech.
    [Parallel](../Devices_Manual_guide/node000E.html)      Controls the parallel port.
    [Printer](../Devices_Manual_guide/node003E.html)       Converts a standard set of printer control codes to
                  printer specific codes.
    [SCSI](../Devices_Manual_guide/node0073.html)          Controls the Small Computer Standard Interface hardware.
    [Serial](../Devices_Manual_guide/node009A.html)        Controls the serial port.
    [Timer](../Devices_Manual_guide/node00BD.html)         Provides timing functions to measure time intervals and
                  send interrupts.
    [Trackdisk](../Devices_Manual_guide/node00DC.html)     Controls the Amiga floppy disk drives.
```
The philosophy behind the devices is that I/O operations should be
consistent and uniform.  You print a file in the same manner as you play
an audio sample, i.e., you send the device in question a [WRITE](../Libraries_Manual_guide/node029F.html#line40) command and
the address of the buffer holding the data you wish to write.

The result is that the interface presented to the programmer is
essentially device independent and accessible from any computer language.
This greatly expands the power the Amiga brings to the programmer and,
ultimately, to the user.

Devices support two types of commands: Exec standard commands like [READ](../Libraries_Manual_guide/node029F.html#line40)
and [WRITE](../Libraries_Manual_guide/node029F.html#line40), and device specific commands like the trackdisk device [MOTOR](../Libraries_Manual_guide/node029F.html#line68)
command which controls the floppy drive motor, and the keyboard device
[READMATRIX](../Libraries_Manual_guide/node029F.html#line59) command which returns the state of each key on the keyboard.
You should keep in mind, however, that supporting standard commands does
not mean that all devices execute them in exactly the same manner.

This chapter contains an introduction to the Exec and amiga.lib functions
that are used when accessing Amiga devices.  Consult the Amiga ROM Kernel
Manual: [Devices](../Devices_Manual_guide/node0000.html) volume for chapters on each of the Amiga devices and the
commands they support.  In addition, the Amiga ROM Kernel Reference
Manual: Includes and Autodocs contains Autodocs summarizing the commands
of each device, and listings of the device include files.  Both are very
useful manuals to have around when you are programming the devices.

