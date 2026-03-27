# 20 / Memory Functions / Freeing System Memory


The following examples free the memory chunks shown in the previous calls
to [AllocMem()](../Libraries_Manual_guide/node02A7.html).


```c
    FreeMem(apointer, 100);
    FreeMem(anotherptr, 1000);
```
A memory block allocated with [AllocVec()](../Libraries_Manual_guide/node02A9.html#line21) must be returned to the system
pool with the [FreeVec()](../Includes_and_Autodocs_2._guide/node0358.html).  This function uses the stored size in the
allocation to free the memory block, so there is no need to specify the
size of the memory block to free.


```c
    FreeVec(yap);
```
[FreeMem()](../Libraries_Manual_guide/node02A7.html#line11) and [FreeVec()](../Includes_and_Autodocs_2._guide/node0358.html) return no status.  However, if you attempt to free
a memory block in the middle of a chunk that the system believes is
already free, you will cause a system crash. Applications must free the
same size memory blocks that they allocated.  An allocated block may not
be deallocated as smaller pieces.  Due to the internal way the system
rounds up and aligns allocations.  Partial deallocations can corrupt the
system memory list.


```c
    Leave Memory Allocations Out Of Interrupt Code.
    -----------------------------------------------
    Do not allocate or deallocate system memory from within interrupt
    code.  The "[Exec Interrupts](../Libraries_Manual_guide/node0308.html#line13)" chapter explains that an interrupt may
    occur at any time, even during a memory allocation process.  As a
    result, system data structures may not be internally consistent at
    this time.
```
