---
title: 32 / The Expansion Sequence / Simple Expansion Library Example
manual: libraries
chapter: libraries
section: 32-the-expansion-sequence-simple-expansion-library-example
functions: []
libraries: []
---

# 32 / The Expansion Sequence / Simple Expansion Library Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following example uses [FindConfigDev()](autodocs-2.0/expansion-library-findconfigdev.md) to print out information about
all of the configured expansion peripherals in the system.
FindConfigDev() searches the system's list of [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md) structures and
returns a pointer to the ConfigDev structure matching a specified board:


```c
    newconfigdev = struct ConfigDev *
                       FindConfigDev( struct ConfigDev *oldconfigdev,
                                      LONG manufacturer, LONG product )
```
The oldconfigdev argument may be set to NULL to begin searching at the top
of the system list or, if it points to a valid [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md), searching will
begin after that entry in the system list.  The manufacturer and product
arguments can be set to search for a specific manufacturer and product by
number, or, if these are set to -1, the function will match any board.


```c
     [findboards.c](libraries/lib-examples-findboards-c.md) 
```
