# 20 / Other Memory Functions / Allocating Memory at an Absolute Address


For special advanced applications, [AllocAbs()](../Includes_and_Autodocs_2._guide/node032F.html) is provided. Using
AllocAbs(), an application can allocate a memory block starting at a
specified absolute memory address.  If the memory is already allocated or
if there is not enough memory available for the request, AllocAbs()
returns a zero.

Be aware that an absolute memory address which happens to be available on
one Amiga may not be available on a machine with a different configuration
or different operating system revision, or even on the same machine at a
different times.  For example, a piece of memory that is available during
expansion board configuration might not be available at earlier or later
times.  Here is an example call to [AllocAbs()](../Includes_and_Autodocs_2._guide/node032F.html):


```c
    APTR absoluteptr;

    absoluteptr = (APTR)AllocAbs(10000, 0x2F0000);
    if (!(absoluteptr))
        { /* Couldn't get memory, act accordingly. */  }

    /* After we're done using it, we call FreeMem() to free the memory */
    /* block. */
    FreeMem(absoluteptr, 10000);
```
