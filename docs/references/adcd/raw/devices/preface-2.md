# Preface


The Amiga® Technical Reference Series is the official guide to programming
Amiga computers.  This revised edition of the Amiga ROM Kernel
Reference Manual: Devices provides detailed information about the Amiga's
I/O subsystems.  It has been updated for Release 2 (Kickstart V36 and up)
of the Amiga operating system, however, most of the material and example
programs are also compatible with version 1.3.

This book is intended for the following audiences:

   *  Novice Amiga programmers who want to try out features of the Amiga

      devices without writing full-blown applications.
   *  Experienced programmers new to the Amiga.

   *  Amiga programmers and developers who want to use the devices in an

      application.
It is assumed that the reader can program in C or at least understand it.

Here is a brief overview of the contents:

 [Chapter 1, Introduction to Amiga System Devices](../Devices_Manual_guide/node0003.html)   An introduction to the
concept of an Amiga system device, the device interface, and how to
perform I/O using the devices.

 [Chapter 2, Audio Device](../Devices_Manual_guide/node001A.html)   The Amiga audio device allows you to play music
and make sounds.  Two example programs are included.

 [Chapter 3, Clipboard Device](../Devices_Manual_guide/node0065.html)   The clipboard device is a central facility
for sharing information between applications.  The chapter covers the
types of clipboard data and the proper ways to use the clipboard.  Two
example programs are included plus an extensively commented module of
support functions for the programs.

 [Chapter 4, Console Device](../Devices_Manual_guide/node0080.html)  The console device is the text-oriented
interface for Amiga windows.  The chapter lists the escape sequences used
for console windows and the types of console windows.  An example program
is included.

 [Chapter 5, Gameport Device](../Devices_Manual_guide/node00AE.html)   The gameport device manages the various
pointing devices you plug into the mouse/joystick connectors.  The chapter
discusses the types of pointing devices, the protocol for using the device
and includes an example program.

 [Chapter 6, Input Device](../Devices_Manual_guide/node00CA.html)   The input device collects input event
information and passes this on to the operating system.  The chapter
covers this interaction between the various input sources of the system,
tells how to create your own input events and includes two example
programs.

 [Chapter 7, Keyboard Device](../Devices_Manual_guide/node00FC.html)   The keyboard device is the Amiga keyboard
manager.  The chapter covers how to read the keyboard at a low level and
also how to program system reset (Ctrl-Amiga-Amiga) handlers. Three
example programs are included.

 [Chapter 8, Narrator Device](../Devices_Manual_guide/node0113.html)   The narrator device is the voice of the
Amiga.  This chapter explains how to use the narrator device and the
translator library, how to write phonetic strings for the device, and
discusses the technical aspects of computer generated speech in thorough,
but understandable terms. Two example programs are included.

 [Chapter 9, Parallel Device](../Devices_Manual_guide/node000E.html)   The parallel device manages the Amiga
parallel port. Two example programs are included.

 [Chapter 10, Printer Device](../Devices_Manual_guide/node003E.html)   The printer device translates character
streams into printer specific sequences.  The chapter covers how to use
the printer device and how to write your own printer driver.  It contains
two example programs and two complete printer drivers.

 [Chapter 11, SCSI Device](../Devices_Manual_guide/node0073.html)   The SCSI device provides the Small Computer
System Interface for the Amiga.  The chapter covers how to send Amiga
specific and SCSI specific commands to SCSI devices.  An example program
is included.

 [Chapter 12, Serial Device](../Devices_Manual_guide/node009A.html)   The serial device manages the Amiga serial
port.  Three example programs are included.

 [Chapter 13, Timer Device](../Devices_Manual_guide/node00BD.html)   The timer device an interface to the Amiga's
internal clocks.  The chapter explains the types of clocks and clock
units.  Four example programs are included.

 [Chapter 14, Trackdisk Device](../Devices_Manual_guide/node00DC.html)   The trackdisk device controls the Amiga
disk drives.  The chapter covers how to use the drives at a high-level
(formatted reads and writes) and low-level (raw reads and writes). An
example program is included.

 [Chapter 15, Resources](../Devices_Manual_guide/node0108.html)   The Amiga resources are a collection of low-level
interfaces to special Amiga hardware.  The chapter covers the general
resource interface and how to use all seven resources. Example code is
included for all but one of the resources.

 [Appendix A, IFF, Interchange File Format](../Devices_Manual_guide/node0129.html)   IFF is the standardized file
format of the Amiga.  This appendix introduces IFF, covers five of the IFF
types, lists the official FORM and Chunk names that are reserved and in
use and how to register new ones.  IFF include files, link modules,
example programs and utilities are included.

 [Appendix B, Example Device](../Devices_Manual_guide/node0159.html)   This appendix contains the assembly code for
an Amiga device for all those who want to create their own custom software
I/O device.

 [Appendix C, Amiga Floppy Boot Process and Physical Layout](../Devices_Manual_guide/node015A.html)   This appendix
lists the method used to read the boot block of a floppy and how the data
is arranged in the boot block.

The other manuals in this series are the Amiga User Interface Style Guide,
an application design specification and reference work for Amiga
programmers, the Amiga ROM Kernel Reference Manual: [Includes and Autodocs](../Includes_and_Autodocs_2._guide/node0000.html),
an alphabetically organized reference of ROM function summaries and Amiga
system include files, the Amiga ROM Kernel Reference Manual: [Libraries](../Libraries_Manual_guide/node0000.html), a
work consisting of tutorial-style chapters on the use of each Amiga system
library, and the Amiga [Hardware Reference Manual](../Hardware_Manual_guide/node0000.html), a detailed description
of the Amiga's hardware components.

