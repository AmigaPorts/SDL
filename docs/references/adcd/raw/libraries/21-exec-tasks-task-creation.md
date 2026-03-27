# 21 Exec Tasks / Task Creation


To create a new task you must allocate a task structure, initialize its
various fields, and then link AutoDocs/it into Exec with a call to [AddTask()](../Includes_and_Autodocs_2._guide/node032D.html). The
task structure may be allocated by calling the [AllocMem()](../Libraries_Manual_guide/node02A7.html) function with
the [MEMF_CLEAR](../Libraries_Manual_guide/node02A8.html#line37) and [MEMF_PUBLIC](../Libraries_Manual_guide/node02A8.html#line31) allocation attributes.  These attributes
indicate that the data structure is to be pre-initialized to zero and that
the structure is shared.

The [Task](../Libraries_Manual_guide/node02BB.html) fields that require initialization depend on how you intend to
use the task.  For the simplest of tasks, only a few fields must be
initialized:

```c
    tc_Node
        The task list node structure.  This includes the task's
        priority, its type, and its name (refer to the chapter
```
	"[Exec Lists and Queues](../Libraries_Manual_guide/node02DA.html)").


    tc_SPLower
        The lower memory bound of the task's stack.

    tc_SPUpper
        The upper memory bound of the task's stack.

    tc_SPReg
        The initial stack pointer.  Because task stacks grow downward in
        memory, this field is usually set to the same value as
        tc_SPUpper.
Zeroing all other unused fields will cause Exec to supply the appropriate
system default values.  Allocating the structure with the [MEMF_CLEAR](../Libraries_Manual_guide/node02A8.html#line37)
attribute is an easy way to be sure that this happens.

Once the structure has been initialized, it must be linked to Exec. This
is done with a call to [AddTask()](../Includes_and_Autodocs_2._guide/node032D.html) in which the following parameters are
specified:


```c
    AddTask(struct Task *task, APTR initialPC, APTR finalPC )
```
The task argument is a pointer to your initialized [Task](../Libraries_Manual_guide/node02BB.html) structure.  Set
initialPC to the entry point of your task code.   This is the address of
the first instruction the new task will execute.

Set finalPC to the address of the finalization code for your task.  This
is a code section that will receive control if the initialPC routine ever
performs a return (RTS). This exists to prevent your task from being
launched into random memory upon an accidental return.  The finalPC
routine should usually perform various program-related clean-up duties and
should then remove the task.  If a zero is supplied for this parameter,
Exec will use its default finalization code (which simply calls the
[RemTask()](../Libraries_Manual_guide/node02D0.html#line5) function).

Under Release 2, [AddTask()](../Includes_and_Autodocs_2._guide/node032D.html) returns the address of the newly added task or
NULL for failure.  Under 1.3 and older versions of the OS, no values are
returned.

 [Task Creation With Amiga.lib](../Libraries_Manual_guide/node02BD.html)    [Task Stack](../Libraries_Manual_guide/node02BE.html)    [Task Priority](../Libraries_Manual_guide/node02BF.html) 

