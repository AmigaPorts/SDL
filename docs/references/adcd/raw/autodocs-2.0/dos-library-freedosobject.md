# dos.library/FreeDosObject



NAME

```c
    FreeDosObject -- Frees an object allocated by [AllocDosObject()](../Includes_and_Autodocs_2._guide/node027F.html) (V36)
```
SYNOPSIS

```c
    FreeDosObject(type, ptr)
                   D1   D2

    void FreeDosObject(ULONG, void *)
```
FUNCTION

```c
    Frees an object allocated by [AllocDosObject()](../Includes_and_Autodocs_2._guide/node027F.html).  Do NOT call for
    objects allocated in any other way.
```
INPUTS

```c
    type - type passed to [AllocDosObject()](../Includes_and_Autodocs_2._guide/node027F.html)
    ptr  - ptr returned by [AllocDosObject()](../Includes_and_Autodocs_2._guide/node027F.html)
```
SEE ALSO

```c
    [AllocDosObject()](../Includes_and_Autodocs_2._guide/node027F.html), [<dos/dos.h>](../Includes_and_Autodocs_2._guide/node0068.html)
```
