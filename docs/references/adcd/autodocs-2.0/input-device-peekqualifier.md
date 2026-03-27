---
title: input.device/PeekQualifier
manual: autodocs-2.0
chapter: autodocs-2.0
section: input-device-peekqualifier
functions: [PeekQualifier]
libraries: [input.device]
---

# input.device/PeekQualifier

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    PeekQualifier -- get the input device's current qualifiers (V36)
```
SYNOPSIS

```c
    qualifier = PeekQualifier()
    d0

    UWORD PeekQualifier( VOID );
```
FUNCTION

    This function takes a snapshot of what the input device thinks
    the current qualifiers are.
RESULTS

    qualifier - a word with the following bits set according to
        what the input device knows their state to be:
            IEQUALIFIER_LSHIFT, IEQUALIFIER_RSHIFT,
            IEQUALIFIER_CAPSLOCK, IEQUALIFIER_CONTROL,
            IEQUALIFIER_LALT, IEQUALIFIER_RALT,
            IEQUALIFIER_LCOMMAND, IEQUALIFIER_RCOMMAND,
            IEQUALIFIER_LEFTBUTTON, IEQUALIFIER_RBUTTON,
            IEQUALIFIER_MIDBUTTON
NOTE

    This function is new for V36.
SEE ALSO

```c
    [devices/inputevent.h](autodocs-2.0/includes-devices-inputevent-h.md)
```

---

## See Also

- [PeekQualifier — input.device](../autodocs/input.device.md#peekqualifier)
