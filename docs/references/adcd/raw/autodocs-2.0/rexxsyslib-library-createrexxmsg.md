# rexxsyslib.library/CreateRexxMsg



NAME

    CreateRexxMsg - Create an ARexx message structure
SYNOPSIS

```c
    rexxmsg = CreateRexxMsg(port, extension, host)
    D0,A0                   A0    A1         D0

    struct [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) *CreateRexxMsg(struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *, UBYTE *, UBYTE *);
```
FUNCTION

```c
    This functions allocates an ARexx message packet.  The [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99)
    consists of a standard EXEC message structure extended to include
    the ARexx specific information.
```
INPUTS

    port - A pointer to a public or private message port.  This *MUST*
           be a valid port as this is where the message will be replied.

    extension - A pointer to a NULL terminated string that is to be used
                as the default extension for the REXX scripts.  If this
                is NULL, the default is "REXX"

    host - A pointer to a NULL terminated string that is to be used
           as the default host port.  The name must be the same as the
           name of the public message port that is to be the default host.
           If this field is NULL, the default is REXX.
RESULTS

```c
    rexxmsg - A [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) structure
```
NOTES

```c
    The extension and host strings must remain valid for as long as the
    [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) exists as only the pointer to those strings are stored.
```
SEE ALSO

```c
    [DeleteRexxMsg()](../Includes_and_Autodocs_2._guide/node031C.html), [ClearRexxMsg()](../Includes_and_Autodocs_2._guide/node0318.html), [FillRexxMsg()](../Includes_and_Autodocs_2._guide/node031D.html)
```
BUGS

