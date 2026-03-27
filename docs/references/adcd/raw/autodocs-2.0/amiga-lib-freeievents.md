# amiga.lib/FreeIEvents



NAME

```c
    FreeIEvents -- free a chain of input events allocated by
                   [InvertString()](../Includes_and_Autodocs_2._guide/node0160.html). (V36)
```
SYNOPSIS

```c
    FreeIEvents(events)

    VOID FreeIEvents(struct [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) *);
```
FUNCTION

```c
    This function frees a linked list of input events as obtained from
    [InvertString()](../Includes_and_Autodocs_2._guide/node0160.html).
```
INPUTS
   events - the list of input events to free, may be NULL.

SEE ALSO

```c
    [InvertString()](../Includes_and_Autodocs_2._guide/node0160.html)
```
