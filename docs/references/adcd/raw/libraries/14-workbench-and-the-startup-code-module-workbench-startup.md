# 14 / Workbench and the Startup Code Module / Workbench Startup


When the user activates a project or tool icon, the program is run as a
separate process asynchronous to Workbench.  This allows the user to take
full advantage of the multitasking features of the Amiga.  A process is
simply a task with additional information needed to use DOS library.

When Workbench loads and starts a program, its sends the program a
[WBStartup](../Libraries_Manual_guide/node023E.html) message containing the arguments as described earlier.  The
WBStartup also contains a pointer to the new [Process](../Libraries_Manual_guide/node0287.html#line51) structure which
describes the execution environment of the program.  The WBStartup message
is posted to the message port of the program's Process structure.

The [Process](../Libraries_Manual_guide/node0287.html#line51) message port is for the exclusive use of DOS, so this message
must be removed from the port before using any DOS library functions.
Normally this is handled by the startup code module that comes with your
compiler so you don't have to worry about this unless you are writing your
own startup code.

Standard startup code modules also set up [SysBase](../Libraries_Manual_guide/node0013.html#line5), the pointer to the Exec
master library, and open the DOS library setting up [DOSBase](../Libraries_Manual_guide/node0290.html#line128).   That is why
Exec and AmigaDOS functions can be called by C applications without first
opening a library; the startup code that applications are linked with
handles this.  Some special startups may also set up NIL: input and output
streams, or may open a stdio window so that the Workbench applications can
use stdio functions such as [printf()](../Includes_and_Autodocs_2._guide/node0162.html).

The startup code can tell if it is running in the Workbench environment
because the [pr_CLI](../Includes_and_Autodocs_2._guide/node0078.html#line53) field of the [Process](../Libraries_Manual_guide/node0287.html#line51) structure will contain NULL.  In
that case the startup code removes the [WBStartup](../Libraries_Manual_guide/node023E.html) message from the Process
message port with [GetMsg()](../Libraries_Manual_guide/node02F2.html) before using any functions in the DOS library.


```c
    Do Not Use the Process Message Port for Anything Else.
    ------------------------------------------------------
    The message port in a [Process](../Libraries_Manual_guide/node0287.html#line51) structure is for the exclusive use
    of the DOS library.
```
Standard startup code will pass the [WBStartup](../Libraries_Manual_guide/node023E.html) message pointer in argv and
0 (zero) in argc if the program is started from Workbench.  These values
are pushed onto the stack, and the startup code calls the application code
that it is linked with as a function.  When the application code exits
back to the startup code, the startup code closes and frees all opens and
allocations it made.  It will then [Forbid()](../Libraries_Manual_guide/node02D0.html#line10), and [ReplyMsg()](../Libraries_Manual_guide/node02F3.html) the WBStartup
message, notifying Workbench that the application [Process](../Libraries_Manual_guide/node0287.html#line51) may be
terminated and its code unloaded from memory.


```c
    Avoid the DOS Exit() function.
    ------------------------------
    The DOS [Exit()](../Includes_and_Autodocs_2._guide/node029F.html) function does not return an application to the
    startup code that called it.  If you wish to exit your application,
    use the exit function provided by your startup code (usually
    lower-case exit(), or _exit for assembler), passing it a valid
    DOS return code as listed in the include file <libraries/[dos.h](../Includes_and_Autodocs_2._guide/node0108.html)>.
```
