# 25 / Semaphore Functions / The Signal Semaphore


Exec semaphores are signal based. Using signal semaphores is the easiest
way to protect shared, single-access resources in the Amiga.  Your task
will sleep until the semaphore is available for use.  The [SignalSemaphore](../Includes_and_Autodocs_2._guide/node0082.html#line39)
structure is as follows:


```c
    struct SignalSemaphore {
        struct  Node ss_Link;
        SHORT   ss_NestCount;
        struct  MinList ss_WaitQueue;
        struct  SemaphoreRequest ss_MultipleLink;
        struct  Task *ss_Owner;
        SHORT   ss_QueueCount;
    };
```
ss_Link

```c
    is the node structure used to link semaphores together.  The [ln_Pri](../Libraries_Manual_guide/node02D9.html#line34)
    and [ln_Name](../Libraries_Manual_guide/node02D9.html#line38) fields are used to set the priority of the semaphore in a
    list and to name the semaphore for [public](../Libraries_Manual_guide/node02F9.html) access.  If a semaphore is
    not public the ln_Name and ln_Pri fields may be left NULL.
```
ss_NestCount

    is the count of number of locks the current owner has on the
    semaphore.
ss_WaitQueue

```c
    is the [List](../Libraries_Manual_guide/node02DB.html#line23) header for the list of other tasks waiting for this
    semaphore.
```
ss_MultipleLink

```c
    is the [SemaphoreRequest](../Includes_and_Autodocs_2._guide/node0082.html#line33) used by [ObtainSemaphoreList()](../Libraries_Manual_guide/node02FF.html).
```
ss_Owner

    is the pointer to the current owning task.
ss_QueueCount

    is the number of other tasks waiting for the semaphore.
A practical application of a SignalSemaphore would be to use it as the
base of a shared data structure.  For example:


```c
    struct SharedList {
        struct SignalSemaphore sl_Semaphore;
        struct MinList         sl_List;
    };
```
 [Creating a SignalSemaphore Structure](../Libraries_Manual_guide/node02F8.html) 
 [Making a SignalSemaphore Available to the Public](../Libraries_Manual_guide/node02F9.html) 
 [Obtaining a SignalSemaphore Exclusively](../Libraries_Manual_guide/node02FA.html) 
 [Obtaining a Shared SignalSemaphore](../Libraries_Manual_guide/node02FB.html) 
 [Checking a SignalSemaphore](../Libraries_Manual_guide/node02FC.html) 
 [Releasing a SignalSemaphore](../Libraries_Manual_guide/node02FD.html) 
 [Removing a SignalSemaphore Structure](../Libraries_Manual_guide/node02FE.html) 

