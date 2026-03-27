---
title: graphics.library/CloseMonitor
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-closemonitor-2
functions: [OpenMonitor]
libraries: [graphics.library]
---

# graphics.library/CloseMonitor

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CloseMonitor -- close a [MonitorSpec](autodocs-3.5/include-graphics-monitor-h.md) (V36)

   SYNOPSIS
	error = CloseMonitor( monitor_spec )
	d0                    a0

	[LONG](autodocs-3.5/include-exec-types-h.md) CloseMonitor( struct [MonitorSpec](autodocs-3.5/include-graphics-monitor-h.md) * );

   FUNCTION
	Relinquish access to a [MonitorSpec](autodocs-3.5/include-graphics-monitor-h.md).

   INPUTS
	monitor_spec - a pointer to a [MonitorSpec](autodocs-3.5/include-graphics-monitor-h.md) opened via [OpenMonitor()](autodocs-3.5/graphics-library-openmonitor-2.md),
	or NULL.

   RESULTS
	error - FALSE if [MonitorSpec](autodocs-3.5/include-graphics-monitor-h.md) closed uneventfully.
	        TRUE if [MonitorSpec](autodocs-3.5/include-graphics-monitor-h.md) could not be closed.

   BUGS

   SEE ALSO
	[OpenMonitor()](autodocs-3.5/graphics-library-openmonitor-2.md)

---

## See Also

- [OpenMonitor — graphics.library](../autodocs/graphics.library.md#openmonitor)
