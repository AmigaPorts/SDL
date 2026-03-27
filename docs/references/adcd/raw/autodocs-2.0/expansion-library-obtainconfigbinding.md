# expansion.library/ObtainConfigBinding



NAME

    ObtainConfigBinding - try to get permission to bind drivers
SYNOPSIS


```c
    ObtainConfigBinding()
```
FUNCTION

```c
    ObtainConfigBinding gives permission to bind drivers to
    [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structures.  It exists so two drivers at once
    do not try and own the same [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structure.  This
    call will block until it is safe proceed.

    It is crucially important that people lock out others
    before loading new drivers.  Much of the data that is used
    to configure things is statically kept, and others need
    to be kept from using it.

    This call is built directly on Exec [SignalSemaphore](../Includes_and_Autodocs_2._guide/node0082.html#line40) code
    (e.g. ObtainSemaphore).
```
INPUTS

RESULTS

EXCEPTIONS

SEE ALSO

```c
    [ReleaseConfigBinding()](../Includes_and_Autodocs_2._guide/node03BC.html)
```
BUGS

