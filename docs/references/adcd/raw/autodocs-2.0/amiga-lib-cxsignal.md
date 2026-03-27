# amiga.lib/CxSignal



NAME

```c
    CxSignal -- create a commodity signaller object. (V36)
```
SYNOPSIS

```c
    signalerObj = CxSignal(task,signal);

    CxObj *CxSignal(struct [Task](../Includes_and_Autodocs_2._guide/node008E.html#line25) *,LONG);
```
FUNCTION

```c
    This function creates a Commodities signal object. The action
    of this object on receiving a Commodities message is to
    send the 'signal' to the 'task'. The caller is responsible
    for allocating the signal and determining the proper task ID.

    Note that 'signal' is the signal value as returned by [AllocSignal()](../Includes_and_Autodocs_2._guide/node0333.html),
    not the mask made from that value.

    This function is a C-language macro for [CreateCxObj()](../Includes_and_Autodocs_2._guide/node01A1.html), defined
    in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html).
```
INPUTS

    task - the task for the signaller to signal
    signal - the signal bit number for the signaller to send
RESULTS

    signallerObj - a pointer to the signaller object, or NULL if it could
                   not be created.
SEE ALSO

```c
    [commodities.library/CreateCxObj()](../Includes_and_Autodocs_2._guide/node01A1.html), [exec.library/FindTask()](../Includes_and_Autodocs_2._guide/node0352.html)
    [exec.library/Signal()](../Includes_and_Autodocs_2._guide/node0381.html), [exec.library/AllocSignal()](../Includes_and_Autodocs_2._guide/node0333.html),
```
