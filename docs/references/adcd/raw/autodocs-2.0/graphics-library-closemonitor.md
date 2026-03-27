# graphics.library/CloseMonitor



NAME

```c
    CloseMonitor -- close a [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) (V36)
```
SYNOPSIS

```c
    error = CloseMonitor( monitor_spec )
      d0                    a0
```
   LONG CloseMonitor( struct [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) * );

FUNCTION

```c
    Relinquish access to a [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26).
```
INPUTS

```c
    monitor_spec - a pointer to a [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) opened via [OpenMonitor()](../Includes_and_Autodocs_2._guide/node0463.html)
```
RESULTS

```c
    error - FALSE if [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) closed uneventfully.
            TRUE if [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) could not be closed.
```
BUGS

SEE ALSO

```c
    [OpenMonitor()](../Includes_and_Autodocs_2._guide/node0463.html)
```
