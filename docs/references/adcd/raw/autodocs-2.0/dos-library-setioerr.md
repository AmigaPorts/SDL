# dos.library/SetIoErr



NAME

```c
    SetIoErr -- Sets the value returned by [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) (V36)
```
SYNOPSIS

```c
    oldcode = SetIoErr(code)
    D0                  D1

    LONG SetIoErr(LONG);
```
FUNCTION

```c
    This routine sets up the secondary result (pr_Result2) return code
    (returned by the [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) function).
```
INPUTS

```c
    code - Code to be returned by a call to [IoErr](../Includes_and_Autodocs_2._guide/node02C2.html).
```
RESULT

    oldcode - The previous error code.
SEE ALSO

```c
    [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html), [Fault()](../Includes_and_Autodocs_2._guide/node02A1.html), [PrintFault()](../Includes_and_Autodocs_2._guide/node02DE.html)
```
