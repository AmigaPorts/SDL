# 4 / Other Window Functions / Requesters in the Window


Requesters are temporary sub-windows, usually containing several gadgets,
used to confirm actions, access files, or adjust the options of a command
the user has just given.  [Request()](../Libraries_Manual_guide/node01A2.html#line12) creates and activates a requester in
the window.  [EndRequest()](../Libraries_Manual_guide/node01A2.html#line24) removes the requester from the window.


```c
    BOOL Request( struct Requester *requester, struct Window *window );
    void EndRequest( struct Requester *requester, struct Window *window );
```
For simple requesters in a format that matches system requesters, two new
functions have been added to Release 2:


```c
    LONG EasyRequestArgs( struct Window *window,
                          struct EasyStruct *easyStruct,
                          ULONG *idcmpPtr, APTR args );
    LONG EasyRequest( struct Window *window,
                          struct EasyStruct *easyStruct,
                          ULONG *idcmpPtr, APTR arg1, ... );
```
The [EasyRequest()](../Libraries_Manual_guide/node01AC.html) functions support requesters with one or more gadgets
automatically providing a layout that is sensitive to the current font and
screen resolution.  See the chapter "[Intuition Requesters and Alerts](../Libraries_Manual_guide/node01AC.html)" for
more information on using requester functions.

