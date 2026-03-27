# iffparse.library/FindPropContext



NAME

    FindPropContext -- Get the property context for the current state.
SYNOPSIS

```c
    cn = FindPropContext (iff)
    d0                    a0

    struct [ContextNode](../Includes_and_Autodocs_2._guide/node010B.html#line68)        *cn;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34)  *iff;
```
FUNCTION

```c
    Locates the context node which would be the scoping chunk for
    properties in the current parsing state.  (Huh?)  This is used for
    locating the proper scoping context for property chunks i.e. the
    scope from which a property would apply.  This is usually the FORM
    or LIST with the highest precedence in the context stack.

    If you don't understand this, read the IFF spec a couple more times.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
```
RESULT

```c
    cn      - [ContextNode](../Includes_and_Autodocs_2._guide/node010B.html#line68) of property scoping chunk.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CurrentChunk()](../Includes_and_Autodocs_2._guide/node01BE.html), [ParentChunk()](../Includes_and_Autodocs_2._guide/node01D0.html), [StoreItemInContext()](../Includes_and_Autodocs_2._guide/node01DC.html)
```
