---
title: Volume Manipulation/Information
manual: amiga-mail
chapter: amiga-mail
section: volume-manipulation-information
functions: []
libraries: []
---

# Volume Manipulation/Information

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Volume Manipulation and Information actions are used to allow
access to the underlying volume currently being manipulated by the
file system.


ACTION_CURRENT_VOLUME    7       <sendpkt only>
RES1:   BPTR    Pointer to volume node of current volume

This action returns a pointer to the volume node (from the DOS device
list) associated with the file system.  As the volume node may be
removed from the device list when the file system mounts a different
volume (such as when directed to by an ACTION_INHIBIT) there is no
guarantee that this pointer will remain valid for any amount of time.
This action is generally used by AmigaDOS to provide the volume line
of a requester.


ACTION_DISK_INFO         25      Info(...)
ARG1:   BPTR    Pointer to an InfoData structure to fill in

RES1:   BOOL    Success/Failure (DOSTRUE/DOSFALSE)


ACTION_INFO              26      <sendpkt only>
ARG1:   LOCK    Lock
ARG2:   BPTR    Pointer to a InfoData Structure to fill in

RES1:   BOOL    Success/Failure (DOSTRUE/DOSFALSE)

These actions are used to get information about the device and status
of the file handler.  ACTION_DISK_INFO is used by the info command to
report the status of the volume currently in the drive.  It fills in
an InfoData structure about the volume the file system currently
controls.  This structure should be longword aligned.  ACTION_INFO
fills in an InfoData structure for  the volume the lock (ARG1) is on
instead of the volume currently in the drive.  These actions are
generally expected to return DOSTRUE.

The ACTION_DISK_INFO packet has a special meaning for console style
handlers.  When presented with this packet, a console style handler
should return a pointer to the window associated with the open handle.


ACTION_RENAME_DISK      9       Relabel(...) in 2.0
ARG1:   BSTR    New disk name

RES1:   BOOL    Success/Failure (DOSTRUE/DOSFALSE)

This action allows an application to change the name of the current
volume.  A file system implementing this function must also change
the name stored in the volume node of the DOS device list.


ACTION_FORMAT            1020    Format(fs,vol,type)
ARG1:   BSTR    Name for volume (if supported)
ARG2:   LONG    Type of format (file system specific)

RES1:   BOOL    Success/Failure (DOSTRUE/DOSFALSE)
RES2:   CODE    Failure code if RES1 is DOSFALSE

This packet tells a file system to perform any device or file system
specific formatting on any newly initialized media.  Upon receiving
this action, a file system can assume that the media has already been
low level formatted and should proceed to write out any high level
disk structure necessary to create an empty volume.

