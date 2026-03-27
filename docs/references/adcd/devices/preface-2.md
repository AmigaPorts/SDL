---
title: Preface
manual: devices
chapter: devices
section: preface-2
functions: []
libraries: []
---

# Preface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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

 [Chapter 1, Introduction to Amiga System Devices](devices/1-introduction-to-amiga-system-devices.md)   An introduction to the
concept of an Amiga system device, the device interface, and how to
perform I/O using the devices.

 [Chapter 2, Audio Device](devices/2-audio-device.md)   The Amiga audio device allows you to play music
and make sounds.  Two example programs are included.

 [Chapter 3, Clipboard Device](devices/3-clipboard-device.md)   The clipboard device is a central facility
for sharing information between applications.  The chapter covers the
types of clipboard data and the proper ways to use the clipboard.  Two
example programs are included plus an extensively commented module of
support functions for the programs.

 [Chapter 4, Console Device](devices/4-console-device.md)  The console device is the text-oriented
interface for Amiga windows.  The chapter lists the escape sequences used
for console windows and the types of console windows.  An example program
is included.

 [Chapter 5, Gameport Device](devices/5-gameport-device.md)   The gameport device manages the various
pointing devices you plug into the mouse/joystick connectors.  The chapter
discusses the types of pointing devices, the protocol for using the device
and includes an example program.

 [Chapter 6, Input Device](devices/6-input-device.md)   The input device collects input event
information and passes this on to the operating system.  The chapter
covers this interaction between the various input sources of the system,
tells how to create your own input events and includes two example
programs.

 [Chapter 7, Keyboard Device](devices/7-keyboard-device.md)   The keyboard device is the Amiga keyboard
manager.  The chapter covers how to read the keyboard at a low level and
also how to program system reset (Ctrl-Amiga-Amiga) handlers. Three
example programs are included.

 [Chapter 8, Narrator Device](devices/8-narrator-device.md)   The narrator device is the voice of the
Amiga.  This chapter explains how to use the narrator device and the
translator library, how to write phonetic strings for the device, and
discusses the technical aspects of computer generated speech in thorough,
but understandable terms. Two example programs are included.

 [Chapter 9, Parallel Device](devices/9-parallel-device.md)   The parallel device manages the Amiga
parallel port. Two example programs are included.

 [Chapter 10, Printer Device](devices/10-printer-device.md)   The printer device translates character
streams into printer specific sequences.  The chapter covers how to use
the printer device and how to write your own printer driver.  It contains
two example programs and two complete printer drivers.

 [Chapter 11, SCSI Device](devices/11-scsi-device.md)   The SCSI device provides the Small Computer
System Interface for the Amiga.  The chapter covers how to send Amiga
specific and SCSI specific commands to SCSI devices.  An example program
is included.

 [Chapter 12, Serial Device](devices/12-serial-device.md)   The serial device manages the Amiga serial
port.  Three example programs are included.

 [Chapter 13, Timer Device](devices/13-timer-device.md)   The timer device an interface to the Amiga's
internal clocks.  The chapter explains the types of clocks and clock
units.  Four example programs are included.

 [Chapter 14, Trackdisk Device](devices/14-trackdisk-device.md)   The trackdisk device controls the Amiga
disk drives.  The chapter covers how to use the drives at a high-level
(formatted reads and writes) and low-level (raw reads and writes). An
example program is included.

 [Chapter 15, Resources](devices/15-resources.md)   The Amiga resources are a collection of low-level
interfaces to special Amiga hardware.  The chapter covers the general
resource interface and how to use all seven resources. Example code is
included for all but one of the resources.

 [Appendix A, IFF, Interchange File Format](devices/appendix-a-iff-interchange-file-format.md)   IFF is the standardized file
format of the Amiga.  This appendix introduces IFF, covers five of the IFF
types, lists the official FORM and Chunk names that are reserved and in
use and how to register new ones.  IFF include files, link modules,
example programs and utilities are included.

 [Appendix B, Example Device](devices/appendix-b-example-device.md)   This appendix contains the assembly code for
an Amiga device for all those who want to create their own custom software
I/O device.

 [Appendix C, Amiga Floppy Boot Process and Physical Layout](devices/appendix-c-floppy-boot-process-and-physical-layout.md)   This appendix
lists the method used to read the boot block of a floppy and how the data
is arranged in the boot block.

The other manuals in this series are the Amiga User Interface Style Guide,
an application design specification and reference work for Amiga
programmers, the Amiga ROM Kernel Reference Manual: [Includes and Autodocs](autodocs-2.0/includes-and-autodocs-2-0.md),
an alphabetically organized reference of ROM function summaries and Amiga
system include files, the Amiga ROM Kernel Reference Manual: [Libraries](libraries/contents.md), a
work consisting of tutorial-style chapters on the use of each Amiga system
library, and the Amiga [Hardware Reference Manual](hardware/amiga-hardware-reference-manual-contents.md), a detailed description
of the Amiga's hardware components.

