# gadtools.library/GT_ReplyIMsg



NAME

```c
    GT_ReplyIMsg -- Reply a message obtained with [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html). (V36)
```
SYNOPSIS

```c
    GT_ReplyIMsg(imsg)
                 A1

    VOID GT_ReplyIMsg(struct [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) *);
```
FUNCTION

```c
    Reply a modified [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) obtained with [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html).
    If you use [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html), use this function where you would normally
    have used [exec.library/ReplyMsg()](../Includes_and_Autodocs_2._guide/node0379.html).
    You may safely call this routine with a NULL pointer (nothing
    will be done).
```
INPUTS

```c
    imsg - A modified [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) obtained with [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html).
```
RESULT

    None.
EXAMPLE

NOTES

```c
    When using GadTools, you MUST explicitly GT_ReplyIMsg()
    all messages you receive.  You cannot depend on [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html)
    to handle messages you have not replied.
```
BUGS

SEE ALSO

```c
    [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html)
```
