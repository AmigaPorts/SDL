---
title: DeleteCxObjAll()
manual: amiga-mail
chapter: amiga-mail
section: deletecxobjall
functions: [DeleteCxObjAll]
libraries: [commodities.library]
---

# DeleteCxObjAll()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Cleaning up after a commodity requires deleting its CxObjects.  If a
commodity has a lot of CxObjects, deleting each individually can be a
bit tedious.  DeleteCxObjAll() will delete a CxObject and any other
CxObjects that are attached to it.


```c
    void DeleteCxObjAll( CxObj *delete_co );
```
HotKey uses this function to delete all its CxObjects.  A commodity
that uses DeleteCxObjAll() to delete all its CxObjects should make
sure that they are all connected to the main one.

---

## See Also

- [DeleteCxObjAll — commodities.library](../autodocs/commodities.library.md#deletecxobjall)
