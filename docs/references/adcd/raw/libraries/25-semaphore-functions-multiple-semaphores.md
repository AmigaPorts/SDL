# 25 / Semaphore Functions / Multiple Semaphores


The semaphore system has the ability to ask for ownership of a complete
list of semaphores.  This can help prevent deadlocks when there are two or
more tasks trying to get the same set of semaphores.  If task A gets
semaphore 1 and tries to obtain semaphore 2 after task B has obtained
semaphore 2 but before task B tries to obtain semaphore 1 then both tasks
will hang.  Exec provides [ObtainSemaphoreList()](../Includes_and_Autodocs_2._guide/node0363.html) and [ReleaseSemaphoreList()](../Includes_and_Autodocs_2._guide/node036E.html)
to prevent this problem.

A semaphore list is a list header to a list that contains [SignalSemaphore](../Libraries_Manual_guide/node02F7.html)
structures.  The semaphore list must not contain any [public](../Libraries_Manual_guide/node02F9.html) semaphores.
This is because the semaphore list functions use the standard node
structures in the semaphore.

To arbitrate access to a semaphore list use another semaphore.  Create a
[public](../Libraries_Manual_guide/node02F9.html) semaphore and use it to arbitrate access to the list header of the
semaphore list.  This also gives you a locking semaphore, protecting the
[ObtainSemaphoreList()](../Includes_and_Autodocs_2._guide/node0363.html) call.  Once you have gained access to the list with
[ObtainSemaphore()](../Libraries_Manual_guide/node02FA.html), you may obtain all the semaphores on the list via
ObtainSemaphoreList() (or get individual semaphores with
ObtainSemaphore()).  When you are finished with the protected objects,
release the semaphores on the list with [ReleaseSemaphoreList()](../Includes_and_Autodocs_2._guide/node036E.html), and then
release the list semaphore via [ReleaseSemaphore()](../Libraries_Manual_guide/node02FD.html).

For example:


```c
    ObtainSemaphore((struct SignalSemaphore *)SemaphoreList);
    ObtainSemaphoreList(SemaphoreList->sl_List);

    /* At this point the objects are protected, and can be manipulated */

    ReleaseSemaphoreList(SemaphoreList->sl_List);
    ReleaseSemaphore((struct SignalSemaphore *)SemaphoreList);
```
See the [SharedList](../Libraries_Manual_guide/node02F7.html#line37) structure above for an example of a semaphore structure
with a list header.

