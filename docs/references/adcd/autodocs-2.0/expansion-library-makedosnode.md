---
title: expansion.library/MakeDosNode
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-makedosnode
functions: []
libraries: []
---

# expansion.library/MakeDosNode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    MakeDosNode -- construct dos data structures that a disk needs
SYNOPSIS

```c
    deviceNode = MakeDosNode( parameterPkt )
    D0                        A0

    struct [DeviceNode](autodocs-2.0/includes-dos-filehandler-h.md) * MakeDosNode( void * );
```
FUNCTION

```c
    This routine manufactures the data structures needed to enter
    a dos disk device into the system.  This consists of a [DeviceNode](autodocs-2.0/includes-dos-filehandler-h.md),
    a [FileSysStartupMsg](autodocs-2.0/includes-dos-filehandler-h.md), a disk environment vector, and up to two
    bcpl strings.  See the [libraries/dosextens.h](autodocs-2.0/includes-libraries-dosextens-h.md) and
    libraries/filehandler.h include files for more information.

    MakeDosNode will allocate all the memory it needs, and then
    link the various structure together.  It will make sure all
    the structures are long-word aligned (as required by the DOS).
    It then returns the information to the user so he can
    change anything else that needs changing.  Typically he will
    then call [AddDosNode()](autodocs-2.0/expansion-library-adddosnode.md) to enter the new device into the dos
    tables.
```
INPUTS

```c
    parameterPkt - a longword array containing all the information
        needed to initialize the data structures.  Normally I
        would have provided a structure for this, but the variable
        length of the packet caused problems.  The two strings are
        null terminated strings, like all other exec strings.

        longword    description
        --------    -----------
        0           string with dos handler name
        1           string with exec device name
        2           unit number (for OpenDevice)
        3           flags (for OpenDevice)
        4           # of longwords in rest of enviroment
        5-n         file handler environment (see libraries/filehandler.h)
```
RESULTS

```c
    deviceNode - pointer to initialize device node structure, or
        null if there was not enough memory.  You may need to change
        certain fields before passing the [DeviceNode](autodocs-2.0/includes-dos-filehandler-h.md) to [AddDosNode()](autodocs-2.0/expansion-library-adddosnode.md).
```
EXAMPLES


```c
    /* set up a 3.5" amiga format floppy drive for unit 1 */

    char execName[] = "trackdisk.device";
    char dosName[] = "df1";

    ULONG parmPkt[] = {
        (ULONG) dosName,
        (ULONG) execName,
        1,                  /* unit number */
        0,                  /* [OpenDevice](autodocs-2.0/exec-library-opendevice.md) flags */

        /* here is the environment block */
        16,                 /* table upper bound */
        512>>2,             /* # longwords in a block */
        0,                  /* sector origin -- unused */
        2,                  /* number of surfaces */
        1,                  /* secs per logical block -- leave as 1 */
        11,                 /* blocks per track */
        2,                  /* reserved blocks -- 2 boot blocks */
        0,                  /* ?? -- unused */
        0,                  /* interleave */
        0,                  /* lower cylinder */
        79,                 /* upper cylinder */
        5,                  /* number of buffers */
        MEMF_CHIP,          /* type of memory for buffers */
        (~0 >> 1),          /* largest transfer size (largest signed #) */
        ~1,                 /* addmask */
        0,                  /* boot priority */
        0x444f5300,         /* dostype: 'DOS0' */
    };

    struct [Device](autodocs-2.0/includes-exec-devices-h.md) [Node](autodocs-2.0/includes-exec-nodes-h.md) *node, *MakeDosNode();

    node = MakeDosNode( parmPkt );
```
SEE ALSO

```c
    [AddDosNode](autodocs-2.0/expansion-library-adddosnode.md), [libraries/dosextens.h](autodocs-2.0/includes-libraries-dosextens-h.md), libraries/filehandler.h
```
