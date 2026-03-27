# commodities.library/AddIEvents



NAME

```c
    AddIEvents -- add input events to commodities' input stream. (V36)
```
SYNOPSIS

```c
    AddIEvents(events)
               A0

    VOID AddIEvents(struct [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) *);
```
FUNCTION

```c
    This function adds a null-terminated linked list of input events to
    the input stream of commodities. It is a touch easier than using the
    input device directly.

    The contents of the input events are copied into commodity
    messages, so they may be disposed of as soon as this call returns.

    The messages are initially routed to the first broker in the
    Commodities Object [List](../Includes_and_Autodocs_2._guide/node007D.html#line21).
```
INPUTS

    events - the list of input events to add
SEE ALSO

```c
    [cx_lib/FreeIEvents()](../Includes_and_Autodocs_2._guide/node015C.html)
```
