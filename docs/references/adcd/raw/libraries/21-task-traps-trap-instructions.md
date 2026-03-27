# 21 / Task Traps / Trap Instructions


The TRAP instructions in the 68000 generate traps 32-47.  Because many
independent pieces of system code may desire to use these traps, the
[AllocTrap()](../Includes_and_Autodocs_2._guide/node0334.html) and [FreeTrap()](../Includes_and_Autodocs_2._guide/node0357.html) functions are provided.  These work in a
fashion similar to that used by [AllocSignal()](../Libraries_Manual_guide/node02D3.html#line5) and [FreeSignal()](../Libraries_Manual_guide/node02D3.html#line5), mentioned
in the "[Exec Signals](../Libraries_Manual_guide/node02D3.html)" chapter.

Allocating a trap is simply a bookkeeping job within a task.  It does not
affect how the system calls the trap handler; it helps coordinate who owns
what traps.  Exec does nothing to determine whether or not a task is
prepared to handle a particular trap.  It simply calls your code. It is up
to your program to handle the trap.

To allocate any trap, you can use the following code:


```c
    if (-1 == (trap = AllocTrap(-1)))
        printf("all trap instructions are in use\n");
```
Or you can select a specific trap using this code:


```c
    if (-1 == (trap = AllocTrap(3)))
        printf("trap #3 is in use\n");
```
To free a trap, you use the [FreeTrap()](../Includes_and_Autodocs_2._guide/node0357.html) function passing it the trap number
to be freed.

