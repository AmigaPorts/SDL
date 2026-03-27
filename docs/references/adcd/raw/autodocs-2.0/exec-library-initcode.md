# exec.library/InitCode



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

    Call [InitResident()](../Includes_and_Autodocs_2._guide/node035C.html) for all resident modules in the ResModules array
    with the given startClass and with versions equal or greater than
    that specified.  The segList parameter is passed as zero.

    [Resident](../Includes_and_Autodocs_2._guide/node00A0.html#line19) modules are used by the system to pull all its parts
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
