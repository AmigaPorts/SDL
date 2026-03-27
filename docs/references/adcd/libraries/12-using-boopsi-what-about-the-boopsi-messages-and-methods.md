---
title: 12 / / Using Boopsi / What About the Boopsi Messages and Methods?
manual: libraries
chapter: libraries
section: 12-using-boopsi-what-about-the-boopsi-messages-and-methods
functions: [DisposeObject, GetAttr, NewObject]
libraries: [intuition.library]
---

# 12 / / Using Boopsi / What About the Boopsi Messages and Methods?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

According to the "[OOP Overview](libraries/12-boopsi-object-oriented-intuition-oop-overview.md)" section, for an object to perform a
method, something has to pass it a Boopsi message.  The previous section
discussed using Intuition functions to ask an object to do things like set
and get attributes.  The functions in the previous section seem to
completely ignore all that material about methods and messages.  What
happened to the methods and messages?

Nothing--these functions don't ignore the OOP constructs, they just shield
the programmer from them.  Each of these functions corresponds to a Boopsi
method:


```c
    [NewObject()](libraries/12-using-boopsi-creating-an-object.md)                  [OM_NEW](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md)
    [DisposeObject()](libraries/12-using-boopsi-disposing-of-an-object.md)              [OM_DISPOSE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md)
    [SetAttrs()/SetGadgetAttrs()](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md)  [OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md)
    [GetAttr()](libraries/12-using-boopsi-getting-an-object-s-attributes.md)                    [OM_GET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md)
```
These methods are defined on the [rootclass](libraries/12-boopsi-object-oriented-intuition-oop-overview.md) level, so all Boopsi classes
inherit them.  The Intuition functions that correspond to these methods
take care of constructing and sending a Boopsi message with the
appropriate method ID and parameters.

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
