# 7 / True Requesters / Using a Requester to Block Window Input


There may be times when an application needs to block user input without a
visible requester.  In some cases, the application needs to be busy for a
while.  Other times, an application wants the blocking properties of a
requester, but prefers to use a window instead of a [true](../Libraries_Manual_guide/node01A1.html) requester.  In
this case, the application can create a requester with no imagery,
attaching it to the parent window to block input.  A new window may then
be opened to act as the requester.

Some of the advantages of using a window as a requester instead of a real
requester include:

  * A window can be resized, and moves independently of the parent window.

  * It is legal to render directly into a window.

  * The window can have its own menus since only the parent window's

```c
    menus are disabled (this is only occasionally useful).
```
  * Certain code or a library you are using may not work in requesters

```c
    (GadTools library is an example of this).
```
Of course, using a [true](../Libraries_Manual_guide/node01A1.html) requester instead of a window has the advantage
that the requester automatically moves and depth-arranges along with the
parent window.

 [A Requester Example](../Libraries_Manual_guide/node05A1.html) 

