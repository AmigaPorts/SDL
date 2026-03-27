# 17 Introduction to Exec / Dynamic Memory Allocation


The Amiga has a soft machine architecture, meaning that all tasks,
including those that are part of its operating system, do not use fixed
memory addresses.  As a result, any program that needs to use a chunk of
memory must allocate that memory from the operating system.

There are two functions on the Amiga for simple memory allocation:
[AllocMem()](../Libraries_Manual_guide/node02A7.html) and [AllocVec()](../Libraries_Manual_guide/node02A9.html#line21).  The two functions accept the same parameters,
a ULONG containing the size of the memory block in bytes followed by
32-bit specifier for memory attributes.  Both functions return the address
of a longword aligned memory block if they were successful or NULL if
something went wrong.

[AllocVec()](../Libraries_Manual_guide/node02A9.html#line21) differs from [AllocMem()](../Libraries_Manual_guide/node02A7.html) in that it records the size of the
memory block allocated so an application does not have to remember the
size of a memory block it allocated.  AllocVec() was introduced in Release
2, so it is not available to the 1.3 developer.

Normally the bitmask of memory attributes passed to these functions will
contain any of the following attributes (these flags are defined in
<exec/[memory.h](../Includes_and_Autodocs_2._guide/node0089.html#line66)>):

MEMF_ANY

    This indicates that there is no requirement for either Fast or Chip
    memory.  In this case, while there is Fast memory available, Exec
    will only allocate Fast memory.  Exec will allocate Chip memory if
    there is not enough Fast memory.
MEMF_CHIP

    This indicates the application wants a block of Chip memory, meaning
    it wants memory addressable by the Amiga custom chips.  Chip memory
    is required for any data that will be accessed by custom chip DMA.
    This includes floppy disk buffers, screen memory, images that will be
    blitted, sprite data, copper lists, and audio data.  If your
    application requires a block of Chip RAM, it must use this flag to
    allocate the Chip RAM.  Otherwise, the application will fail on
    machines with expanded memory.
MEMF_FAST

    This indicates a memory block outside of the range that the Amiga's
    custom chips can access.  The "FAST" in MEMF_FAST has to do with the
    custom chips and the CPU trying to access the same memory at the same
    time.  Because the custom chips and the CPU both have access to Chip
    RAM, the CPU may have to wait to access Chip RAM while some custom
    chip is reading or writing Chip RAM.  In the case of Fast RAM, the
    custom chips do not have access to it, so the CPU does not have to
    contend with the custom chips access to Fast RAM, making CPU accesses
    to Fast RAM generally faster than CPU access to Chip RAM.

    Since the flag specifies memory that the custom chips cannot access,
    this flag is mutually exclusive with the MEMF_CHIP flag.  If you
    specify the MEMF_FAST flag, your allocation will fail on Amigas that
    have only Chip memory.  Use MEMF_ANY if you would prefer Fast memory.
MEMF_PUBLIC

```c
    This indicates that the memory should be accessible to other tasks.
    Although this flag doesn't do anything right now, using this flag
    will help ensure compatibility with possible future features of the
    OS (like virtual memory and memory protection).
```
MEMF_CLEAR

    This indicates that the memory should be initialized with zeros.
If an application does not specify any attributes when allocating memory,
the system first looks for MEMF_FAST, then MEMF_CHIP.  There are
additional memory allocation flags for Release 2: [MEM_LOCAL](../Libraries_Manual_guide/node02A8.html#line40), [MEMF_24BITDMA](../Libraries_Manual_guide/node02A8.html#line44)
and [MEMF_REVERSE](../Libraries_Manual_guide/node02A8.html#line50).  See the Exec Autodoc for [AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html) in the Amiga ROM
Kernel Reference Manual: Includes and Autodocs or the include file
<exec/[memory.h](../Includes_and_Autodocs_2._guide/node0089.html#line66)> for additional information on these flags.  Use of these
flags under earlier versions of the operating system will cause your
allocation to fail.


    Make Sure You Have Memory.
    --------------------------
    Always check the result of any memory allocation to be sure the type
    and amount of memory requested is available.  Failure to do so will
    lead to trying to use an non-valid pointer.
When an application is finished with a block of memory it allocated, it
must return it to the operating system.  There is a function to return
memory for both the [AllocMem()](../Libraries_Manual_guide/node02A7.html) and the [AllocVec()](../Libraries_Manual_guide/node02A9.html#line21) functions.  [FreeMem()](../Libraries_Manual_guide/node02A7.html#line11)
releases memory allocated by AllocMem().

It takes two parameters, a pointer to a memory block and the size of the
memory block.  [FreeVec()](../Libraries_Manual_guide/node02A7.html#line11) releases memory allocated by [AllocVec()](../Libraries_Manual_guide/node02A9.html#line21).  It
takes only one parameter, a pointer to a memory block allocated by
AllocVec().  The following example shows how to allocate and deallocate
memory.


```c
    APTR  my_mem;

    if (my_mem = AllocMem(100, MEMF_ANY))
    {
        /* Your code goes here */
        FreeMem(my_mem, 100);
    }
    else  { /* couldn't get memory, exit with an error */ }
```
