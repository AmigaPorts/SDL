# expansion.library/ReleaseConfigBinding



NAME

    ReleaseConfigBinding - allow others to bind to drivers
SYNOPSIS


```c
    ReleaseConfigBinding()
```
FUNCTION

```c
    This call should be used when you are done binding drivers
    to [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) entries.  It releases the SignalSemaphore; this
    allows others to bind their drivers to [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structures.
```
SEE ALSO

```c
    [ObtainConfigBinding()](../Includes_and_Autodocs_2._guide/node03B9.html)
```
