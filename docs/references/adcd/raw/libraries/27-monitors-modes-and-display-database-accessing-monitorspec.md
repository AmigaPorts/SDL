# 27 / / Monitors, Modes and Display Database / Accessing MonitorSpec


The [OpenMonitor()](../Includes_and_Autodocs_2._guide/node0463.html) function will locate and open the requested [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26).
It is called with either the name of the monitor or a ModeID.


```c
    mspc = struct MonitorSpec *OpenMonitor(STRPTR name, ULONG modeID)
```
If the name argument is non-NULL, the [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) is chosen by name.  If
the name argument is NULL, the MonitorSpec is chosen by ModeID.  If both
the name and ModeID arguments are NULL, a pointer to the MonitorSpec for
the default monitor is returned.  [OpenMonitor()](../Includes_and_Autodocs_2._guide/node0463.html) returns either a pointer
to a MonitorSpec structure, or NULL if the requested MonitorSpec could not
be opened.  The [CloseMonitor()](../Includes_and_Autodocs_2._guide/node042F.html) function relinquishes access to a
MonitorSpec previously acquired with OpenMonitor().

To set up a [View](../Libraries_Manual_guide/node032B.html#line51) in Release 2, a [ViewExtra](../Libraries_Manual_guide/node032C.html#line16) structure must also be created
and attached to it.  The ViewExtra.Monitor field must be initialized to
the address of a valid [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) structure before the View is displayed.
Use [OpenMonitor()](../Includes_and_Autodocs_2._guide/node0463.html) to initialize the Monitor field.

