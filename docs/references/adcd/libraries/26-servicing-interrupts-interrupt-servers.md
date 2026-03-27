---
title: 26 / Servicing Interrupts / Interrupt Servers
manual: libraries
chapter: libraries
section: 26-servicing-interrupts-interrupt-servers
functions: [AddIntServer, RemIntServer]
libraries: [exec.library]
---

# 26 / Servicing Interrupts / Interrupt Servers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As [mentioned above](libraries/26-exec-interrupts-servicing-interrupts.md), an interrupt server is one of possibly many system
interrupt routines that are invoked as the result of a single 4703
interrupt. Interrupt servers provide an essential mechanism for interrupt
sharing.

Interrupt servers must be used for [PORTS](libraries/26-introduction-sequence-of-events-during-an-interrupt.md), [COPER](libraries/26-introduction-sequence-of-events-during-an-interrupt.md), [VERTB](libraries/26-introduction-sequence-of-events-during-an-interrupt.md), [EXTER](libraries/26-introduction-sequence-of-events-during-an-interrupt.md), or [NMI](libraries/26-introduction-sequence-of-events-during-an-interrupt.md)
interrupts. For these interrupts, all servers are linked together in a
chain. Every server in the chain will be called in turn as long as the
previous server returned with the processor's Z (zero) flag set.  If you
determine that an interrupt was specifically for your server, you should
return with the processor's Z flag cleared (non-zero condition) so that
the remaining servers on the chain will be skipped.


```c
    Use The Z Flag.
    ---------------
    [VERTB](libraries/26-introduction-sequence-of-events-during-an-interrupt.md) (vertical blank) servers should always return with the Z (zero)
    flag set.  The processor Z flag is used rather than the normal
    function convention of returning a result in D0 because it may be
    tested more quickly by Exec upon the server's return.
```
The easiest way to set the condition code register is to do an immediate
move to the D0 register as follows:

   SetZflag_Calls_Next:

           MOVEQ   #0,D0
           RTS
   ClrZflag_Ends_Chain:

           MOVEQ   #1,D0
           RTS
The same Exec [Interrupt](libraries/26-servicing-interrupts-interrupt-data-structure.md) structure used for handlers is also used for
servers.  Also, like interrupt handlers, servers must terminate their code
with an RTS instruction.

Interrupt servers are called in priority order.  The priority of a server
is specified in its [is_Node](libraries/26-servicing-interrupts-interrupt-data-structure.md).[ln_Pri](libraries/23-list-structure-node-structure-definition.md) field. Higher-priority servers are
called earlier than lower-priority servers.  Adding and removing interrupt
servers from a particular chain is accomplished with the Exec
[AddIntServer()](autodocs-2.0/exec-library-addintserver.md) and [RemIntServer()](autodocs-2.0/exec-library-remintserver.md) functions.  These functions require you
to specify both the 4703 interrupt number and a properly initialized
[Interrupt](libraries/26-servicing-interrupts-interrupt-data-structure.md) structure.

Servers have different register values passed than handlers do.  A server
cannot count on the D0, D1, A0, or A6 registers containing any useful
information.  However, the highest priority system vertical blank server
currently expects to receive a pointer to the custom chips A0.  Therefore,
if you install a vertical blank server at priority 10 or greater, you must
place custom ($DFF000) in A0 before exiting.  Other than that, a server is
free to use D0-D1 and A0-A1/A5-A6 as scratch.

 [Interrupt Server Register Usage](libraries/26-interrupt-servers-interrupt-server-register-usage.md) 

---

## See Also

- [AddIntServer — exec.library](../autodocs/exec.library.md#addintserver)
- [RemIntServer — exec.library](../autodocs/exec.library.md#remintserver)
