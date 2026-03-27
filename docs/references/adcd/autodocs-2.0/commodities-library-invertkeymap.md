---
title: commodities.library/InvertKeyMap
manual: autodocs-2.0
chapter: autodocs-2.0
section: commodities-library-invertkeymap
functions: [MapANSI]
libraries: [keymap.library]
---

# commodities.library/InvertKeyMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    InvertKeyMap -- generate an input event from an ANSI code. (V36)
```
SYNOPSIS

```c
    success = InvertKeyMap(ansicode,event,km)
                           D0       A0    A1

    BOOL InvertKeyMap(ULONG,struct [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) *,struct [KeyMap](autodocs-2.0/includes-devices-keymap-h.md) *);
```
FUNCTION

```c
    This function uses the system call [MapANSI()](autodocs-2.0/keymap-library-mapansi.md) to figure out what
    [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) translates to an ANSI character code 'ansicode'. The
    [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) pointed to by 'event' is filled in with that information.
    The [KeyMap](autodocs-2.0/includes-devices-keymap-h.md) 'km' is used for the translation, unless it is NULL, in
    which case the system default keymap (as defined when
    commodities.library is initialized) is used.
```
INPUTS

```c
    ansicode - the ANSI code to convert to an input event
    event - the [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) to fill-in
    km - the keymap to use for the translation, or NULL to use the
         system default keymap.
```
RESULTS

    success - TRUE if the translation worked, FALSE otherwise.
BUGS

```c
    This function currently handles one-deep dead keys (such as
    <alt f>o). It does not look up the high key map (keystrokes
    with scan codes greater than 0x40), and misses system changes to
    the default key map.
```
SEE ALSO

```c
    [cx_lib/InvertString()](autodocs-2.0/amiga-lib-invertstring.md)
```

---

## See Also

- [MapANSI — keymap.library](../autodocs/keymap.library.md#mapansi)
