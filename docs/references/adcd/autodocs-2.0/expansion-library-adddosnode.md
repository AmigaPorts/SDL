---
title: expansion.library/AddDosNode
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-adddosnode
functions: [Enqueue]
libraries: [exec.library]
---

# expansion.library/AddDosNode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddDosNode -- mount a disk to the system
SYNOPSIS

```c
    ok = AddDosNode( bootPri, flags, deviceNode )
    D0               D0       D1     A0

    BOOL AddDosNode( BYTE,ULONG,struct [DeviceNode](autodocs-2.0/includes-dos-filehandler-h.md) *);
```
FUNCTION

```c
    This is the old (pre V36) function that works just like
    [AddBootNode()](autodocs-2.0/expansion-library-addbootnode.md).  It should only be used if you *MUST* work
    in a 1.3 system and you don't need to autoboot.
```
RESULTS

    ok - non-zero everything went ok, zero if we ran out of memory
        or some other weirdness happened.
EXAMPLE

```c
    /* enter a bootable disk into the system.  Start a file handler
    ** process immediately.
    */
    if(  AddDosNode( 0, ADNF_STARTPROC, MakeDosNode( paramPacket ) )  )
            ...AddDosNode ok...
```
BUGS

```c
    Before V36 Kickstart, no function existed to add BOOTNODES.
    If an older expansion.library is in use, driver code will need
    to manually construct a [BootNode](autodocs-2.0/includes-libraries-expansionbase-h.md) and [Enqueue()](autodocs-2.0/exec-library-enqueue.md) it to eb_Mountlist.
    If you have a V36 or better expansion.library, your code should
    use [AddBootNode()](autodocs-2.0/expansion-library-addbootnode.md).
```
SEE ALSO

```c
    [MakeDosNode](autodocs-2.0/expansion-library-makedosnode.md), [AddBootNode](autodocs-2.0/expansion-library-addbootnode.md)
```

---

## See Also

- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
