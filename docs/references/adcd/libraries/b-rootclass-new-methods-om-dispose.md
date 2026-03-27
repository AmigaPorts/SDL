---
title: B / rootclass / New Methods: OM_DISPOSE
manual: libraries
chapter: libraries
section: b-rootclass-new-methods-om-dispose
functions: [DisposeObject]
libraries: [intuition.library]
---

# B / rootclass / New Methods: OM_DISPOSE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method instructs an object to delete itself.  The [rootclass](libraries/b-boopsi-class-reference-rootclass.md)
dispatcher's OM_DISPOSE method decrements the true class's internal count
of instances of true class.  The return value for this method is not
explicitly defined.

This method uses the default Boopsi message.

Applications should not call this method directly.  Instead they should
use the intuition.library function [DisposeObject()](libraries/12-using-boopsi-disposing-of-an-object.md).

For the OM_DISPOSE method, an object should do the following:

Free any additional resources the object explicitly allocated itself in
the [OM_NEW](libraries/b-rootclass-new-methods-om-new.md) method (this does not include the instance data).

Pass the message up to the superclass, which will eventually reach
[rootclass](libraries/b-boopsi-class-reference-rootclass.md), which will free the instance data allocated for the object.

If a class does not allocate any extra resources when it creates an
object, it can defer all OM_DISPOSE processing to its superclass.

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
