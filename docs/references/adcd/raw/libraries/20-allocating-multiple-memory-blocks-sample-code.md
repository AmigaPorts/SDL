# 20 / Allocating Multiple Memory Blocks / Sample Code


Here's an example of showing how to use the [AllocEntry()](../Libraries_Manual_guide/node02B1.html) with multiple
blocks of memory.


```c
     [allocentry.c](../Libraries_Manual_guide/node05E5.html) 
```
[AllocEntry()](../Libraries_Manual_guide/node02B1.html) returns a pointer to a new [MemList](../Libraries_Manual_guide/node02B1.html) of the same size as the
MemList that you passed to it.  For example, ROM code can provide a
MemList containing the requirements of a task and create a RAM-resident
copy of the list containing the addresses of the allocated entries.  The
pointer to the MemList is used as the argument for [FreeEntry()](../Includes_and_Autodocs_2._guide/node0354.html) to free the
memory blocks.


```c
    Assembly Does Not Have [MemEntry](../Libraries_Manual_guide/node02B1.html#line23).
    --------------------------------
    The [MemList](../Libraries_Manual_guide/node02B1.html) structure used by assembly programmers is slightly
    different; it has only a label for the start of the MemEntry
    array.  See the Exec [AllocEntry()](../Includes_and_Autodocs_2._guide/node0331.html) Autodoc for an example of using
    AllocEntry() from assembler.
```
