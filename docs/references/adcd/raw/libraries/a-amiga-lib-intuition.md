# A / Amiga.lib / Intuition


[CallHook()](../Includes_and_Autodocs_2._guide/node0142.html) and [CallHookA()](../Includes_and_Autodocs_2._guide/node0143.html)

```c
    These functions invoke hooks.  CallHook() expects a parameter packet
    ("message") on the stack, while CallHookA() takes a pointer to the
    message.
```
[DoMethod()](../Includes_and_Autodocs_2._guide/node0156.html) and [DoMethodA()](../Includes_and_Autodocs_2._guide/node0157.html)

```c
    Boopsi support functions that ask a specified Boopsi object to
    perform a specific message.  The message is passed in the function
    call for DoMethodA() and on the stack for DoMethod().  The message is
    invoked on the object's true class.
```
[DoSuperMethod()](../Includes_and_Autodocs_2._guide/node0158.html) and [DoSuperMethodA()](../Includes_and_Autodocs_2._guide/node0159.html)

```c
    Boopsi support functions that ask a Boopsi object to perform a
    supplied message as if it was an instance of its superclass.  The
    message is passed in the function call for DoSuperMethodA() and on
    the stack for DoSuperMethod().
```
[CoerceMethod()](../Includes_and_Autodocs_2._guide/node0145.html) and [CoerceMethodA()](../Includes_and_Autodocs_2._guide/node0146.html)

```c
    Boopsi support functions that ask a Boopsi object to perform a
    supplied message as if it was an instance of some other class. The
    message is passed in the function call for CoerceMethodA() and on the
    stack for CoerceMethod.
```
[SetSuperAttrs()](../Includes_and_Autodocs_2._guide/node0166.html)

```c
    Boopsi support function which invokes the OM_SET method on the
    superclass of the supplied class for the supplied object. Allows the
    ops_AttrList to be supplied on the stack (i.e. in a varargs way).
```
