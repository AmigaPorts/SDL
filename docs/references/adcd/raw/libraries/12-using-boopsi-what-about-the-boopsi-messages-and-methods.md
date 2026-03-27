# 12 / / Using Boopsi / What About the Boopsi Messages and Methods?


According to the "[OOP Overview](../Libraries_Manual_guide/node0200.html#line100)" section, for an object to perform a
method, something has to pass it a Boopsi message.  The previous section
discussed using Intuition functions to ask an object to do things like set
and get attributes.  The functions in the previous section seem to
completely ignore all that material about methods and messages.  What
happened to the methods and messages?

Nothing--these functions don't ignore the OOP constructs, they just shield
the programmer from them.  Each of these functions corresponds to a Boopsi
method:


```c
    [NewObject()](../Libraries_Manual_guide/node0203.html#line25)                  [OM_NEW](../Libraries_Manual_guide/node0211.html#line20)
    [DisposeObject()](../Libraries_Manual_guide/node0204.html)              [OM_DISPOSE](../Libraries_Manual_guide/node0211.html#line24)
    [SetAttrs()/SetGadgetAttrs()](../Libraries_Manual_guide/node0205.html)  [OM_SET](../Libraries_Manual_guide/node0211.html#line28)
    [GetAttr()](../Libraries_Manual_guide/node0206.html)                    [OM_GET](../Libraries_Manual_guide/node0211.html#line36)
```
These methods are defined on the [rootclass](../Libraries_Manual_guide/node0200.html#line50) level, so all Boopsi classes
inherit them.  The Intuition functions that correspond to these methods
take care of constructing and sending a Boopsi message with the
appropriate method ID and parameters.

