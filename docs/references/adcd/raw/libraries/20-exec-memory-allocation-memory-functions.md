# 20 Exec Memory Allocation / Memory Functions


Normally, an application uses the [AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html) function to ask for memory:


```c
    APTR AllocMem(ULONG byteSize, ULONG attributes);
```
The byteSize argument is the amount of memory the application needs and
attributes is a bit field which specifies any special memory
characteristics ([described later](../Libraries_Manual_guide/node02A8.html)).  If [AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html) is successful, it
returns a pointer to a block of memory.  The memory allocation will fail
if the system cannot find a big enough block with the requested
attributes.  If AllocMem() fails, it returns NULL.

Because the system only keeps track of how much free memory is available
and not how much is in use, it has no idea what memory has been allocated
by any task.  This means an application has to explicitly return, or
deallocate, any memory it has allocated so the system can return that
memory to the free memory list.  If an application does not return a block
of memory to the system, the system will not be able to reallocate that
memory to some other task.  That block of memory will be lost until the
Amiga is reset.  If you are using [AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html) to allocate memory, a call to
[FreeMem()](../Includes_and_Autodocs_2._guide/node0355.html) will return that memory to the system:


```c
    void FreeMem(APTR mymemblock, ULONG byteSize);
```
Here mymemblock is a pointer to the memory block the application is
returning to the system and byteSize is the same size that was passed when
the memory was allocated with [AllocMem()](../Includes_and_Autodocs_2._guide/node0332.html).

Unlike some compiler memory allocation functions, the Amiga system memory
allocation functions return memory blocks that are at least longword
aligned.  This means that the allocated memory will always start on an
address which is at least evenly divisible by four.  This alignment makes
the memory suitable for any system structures or buffers which require
word or longword alignment, and also provides optimal alignment for stacks
and memory copying.

 [Memory Attributes](../Libraries_Manual_guide/node02A8.html) 
 [Allocating System Memory](../Libraries_Manual_guide/node02A9.html) 
 [Freeing System Memory](../Libraries_Manual_guide/node02AA.html) 
 [Memory Information Functions](../Libraries_Manual_guide/node02AB.html) 
 [Using Memory Copy Functions](../Libraries_Manual_guide/node02AE.html) 
 [Summary of System Controlled Memory Handling Routines](../Libraries_Manual_guide/node02B0.html) 

