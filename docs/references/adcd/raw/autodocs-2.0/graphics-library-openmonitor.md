# graphics.library/OpenMonitor



NAME

```c
    OpenMonitor -- open a named [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) (V36)
```
SYNOPSIS

```c
    mspc = OpenMonitor( monitor_name , display_id)
     d0                  a1              d0

    struct [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) *OpenMonitor( char *, ULONG );
```
FUNCTION

```c
    Locate and open a named [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26).
```
INPUTS

    monitor_name - a pointer to a null terminated string.
    display_id - an optional 32 bit monitor/mode identifier
RESULTS

```c
    mspc - a pointer to an open [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) structure.
           NULL if [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) could not  be opened.
```
NOTE

    if monitor_name is non-NULL, the monitor will be opened by name.
    if monitor_name is NULL the monitor will be opened by optional ID.
    if both monitor_name and display_id are NULL returns default monitor.
BUGS

SEE ALSO

```c
    [CloseMonitor()](../Includes_and_Autodocs_2._guide/node042F.html) [graphics/monitor.h](../Includes_and_Autodocs_2._guide/node00A7.html)
```
