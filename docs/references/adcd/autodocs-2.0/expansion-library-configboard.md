---
title: expansion.library/ConfigBoard
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-configboard
functions: []
libraries: []
---

# expansion.library/ConfigBoard

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ConfigBoard - configure a board
SYNOPSIS

```c
    error = ConfigBoard( board, configDev )
    D0                   A0     A1
```
FUNCTION

```c
    This routine configures an expansion board.  The board
    will generally live at E_EXPANSIONBASE, but the base is
    passed as a parameter to allow future compatibility.
    The configDev parameter must be a valid configDev that
    has already had [ReadExpansionRom()](autodocs-2.0/expansion-library-readexpansionrom.md) called on it.

    ConfigBoard will allocate expansion memory and place
    the board at its new address.  It will update configDev
    accordingly.  If there is not enough expansion memory
    for this board then an error will be returned.
```
INPUTS

```c
    board - the current address that the expansion board is
            responding.
    configDev - an initialized [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structure, returned
            by [AllocConfigDev](autodocs-2.0/expansion-library-allocconfigdev.md).
```
RESULTS

```c
    error - non-zero if there was a problem configuring this board
            (Can return EE_OK or EE_NOEXPANSION)
```
SEE ALSO

```c
    [FreeConfigDev](autodocs-2.0/expansion-library-freeconfigdev.md)
```
