# commodities.library/CxMsgID



NAME

```c
    CxMsgID -- obtain the ID of a commodity message. (V36)
```
SYNOPSIS

```c
    id = CxMsgID(cxm);
                 A0

    LONG CxMsgID(struct CxMsg *);
```
FUNCTION

    This function returns the value associated with the cause or source
    of the commodity message 'cxm'. Values are provided by the application
    when a sender or custom object is created.
INPUTS

    cxm - the commodity message to inquire about
RESULTS

    id - if not specified by the application, the ID value of a
        commodity message will be 0. It is suggested that using
         non-zero values in your program as a rule may identify some
         possible errors.
SEE ALSO

```c
    [cx_lib/CxSender()](../Includes_and_Autodocs_2._guide/node014E.html), [cx_lib/CxCustom()](../Includes_and_Autodocs_2._guide/node014B.html)
```
