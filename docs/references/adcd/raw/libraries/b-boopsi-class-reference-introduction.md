# B Boopsi Class Reference / Introduction


There are 14 public classes built into the Release 2.04 ROM:


```c
                            [rootclass](../Libraries_Manual_guide/node04BB.html)
                               /
                 _____________/____________
                /         /                \
               /         /                  \
           [icclass](../Libraries_Manual_guide/node04C6.html)      /                [gadgetclass](../Libraries_Manual_guide/node04F2.html)
             /         /                      \
            /         /         _______________\___________________
           /     [imageclass](../Libraries_Manual_guide/node04D1.html)    /           /         \             \
          /         /         /           /           \             \
     [modelclass](../Libraries_Manual_guide/node04CC.html)    /      [propgclass](../Libraries_Manual_guide/node0507.html)  [strgclass](../Libraries_Manual_guide/node0510.html)  [buttongclass](../Libraries_Manual_guide/node051F.html)  [groupgclass](../Libraries_Manual_guide/node052B.html)
                  /                                     \
                 /                                       \
         _______/___________________________        [frbuttongclass](../Libraries_Manual_guide/node0524.html)
        /         \            \            \
       /           \            \            \
```
  [frameiclass](../Libraries_Manual_guide/node04DF.html)  [sysiclass](../Libraries_Manual_guide/node04E7.html)  [fillrectclass](../Libraries_Manual_guide/node04EB.html)  [itexticlass](../Libraries_Manual_guide/node04F0.html)


This appendix documents all the standard Boopsi classes, including their
methods and attributes.

Each class entry in this document can have two sets of methods: new
methods that the class defines and inherited methods that the class has
modified significantly.  Similarly, each class entry can have two sets of
attributes: those that the class defines and those that the class
inherited and modified.  Unless documented otherwise,  all classes inherit
all of its superclass's methods and attributes.

Each method has a Boopsi message associated with it.  These messages are
in the form of C structures.  Many methods use the default message
structure:


```c
    typedef struct
    {
        ULONG MethodID;
    } *Msg;
```
Some methods require a customized message so they can pass other
parameters besides the Method ID.  If a method requires a custom message,
its custom message structure is documented along with the method.

All methods have to return some sort of return value.  The meaning of the
return value depends on the class and method.  Normally a return value of
zero indicates that either the method failed or it is not supported by the
class.  A method can use the return value to return a pointer to an
object.  If a class does not directly support a particular method, the
class's dispatcher should pass the method on to its superclass for
processing.  The class dispatcher should record the return value it gets
from its superclass and use that as its return value.  Methods that assign
no meaning to their return value can return 1L to indicate that the method
is implemented.

The description of each attribute contains a code which lists the
[rootclass](../Libraries_Manual_guide/node04BB.html) methods that apply to that attribute:


```c
    I  [OM_NEW](../Libraries_Manual_guide/node04BC.html)     Attribute can be set at initialization
    S  [OM_SET](../Libraries_Manual_guide/node04C3.html)     Attribute can be set with OM_SET method
    G  [OM_GET](../Libraries_Manual_guide/node04C2.html)     Attribute can be read with OM_GET method
    N  [OM_NOTIFY](../Libraries_Manual_guide/node04C5.html)  Changing the attribute triggers object to send
                  notifications
    U  [OM_UPDATE](../Libraries_Manual_guide/node04C4.html)  Attribute can be set with OM_UPDATE method
```
For example, the [itexticlass](../Libraries_Manual_guide/node04F0.html) attribute [IA_Left](../Libraries_Manual_guide/node04DB.html) has the code (ISG) after
it.  This means an application can set IA_Left when it creates an instance
of itexticlass ([OM_NEW](../Libraries_Manual_guide/node04BC.html)) and when it uses the OM_SET method.  The
application can also ask an itexticlass object what the IA_Left value is,
using the [OM_GET](../Libraries_Manual_guide/node04C2.html) method.

The [OM_NEW](../Libraries_Manual_guide/node04BC.html), [OM_SET](../Libraries_Manual_guide/node04C3.html), [OM_NOTIFY](../Libraries_Manual_guide/node04C5.html), and [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) messages all contain a
pointer to a tag list.  This tag list contains the attributes and
corresponding values that the method affects.  Each [TagItem](../Libraries_Manual_guide/node0497.html) in this list
makes up an attribute/value pair.  The [ti_Tag](../Libraries_Manual_guide/node0497.html) portion of the TagItem
contains the attribute's ID while the [ti_Data](../Libraries_Manual_guide/node0497.html) field contains the
attribute's value.  Note that these tag lists can also contain
utility.library Global System control tags (like [TAG_SKIP](../Libraries_Manual_guide/node0498.html#line8) and [TAG_DONE](../Libraries_Manual_guide/node0498.html#line8)),
so dispatchers should use the tag functions from utility.library to
process these lists.  See documentation on the [Utility](../Libraries_Manual_guide/node0495.html) library for more
information.

All methods are called via a class dispatcher:


```c
    classDispatcher(Class *class, Object *object, Msg msg);
```
The first argument, class, is a pointer to the dispatcher's Class
structure (defined in <intuition/[classes.h](../Includes_and_Autodocs_2._guide/node00DA.html#line22)>).  The second parameter,
object, is a pointer to the Boopsi object to which the Boopsi message (the
third argument, msg) refers.  Both [Object](../Includes_and_Autodocs_2._guide/node00E2.html#line19) and [Msg](../Includes_and_Autodocs_2._guide/node00E2.html#line30) are defined in
<intuition/[classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html)>.

