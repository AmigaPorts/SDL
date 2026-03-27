# commodities.library/SetTranslate



NAME

```c
    SetTranslate -- replace a translator object's translation list. (V36)
```
SYNOPSIS

```c
    SetTranslate(translator,events);
                 A0         A1

    VOID SetTranslate(CxObj *,struct [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) *);
```
FUNCTION

    This function replaces the translation list of a commodity
    translator object with the linked list starting at 'events'.

    A NULL value for 'events' indicates that the object 'translator'
    should swallow all commodity messages that are sent its way.

    Note that the input events are not copied into commodities' private
    memory, but the value of 'events' is used -- asynchronously to the
    application program -- to find a chain of InputEvents in the
    application's data space. At the time of translation, each input event
    is copied into its own new commodity message.

    The above means that no other commodities' user, nor
    commodities.library itself will be modifying your list of InputEvents.
    On the other hand, your program must not corrupt the input event
    chain that has been presented to a translator.
INPUTS

    translator - the translator object to affect
    events - the new input event translation list
SEE ALSO

```c
    [<devices/inputevent.h>](../Includes_and_Autodocs_2._guide/node0051.html), [cx_lib/CxTranslate()](../Includes_and_Autodocs_2._guide/node0150.html)
```
