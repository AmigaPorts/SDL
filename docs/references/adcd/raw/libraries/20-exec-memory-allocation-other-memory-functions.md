# 20 Exec Memory Allocation / Other Memory Functions


[Allocate()](../Includes_and_Autodocs_2._guide/node0330.html) and [Deallocate()](../Includes_and_Autodocs_2._guide/node0346.html) use a memory region header, called [MemHeader](../Includes_and_Autodocs_2._guide/node0089.html#line27),
as part of the calling sequence.  You can build your own local header to
manage memory locally. This structure takes the form:


```c
    struct MemHeader {
        struct Node       mh_Node;
        UWORD             mh_Attributes; /* characteristics of region  */
        struct  MemChunk *mh_First;      /* first free region          */
        APTR              mh_Lower;      /* lower memory bound         */
        APTR              mh_Upper;      /* upper memory bound + 1     */
        ULONG             mh_Free;       /* total number of free bytes */
    };
```
mh_Attributes

```c
    is ignored by [Allocate()](../Includes_and_Autodocs_2._guide/node0330.html) and [Deallocate()](../Includes_and_Autodocs_2._guide/node0346.html).
```
mh_First

```c
    is the pointer to the first [MemChunk](../Includes_and_Autodocs_2._guide/node0089.html#line19) structure.
```
mh_Lower

    is the lowest address within the memory block. This must be a
    multiple of eight bytes.
mh_Upper

```c
    is the highest address within the memory block + 1.  The highest
    address will itself be a multiple of eight if the block was allocated
    to you by [AllocMem()](../Libraries_Manual_guide/node02A7.html).
```
mh_Free

    is the total free space.
This structure is included in the include files <exec/[memory.h](../Includes_and_Autodocs_2._guide/node0089.html#line27)> and
<exec/[memory.i](../Includes_and_Autodocs_2._guide/node008D.html#line70)>.

The following sample code fragment shows the correct initialization of a
MemHeader structure.  It assumes that you wish to allocate a block of
memory from the global pool and thereafter manage it yourself using
[Allocate()](../Includes_and_Autodocs_2._guide/node0330.html) and [Deallocate()](../Includes_and_Autodocs_2._guide/node0346.html).


```c
     [allocate.c](../Libraries_Manual_guide/node05E6.html) 

    How Memory Is Tagged.
    ---------------------
    Only free memory is "tagged" using a [MemChunk](../Includes_and_Autodocs_2._guide/node0089.html#line19) linked list. Once
    memory is allocated, the system has no way of determining which task
    now has control of that memory.
```
If you allocate memory from the system, be sure to deallocate it when your
task exits.  You can accomplish this with matched deallocations, or by
adding a [MemList](../Libraries_Manual_guide/node02B1.html) to your task's [tc_MemEntry](../Libraries_Manual_guide/node02A7.html#line5), or you can deallocate the
memory in the finalPC routine (which can be specified if you perform
[AddTask()](../Libraries_Manual_guide/node02BC.html#line31) yourself).

 [Allocating Memory at an Absolute Address](../Libraries_Manual_guide/node02B7.html) 
 [Adding Memory to the System Pool](../Libraries_Manual_guide/node02B8.html) 

