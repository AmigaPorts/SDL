# 12 / / Building On Existing Public Classes / Building Rkmmodelclass


So far, the theoretical class [rkmmodelclass](../Libraries_Manual_guide/node020F.html) has just one attribute,
[RKMMOD_CurrVal](../Libraries_Manual_guide/node020F.html).  A couple of extra attributes can make it more useful.
Because the rkmmodel object maintains an upper limit on its RKMMOD_CurrVal
integer value, it would be useful if that upper limit was variable.  Using
a new attribute, RKMMOD_Limit, an application can tell a rkmmodel what its
upper limit is.  The rkmmodel will enforce the limit internally, so the
application doesn't have to worry about it.

Another useful addition is a pulse increment and decrement for
[RKMMOD_CurrVal](../Libraries_Manual_guide/node020F.html).  Whenever the model receives an increment or decrement
command, it increments or decrements its internal value. To make the
example class simple, [rkmmodelclass](../Libraries_Manual_guide/node020F.html) implements incrementing and
decrementing by creating "dummy" attributes called RKMMOD_Up and
RKMMOD_Down.  When an rkmmodel receives an [OM_SET](../Libraries_Manual_guide/node0211.html#line28) message for one of these
attributes, it increments or decrements RKMMOD_CurrVal.  An rkmmodelclass
object does not care what the value of the RKMMOD_Up and RKMMOD_Down
attributes are, it only cares that it received an [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) about it.

There are two pieces of data that make up this new class's instance data:
the rkmmodel's current value ([RKMMOD_CurrVal](../Libraries_Manual_guide/node020F.html)) and the upper limit of the
rkmmodel (RKMMOD_Limit).  The example class consolidates them into one
structure:


```c
    struct RKMModData {
        ULONG currval;
        ULONG vallimit;
    };
```
