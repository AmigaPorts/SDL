# commodities.library/CxMsgType



NAME

```c
    CxMsgType -- obtain the type of a commodity message. (V36)
```
SYNOPSIS

```c
    type = CxMsgType(cxm);
                     A0

    ULONG CxMsgType(struct CxMsg *);
```
FUNCTION

```c
    This function returns the type of a commodity message. Possible values
    of 'type' are defined in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html). Most commodity
    messages are of type CXM_IEVENT.
```
INPUTS

    cxm - the commodity message to inquire about
RESULTS

```c
    type - the type of the commodity message, possible values are defined
           in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html)
```
