# amiga.lib/HotKey



NAME

```c
    HotKey -- create a commodity triad. (V36)
```
SYNOPSIS

```c
    filterObj = Hotkey(description,port,id);

    CxObj *HotKey(STRPTR,struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *,LONG);
```
FUNCTION

```c
    This function creates a triad of commodity objects to accomplish a
    high-level function.

    The three objects are a filter, which is created to match by the call
    CxFilter(description), a sender created by the call CxSender(port,id),
    and a translator which is created by CxTranslate(NULL), so that it
    swallows any commodity input event messages that are passed down by
    the filter.

    This is the simple way to get a message sent to your program when the
    user performs a particular input action.

    It is strongly recommended that the ToolTypes environment be used to
    allow the user to specify the input descriptions for your application's
    hotkeys.
```
INPUTS

```c
    description - the description string to use for the filter in the same
                  format as accepted by [commodities.library/SetFilter()](../Includes_and_Autodocs_2._guide/node01B3.html)
    port - port for the sender to send messages to.
    id - id of the messages sent by the sender
```
RESULTS

    filterObj - a pointer to a filter object, or NULL if it could
                not be created.
SEE ALSO

```c
    [CxFilter()](../Includes_and_Autodocs_2._guide/node014D.html), [CxSender()](../Includes_and_Autodocs_2._guide/node014E.html), [CxTranslate()](../Includes_and_Autodocs_2._guide/node0150.html),
    [commodities.library/CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html), [commodities.library/SetFilter()](../Includes_and_Autodocs_2._guide/node01B3.html)
```
