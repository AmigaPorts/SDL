# intuition.library/InitRequester



NAME

```c
    InitRequester -- Initialize a [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) structure.
```
SYNOPSIS

```c
    InitRequester( [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) )
                   A0

    VOID InitRequester( struct [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) * );
```
FUNCTION

```c
    Initializes a requester for general use.  After calling InitRequester,
    you need fill in only those [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) values that fit your needs.
    The other values are set to NULL--or zero--states.

    Note that the example in the early versions of the Intuition
    Reference Manual is flawed because the [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) structure is
    initialized BEFORE InitRequester is called.  Be sure to
    perform your initialization AFTER calling InitRequester.
```
INPUTS

```c
    [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) = a pointer to a [Requester](../Includes_and_Autodocs_2._guide/node00D4.html#line145) structure
```
RESULT

    None
BUGS

    Since the publication of the first Intuition Manual to this
    day, most people haven't used this function, and for
    compatibility reasons, we'll never be able to assume that
    they do.  Thus, this function is useless.
SEE ALSO

