---
title: amiga.lib/InvertString
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-invertstring
functions: [ParseIX]
libraries: [commodities.library]
---

# amiga.lib/InvertString

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    InvertString -- produce input events that would generate the
                    given string. (V36)
```
SYNOPSIS

```c
    events = InvertString(str,km)

    struct [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) *InvertString(STRPTR,struct [KeyMap](autodocs-2.0/includes-devices-keymap-h.md) *);
```
FUNCTION

```c
    This function returns a linked list of input events which would
    translate into the string using the supplied keymap (or the system
    default keymap if 'km' is NULL).

    'str' is null-terminated and may contain:
       - ANSI character codes
       - backslash escaped characters:
            n   -   CR
            r   -   CR
            t   -   TAB
            0   -   illegal, do not use!
            \   -   backslash
       - a text description of an input event as used by [ParseIX()](autodocs-2.0/commodities-library-parseix.md),
         enclosed in angle brackets.

    An example is:

      abc<alt f1>nhi there.
```
INPUTS

    str - null-terminated string to convert to input events
    km - keymap to use for the conversion, or NULL to use the default
         keymap.
RESULTS

```c
    events - a chain of input events, or NULL if there was a problem. The
             most likely cause of failure is an illegal description
             enclosed in angled brackets.

             This chain should eventually be freed using [FreeIEvents()](autodocs-2.0/amiga-lib-freeievents.md).
```
SEE ALSO

```c
    [commodities.library/ParseIX()](autodocs-2.0/commodities-library-parseix.md), [FreeIEvents()](autodocs-2.0/amiga-lib-freeievents.md)
```

---

## See Also

- [ParseIX — commodities.library](../autodocs/commodities.library.md#parseix)
