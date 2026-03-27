# 15 / / Other Functions / GT_FilterIMsg() and GT_PostFilterIMsg()


For most GadTools programs, [GT_GetIMsg()](../Libraries_Manual_guide/node025B.html) and [GT_ReplyIMsg()](../Libraries_Manual_guide/node025B.html) work perfectly
well.  In rare cases an application may find they pose a bit of a problem.
A typical case is when all messages are supposed to go through a
centralized [ReplyMsg()](../Libraries_Manual_guide/node02F3.html) that cannot be converted to a GT_ReplyIMsg().
Since calls to GT_GetIMsg() and GT_ReplyIMsg() must be paired, there would
be a problem.

For such cases, the [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html) and [GT_PostFilterIMsg()](../Includes_and_Autodocs_2._guide/node03F3.html) functions are
available.  These functions allow [GetMsg()](../Libraries_Manual_guide/node02F2.html) and [ReplyMsg()](../Libraries_Manual_guide/node02F3.html) to be used in a
way that is compatible with GadTools.


```c
    Warning:
    --------
    These functions are for specialized use only and will not be used by
    the majority of applications.  See [GT_GetIMsg()](../Libraries_Manual_guide/node025B.html) and
    [GT_ReplyIMsg()](../Libraries_Manual_guide/node025B.html) for standard message handling.


    struct IntuiMessage *GT_FilterIMsg( struct IntuiMessage *imsg );
    struct IntuiMessage *GT_PostFilterIMsg( struct IntuiMessage *imsg );
```
The [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html) function should be called right after [GetMsg()](../Libraries_Manual_guide/node02F2.html).  It
takes a pointer to the original [IntuiMessage](../Libraries_Manual_guide/node01D9.html) and, if the message applies
to a GadTools gadget, returns either a modified IntuiMessage or a NULL.  A
NULL return signifies that the message was consumed by a GadTools gadget
(and not needed by the application).

The [GT_PostFilterIMsg()](../Includes_and_Autodocs_2._guide/node03F3.html) function should be called before replying to any
message modified by [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html).  It takes a pointer to the modified
version of an [IntuiMessage](../Libraries_Manual_guide/node01D9.html) obtained with GT_FilterIMsg() and returns a
pointer to the original IntuiMessage.

The typical calling sequence for a program that uses these functions, is
to call [GetMsg()](../Libraries_Manual_guide/node02F2.html) to get the [IntuiMessage](../Libraries_Manual_guide/node01D9.html).  Then, if the message applies to
a window which contains GadTools gadgets, call [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html).  Any
message returned by GT_FilterIMsg() should be used like a message returned
from [GT_GetIMsg()](../Libraries_Manual_guide/node025B.html).

When done with the message, the application must call [GT_PostFilterIMsg()](../Includes_and_Autodocs_2._guide/node03F3.html)
to perform any clean up necessitated by the previous call to
[GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html).  In all cases, the application must then reply the
original [IntuiMessage](../Libraries_Manual_guide/node01D9.html) using [ReplyMsg()](../Libraries_Manual_guide/node02F3.html).  This is true even for consumed
messages as these are not replied by GadTools.  For example, the
application could use code such as this:


```c
    /* port is a message port receiving different messages */
    /* gtwindow is the window that contains GadTools gadgets */

    imsg = GetMsg(port);

    /* Is this the window with GadTools gadgets? */
    if (imsg->IDCMPWindow == gtwindow)
        {
        /* Filter the message and see if action is needed */
        if (gtimsg = GT_FilterIMsg(imsg))
            {
            switch (gtimsg->Class)
                {
                /* Act depending on the message */
                ...
                }
            /* Clean up the filtered message.  The return value is not */
            /* needed since we already have a pointer to the original  */
            /* message.                                                */
            GT_PostFilterIMsg(gtimsg);
            }
        }
    /* other stuff can go here */
    ReplyMsg(imsg);
```
You should not make any assumptions about the contents of the unfiltered
[IntuiMessage](../Libraries_Manual_guide/node01D9.html) (imsg in the above example).  Only two things are guaranteed:
the unfiltered IntuiMessage must be replied to and the unfiltered
IntuiMessage (if it produces anything when passed through [GT_FilterIMsg()](../Includes_and_Autodocs_2._guide/node03F1.html))
will produce a meaningful GadTools IntuiMessage like those described in
the section on the different [kinds of gadgets](../Libraries_Manual_guide/node025F.html).  The relationship between
the unfiltered and filtered messages are expected to change in the future.
See the section on [documented side-effects](../Libraries_Manual_guide/node0277.html) for more information.

