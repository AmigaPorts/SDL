# exec.library/Permit



NAME

    Permit -- permit task rescheduling.
SYNOPSIS

```c
    Permit()

    void Permit(void);
```
FUNCTION

```c
    Allow other tasks to be scheduled to run by the dispatcher, after a
    matching [Forbid()](../Includes_and_Autodocs_2._guide/node0353.html) has been executed.
```
RESULTS

```c
    Other tasks will be rescheduled as they are ready to run. In order
    to restore normal task rescheduling, the programmer must execute
    exactly one call to Permit() for every call to [Forbid()](../Includes_and_Autodocs_2._guide/node0353.html).
```
NOTE

    This call is guaranteed to preserve all registers.
SEE ALSO

    Forbid, Disable, Enable
