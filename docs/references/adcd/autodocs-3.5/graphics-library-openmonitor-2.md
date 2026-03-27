---
title: graphics.library/OpenMonitor
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-openmonitor-2
functions: [CloseMonitor]
libraries: [graphics.library]
---

# graphics.library/OpenMonitor

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       OpenMonitor -- open a named [MonitorSpec](autodocs-3.5/include-graphics-monitor-h.md) (V36)
```
   SYNOPSIS

```c
       mspc = OpenMonitor( monitor_name , display_id)
       d0                  a1		   d0

       struct [MonitorSpec](autodocs-3.5/include-graphics-monitor-h.md) *OpenMonitor( char *, ULONG );
```
   FUNCTION

```c
       Locate and open a named [MonitorSpec](autodocs-3.5/include-graphics-monitor-h.md).
```
   INPUTS

       monitor_name - a pointer to a null terminated string.
       display_id - an optional 32 bit monitor/mode identifier
   RESULTS

```c
       mspc - a pointer to an open [MonitorSpec](autodocs-3.5/include-graphics-monitor-h.md) structure.
              NULL if [MonitorSpec](autodocs-3.5/include-graphics-monitor-h.md) could not  be opened.
```
   NOTE
	if monitor_name is non-NULL, the monitor will be opened by name.
	if monitor_name is NULL the monitor will be opened by optional ID.
	if both monitor_name and display_id are NULL returns default monitor.

   BUGS

   SEE ALSO

```c
       [CloseMonitor()](autodocs-3.5/graphics-library-closemonitor-2.md) [graphics/monitor.h](autodocs-3.5/include-graphics-monitor-h.md)
```

---

## See Also

- [CloseMonitor — graphics.library](../autodocs/graphics.library.md#closemonitor)
