# 31 Commodities Exchange Library / Translate CxObjects


Normally, after a commodity processes a hot key input event, it needs to
eliminate that input event.  Other commodities may need to replace an
input event with a different one.  The translate [CxObject](../Libraries_Manual_guide/node0401.html) can be used for
these purposes.


```c
    translateCxObj = CxObj  *CxTranslate(struct InputEvent *newinputevent);
```
The macro [CxTranslate()](../Includes_and_Autodocs_2._guide/node0150.html) creates a new translate [CxObject](../Libraries_Manual_guide/node0401.html).  CxTranslate()'s
only argument is a pointer to a chain of one or more [InputEvent](../Libraries_Manual_guide/node01D0.html) structures.

When a translate [CxObject](../Libraries_Manual_guide/node0401.html) receives a [CxMessage](../Libraries_Manual_guide/node0403.html), it eliminates the
CxMessage and its corresponding input event from the system.  The
translator introduces a new input event, which Commodities Exchange copies
from the [InputEvent](../Libraries_Manual_guide/node01D0.html) structure passed to [CxTranslate()](../Includes_and_Autodocs_2._guide/node0150.html) (newinputevent from
the function prototype above), in place of the deleted input event.

A translator is normally attached to some kind of [filtering CxObject](../Libraries_Manual_guide/node0407.html).  If
it wasn't, it would translate all input events into the same exact input
event.  Like the [sender CxObject](../Libraries_Manual_guide/node0409.html), a translator does not divert [CxMessages](../Libraries_Manual_guide/node0403.html)
down its personal list, so it doesn't serve any purpose to add any to it.


```c
    void SetTranslate( CxObj *translator, struct InputEvent *ie );
```
It is possible to change the [InputEvent](../Libraries_Manual_guide/node01D0.html) structure that a translator looks
at when it creates and introduces new input events into the input stream.
The function [SetTranslate()](../Includes_and_Autodocs_2._guide/node01B5.html) accepts a pointer to the new InputEvent
structure, which the translator will duplicate and introduce when it
receives a [CxMessage](../Libraries_Manual_guide/node0403.html).

HotKey utilizes a special kind of translator.  Instead of supplying a new
input event, HotKey passes a NULL to [CxTranslate()](../Includes_and_Autodocs_2._guide/node0150.html).  If a translator has a
NULL new input event pointer, it does not introduce a new input event, but
still eliminates any [CxMessages](../Libraries_Manual_guide/node0403.html) and corresponding input events it receives.

