# commodities.library/CxMsgData



NAME

```c
    CxMsgData -- obtain a pointer to a commodity message's data area. (V36)
```
SYNOPSIS

```c
    data = CxMsgData(cxm);
                     A0

    UBYTE *CxMsgData(struct CxMsg *);
```
FUNCTION

```c
    Most commodity messages contain meaningful data, such as an [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198)
    structure. This function returns a pointer to this data.

    You may get a commodity message from a synchronous (custom object) or
    asynchronous (sender object) source. In the second case, 'data' is
    not valid after you have replied to the message.
```
INPUTS

    cxm - the commodity message to get the data pointer from
RESULTS

    data - a pointer to the message's data, or NULL if 'cxm' is NULL.
SEE ALSO

```c
    [cx_lib/CxSender()](../Includes_and_Autodocs_2._guide/node014E.html), [cx_lib/CxCustom()](../Includes_and_Autodocs_2._guide/node014B.html)
```
