# 2 / How an Application Sees Intuition / Screens and Windows


As mentioned earlier, Intuition allows multiple programs to share the
display by managing a system of [multiple screens](../Libraries_Manual_guide/node00D9.html) and overlapping [windows](../Libraries_Manual_guide/node00FF.html).
A screen sets up the display environment and forms the background that
application windows operate in.  A window is simply a graphic rectangle
that represents a work context.  Each screen can have many windows on it.

[Multiple screens](../Libraries_Manual_guide/node00D9.html) and [windows](../Libraries_Manual_guide/node00FF.html) give each application its own separate visual
context so that many programs can output graphics and text to the display
at the same time without interfering with one another.  Intuition (using
the [layers library](../Libraries_Manual_guide/node03E3.html)) handles all the details of clipping graphics so they
stay inside window bounds and remembering graphics that go temporarily out
of sight when the user [rearranges windows](../Libraries_Manual_guide/node0117.html).

The keyboard and mouse are shared among applications through a simpler
technique:  only one application window at a time can have the
[input focus](../Libraries_Manual_guide/node01D3.html).  Hence, Intuition ensures that only one window, called the
[active window](../Libraries_Manual_guide/node010F.html) gets to know about keyboard, mouse and other types of input
activity.

Each application window is like a virtual terminal or console.  Your
program will seem to have the entire machine and display to itself.  It
can send text and graphics to its terminal window, and ask for input from
any number of sources, ignoring the fact that other programs may be
performing these same operations.  Intuition handles all the housekeeping.
In fact, your program can open several of these virtual terminals and
treat each one as if it were the only program running on the machine.
Intuition will keep track of all the activity and make sure commands and
data are dispatched to the right place.

