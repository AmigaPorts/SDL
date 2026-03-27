# 26 / Servicing Interrupts / Environment


Interrupts execute in an environment different from that of tasks. All
interrupts execute in [supervisor mode](../Libraries_Manual_guide/node02CA.html) and utilize the single system stack.
This stack is large enough to handle extreme cases of nested interrupts
(of higher priorities).  Interrupt processing has no effect on task stack
usage.

All interrupt processing code, both handlers and servers, is invoked as
assembly code subroutines.  Normal assembly code register conventions
dictate that the D0, D1, A0 and A1 registers be free for scratch use.  In
the case of an interrupt handler, some of these registers also contain
data that may be useful to the handler code.  See the section on [handlers](../Libraries_Manual_guide/node0309.html)
below.

Because interrupt processing executes outside the context of most system
activities, certain data structures will not be self-consistent and must
be considered off limits for all practical purposes.  This happens because
certain system operations are not atomic in nature and might be
interrupted only after executing part of an important instruction
sequence.  For example, memory allocation and deallocation routines do not
disable interrupts.  This results in the possibility of interrupting a
memory-related routine.  In such a case, a memory linked list may be
inconsistent during and interrupt. Therefore, interrupt routines must not
use any memory allocation or deallocation functions.

In addition, interrupts may not call any system function which might
allocate memory, wait, manipulate unprotected lists, or modify
[ExecBase](../Includes_and_Autodocs_2._guide/node009E.html#line31)->ThisTask data (for example [Forbid()](../Libraries_Manual_guide/node02C2.html#line9), [Permit()](../Libraries_Manual_guide/node02C2.html#line9), and [mathieee](../Libraries_Manual_guide/node047B.html)
libraries).  In practice, this means that very few system calls may be
used within interrupt code. The following functions may generally be used
safely within interrupts:


```c
    [Alert()](../Includes_and_Autodocs_2._guide/node032E.html), [Disable()](../Libraries_Manual_guide/node02C3.html#line6), [Enable()](../Libraries_Manual_guide/node02C3.html#line6), [Signal()](../Libraries_Manual_guide/node02D5.html), [Cause()](../Libraries_Manual_guide/node030D.html#line9),
    [GetMsg()](../Libraries_Manual_guide/node02F2.html), [PutMsg()](../Libraries_Manual_guide/node02F0.html), [ReplyMsg()](../Libraries_Manual_guide/node02F3.html), [FindPort()](../Libraries_Manual_guide/node02EE.html), [FindTask()](../Libraries_Manual_guide/node02BB.html)
```
and if you are manipulating your own [List](../Libraries_Manual_guide/node02DB.html#line23) structures while in an interrupt:


```c
    [AddHead()](../Libraries_Manual_guide/node02DF.html), [AddTail()](../Libraries_Manual_guide/node02DF.html), [RemHead()](../Libraries_Manual_guide/node02E0.html), [RemTail()](../Libraries_Manual_guide/node02E0.html), [FindName()](../Libraries_Manual_guide/node02E3.html#line5)
```
In addition, certain devices (notably the timer device) specifically allow
limited use of [SendIO()](../Libraries_Manual_guide/node029F.html#line13) and [BeginIO()](../Libraries_Manual_guide/node029F.html#line21) within interrupts.

