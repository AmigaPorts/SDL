# commodities.library/RouteCxMsg



NAME

```c
    RouteCxMsg -- set the next destination of a commodity message. (V36)
```
SYNOPSIS

```c
    RouteCxMsg(cxm,co);
               A0  A1

    VOID RouteCxMsg(struct CxMsg *,CxObj *);
```
FUNCTION

```c
    Establishes the next destination of a commodity message
    to be 'co', which must be a valid commodity object, and
    must be linked in ultimately to the Commodities Object [List](../Includes_and_Autodocs_2._guide/node007D.html#line21).

    Routing of an object is analogous to a 'goto' in a program.
    There is no effect on the message's routing stack.
```
INPUTS

    cxm - the commodity message to route
    co - the commodity object to route the message to
SEE ALSO

```c
    [DivertCxMsg()](../Includes_and_Autodocs_2._guide/node01AB.html)
```
