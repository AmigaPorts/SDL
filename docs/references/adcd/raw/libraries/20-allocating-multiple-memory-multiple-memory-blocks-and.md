# 20 / Allocating Multiple Memory / Multiple Memory Blocks and Tasks


If you want to take advantage of Exec's automatic cleanup, use the [MemList](../Libraries_Manual_guide/node02B1.html)
and [AllocEntry()](../Libraries_Manual_guide/node02B1.html) facility to do your dynamic memory allocation.

In the [Task](../Libraries_Manual_guide/node02BB.html) control block structure, there is a list header named
[tc_MemEntry](../Libraries_Manual_guide/node02BB.html#line5). This is the list header that you initialize to include
[MemList](../Libraries_Manual_guide/node02B1.html)s that your task has created by call(s) to [AllocEntry()](../Libraries_Manual_guide/node02B1.html).  Here is a
short program segment that handles task memory list header initialization
only.  It assumes that you have already run AllocEntry() as shown in the
simple AllocEntry() example above.


```c
    struct Task *tc;
    struct MemList *ml;

    /* First initialize the task pointer and AllocEntry() the memlist ml */

    if(!tc->tc_MemEntry)
        NewList(tc->tc_MemEntry);  /* Initialize the task's memory    */
                                   /* list header. Do this once only! */
    AddTail(tc->tc_MemEntry, ml);
```
Assuming that you have only used the [AllocEntry()](../Libraries_Manual_guide/node02B1.html) method (or [AllocMem()](../Libraries_Manual_guide/node02A7.html)
and built your own custom [MemList](../Libraries_Manual_guide/node02B1.html)), the system now knows where to find the
blocks of memory that your task has dynamically allocated.  The [RemTask()](../Libraries_Manual_guide/node02D0.html#line5)
function automatically frees all memory found on [tc_MemEntry](../Libraries_Manual_guide/node02BB.html#line5).


```c
    [CreateTask()](../Libraries_Manual_guide/node02BD.html) Sets Up A [MemList](../Libraries_Manual_guide/node02B1.html).
    -------------------------------
    The amiga.lib CreateTask() function, and other system task and
    process creation functions use a MemList in [tc_MemEntry](../Libraries_Manual_guide/node02BB.html#line5) so that
    the Task structure and stack will be automatically deallocated when
    the Task is removed.
```
