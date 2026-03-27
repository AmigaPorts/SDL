# intuition.library/EndRequest



NAME

    EndRequest -- Remove a currently active requester.
SYNOPSIS

```c
    EndRequest( [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145), [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) )
                A0         A1

    VOID EndRequest( struct [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) *, struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) * );
```
FUNCTION

    Ends the request by erasing the requester and decoupling it from
    the window.

    Note that this doesn't necessarily clear all requesters from the
    window, only the specified one.  If the window labors under other
    requesters, they will remain in the window.
INPUTS

```c
    [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) = pointer to the requester to be removed
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = pointer to the [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) structure with which this requester
       is associated
```
RESULT

    None
BUGS

SEE ALSO

```c
    [Request()](../Includes_and_Autodocs_2._guide/node0249.html)
```
