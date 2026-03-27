/* Source: ADCD 2.1
 * Section: exec-library-addsemaphore
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-addsemaphore.md
 */

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
