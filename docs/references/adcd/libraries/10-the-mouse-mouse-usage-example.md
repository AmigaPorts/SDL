---
title: 10 / The Mouse / Mouse Usage Example
manual: libraries
chapter: libraries
section: 10-the-mouse-mouse-usage-example
functions: [DoubleClick]
libraries: [intuition.library]
---

# 10 / The Mouse / Mouse Usage Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The example program below shows the use of [IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md),
[IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md) and [DoubleClick()](autodocs-2.0/intuition-library-doubleclick.md).  DoubleClick() is used to test the
interval between two times and determine if the interval is within the
user specified time for double clicking as set in the Preferences Input
editor.


```c
    BOOL DoubleClick( unsigned long sSeconds, unsigned long sMicros,
                      unsigned long cSeconds, unsigned long cMicros );
```
The sSeconds and sMicros arguments specify a timestamp value describing
the start of the double click time interval to be tested.  The cSeconds
and cMicros arguments specify a timestamp value describing the end of the
double click time interval to be tested.

[DoubleClick()](autodocs-2.0/intuition-library-doubleclick.md) returns TRUE if the time interval was short enough to
qualify as a double-click.  A FALSE return indicates that the time
interval between presses took too long.  The button presses should be
treated as separate events in that case.


```c
     [mousetest.c](libraries/lib-examples-mousetest-c.md) 
```

---

## See Also

- [DoubleClick — intuition.library](../autodocs/intuition.library.md#doubleclick)
