# intuition.library/SetMouseQueue



NAME

```c
    SetMouseQueue -- Change limit on pending mouse messages. (V36)
```
SYNOPSIS

```c
    oldQueueLength = SetMouseQueue( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797), QueueLength )
    D0                              A0      D0

    LONG SetMouseQueue( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, UWORD );
```
FUNCTION

    Changes the number of mouse messages that Intuition will allow
    to be outstanding for your window.
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = your window
    QueueLength = the new value of outstanding mouse movement messages
      you wish to allow.
```
RESULT

    -1 if 'Window' is not known
    Otherwise the previous value of the queue limit.
    The corresponding function for changing the repeat key
    queue limit is not yet implemented.
BUGS

SEE ALSO

```c
    [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html)
```
