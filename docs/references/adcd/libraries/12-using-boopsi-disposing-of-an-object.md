---
title: 12 / / Using Boopsi / Disposing of an Object
manual: libraries
chapter: libraries
section: 12-using-boopsi-disposing-of-an-object
functions: [DisposeObject]
libraries: [intuition.library]
---

# 12 / / Using Boopsi / Disposing of an Object

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When an application is done with an object it has to dispose of the
object.  To dispose of an object, use the Intuition function
[DisposeObject()](autodocs-2.0/intuition-library-disposeobject.md):


```c
    VOID DisposeObject(APTR boopsiobject);
```
where boopsiobject is a pointer to the Boopsi object to be disposed.  Note
that some classes allow applications to connect child objects to a parent
object so that when the application deletes the parent object, it
automatically disposes of all of its children.  Be careful not to dispose
of an object that has already been disposed.

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
