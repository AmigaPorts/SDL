# 11 / Easy Memory Allocation and Deallocation / Helps You Remember


The [AllocRemember()](../Includes_and_Autodocs_2._guide/node01FE.html) routine calls the Exec [AllocMem()](../Libraries_Manual_guide/node02A7.html) function to perform
the memory allocation.  (Of course, the application may directly call Exec
memory functions, see the chapter "[Exec Memory Allocation](../Libraries_Manual_guide/node02A6.html)" for details.)

[AllocRemember()](../Includes_and_Autodocs_2._guide/node01FE.html) performs two allocations each time it is called.  The
first allocation is the actual memory requested by the application.  This
memory is of the size and type specified in the call and is independent of
the second block of memory.  The second allocation is memory for a
[Remember](../Libraries_Manual_guide/node01FA.html) structure which is used to save the specifics of the allocation
in a linked list.  When [FreeRemember()](../Includes_and_Autodocs_2._guide/node0217.html) is called it uses the information
in this linked list to free all previous memory allocations at once.  This
is convenient since normally you would have to free each memory block one
at a time which requires knowing the size and base address of each one.

The [AllocRemember()](../Includes_and_Autodocs_2._guide/node01FE.html) call takes three arguments:


```c
    APTR AllocRemember( struct Remember **rememberKey, unsigned long size,
                        unsigned long flags );
```
The rememberKey is the address of a pointer to a [Remember](../Libraries_Manual_guide/node01FA.html) structure.  Note
that this is a double indirection, not just a simple pointer.  The size is
the size, in bytes, of the requested allocation.  The flags argument is
the specification for the memory allocation.  These are the same as the
specifications for the Exec [AllocMem()](../Libraries_Manual_guide/node02A7.html) function described in the chapter
on "[Exec Memory Allocation](../Libraries_Manual_guide/node02A6.html)".

If [AllocRemember()](../Includes_and_Autodocs_2._guide/node01FE.html) succeeds, it returns the address of the allocated
memory block.  It returns a NULL if the allocation fails.

The [FreeRemember()](../Includes_and_Autodocs_2._guide/node0217.html) function gives the option of freeing memory in either
of two ways.  The first (and most useful) option is to free both the link
nodes that [AllocRemember()](../Includes_and_Autodocs_2._guide/node01FE.html) created and the memory blocks to which they
correspond.  The second option is to free only the link nodes, leaving the
memory blocks for further use (and later deallocation via Exec's [FreeMem()](../Libraries_Manual_guide/node02A7.html#line11)
function).  But, as a general rule, the application should never free only
the link nodes as this can greatly fragment memory.  If the link nodes are
not required, use the Exec memory allocation functions.

The [FreeRemember()](../Includes_and_Autodocs_2._guide/node0217.html) call is as follows:


```c
    void FreeRemember( struct Remember **rememberKey, long reallyForget );
```
Set the rememberKey argument to the address of a pointer to a [Remember](../Libraries_Manual_guide/node01FA.html)
structure.  This is the same value that was passed to previous calls to
[AllocRemember()](../Includes_and_Autodocs_2._guide/node01FE.html).  The reallyForget argument is a boolean that should be
set to TRUE.  If TRUE, then both the link nodes and the memory blocks are
freed.  If FALSE, then only the link nodes are freed.  Again, applications
should avoid using the FALSE value since it can lead to highly fragmented
memory.

