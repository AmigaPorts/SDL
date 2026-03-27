# exec.library/Enable



NAME

    Enable -- permit system interrupts to resume.
SYNOPSIS

```c
    Enable();

    void Enable(void);
```
FUNCTION

```c
    Allow system interrupts to again occur normally, after a matching
    [Disable()](../Includes_and_Autodocs_2._guide/node034A.html) has been executed.
```
RESULTS

```c
    [Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23) processing is restored to normal operation. The
    programmer must execute exactly one call to Enable() for every call
    to [Disable()](../Includes_and_Autodocs_2._guide/node034A.html).
```
NOTE

    This call is guaranteed to preserve all registers.
SEE ALSO

    Forbid, Permit, Disable
