---
title: exec.library/InitCode
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-initcode
functions: [InitResident]
libraries: [exec.library]
---

# exec.library/InitCode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    InitCode - initialize resident code modules (internal function)
```
SYNOPSIS

```c
    InitCode(startClass, version)
             D0          D1

    void InitCode(ULONG,ULONG);
```
FUNCTION

```c
    (This function may be ignored by application programmers)

    Call [InitResident()](autodocs-2.0/exec-library-initresident.md) for all resident modules in the ResModules array
    with the given startClass and with versions equal or greater than
    that specified.  The segList parameter is passed as zero.

    [Resident](autodocs-2.0/includes-exec-resident-h.md) modules are used by the system to pull all its parts
    together at startup.  Modules are initialized in a prioritized order.

    Modules that do not have a startclass should be of priority -120.
    RTF_AFTERDOS modues should start at -100 (working down).
```
INPUTS

```c
    startClass - the class of code to be initialized:
            BITDEF RT,COLDSTART,0
            BITDEF RT,SINGLETASK,1  ;ExecBase->ThisTask==0 (V36 only)
            BITDEF RT,AFTERDOS,2    ;(V36 only)
    version - a major version number
```
SEE ALSO

```c
    ResidentTag (RT) structure definition (resident.h)
```

---

## See Also

- [InitResident — exec.library](../autodocs/exec.library.md#initresident)
