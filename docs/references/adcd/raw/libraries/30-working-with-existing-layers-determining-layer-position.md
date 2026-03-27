# 30 / / Working With Existing Layers / Determining Layer Position


If the viewing area has been separated into several layers, the
application may need to find out which layer is topmost at a particular
x,y coordinate.  Use the [WhichLayer()](../Includes_and_Autodocs_2._guide/node03AA.html) function for this:


```c
    struct Layer *WhichLayer( struct Layer_Info *li, long x, long y );
```
To be sure that no task adds, deletes, or changes the sequence of layers
before this information is used, call [LockLayerInfo()](../Libraries_Manual_guide/node03EC.html#line11) before calling
[WhichLayer()](../Includes_and_Autodocs_2._guide/node03AA.html), and call [UnlockLayerInfo()](../Libraries_Manual_guide/node03EC.html#line11) when the operation is complete.
In this way, the program may ensure that it is acting on valid
information.  Always check for a NULL return value (coordinate not in a
layer) from WhichLayer().

