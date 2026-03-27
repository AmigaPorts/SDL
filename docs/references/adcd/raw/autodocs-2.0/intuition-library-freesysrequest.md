# intuition.library/FreeSysRequest



NAME

```c
    FreeSysRequest -- Free resources gotten by a call to [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html).
```
SYNOPSIS

```c
    FreeSysRequest( [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) )
                    A0

    VOID FreeSysRequest( struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) * );
```
FUNCTION

```c
    This routine frees up all memory allocated by a successful call to
    the [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html) procedure.  If [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html) returned a
    pointer to a window, then you are able to wait on the message port
    of that window to detect an event which satisfies the requester.
    When you want to remove the requester, you call this procedure.  It
    ends the requester and deallocates any memory used in the creation
    of the requester.  It also closes the special window that was opened
    for your system requester.

    For V36: It's OK if you pass a NULL or a TRUE (1) value to
    this function.  Also, this function properly disposes of
    requesters gotten using BuildEasyRequest().
```
INPUTS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = value of the window pointer returned by a successful call to
       the [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html) procedure
```
RESULT

    None
BUGS

SEE ALSO

```c
    [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html), [AutoRequest()](../Includes_and_Autodocs_2._guide/node01FF.html), [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html)
```
