# 4 / Communicating with Intuition / The IDCMP


The IDCMP gives an application convenient access to many types of user
input events through the Exec message and port system.  Intuition input
event messages include mouse and keyboard activity as well as high level
events from menus and gadgets.

With the IDCMP, you specify the input events you want to know about when
you open the window.  The input events are specified with one or more of
the [IDCMP flags](../Libraries_Manual_guide/node01DA.html) in <intuition/[intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line722)>.  Use the flags with the
[WA_IDCMP](../Libraries_Manual_guide/node0124.html#line35) tag for the [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) (or [OpenWindowTags()](../Libraries_Manual_guide/node0103.html)) function.
Or, set the flags in [NewWindow.IDCMPFlags](../Libraries_Manual_guide/node0124.html#line35) for the [OpenWindow()](../Libraries_Manual_guide/node0103.html) function.  If
any IDCMP flags are set when the window is opened, Intuition automatically
creates a message port for you to receive messages about user activity.
If NULL is specified for IDCMP flags, no port is created.  For more
information on receiving messages from Intuition, see the IDCMP sections
in the chapter "[Intuition Input and Output Methods](../Libraries_Manual_guide/node01CE.html)."

