# A / Amiga.lib / Commodities


[ArgArrayInit()](../Includes_and_Autodocs_2._guide/node013D.html) and [ArgArrayDone()](../Includes_and_Autodocs_2._guide/node013C.html)

```c
    ArgArrayInit() returns an array of strings suitable for sending to
    icon.library/[FindToolType()](../Includes_and_Autodocs_2._guide/node0186.html). This array will be the ToolTypes array
    of the program's icon, if it was started from Workbench. It will just
    be 'argv' if the program was started from a shell. ArgArrayDone()
    frees memory and does cleanup required after a call to ArgArrayInit().
```
[ArgInt()](../Includes_and_Autodocs_2._guide/node013E.html) and [ArgString()](../Includes_and_Autodocs_2._guide/node013F.html)

```c
    These functions look for a particular entry in a ToolType array
    returned by ArgArrayInit() and return the integer (ArgInt()) or
    string (ArgString()) associated with that entry.  A default value can
    be passed to each function which will be returned in the event that
    the requested entry could not be found in the ToolType array.
```
[CxCustom()](../Includes_and_Autodocs_2._guide/node014B.html)

    This function creates a custom commodity object. The action of this
    object on receiving a commodity message is to call a function of the
    application programmer's choice.
[CxDebug()](../Includes_and_Autodocs_2._guide/node014C.html)

```c
    This function creates a Commodities debug object. The action of this
    object on receiving a Commodities message is to print out information
    about the message through the serial port (using the
    debug.lib/[KprintF()](../Libraries_Manual_guide/node04B8.html#line31) routine). A specified 'id' will also be displayed.
```
[CxFilter()](../Includes_and_Autodocs_2._guide/node014D.html)

```c
    Creates a Commodities input event filter object that matches a
    description string. The description string is in the same format as
    strings expected by commodities.library/[SetFilter()](../Includes_and_Autodocs_2._guide/node01B3.html). If the
    description string is NULL, the filter will not match any messages.
```
[CxSender()](../Includes_and_Autodocs_2._guide/node014E.html)

    This function creates a Commodities sender object. The action of this
    object on receiving a Commodities message is to copy the Commodities
    message into a standard Exec Message, to put a supplied id in the
    message as well, and to send the message off to the message port.
[CxSignal()](../Includes_and_Autodocs_2._guide/node014F.html)

    This function creates a Commodities signal object. The action of this
    object on receiving a Commodities message is to send a signal to a
    task.  The caller is responsible for allocating the signal and
    determining the proper task ID.
[CxTranslate()](../Includes_and_Autodocs_2._guide/node0150.html)

    This function creates a Commodities translator object. The action of
    this object on receiving a Commodities message is to replace that
    message in the commodities network with a chain of Commodities input
    messages.
[HotKey()](../Includes_and_Autodocs_2._guide/node015F.html)

```c
    This function creates a triad of commodity objects to accomplish a
    high-level function.

    The three objects are a filter, which is created to match by
    CxFilter(), a sender created by CxSender(), and a translator which is
    created by CxTranslate(), so that it swallows any commodity input
    event messages that are passed down by the filter.

    This is the simple way to get a message sent to your program when the
    user performs a particular input action.
```
[InvertString()](../Includes_and_Autodocs_2._guide/node0160.html)

```c
    This function returns a linked list of input events which would
    translate into the string using the supplied keymap (or the system
    default keymap if the supplied keymap is NULL).

    This chain should eventually be freed using FreeIEvents().
```
[FreeIEvents()](../Includes_and_Autodocs_2._guide/node015C.html)

```c
    This function frees a linked list of input events as obtained from
    InvertString().
```
