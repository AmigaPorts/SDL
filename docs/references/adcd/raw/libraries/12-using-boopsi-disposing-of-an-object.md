# 12 / / Using Boopsi / Disposing of an Object


When an application is done with an object it has to dispose of the
object.  To dispose of an object, use the Intuition function
[DisposeObject()](../Includes_and_Autodocs_2._guide/node020D.html):


```c
    VOID DisposeObject(APTR boopsiobject);
```
where boopsiobject is a pointer to the Boopsi object to be disposed.  Note
that some classes allow applications to connect child objects to a parent
object so that when the application deletes the parent object, it
automatically disposes of all of its children.  Be careful not to dispose
of an object that has already been disposed.

