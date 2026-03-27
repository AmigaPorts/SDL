# 26 / Servicing Interrupts / Interrupt Servers


As [mentioned above](../Libraries_Manual_guide/node0306.html), an interrupt server is one of possibly many system
interrupt routines that are invoked as the result of a single 4703
interrupt. Interrupt servers provide an essential mechanism for interrupt
sharing.

Interrupt servers must be used for [PORTS](../Libraries_Manual_guide/node0303.html#line79), [COPER](../Libraries_Manual_guide/node0303.html#line81), [VERTB](../Libraries_Manual_guide/node0303.html#line81), [EXTER](../Libraries_Manual_guide/node0303.html#line99), or [NMI](../Libraries_Manual_guide/node0303.html#line103)
interrupts. For these interrupts, all servers are linked together in a
chain. Every server in the chain will be called in turn as long as the
previous server returned with the processor's Z (zero) flag set.  If you
determine that an interrupt was specifically for your server, you should
return with the processor's Z flag cleared (non-zero condition) so that
the remaining servers on the chain will be skipped.


```c
    Use The Z Flag.
    ---------------
    [VERTB](../Libraries_Manual_guide/node0303.html#line81) (vertical blank) servers should always return with the Z (zero)
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
The same Exec [Interrupt](../Libraries_Manual_guide/node0307.html) structure used for handlers is also used for
servers.  Also, like interrupt handlers, servers must terminate their code
with an RTS instruction.

Interrupt servers are called in priority order.  The priority of a server
is specified in its [is_Node](../Libraries_Manual_guide/node0307.html).[ln_Pri](../Libraries_Manual_guide/node02D9.html#line34) field. Higher-priority servers are
called earlier than lower-priority servers.  Adding and removing interrupt
servers from a particular chain is accomplished with the Exec
[AddIntServer()](../Includes_and_Autodocs_2._guide/node0326.html) and [RemIntServer()](../Includes_and_Autodocs_2._guide/node0371.html) functions.  These functions require you
to specify both the 4703 interrupt number and a properly initialized
[Interrupt](../Libraries_Manual_guide/node0307.html) structure.

Servers have different register values passed than handlers do.  A server
cannot count on the D0, D1, A0, or A6 registers containing any useful
information.  However, the highest priority system vertical blank server
currently expects to receive a pointer to the custom chips A0.  Therefore,
if you install a vertical blank server at priority 10 or greater, you must
place custom ($DFF000) in A0 before exiting.  Other than that, a server is
free to use D0-D1 and A0-A1/A5-A6 as scratch.

 [Interrupt Server Register Usage](../Libraries_Manual_guide/node030C.html) 

