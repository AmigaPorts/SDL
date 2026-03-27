# D / Errors / Memory Loss


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
narrator.device is first opened.  See "[Memory Loss--CLI Only](../Libraries_Manual_guide/node0551.html)" and
"[Memory Loss--WorkBench Only](../Libraries_Manual_guide/node0554.html)" if appropriate.  If you lose memory from
both WB and CLI, then check all of the open/alloc/get/create/lock type
calls in your code, and make sure that there is a matching
close/free/delete/unlock type call for each of them (note--there are a few
system calls that have or require no corresponding free--check the
Autodocs).  Generally, the close/free/delete/unlock calls should be in
opposite order of the allocations.

If you are losing a fixed small amount of memory, look for a structure of
that size in the [Structure Offsets](../Includes_and_Autodocs_2._guide/node0551.html) listing in the Amiga ROM Kernel
Reference Manual: Includes and Autodocs.  For example, a loss of exactly
24 bytes is probably a [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html) which has not been [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html)ed.  If you are
using [ScrollRaster()](../Libraries_Manual_guide/node0363.html), be aware that ScrollRaster() left or right in a
[Superbitmap window](../Libraries_Manual_guide/node011C.html) with no [TmpRas](../Libraries_Manual_guide/node034D.html#line32) will lose memory under 1.3
(workaround--attach a TmpRas).  If you lose much more memory when started
from Workbench, make sure your program is not using [Exit](../Includes_and_Autodocs_2._guide/node029F.html)(n).  This would
bypass startup code cleanups and prevent a Workbench-loaded program from
being unloaded.  Use exit(n) instead.

