# gadtools.library/GT_FilterIMsg



NAME

```c
    GT_FilterIMsg -- Filter an [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) through GadTools. (V36)
```
SYNOPSIS

```c
    modimsg = GT_FilterIMsg(imsg)
    D0                      A1

    struct [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) *GT_FilterIMsg(struct [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) *);
```
FUNCTION

```c
    NOTE WELL:  Extremely few programs will actually need this function.
    You almost certainly should be using [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html) and [GT_ReplyIMsg()](../Includes_and_Autodocs_2._guide/node03F5.html)
    only, and not GT_FilterIMsg() and [GT_PostFilterIMsg()](../Includes_and_Autodocs_2._guide/node03F3.html).

    GT_FilterIMsg() takes the supplied [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) and asks the
    [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) Toolkit to consider and possibly act on it.  Returns
    NULL if the message was only of significance to a GadTools gadget
    (i.e. not to you), else returns a pointer to a modified IDCMP
    message, which may contain additional information.
    You should examine the Class, Code, and IAddress fields of
    the returned message to learn what happened.  Do not make
    interpretations based on the original imsg.
    You should use [GT_PostFilterIMsg()](../Includes_and_Autodocs_2._guide/node03F3.html) to revert to the original
    [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) once you are done with the modified one.
```
INPUTS

```c
    imsg - An [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) you obtained from a Window's UserPort.
```
RESULT

```c
    modimsg - A modified [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679), possibly with extra information
        from GadTools, or NULL.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html), [GT_PostFilterIMsg()](../Includes_and_Autodocs_2._guide/node03F3.html)
```
