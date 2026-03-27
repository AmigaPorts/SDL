# 15 / GadTools Gadgets / Handling Gadget Messages


GadTools gadgets follow the same input model as other Intuition
components.  When the user operates a GadTools gadget, Intuition notifies
the application about the input event by sending an [IntuiMessage](../Libraries_Manual_guide/node01D9.html).  The
application can get these messages at the [Window](../Libraries_Manual_guide/node0121.html).UserPort.  However
GadTools gadgets use different message handling functions to get and reply
these messages.  Instead of the Exec functions [GetMsg()](../Libraries_Manual_guide/node02F2.html) and [ReplyMsg()](../Libraries_Manual_guide/node02F3.html),
applications should get and reply these messages through a pair of special
GadTools functions, [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html) and [GT_ReplyIMsg()](../Includes_and_Autodocs_2._guide/node03F5.html).


```c
    struct IntuiMessage *GT_GetIMsg(struct MsgPort *iport)
    void  GT_ReplyIMsg(struct IntuiMessage *imsg)
```
For [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html), the iport argument should be set to the window's
UserPort.  For [GT_ReplyIMsg()](../Includes_and_Autodocs_2._guide/node03F5.html), the imsg argument should be set to a
pointer to the [IntuiMessage](../Libraries_Manual_guide/node01D9.html) returned by GT_GetIMsg().

These functions ensure that the application only sees the gadget events
that concern it and in a desirable form.  For example, with a GadTools
slider gadget, a message only gets through to the application when the
slider's level actually changes and that level can be found in the
[IntuiMessage](../Libraries_Manual_guide/node01D9.html)'s [Code](../Libraries_Manual_guide/node01D9.html#line33) field:


```c
    imsg = GT_GetIMsg(win->UserPort);
    object = imsg->IAddress;
    class = imsg->Class;
    code = imsg->Code;
    GT_ReplyIMsg(imsg);
    switch (class)
        {
        case IDCMP_MOUSEMOVE:
            if (object == slidergad)
                {
                printf("Slider at level %ld\n", code);
                }
            ...
            break;
        ...
        }
```
In general, the [IntuiMessage](../Libraries_Manual_guide/node01D9.html)s received from GadTools contain more
information in the [Code](../Libraries_Manual_guide/node01D9.html#line33) field than is found in regular Intuition gadget
messages.  Also, when dealing with GadTools a lot of messages (mostly
[IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23)s) do not have to be processed by the application.  These
are two reasons why dealing with GadTools gadgets is much easier than
dealing with regular Intuition gadgets.  Unfortunately this processing
cannot happen magically, so applications must use [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html) and
[GT_ReplyIMsg()](../Includes_and_Autodocs_2._guide/node03F5.html) where they would normally have used [GetMsg()](../Libraries_Manual_guide/node02F2.html) and [ReplyMsg()](../Libraries_Manual_guide/node02F3.html).

[GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html) actually calls [GetMsg()](../Libraries_Manual_guide/node02F2.html) to remove a message from the
specified window's UserPort.  If the message pertains to a GadTools gadget
then some dispatching code in GadTools will be called to process the
message.  What the program will receive from GT_GetIMsg() is actually a
copy of the real [IntuiMessage](../Libraries_Manual_guide/node01D9.html), possibly with some supplementary
information from GadTools, such as the information typically found in the
[Code](../Libraries_Manual_guide/node01D9.html#line33) field.

The [GT_ReplyIMsg()](../Includes_and_Autodocs_2._guide/node03F5.html) call will take care of cleaning up and replying to the
real [IntuiMessage](../Libraries_Manual_guide/node01D9.html).


```c
    Warning:
    --------
    When an [IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23) message is received from a GadTools gadget,
    GadTools arranges to have the gadget's pointer in the [IAddress](../Libraries_Manual_guide/node01D9.html#line73)
    field of the [IntuiMessage](../Libraries_Manual_guide/node01D9.html).  While this is extremely convenient, it
    is also untrue of messages from regular Intuition gadgets (described
    in the "[Intuition Gadgets](../Libraries_Manual_guide/node0148.html#line5)" chapter).  Do not make the mistake of
    assuming it to be true.
```
This description of the inner workings of [GT_GetIMsg()](../Includes_and_Autodocs_2._guide/node03F2.html) and [GT_ReplyIMsg()](../Includes_and_Autodocs_2._guide/node03F5.html)
is provided for understanding only; it is crucial that the program make no
assumptions or interpretations about the real [IntuiMessage](../Libraries_Manual_guide/node01D9.html).  Any such
inferences are not likely to hold true in the future.  See the section on
[documented side-effects](../Libraries_Manual_guide/node0277.html) for more information.

