# 20 / Other Memory Functions / Adding Memory to the System Pool


When non-Autoconfig memory needs to be added to the system free pool, the
[AddMemList()](../Includes_and_Autodocs_2._guide/node0328.html) function can be used.  This function takes the size of the
memoryblock, its type, the priority for the memory list, the base address
and the name of the memory block.  A [MemHeader](../Libraries_Manual_guide/node02B6.html) structure will be placed at
the start of the memory block, the remainder of the memory block will be
made available for allocation. For example:


```c
    AddMemList(0x200000, MEMF_FAST, 0, 0xF00000, "FZeroBoard");
```
will add a two megabyte memory block, starting at $F00000 to the system
free pool as Fast memory.  The memory list entry is identified with
"FZeroBoard".

