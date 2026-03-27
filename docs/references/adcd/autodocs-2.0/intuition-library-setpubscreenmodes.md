---
title: intuition.library/SetPubScreenModes
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-setpubscreenmodes
functions: [OpenScreen]
libraries: [intuition.library]
---

# intuition.library/SetPubScreenModes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetPubScreenModes -- Establish global public screen behavior. (V36)
```
SYNOPSIS

```c
    OldModes = SetPubScreenModes( Modes )
    D0                            D0

    UWORD SetPubScreenModes( UWORD );
```
FUNCTION

    Sets GLOBAL Intuition public screen modes.
INPUTS

```c
    Modes = new global modes flags.  Values for flag bits are:
      SHANGHAI: workbench windows are to be opened on the
            default public screen
      POPPUBSCREEN: when a visitor window is opened, the public
            screen it opens on is to be brought to the front.
```
RESULT

```c
    OldModes = previous global mode settings
```
BUGS

SEE ALSO

```c
    [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md), Intuition V36 update documentation
```

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
