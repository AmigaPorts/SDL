# 11 / Easy Memory Allocation and Deallocation / The Remember Structure


The Remember structure is defined in <intuition/[intuition](../Includes_and_Autodocs_2._guide/node00D4.html#line1229)> as follows:


```c
    struct Remember
        {
        struct Remember *NextRemember;
        ULONG RememberSize;
        UBYTE *Memory;
        };
```
Generally, the Remember structure is handled only by the system.  Here are
its fields:


    NextRemember - The link to the next Remember structure.
    RememberSize - The size of the memory tracked by this node.
    Memory       - A pointer to the memory tracked by this node.
