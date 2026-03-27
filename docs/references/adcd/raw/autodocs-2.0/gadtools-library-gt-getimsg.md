# gadtools.library/GT_GetIMsg



NAME

```c
    GT_GetIMsg -- Get an [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679), with GadTools processing. (V36)
```
SYNOPSIS

```c
    imsg = GT_GetIMsg(intuiport)
    D0                A0

    struct [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) *GT_GetIMsg(struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *);
```
FUNCTION

```c
    Use GT_GetIMsg() in place of the usual [exec.library/GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html) when
    reading IntuiMessages from your window's UserPort.  If needed,
    the GadTools dispatcher will be invoked, and suitable processing
    will be done for gadget actions.  This function returns a pointer
    to a modified [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) (which is a copy of the original,
    possibly with some supplementary information from GadTools).
    If there are no messages (or if the only messages are meaningful
    only to GadTools, NULL will be returned.
```
INPUTS

```c
    intuiport - The Window->UserPort of a window that is using the
        [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) Toolkit.
```
RESULT

```c
    imsg - Pointer to modified [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679), or NULL if there are
        no applicable messages.
```
EXAMPLE

NOTES

```c
    Be sure to use [GT_ReplyIMsg()](../Includes_and_Autodocs_2._guide/node03F5.html) and not [exec.library/ReplyMsg()](../Includes_and_Autodocs_2._guide/node0379.html) on
    messages obtained with GT_GetIMsg().
    If you intend to do more with the resulting message than read
    its fields, act on it, and reply it, you may find [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html)
    more appropriate.
```
BUGS

SEE ALSO

```c
    [GT_ReplyIMsg()](../Includes_and_Autodocs_2._guide/node03F5.html), [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html)
```
