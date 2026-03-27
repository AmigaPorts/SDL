---
title: graphics.library/CloseMonitor
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-closemonitor
functions: [OpenMonitor]
libraries: [graphics.library]
---

# graphics.library/CloseMonitor

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CloseMonitor -- close a [MonitorSpec](autodocs-2.0/includes-graphics-monitor-h.md) (V36)
```
SYNOPSIS

```c
    error = CloseMonitor( monitor_spec )
      d0                    a0
```
   LONG CloseMonitor( struct [MonitorSpec](autodocs-2.0/includes-graphics-monitor-h.md) * );

FUNCTION

```c
    Relinquish access to a [MonitorSpec](autodocs-2.0/includes-graphics-monitor-h.md).
```
INPUTS

```c
    monitor_spec - a pointer to a [MonitorSpec](autodocs-2.0/includes-graphics-monitor-h.md) opened via [OpenMonitor()](autodocs-2.0/graphics-library-openmonitor.md)
```
RESULTS

```c
    error - FALSE if [MonitorSpec](autodocs-2.0/includes-graphics-monitor-h.md) closed uneventfully.
            TRUE if [MonitorSpec](autodocs-2.0/includes-graphics-monitor-h.md) could not be closed.
```
BUGS

SEE ALSO

```c
    [OpenMonitor()](autodocs-2.0/graphics-library-openmonitor.md)
```

---

## See Also

- [OpenMonitor — graphics.library](../autodocs/graphics.library.md#openmonitor)
