---
title: D / Errors / Memory Loss
manual: libraries
chapter: libraries
section: d-errors-memory-loss
functions: [Lock, ScrollRaster, UnLock]
libraries: [dos.library, graphics.library]
---

# D / Errors / Memory Loss

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

First determine that your program is actually causing a memory loss.  It
is important to boot with a standard Workbench because a number of third
party items such as some background utilities, shells, and network
handlers dynamically allocate and free pieces of memory.  Open a Shell for
memory checking, and a Shell or Workbench drawer for starting your
program.  Arrange windows so that all are accessible, and so that no
window rearrangement will be needed to run your program.

In the Shell, type Avail FLUSH<RET> several times (2.0 option).  This will
flush all non-open disk-loaded fonts, devices, etc., from memory. Note the
amount of free memory.  Now without rearranging any windows, start your
program and use all of your program features.  Exit your program, wait a
few seconds, then type Avail FLUSH<RET> several times.  Note the amount of
free memory.  If this matches the first value you noted, your program is
fine, and is not causing a memory loss.

If memory was actually lost, and your program can be run from CLI or
Workbench, then try the above procedure with both methods of starting your
program.  Note that under 2.0, there will be a slight permanent (until
reboot) memory usage of about 672 bytes when the audio.device or
narrator.device is first opened.  See "[Memory Loss--CLI Only](libraries/d-errors-memory-loss-cli-only.md)" and
"[Memory Loss--WorkBench Only](libraries/d-errors-memory-loss-workbench-only.md)" if appropriate.  If you lose memory from
both WB and CLI, then check all of the open/alloc/get/create/lock type
calls in your code, and make sure that there is a matching
close/free/delete/unlock type call for each of them (note--there are a few
system calls that have or require no corresponding free--check the
Autodocs).  Generally, the close/free/delete/unlock calls should be in
opposite order of the allocations.

If you are losing a fixed small amount of memory, look for a structure of
that size in the [Structure Offsets](autodocs-2.0/references-structure-offs.md) listing in the Amiga ROM Kernel
Reference Manual: Includes and Autodocs.  For example, a loss of exactly
24 bytes is probably a [Lock()](autodocs-2.0/dos-library-lock.md) which has not been [UnLock()](autodocs-2.0/dos-library-unlock.md)ed.  If you are
using [ScrollRaster()](libraries/27-data-move-operations-scrolling-a-sub-rectangle-of-a.md), be aware that ScrollRaster() left or right in a
[Superbitmap window](libraries/4-refreshing-intuition-windows-superbitmap-refresh.md) with no [TmpRas](libraries/27-the-rastport-structure-rastport-area-fill-information.md) will lose memory under 1.3
(workaround--attach a TmpRas).  If you lose much more memory when started
from Workbench, make sure your program is not using [Exit](autodocs-2.0/dos-library-exit.md)(n).  This would
bypass startup code cleanups and prevent a Workbench-loaded program from
being unloaded.  Use exit(n) instead.

---

## See Also

- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [ScrollRaster — graphics.library](../autodocs/graphics.library.md#scrollraster)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
