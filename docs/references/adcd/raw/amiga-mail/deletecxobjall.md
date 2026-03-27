# DeleteCxObjAll()


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

