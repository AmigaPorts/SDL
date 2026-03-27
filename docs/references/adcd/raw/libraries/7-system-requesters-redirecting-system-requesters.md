# 7 / System Requesters / Redirecting System Requesters


A process can force the [system](../Libraries_Manual_guide/node01AF.html) requests which are caused by its actions to
appear on a custom screen by changing the pr_WindowPtr field of its
[Process](../Includes_and_Autodocs_2._guide/node0078.html#line34) structure.  This field may be set to three values: zero, negative
one or a valid pointer to the [Window](../Libraries_Manual_guide/node0121.html) structure of an open window.  If
pr_WindowPtr is set to zero, the request will appear on the default public
screen.  If pr_WindowPtr is set to negative one, the system request will
never appear and the return code will be as if the user had selected the
rightmost button (negative response).  If pr_WindowPtr is set to a valid
window pointer, then the request will appear on the same screen as the
window.

The original value of [pr_WindowPtr](../Includes_and_Autodocs_2._guide/node0078.html#line56) should be cached and restored before
the window is closed.

