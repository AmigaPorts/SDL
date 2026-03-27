---
title: expansion.library/AddBootNode
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-addbootnode
functions: []
libraries: []
---

# expansion.library/AddBootNode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddBootNode -- Add a BOOTNODE to the system (V36)
```
SYNOPSIS

```c
    ok = AddBootNode( bootPri, flags, deviceNode, configDev )
    D0                D0       D1     A0          A1

    BOOL AddBootNode( BYTE,ULONG,struct [DeviceNode](autodocs-2.0/includes-dos-filehandler-h.md) *,struct [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) * );
```
FUNCTION

    This function will do one of two things:

            1> If dos is running, add a new disk type device immediatly.
            2> If dos is not yet running, save information for later
               use by the system.
FUNCTION

```c
    This routine makes sure that your disk device (or a device
    that wants to be treated as if it was a disk...) will be
    entered into the system.  If the dos is already up and
    running, then it will be entered immediately.  If the dos
    has not yet been run then the data will be recorded, and the
    dos will get it later.

    We try and boot off of each device in turn, based on priority.
    Floppies have a hard-coded priority.

    There is only one additional piece of magic done by AddBootNode.
    If there is no executable code specified in the deviceNode
    structure (e.g. dn_SegList, dn_Handler, and dn_Task are all
    null) then the standard dos file handler is used for your
    device.

    Documentation note: a "task" as used here is a dos-task, not
    an exec-task.  A dos-task, in the strictest sense, is the
    address of an exec-style message port.  In general, it is
    a pointer to a process's pr_MsgPort field (e.g. a constant
    number of bytes after an exec task).

    Autoboot from an expansion card before DOS is running requires
    the card's [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structure.

    Pass a NULL [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) pointer to create a non-bootable node.
```
INPUTS

```c
    bootPri -- a BYTE quantity with the boot priority for this disk.
        This priority is only for which disks should be looked at:
        the actual disk booted from will be the first disk with
        a valid boot block.  If no disk is found then the "bootme"
        hand will come up and the bootstrap code will wait for
        a floppy to be inserted.  Recommend priority assignments are:

            +5   -- unit zero for the floppy disk.  The floppy should
                    always be highest priority to allow the user to
                    abort out of a hard disk boot.
             0   -- the run of the mill hard disk
            -5   -- a "network" disk (local disks should take priority).
            -128 -- don't even bother to boot from this device.

    flags -- additional flag bits for the call:
        ADNF_STARTPROC (bit 0) -- start a handler process immediately.
            Normally the process is started only when the device node
            is first referenced.  This bit is meaningless if you
            have already specified a handler process (non-null dn_Task).

    deviceNode -- a legal DOS device node, properly initialized.
            Typically this will be the result of a [MakeDosNode()](autodocs-2.0/expansion-library-makedosnode.md).
            Special cases may require a custom-built device node.

    configDev -- a valid board's [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) stucture.  This is required
            for autoboot before DOS is running and if left NULL will
            result in an non-bootable node.
```
RESULTS

    ok - non-zero everything went ok, zero if we ran out of memory
        or some other weirdness happened.
NOTE

```c
    This function eliminates the need to manually [Enqueue](autodocs-2.0/exec-library-enqueue.md) a BOOTNODE
    onto an expansion.library list.  Be sure V36 expansion.library is
    available before calling this function!
```
SEE ALSO

```c
    [AddDosNode](autodocs-2.0/expansion-library-adddosnode.md)
```
