---
title: 25 / / / Making a SignalSemaphore Available to the Public
manual: libraries
chapter: libraries
section: 25-making-a-signalsemaphore-available-to-the-public
functions: [AddPort, AddSemaphore, Forbid, Permit]
libraries: [exec.library]
---

# 25 / / / Making a SignalSemaphore Available to the Public

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A semaphore should be used internally in your program if it has more than
one task operating on shared data structures.  There may also be cases
when you wish to make a data item public to other applications but still
need to restrict its access via semaphores.  In that case, you would give
your semaphore a unique name and add it to the public [SignalSemaphore](libraries/25-semaphore-functions-the-signal-semaphore.md) list
maintained by Exec.  The [AddSemaphore()](autodocs-2.0/exec-library-addsemaphore.md) function does this for you.  This
works in a manner similar to [AddPort()](libraries/24-message-ports-creating-a-message-port.md) for message ports.

To create and initialize a public semaphore for a data item and add it to
the public semaphore list maintained by Exec, the following function
should be used.  (This will prevent the semaphore from being added or
removed more than once by separate programs that use the semaphore).

   UBYTE *name;   /* name of semaphore to add */
   struct SignalSemaphore *semaphore;

   Forbid();
   /* Make sure the semaphore name is unique */
   if (!FindSemaphore(name)) {
```c
       /* Allocate memory for the structure */
       if (sema=(struct SignalSemaphore *)
           AllocMem(sizeof(struct SignalSemaphore),MEMF_PUBLIC|MEMF_CLEAR))
       {
           sema->ss_Link.ln_Pri=0;         /* Set the priority to zero */
           sema->ss_Link.ln_Name=name;
           /* Note that the string 'name' is not copied. If that is    */
           /* needed, allocate memory for it and copy the string. And  */
           /* add the semaphore the the system list                    */
           AddSemaphore(semaphore);
       }
```
   }
   Permit();

A value of NULL for semaphore means that the semaphore already exists or
that there was not enough free memory to create it.

Before using the data item or other resource which is protected by a
semaphore, you must first obtain the semaphore.  Depending on your needs,
you can get either [exclusive](libraries/25-the-signal-semaphore-obtaining-a-signalsemaphore.md) or [shared](libraries/25-the-signal-semaphore-obtaining-a-shared-signalsemaphore.md) access to the semaphore.

---

## See Also

- [AddPort — exec.library](../autodocs/exec.library.md#addport)
- [AddSemaphore — exec.library](../autodocs/exec.library.md#addsemaphore)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
