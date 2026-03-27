# exec.library/AddSemaphore



NAME

    AddSemaphore -- initialize then add a signal semaphore to the system
SYNOPSIS

```c
    AddSemaphore(signalSemaphore)
                 A1

    void AddSemaphore(struct [SignalSemaphore](../Includes_and_Autodocs_2._guide/node0082.html#line40) *);
```
FUNCTION

```c
    This function attaches a signal semaphore structure to the system's
    public signal semaphore list.  The name and priority fields of the
    semaphore structure must be initialized prior to calling this
    function.  If you do not want to let others rendezvous with this
    semaphore, use [InitSemaphore()](../Includes_and_Autodocs_2._guide/node035D.html) instead.

    If a semaphore has been added to the naming list, you must be
    careful to remove the semaphore from the list (via RemSemaphore)
    before deallocating its memory.

    Semaphores that are linked together in an allocation list (which
    [ObtainSemaphoreList()](../Includes_and_Autodocs_2._guide/node0363.html) would use) may not be added to the system
    naming list, because the facilities use the link field of the
    signal semaphore in incompatible ways
```
INPUTS
   signalSemaphore -- an signal semaphore structure

BUGS

```c
    Does not work in Exec <V36.  Instead use this code:

        #include [<exec/execbase.h>](../Includes_and_Autodocs_2._guide/node009E.html)
        #include [<exec/nodes.h>](../Includes_and_Autodocs_2._guide/node0091.html)
        extern struct [ExecBase](../Includes_and_Autodocs_2._guide/node009E.html#line35) *SysBase;
            ...
        void LocalAddSemaphore(s)
        struct [SignalSemaphore](../Includes_and_Autodocs_2._guide/node0082.html#line40) *s;
        {
            s->ss_Link.ln_Type=NT_SIGNALSEM;
            InitSemaphore(s);
            Forbid();
            Enqueue(&SysBase->SemaphoreList,s);
            Permit();
        }
```
SEE ALSO

```c
    [RemSemaphore](../Includes_and_Autodocs_2._guide/node0376.html), [FindSemaphore](../Includes_and_Autodocs_2._guide/node0351.html), [InitSemaphore](../Includes_and_Autodocs_2._guide/node035D.html)
```
