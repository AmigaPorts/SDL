# 7 / True Requesters / Creating Application Requesters


To create a requester, the application first allocates memory for or
declares an instance of the [Requester](../Libraries_Manual_guide/node01AB.html) structure as defined in
<intuition/[intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line145)>.  Once the Requester structure is set up, it is
initialized with the [InitRequester()](../Includes_and_Autodocs_2._guide/node0221.html) function.


```c
    void InitRequester( struct Requester *requester)
```
This function simply clears the [Requester](../Libraries_Manual_guide/node01AB.html) structure.  The application
should do further initialization depending on its needs.  See the section
on the "[Requester Structure](../Libraries_Manual_guide/node01AB.html#line34)" below for an explanation of all the Requester
fields and how to set them.

A [true](../Libraries_Manual_guide/node01A1.html) (modal) requester is attached to its parent window and displayed
with the [Request()](../Includes_and_Autodocs_2._guide/node0249.html) function.


```c
    BOOL Request(struct Requester *requester, struct Window *window)
```
This function returns TRUE if the requester opens successfully or FALSE if
the requester cannot be opened.  If the requester opens successfully, menu
and gadget input in the parent window is blocked as long as the requester
is displayed.  The application should process input events from the
requester, which are sent to the parent window's [Window.UserPort](../Libraries_Manual_guide/node01D6.html#line16), until
the requester is satisfied.

To remove a requester from its parent window and update the display, use
[EndRequest()](../Includes_and_Autodocs_2._guide/node0214.html).


```c
    void EndRequest( struct Requester *requester, struct Window *window );
```
This removes only the one requester specified.  It is possible to set up a
requester with a special gadget that, if selected, will automatically
close the requester.  In that case, [EndRequest()](../Includes_and_Autodocs_2._guide/node0214.html) need not be called.  If
the program needs to cancel the request early, or cancel it only after
some specific manipulation of the gadgets, EndRequest() should be used.

The application should always provide a safe way for the user to back out
of a requester without taking any action that affects the user's work.
Providing an escape hatch is important, for instance, a requester with the
message "Overwrite File?" should allow the user to cancel the operation
without losing the old data.

