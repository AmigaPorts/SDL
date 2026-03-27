# 7 / Easy Requesters / Low Level Access to Easy Requesters


The [EasyRequest()](../Libraries_Manual_guide/node01AC.html) function calls a lower level Intuition function named
[BuildEasyRequest()](../Includes_and_Autodocs_2._guide/node0201.html) to construct the requester.  An application can call
BuildEasyRequest() directly if it needs to use an easy requester but
requires custom handling of the events sent to the requester.  Handling of
the events should be done using the [SysReqHandler()](../Includes_and_Autodocs_2._guide/node025B.html) function as described
below.

The [BuildEasyRequest()](../Includes_and_Autodocs_2._guide/node0201.html) functions take the same arguments as [EasyRequest()](../Libraries_Manual_guide/node01AC.html):


```c
    struct Window *BuildEasyRequestArgs( struct Window *window,
                                         struct EasyStruct *easyStruct,
                                         unsigned long idcmp, APTR args );

    struct Window *BuildEasyRequest( struct Window *window,
                                     struct EasyStruct *easyStruct,
                                     unsigned long idcmp, APTR arg1, ... );
```
To process input event information directly while an easy requester is
displayed, first call [BuildEasyRequest()](../Includes_and_Autodocs_2._guide/node0201.html) then call [SysReqHandler()](../Includes_and_Autodocs_2._guide/node025B.html)
periodically to process user input.


```c
    LONG SysReqHandler( struct Window *window, ULONG *idcmpPtr,
                        long waitInput );
```
This will provide standard handling of events but allow the application to
control the timing of checking the events.  This handling includes checks
for left Amiga keys.

The [FreeSysRequest()](../Includes_and_Autodocs_2._guide/node0219.html) function must be called after an application has
finished with a requester (if it was created with [BuildEasyRequest()](../Includes_and_Autodocs_2._guide/node0201.html) call).


```c
    void FreeSysRequest( struct Window *window );
```
This function ends the requester and frees any resources allocated with
the [BuildEasyRequest()](../Includes_and_Autodocs_2._guide/node0201.html) call.

