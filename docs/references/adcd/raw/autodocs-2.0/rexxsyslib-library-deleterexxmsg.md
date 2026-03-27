# rexxsyslib.library/DeleteRexxMsg



NAME

```c
    DeleteRexxMsg - Releases a [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) structure created by [CreateRexxMsg()](../Includes_and_Autodocs_2._guide/node031A.html)
```
SYNOPSIS

```c
    DeleteRexxMsg(packet)
                  A0

    VOID DeleteRexxMsg(struct [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) *);
```
FUNCTION

```c
    The function releases an ARexx message packet that was allocated
    with [CreateRexxMsg()](../Includes_and_Autodocs_2._guide/node031A.html).  Any argument fields in the [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) structure
    should be cleared before calling this function as it does
    not release them for you.
```
INPUTS

```c
    packet - A pointer to a [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) structure allocated by [CreateRexxMsg()](../Includes_and_Autodocs_2._guide/node031A.html)
```
EXAMPLE

```c
    if (rmsg=CreateRexxMsg(myport,"myapp","MYAPP_PORT"))
    {
            /* Do my think with rmsg */
            ClearRexxMsg(rmsg,16);  /* We may not want to clear all 16 */
            DeleteRexxMsg(rmsg);
    }
```
SEE ALSO

```c
    [CreateRexxMsg()](../Includes_and_Autodocs_2._guide/node031A.html), [ClearRexxMsg()](../Includes_and_Autodocs_2._guide/node0318.html)
```
BUGS

