# 28 / Using Bobs / Removing a Bob


Two methods may be used to remove a Bob.  The first method uses the
[RemBob()](../Includes_and_Autodocs_2._guide/node046E.html) macro.  RemBob() causes the system to remove the Bob during the
next call to [DrawGList()](../Libraries_Manual_guide/node038C.html) (or two calls to DrawGList() if the system is
double-buffered).  RemBob() asks the system to remove the Bob at the next
convenient time.  See the description of the [BOBSAWAY](../Libraries_Manual_guide/node039A.html#line39) and [BOBNIX](../Libraries_Manual_guide/node039A.html#line50) flags
above. It is called as follows:


```c
    struct Bob myBob = {0};

    RemBob(&myBob);
```
The second method uses the [RemIBob()](../Includes_and_Autodocs_2._guide/node0470.html) routine.  RemIBob() tells the system
to remove this Bob immediately.  For example:


```c
    struct Bob      myBob = {0};
    struct RastPort rastport = {0};
    struct ViewPort viewport = {0};

    RemIBob(&myBob, &rastport, &viewport);
```
This causes the system to erase the Bob from the drawing area and causes
the immediate erasure of any other Bob that had been drawn subsequent to
(and on top of) this one.  The system then unlinks the Bob from the system
GEL list.  To redraw the Bobs that were drawn on top of the one just
removed, another call to [DrawGList()](../Libraries_Manual_guide/node038C.html) must be made.

