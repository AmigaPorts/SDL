# commodities.library/DisposeCxMsg



NAME

```c
    DisposeCxMsg -- delete a commodity message. (V36)
```
SYNOPSIS

```c
    DisposeCxMsg(cxm);
                 A0

    VOID DisposeCxMsg(struct CxMsg *);
```
FUNCTION

    This function eliminates the commodity message pointed to by 'cxm'.
    Can be used to 'swallow' InputEvents by disposing of every commodity
    message of type CXM_IEVENT.
INPUTS

    cxm - the commodity message to delete
