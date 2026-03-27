# exec.library/UserState



NAME

    UserState -- return to user state with user stack
SYNOPSIS

```c
    UserState(sysStack)
              D0

    void UserState(APTR);
```
FUNCTION

```c
    Return to user state with user stack, from supervisor state with
    user stack.  This function is normally used in conjunction with the
    [SuperState](../Includes_and_Autodocs_2._guide/node0385.html) function above.

    This function must not be called from the user state.
```
INPUT

    sysStack - supervisor stack pointer
BUGS

    This function is broken in V33/34 Kickstart.  Fixed in V1.31 setpatch.
SEE ALSO

```c
    [SuperState/Supervisor](../Includes_and_Autodocs_2._guide/node0386.html)
```
