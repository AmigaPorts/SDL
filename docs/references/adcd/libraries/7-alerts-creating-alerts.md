---
title: 7 / Alerts / Creating Alerts
manual: libraries
chapter: libraries
section: 7-alerts-creating-alerts
functions: [DisplayAlert]
libraries: [intuition.library]
---

# 7 / Alerts / Creating Alerts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The function [DisplayAlert()](autodocs-2.0/intuition-library-displayalert.md) creates and displays an alert message.  The
message will almost always be displayed regardless of the state of the
machine (with the exception of catastrophic hardware failures).  If the
user presses one of the mouse buttons, the display is restored to its
original state, if possible.  If a recoverable alert cannot be displayed
(because memory is low), DisplayAlert() will return FALSE, as if the user
had selected cancel.  DisplayAlert() is also used by the system to display
the Amiga system alert messages.


```c
    BOOL DisplayAlert( unsigned long alertNumber, UBYTE *string,
                       unsigned long height );
```
The alertNumber argument is a LONG value, specifying whether this is a
[RECOVERY_ALERT](libraries/7-alerts-types-of-alerts.md) or a [DEADEND_ALERT](libraries/7-alerts-types-of-alerts.md) (see the <intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)> include
file).

The string argument points to a string that is made up of one or more
substrings.  Each substring contains the following:

  * The first component is a 16 bit x-coordinate and an 8 bit

    y-coordinate describing where to position the substring within the
    alert display.  The units are in pixels.  The y-coordinate describes
    the location of the text baseline.
  * The second component is the text itself.  The substring must be NULL

```c
    terminated (it ends with a zero byte).
```
  * The last component is the continuation byte.  If this byte is zero,

    this is the last substring in the message.  If this byte is non-zero,
    there is another substring in this alert message.
The complete string must be terminated by two NULL characters; one as the
end of the last substring, and one as a NULL continuation byte, indicating
that this was the last substring. The height argument is the number of
display lines required for the alert.

---

## See Also

- [DisplayAlert — intuition.library](../autodocs/intuition.library.md#displayalert)
