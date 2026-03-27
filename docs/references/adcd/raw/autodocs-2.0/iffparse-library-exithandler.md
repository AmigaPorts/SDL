# iffparse.library/ExitHandler



NAME

```c
    ExitHandler -- Add an exit handler to the [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) context.
```
SYNOPSIS

```c
    error = ExitHandler (iff, type, id, position, hook, object)
     d0                  a0    d0   d1    d2       a1     a2

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    LONG             type, id, position;
    struct [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23)     *hook;
    APTR             object;
```
FUNCTION

```c
    Installs an exit handler vector for a specific type of chunk into the
    context for the given [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.  Type and id are the longword
    identifiers for the chunk to handle.  The hook is a client-supplied
    standard 2.0 [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) structure, properly initialized.  Position tells
    where to put the handler in the context.  The handler will be called
    just before the parser exits the given chunk in the "pause" parse
    state.  The IFF stream may not be positioned predictably within the
    chunk.  The handler will execute in the same context as whoever
    called [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html).  The handler will be called (through the hook)
    with the following arguments:

            A0:     the [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) pointer you passed.
            A2:     the 'object' pointer you passed.
            A1:     pointer to a LONG containing the value
                    IFFCMD_EXIT.

    The error code your call-back routine returns will affect the parser
    in three different ways:

    Return value            Result
    ------------            ------
    0:                      Normal success;  [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) will continue
                            through the file.
    IFF_RETURN2CLIENT:      [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) will stop and return the value 0.
                            (StopChunk() is internally implemented using
                            this return value.)
    Any other value:        [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) will stop and return the value
                            you supplied.  This is how errors should be
                            returned.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
    type    - type code for chunk to handle (ex. "ILBM").
    id      - identifier code for chunk to handle (ex. "CMAP").
    position- local context item position.  One of the IFFSLI_#? codes.
    hook    - pointer to [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) structure.
    object  - a client-defined pointer which is passed in A2 during call-
              back.
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

    Returning the values IFFERR_EOF or IFFERR_EOC from the call-back
    routine *may* confuse the parser.

    There is no way to explicitly remove a handler once installed.
    However, by installing a do-nothing handler using IFFSLI_TOP,
    previous handlers will be overridden until the context expires.
SEE ALSO

```c
    [EntryHandler()](../Includes_and_Autodocs_2._guide/node01BF.html), [StoreLocalItem()](../Includes_and_Autodocs_2._guide/node01DD.html), [StoreItemInContext()](../Includes_and_Autodocs_2._guide/node01DC.html),
    [utility/hooks.h](../Includes_and_Autodocs_2._guide/node012D.html)
```
