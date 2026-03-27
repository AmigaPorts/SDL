---
title: 27 / / Monitors, Modes and Display Database / Accessing MonitorSpec
manual: libraries
chapter: libraries
section: 27-monitors-modes-and-display-database-accessing-monitorspec
functions: [CloseMonitor, OpenMonitor]
libraries: [graphics.library]
---

# 27 / / Monitors, Modes and Display Database / Accessing MonitorSpec

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [OpenMonitor()](autodocs-2.0/graphics-library-openmonitor.md) function will locate and open the requested [MonitorSpec](autodocs-2.0/includes-graphics-monitor-h.md).
It is called with either the name of the monitor or a ModeID.


```c
    mspc = struct MonitorSpec *OpenMonitor(STRPTR name, ULONG modeID)
```
If the name argument is non-NULL, the [MonitorSpec](autodocs-2.0/includes-graphics-monitor-h.md) is chosen by name.  If
the name argument is NULL, the MonitorSpec is chosen by ModeID.  If both
the name and ModeID arguments are NULL, a pointer to the MonitorSpec for
the default monitor is returned.  [OpenMonitor()](autodocs-2.0/graphics-library-openmonitor.md) returns either a pointer
to a MonitorSpec structure, or NULL if the requested MonitorSpec could not
be opened.  The [CloseMonitor()](autodocs-2.0/graphics-library-closemonitor.md) function relinquishes access to a
MonitorSpec previously acquired with OpenMonitor().

To set up a [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) in Release 2, a [ViewExtra](libraries/27-display-routines-and-structures-forming-a-basic-display.md) structure must also be created
and attached to it.  The ViewExtra.Monitor field must be initialized to
the address of a valid [MonitorSpec](autodocs-2.0/includes-graphics-monitor-h.md) structure before the View is displayed.
Use [OpenMonitor()](autodocs-2.0/graphics-library-openmonitor.md) to initialize the Monitor field.

---

## See Also

- [CloseMonitor — graphics.library](../autodocs/graphics.library.md#closemonitor)
- [OpenMonitor — graphics.library](../autodocs/graphics.library.md#openmonitor)
