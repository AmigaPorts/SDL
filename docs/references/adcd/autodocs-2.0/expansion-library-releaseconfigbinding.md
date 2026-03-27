---
title: expansion.library/ReleaseConfigBinding
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-releaseconfigbinding
functions: []
libraries: []
---

# expansion.library/ReleaseConfigBinding

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ReleaseConfigBinding - allow others to bind to drivers
SYNOPSIS


```c
    ReleaseConfigBinding()
```
FUNCTION

```c
    This call should be used when you are done binding drivers
    to [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) entries.  It releases the SignalSemaphore; this
    allows others to bind their drivers to [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structures.
```
SEE ALSO

```c
    [ObtainConfigBinding()](autodocs-2.0/expansion-library-obtainconfigbinding.md)
```
