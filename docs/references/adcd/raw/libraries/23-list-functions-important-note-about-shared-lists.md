# 23 / List Functions / Important Note About Shared Lists


It is possible to run into contention problems with other tasks when
manipulating a list that is shared by more than one task.  None of the
standard Exec list functions arbitrates for access to the list.  For
example, if some other task happens to be modifying a list while your task
scans it, an inconsistent view of the list may be formed.  This can result
in a corrupted system.

Generally it is not permissible to read or write a shared list without
first locking out access from other tasks.  All users of a list must use
the same arbitration method.  Several arbitration techniques are used on
the Amiga.  Some lists are protected by a semaphore.  The [ObtainSemaphore()](../Libraries_Manual_guide/node02FA.html)
call grants ownership of the list (see the "[Exec Semaphores](../Libraries_Manual_guide/node02F5.html)" chapter for
more information).  Some lists require special arbitration. For example,
you must use the Intuition [LockIBase](../Libraries_Manual_guide/node01F6.html#line6)(0) call before accessing any
Intuition lists.  Other lists may be accessed only during [Forbid()](../Libraries_Manual_guide/node02C2.html#line9) or
[Disable()](../Libraries_Manual_guide/node02C3.html#line6) (see the "[Exec Tasks](../Libraries_Manual_guide/node02C1.html)" chapter for more information).

The preferred method for arbitrating use of a shared list is through
semaphores because a semaphores only holds off other tasks that are trying
to access the shared list.  Rather than suspending all multitasking.
Failure to lock a shared list before use will result in unreliable
operation.

Note that I/O functions including [printf()](../Includes_and_Autodocs_2._guide/node0162.html) generally call [Wait()](../Libraries_Manual_guide/node02D4.html) to wait
for I/O completion, and this allows other tasks to run.  Therefore, it is
not safe to print or Wait() while traversing a list unless the list is
fully controlled by your application, or if the list is otherwise
guaranteed not to change during multitasking.

