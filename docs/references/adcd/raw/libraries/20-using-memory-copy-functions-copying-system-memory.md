# 20 / / Using Memory Copy Functions / Copying System Memory


The following samples show how to use the copying routines.


```c
    APTR source, target;

    source = AllocMem(1000, MEMF_CLEAR);
    target = AllocMem(1000, MEMF_CHIP);
    CopyMem(source, target, 1000);
```
[CopyMem()](../Includes_and_Autodocs_2._guide/node0342.html) copies the specified number of bytes from the source data region
to the target data region.  The pointers to the regions can be aligned on
arbitrary address boundaries.  CopyMem() will attempt to copy the memory
as efficiently as it can according to the alignment of the memory blocks,
and the amount of data that it has to transfer.  These functions are
optimized for copying large blocks of memory which can result in
unnecessary overhead if used to transfer very small blocks of memory.


```c
    CopyMemQuick(source, target, 1000);
```
[CopyMemQuick()](../Includes_and_Autodocs_2._guide/node0343.html) performs an optimized copy of the specified number of bytes
from the source data region to the target data region.  The source and
target pointers must be longword aligned and the size (in bytes) must be
divisible by four.


```c
    Not All Copies Are Supported.
    -----------------------------
    Neither [CopyMem()](../Includes_and_Autodocs_2._guide/node0342.html) nor [CopyMemQuick()](../Includes_and_Autodocs_2._guide/node0343.html) supports copying between
    regions that overlap.
```
