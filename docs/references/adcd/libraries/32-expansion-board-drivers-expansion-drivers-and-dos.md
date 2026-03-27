---
title: 32 / Expansion Board Drivers / Expansion Drivers and DOS
manual: libraries
chapter: libraries
section: 32-expansion-board-drivers-expansion-drivers-and-dos
functions: [Enqueue]
libraries: [exec.library]
---

# 32 / Expansion Board Drivers / Expansion Drivers and DOS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Two other expansion.library functions commonly used by expansion board
drivers are [MakeDosNode()](autodocs-2.0/expansion-library-makedosnode.md) and [AddDosNode()](autodocs-2.0/expansion-library-adddosnode.md).  These functions allow a
driver to create and add a DOS device node (for example DH0:) to the
system.   A new function, [AddBootNode()](autodocs-2.0/expansion-library-addbootnode.md), is also available in Release 2
(V36 and later versions of the OS) that can be used to add an [autobooting](libraries/32-expansion-board-drivers-rom-based-and-autoboot-drivers.md)
DOS device node.

[MakeDosNode()](autodocs-2.0/expansion-library-makedosnode.md) requires an initialized structure of environment information
for creating a DOS device node. The format of the function is:


```c
    struct DeviceNode *deviceNode = MakeDosNode(parameterPkt);
```
The parameterPkt argument is a pointer (passed in A0 from assembler) to an
initialized packet of environment parameters.

The parameter packet for [MakeDosNode()](autodocs-2.0/expansion-library-makedosnode.md) consists of four longwords followed
by a [DosEnvec](autodocs-2.0/includes-dos-filehandler-h.md) structure:


;-----------------------------------------------------------------------
;
; Layout of parameter packet for MakeDosNode
;
;-----------------------------------------------------------------------

* The packet for MakeDosNode starts with the following four
* longwords, directly followed by a DosEnvec structure.


```c
    APTR  dosName    ; Points to a DOS device name (ex. 'RAM1',0)
    APTR  execName   ; Points to device driver name (ex. 'ram.device',0)
    ULONG unit       ; Unit number
    ULONG flags      ; OpenDevice flags
```
* The DosEnvec disk "environment" is a longword array that describes the
* disk geometry.  It is variable sized, with the length at the beginning.
* Here are the constants for a standard geometry.
* See libraries/filehandler.i for additional notes.

 STRUCTURE DosEnvec,0


```c
    ULONG de_TableSize       ; Size of Environment vector
    ULONG de_SizeBlock       ; in longwords: standard value is 128
    ULONG de_SecOrg          ; not used; must be 0
    ULONG de_Surfaces        ; # of heads (surfaces). drive specific
    ULONG de_SectorPerBlock  ; not used; must be 1
    ULONG de_BlocksPerTrack  ; blocks per track. drive specific
    ULONG de_Reserved        ; DOS reserved blocks at start of partition.
    ULONG de_PreAlloc        ; DOS reserved blocks at end of partition
    ULONG de_Interleave      ; usually 0
    ULONG de_LowCyl          ; starting cylinder. typically 0
    ULONG de_HighCyl         ; max cylinder. drive specific
    ULONG de_NumBuffers      ; Initial # DOS of buffers.
    ULONG de_BufMemType      ; type of mem to allocate for buffers
    ULONG de_MaxTransfer     ; Max number of bytes to transfer at a time
    ULONG de_Mask            ; Address Mask to block out certain memory
    LONG  de_BootPri         ; Boot priority for autoboot
    ULONG de_DosType         ; ASCII (HEX) string showing filesystem type;
                             ; 0X444F5300 is old filesystem,
                             ; 0X444F5301 is fast file system
    ULONG de_Baud            ; Baud rate for serial handler
    ULONG de_Control         ; Control word for handler/filesystem
                             ; (used as filesystem/handler desires)
    ULONG de_BootBlocks      ; Number of blocks containing boot code
                             ; (for non-AmigaDOS filesystems)
    LABEL DosEnvec_SIZEOF
```
After making a DOS device node, drivers (except for [autoboot](libraries/32-expansion-board-drivers-rom-based-and-autoboot-drivers.md) drivers) use
[AddDosNode](autodocs-2.0/expansion-library-adddosnode.md)(deviceNode) to add their node to the system. Autoboot drivers
will instead use the new Release 2 expansion.library [AddBootNode()](autodocs-2.0/expansion-library-addbootnode.md)
function (if running under V36 or higher) or the Exec [Enqueue()](libraries/23-list-functions-prioritized-insertion.md) function
(if running under pre-V36) to add a [BootNode](libraries/32-rom-based-and-autoboot-drivers-events-at-romtag-init-time.md) to the
[ExpansionBase.eb_MountList](autodocs-2.0/includes-libraries-expansionbase-h.md).

---

## See Also

- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
