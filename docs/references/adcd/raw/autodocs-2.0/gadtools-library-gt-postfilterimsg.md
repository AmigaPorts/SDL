# gadtools.library/GT_PostFilterIMsg



NAME

```c
    GT_PostFilterIMsg -- Return the unfiltered message after
        [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html) was called, and clean up. (V36)
```
SYNOPSIS

```c
    imsg = GT_PostFilterIMsg(modimsg)
    D0                       A1

    struct [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) *GT_PostFilterIMsg(struct [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) *);
```
FUNCTION

```c
    NOTE WELL:  Extremely few programs will actually need this function.
    You almost certainly should be using [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html) and [GT_ReplyIMsg()](../Includes_and_Autodocs_2._guide/node03F5.html)
    only, and not [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html) and GT_PostFilterIMsg().

    Performs any clean-up necessitated by a previous call to
    [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html).  The original [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) is now yours to handle.
    Do not interpret the fields of the original [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679), but
    rather use only the one you got from [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html).  You
    may only do message related things at this point, such as queueing
    it up or replying it.  Since you got the message with
    [exec.library/GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html), your responsibilities do include replying
    it with [exec.library/ReplyMsg()](../Includes_and_Autodocs_2._guide/node0379.html). This function may be safely
    called with a NULL parameter.
```
INPUTS

```c
    modimsg - A modified [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) obtained with [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html).
```
RESULT

```c
    imsg - A pointer to the original [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679), if [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html)
        returned non-NULL.
```
EXAMPLE

NOTES

```c
    Be sure to use [exec.library/ReplyMsg()](../Includes_and_Autodocs_2._guide/node0379.html) on the original [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679)
    you obtained with [GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html), (which is the what you passed to
    [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html)), and not on the parameter of this function.
```
BUGS

SEE ALSO

```c
    [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html)
```
