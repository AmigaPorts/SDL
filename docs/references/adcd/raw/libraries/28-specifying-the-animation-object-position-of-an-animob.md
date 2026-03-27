# 28 / / Specifying the Animation Object / Position of an AnimOb


To position the object and its component parts, use the [AnimOb](../Libraries_Manual_guide/node03B9.html#line34) structure
members [AnX and AnY](../Libraries_Manual_guide/node03B9.html#line44).  The following figure illustrates how each component
has its own offset from the AnimOb's common reference point.


```c
     [Figure 28-7: Specifying an AnimOb Position](../Libraries_Manual_guide/node05F6.html) 
```
When you change the animation object's [AnX and AnY](../Libraries_Manual_guide/node03B9.html#line44), all of the component
parts will be redrawn relative to it the next time [DrawGList()](../Libraries_Manual_guide/node038C.html) is called.

