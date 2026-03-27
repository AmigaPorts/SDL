# D / Errors / DOS-related Problems


In general, any dos.library function which fills in a structure for you
(for example, [Examine()](../Includes_and_Autodocs_2._guide/node029C.html)), requires that the structure be longword aligned.
In most cases, the only way to insure longword alignment in C is to
dynamically allocate the structure.  Unless documented otherwise,
dos.library functions may only be called from a process, not from a task.
Also note that a process's [pr_MsgPort](../Includes_and_Autodocs_2._guide/node0078.html#line38) is intended for the exclusive use of
dos.library.  (The port may be used to receive a [WBStartup](../Libraries_Manual_guide/node023E.html#line5) message as long
as the message is [GetMsg()](../Libraries_Manual_guide/node02F2.html)'d from the port before DOS is used.

