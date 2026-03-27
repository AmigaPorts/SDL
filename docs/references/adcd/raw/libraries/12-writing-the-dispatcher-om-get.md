# 12 / / Writing The Dispatcher / OM_GET


The rkmmodel only has one "gettable" attribute: [RKMMOD_CurrVal](../Libraries_Manual_guide/node020F.html), which
makes processing it easy.  The [OM_GET](../Libraries_Manual_guide/node0211.html#line36) message looks like this (defined in
<intuition/[classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html#line106)>):


```c
    struct opGet {
        ULONG MethodID;     /* OM_GET */
        ULONG opg_AttrID;   /* The attribute to retrieve */
        ULONG *opg_Storage; /* a place to put the attribute's value */
    };
```
When the [rkmmodelclass](../Libraries_Manual_guide/node020F.html) dispatcher receives an [OM_GET](../Libraries_Manual_guide/node0211.html#line36) message with an
opg_AttrID equal to [RKMMOD_CurrVal](../Libraries_Manual_guide/node020F.html), it copies the current value
([RKMModData](../Libraries_Manual_guide/node0210.html#line18)).currval to the memory location opg_Storage points to and
returns a value of TRUE.  The TRUE indicates that there was no error.  If
opg_AttrID is not RKMMOD_CurrVal, the dispatcher should let its superclass
handle this message.

The [rkmmodelclass](../Libraries_Manual_guide/node020F.html) dispatcher can take advantage of the fact that the only
"gettable" attribute available to an rkmmodel is [RKMMOD_CurrVal](../Libraries_Manual_guide/node020F.html) (the
attributes defined by [modelclass](../Libraries_Manual_guide/node020D.html#line13) and [icclass](../Libraries_Manual_guide/node0200.html#line55) are not gettable--see the
Boopsi Class Reference in the [Appendix B](../Libraries_Manual_guide/node04B9.html) of this manual for more details
on which attributes are "settable", "gettable", etc.).  If opg_AttrID is
not RKMMOD_CurrVal, the rkmmodelclass dispatcher can return FALSE,
indicating that the attribute was not "gettable".

If the [rkmmodelclass](../Libraries_Manual_guide/node020F.html) dispatcher comes across any other messages besides
[OM_NEW](../Libraries_Manual_guide/node0211.html#line20), [OM_SET](../Libraries_Manual_guide/node0211.html#line28), [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32), and [OM_GET](../Libraries_Manual_guide/node0211.html#line36) message, it blindly passes them on
to its superclass for processing.

