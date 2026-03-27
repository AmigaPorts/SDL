---
title: II-5: AmigaDOS Packet Interface Specification
manual: amiga-mail
chapter: amiga-mail
section: ii-5-amigados-packet-interface-specification
functions: []
libraries: []
---

# II-5: AmigaDOS Packet Interface Specification

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

AmigaDOS Packet Interface Specification

by John Toebes


AmigaDOS communicates with file systems and other DOS handlers by
sending and receiving packets.  Opening and closing file handles
(including console file handles), creating directories, and renaming
disks all require DOS to tell a handler to perform these actions
through sending a packet.  The particular action a handler performs
depends on the type of packet it receives.

This article documents the standard AmigaDOS packet types.  For
information on how to use packets to communicate with handlers see
the AmigaDOS Manual.

Packets sent to a file system or handler can be divided into several
basic categories:


```c
    o   [Basic Input/Output](amiga-mail/basic-input-output.md)
```
These actions deal with tranferring data to and from objects
controlled by the handler.


```c
    o   [File/Directory Manipulation/Information](amiga-mail/directory-file-manipulation-information.md)
```
These actions are used to gain access to and manipulate the high
level structures of the file system.


```c
    o   [Volume Manipulation/Information](amiga-mail/volume-manipulation-information.md)
```
These actions allow access to the specific volume controlled by the
file system.


```c
    o   [Handler Maintenance and Control](amiga-mail/handler-maintenance-and-control.md)
```
These allow control over the handler/file system itself, independent
of the actual volume or structure underneath.


```c
    o   [Handler Internal](amiga-mail/handler-internal.md)
```
These actions are never sent to the handler directly.  Instead they
are generally responses to IO requests made by the handler.  The
handler makes these responses look like packets in order to simplify
processing.


```c
    o   [Obsolete Packets](amiga-mail/obsolete-packets.md)
```
These packets are no longer valid for use by handlers and file
systems.


```c
    o   [Console Only Packets](amiga-mail/console-only-packets.md)
```
These packets are specific to console handlers.  File Systems can
ignore these packets.


Much of this information can be extracted from Developer Conference
notes, The AmigaDOS Manual, and various Fred Fish disks.  However,
because there is no single complete reference to these packet types,
a consolidated view of all the packets is presented here.  Several
structures are referenced here which can be found by looking at the
include files <dos/dos.h> and <dos/dosextens.h>.  (If you are using
the 1.3 version of the include files, these are in the libraries
directory instead of the dos directory).  Before attempting to work
with a file handler you should first become familiar with these files.

Each packet type documented in this article is listed with its action
name, its corresponding number, any AmigaDOS routines which uses this
packet, and the list of  parameters that the packets uses.  The C
variable types for the packet parameters are one of the following
types:


