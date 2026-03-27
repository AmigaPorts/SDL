# 12 / / Writing The Dispatcher / OM_NEW


The [OM_NEW](../Libraries_Manual_guide/node0211.html#line20) method returns a pointer to a newly created Boopsi object, or
NULL if it failed to create the object.  This method receives the
following message structure (defined in <intuition/[classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html#line76)>):


```c
    /* The OM_NEW method uses the same structure as OM_SET */

    struct opSet {
        ULONG             MethodID;
        struct TagItem    *ops_AttrList;
        struct GadgetInfo *ops_GInfo;
    };
```
The ops_AttrList field contains a pointer to a [TagItem](../Libraries_Manual_guide/node0497.html) array of
attribute/value pairs.  These contain the initial values of the new
object's attributes.  The ops_GInfo field is always NULL for the [OM_NEW](../Libraries_Manual_guide/node0211.html#line20)
method.

Unlike other methods, when a dispatcher gets an [OM_NEW](../Libraries_Manual_guide/node0211.html#line20) message, the object
pointer (recvobject from the [dispatchRKMModel()](../Libraries_Manual_guide/node0211.html) prototype above) does not
point to an object.  It doesn't make sense for recvobject to point to an
object because the idea is to create a new object, not act on an existing
one.

The pointer normally used to pass a Boopsi object is instead used to pass
the address of the object's "true class".  An object's true class is the
class of which the object is an instance.

The first thing the dispatcher does when it processes an [OM_NEW](../Libraries_Manual_guide/node0211.html#line20) message is
pass the OM_NEW message on to its superclass's dispatcher. It does this
using the amiga.lib function [DoSuperMethodA()](../Includes_and_Autodocs_2._guide/node0159.html):


```c
    ULONG DoSuperMethodA(Class *cl, Object *trueclass, Msg msg);
```
Each dispatcher passes control to its superclass.  Eventually the message
will arrive at the [rootclass](../Libraries_Manual_guide/node0200.html#line50) dispatcher.  The [OM_NEW](../Libraries_Manual_guide/node0211.html#line20) method in the
rootclass dispatcher looks at the object's true class (trueclass from the
prototype) to find out which class dispatcher is trying to create a new
object.  Note that trueclass is not necessarily the same as the current
dispatcher's class (cl from the [dispatchRKMModel()](../Libraries_Manual_guide/node0211.html) prototype above),
although this would be the case if the object's true class is a subclass
of the current dispatcher's class.

The [rootclass](../Libraries_Manual_guide/node0200.html#line50) dispatcher uses the true class to find out how much memory
to allocate for the object's instance data.  Each class keeps a record of
how much memory its local instance data requires.  The rootclass
dispatcher also looks at each class between the true class and rootclass
to find out much memory the local instance data for those classes require.
The rootclass dispatcher totals the amount of local instance data memory
needed by the true class and each of its superclasses and allocates that
much memory.

If all goes well, the [rootclass](../Libraries_Manual_guide/node0200.html#line50) dispatcher increments a private field in
the true class that keeps track of how many instances of the true class
there currently are.  It then returns a pointer to the newly created
object and passes control back to the subclass dispatcher that called it,
which is [icclass](../Libraries_Manual_guide/node0200.html#line55) in the case of [rkmmodelclass](../Libraries_Manual_guide/node020F.html).  If there was a problem,
the rootclass dispatcher does not increment the object count and passes
back a NULL.

When the [rootclass](../Libraries_Manual_guide/node0200.html#line50) dispatcher returns, the [icclass](../Libraries_Manual_guide/node0200.html#line55) dispatcher regains
control from [DoSuperMethodA()](../Includes_and_Autodocs_2._guide/node0159.html).  DoSuperMethodA() will return either a
pointer to the new object or else it returns NULL if there was an error.
Although the rootclass dispatcher allocated all the memory the object
needs, it only initialized the instance data local to rootclass. Now it's
the icclass dispatcher's turn to do some work.  It has to initialize the
instance data that is local to icclass.

A dispatcher finds its local instance data by using the INST_DATA() macro
(defined in <intuition/[classes.h](../Includes_and_Autodocs_2._guide/node00DA.html#line46)>):

   void *INST_DATA(Class *localclass, Object *object);

INST_DATA() takes two arguments, a pointer to a class and a pointer to the
object.  The INST_DATA() macro returns a pointer to the instance data
local to localclass.  When the [icclass](../Libraries_Manual_guide/node0200.html#line55) dispatcher was called, it received
three arguments, one of which was a pointer to the local class (icclass).
The icclass dispatcher passes this pointer and the new object pointer it
got from [DoSuperMethodA()](../Includes_and_Autodocs_2._guide/node0159.html) to INST_DATA() to get a pointer to the instance
data local to icclass.

After initializing its local instance data, the [icclass](../Libraries_Manual_guide/node0200.html#line55) dispatcher passes
control back to the [modelclass](../Libraries_Manual_guide/node020D.html#line13) dispatcher, which in turn, initializes the
instance data local to modelclass.  Finally, the [rkmmodelclass](../Libraries_Manual_guide/node020F.html) dispatcher
regains control and now has to take care of its local instance data.

To find its local instance data, the [rkmmodelclass](../Libraries_Manual_guide/node020F.html) dispatcher needs a
pointer to its Class and a pointer to the new object.  The dispatcher
function gets its Class pointer as its first argument (cl from the
[dispatchRKMModel()](../Libraries_Manual_guide/node0211.html) prototype above).  It gets the new object pointer as
the return value from [DoSuperMethodA()](../Includes_and_Autodocs_2._guide/node0159.html).  In this case, INST_DATA() returns
a pointer to an [RKMModData](../Libraries_Manual_guide/node0210.html#line18) structure.

Now the dispatcher has to initialize its local instance data.  It has to
scan through the tag list passed in the [OM_NEW](../Libraries_Manual_guide/node0211.html#line20) message looking for initial
values for the [RKMMOD_CurrVal](../Libraries_Manual_guide/node020F.html) and [RKMMOD_Limit](../Libraries_Manual_guide/node0210.html) attributes. As an
alternative, the dispatcher's OM_NEW method can use its [OM_SET](../Libraries_Manual_guide/node0211.html#line28) method to
handle initializing these "settable" attributes.

Finally, the dispatcher can return.  When the dispatcher returns from an
[OM_NEW](../Libraries_Manual_guide/node0211.html#line20) method, it returns a pointer to the new object.

If the [OM_NEW](../Libraries_Manual_guide/node0211.html#line20) method fails, it should tell the partially initialized
object it got from its superclass's dispatcher to dispose of itself (using
[OM_DISPOSE](../Libraries_Manual_guide/node0211.html#line24)) and return NULL.

