# 16 / Creating a File Requester / ASL Requesters and Custom Screens


An application that uses a custom screen normally wants its requesters to
open on its screen.  Using the ASL_Window tag, a program can associate a
requester with a specific window so that the requester appears on the same
screen as the window.  The ASL_Window tag is followed by a pointer to a
window structure.  ASL_Window works with both file and font requesters.
The [example](../Libraries_Manual_guide/node057D.html) above shows how the ASL_Window tag is used with a file
requester.

Normally, a requester associated with a window (using ASL_Window) shares
that window's IDCMP port for its communication.  An application may not
want to share an IDCMP port with the requester.  Using the ASL_FuncFlags
tag, a program can ask for a requester that creates its own IDCMP port.
There are two flags that accomplish this.  The first, [FILF_NEWIDCMP](../Libraries_Manual_guide/node027D.html#line8), is
used on file requesters.   The other, FONF_NEWIDCMP, is used on font
requesters.