BPTR    This is BCPL pointer (the address of the given object shifted


```c
        right by 2).  Note: this means that the object must be
        aligned on a longword boundary.
```
LOCK    This is a BPTR to a FileLock structure returned by a previous


        ACTION_LOCATE_OBJECT.  A lock of 0 is legal, indicating the
        root of the volume for the handler.
BSTR    This is a BPTR to a string where the first byte indicates the


        number of characters in the string.  This length byte is
        unsigned but because it is stored in a byte, the strings are
        limited to 255 characters in length.
BOOL    A 32-bit boolean value either containing DOSTRUE (-1) or


```c
        DOSFALSE (0).  Note: equality comparisons with DOSTRUE should
        be avoided.
```
CODE    A 32 bit error code as defined in the dos/dos.h include file.


        Handlers should not return error codes besides those defined
        in dos/dos.h.
ARG1    The FileHandle->fh_Arg1 field.


LONG    A 32 bit integer value.



Summary of Defined Packet Numbers

This is a listing of all the DOS packets defined by Commodore.
Packets 0-1999 are reserved for use by Commodore.  Unless otherwise
noted, packets 2050-2999 are reserved for use by third party
developers (see chart below).  The remaining packets are reserved for
future expansion (Note: packets 2008, 2009, 4097, and 4098 are in use
by Commodore).


        Decimal Hex     Action #define

        0       0x0000  ACTION_NIL
        1               <Reserved by Commodore>
        2       0x0002  ACTION_GET_BLOCK
        3               <Reserved by Commodore>
        4       0x0004  ACTION_SET_MAP
        5       0x0005  ACTION_DIE
        6       0x0006  ACTION_EVENT
        7       0x0007  ACTION_CURRENT_VOLUME
        8       0x0008  ACTION_LOCATE_OBJECT
        9       0x0009  ACTION_RENAME_DISK
        10-14           <Reserved by Commodore>
        15      0x000F  ACTION_FREE_LOCK
        16      0x0010  ACTION_DELETE_OBJECT
        17      0x0011  ACTION_RENAME_OBJECT
        18      0x0012  ACTION_MORE_CACHE
        19      0x0013  ACTION_COPY_DIR
        20      0x0014  ACTION_WAIT_CHAR
        21      0x0015  ACTION_SET_PROTECT
        22      0x0016  ACTION_CREATE_DIR
        23      0x0017  ACTION_EXAMINE_OBJECT
        24      0x0018  ACTION_EXAMINE_NEXT
        25      0x0019  ACTION_DISK_INFO
        26      0x001A  ACTION_INFO
        27      0x001B  ACTION_FLUSH
        28      0x001C  ACTION_SET_COMMENT
        29      0x001D  ACTION_PARENT
        30      0x001E  ACTION_TIMER
        31      0x001F  ACTION_INHIBIT
        32      0x0020  ACTION_DISK_TYPE
        33      0x0021  ACTION_DISK_CHANGE
        34      0x0022  ACTION_SET_DATE
        35-39           <Reserved by Commodore>
        40      0x0028  ACTION_SAME_LOCK
        41-81           <Reserved by Commodore>
        82      0x0052  ACTION_READ
        83-86           <Reserved by Commodore>
        87      0x0057  ACTION_WRITE
        88-993          <Reserved by Commodore>
        994     0x03E2  ACTION_SCREEN_MODE
        995     0x03E3  ACTION_CHANGE_SIGNAL
        996-1000        <Reserved by Commodore>
        1001    0x03E9  ACTION_READ_RETURN
        1002    0x03EA  ACTION_WRITE_RETURN
        1003            <Reserved by Commodore>
        1004    0x03EC  ACTION_FINDUPDATE
        1005    0x03ED  ACTION_FINDINPUT
        1006    0x03EE  ACTION_FINDOUTPUT
        1007    0x03EF  ACTION_END
        1008    0x03F0  ACTION_SEEK
        1009-1019       <Reserved by Commodore>
        1020    0x03FC  ACTION_FORMAT
        1021    0x03FD  ACTION_MAKE_LINK
        1022    0x03FE  ACTION_SET_FILE_SIZE
        1023    0x03FF  ACTION_WRITE_PROTECT
        1024    0x0400  ACTION_READ_LINK
        1025            <Reserved by Commodore>
        1026    0x0402  ACTION_FH_FROM_LOCK
        1027    0x0403  ACTION_IS_FILESYSTEM
        1028    0x0404  ACTION_CHANGE_MODE
        1029            <Reserved by Commodore>
        1030    0x0406  ACTION_COPY_DIR_FH
        1031    0x0407  ACTION_PARENT_FH
        1032            <Reserved by Commodore>
        1033    0x0409  ACTION_EXAMINE_ALL
        1034    0x040A  ACTION_EXAMINE_FH
        1035-2007       <Reserved by Commodore>
        2008    0x07D8  ACTION_LOCK_RECORD
        2009    0x07D9  ACTION_FREE_RECORD
        2010-2049       <Reserved by Commodore>
        2050-2999       <Reserved for 3rd Party Handlers>
        4097    0x1001  ACTION_ADD_NOTIFY
        4098    0x1002  ACTION_REMOVE_NOTIFY
        4099-           <Reserved by Commodore for Future Expansion>
