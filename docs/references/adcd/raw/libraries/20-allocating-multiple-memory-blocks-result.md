# 20 / Allocating Multiple Memory Blocks / Result


The [MemList](../Libraries_Manual_guide/node02B1.html) created by [AllocEntry()](../Libraries_Manual_guide/node02B1.html) contains [MemEntry](../Libraries_Manual_guide/node02B1.html#line23) entries.  MemEntrys
are defined by a union statement, which allows one memory space to be
defined in more than one way.

If [AllocEntry()](../Libraries_Manual_guide/node02B1.html) returns a value with bit 31 clear, then all of the
[meu_Addr](../Libraries_Manual_guide/node02B1.html#line25) positions in the returned [MemList](../Libraries_Manual_guide/node02B1.html) will contain valid memory
addresses meeting the requirements you have provided.  To use this memory
area, you would use code similar to the following:


```c
    #define ALLOCERROR 0x80000000
    struct  MemList *ml;
    APTR    data, moredata;

    if ( ! ((ULONG)ml & ALLOCERROR)))    /* After calling AllocEntry to */
                                         /* allocate ml */
    {
        data     = ml->ml_ME[0].me_Addr;
        moredata = ml->ml_ME[1].me_Addr;
    }
    else  exit(200);                     /* error during AllocEntry */
```
If [AllocEntry()](../Libraries_Manual_guide/node02B1.html) has problems while trying to allocate the memory you have
requested, instead of the address of a new [MemList](../Libraries_Manual_guide/node02B1.html), it will return the
memory requirements value with which it had the problem.  Bit 31 of the
value returned will be set, and no memory will be allocated.  Entries in
the list that were already allocated will be freed.  For example, a failed
allocation of cleared Chip memory ([MEMF_CLEAR](../Libraries_Manual_guide/node02A8.html#line37) | [MEMF_CHIP](../Libraries_Manual_guide/node02A8.html#line11)) could be
indicated with 0x80010002, where bit 31 indicates failure, bit 16 is the
MEMF_CLEAR flag and bit 1 is the MEMF_CHIP flag.

