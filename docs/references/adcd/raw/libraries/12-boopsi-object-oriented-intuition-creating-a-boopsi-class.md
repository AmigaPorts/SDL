# 12 Boopsi--Object Oriented Intuition / Creating a Boopsi Class


So far this chapter has only hinted at what is possible with Boopsi. Its
power lies in its extensibility.  Boopsi grants the application programmer
the power to add custom features to existing classes.  If an existing
class comes close to your needs, you can build on that class so it does
exactly what you want.  If you want a class that is unlike an existing
class, you can create it.

The heart of a Boopsi class is its method Dispatcher function. According
to the OOP metaphor, when an application wants a Boopsi object to perform
a method, it sends the object a message.  In reality, that object is only
a data structure, so it does not have the power to do anything.  When an
object receives a Boopsi message, a Boopsi message structure is passed to
the dispatcher of that object's class.  The dispatcher examines the
message and figures out what to do about it.

For example, when an application calls [SetGadgetAttrs()](../Libraries_Manual_guide/node0205.html#line5) on an integer
gadget:


```c
    SetGadgetAttrs(myintegergadget, mywindow, NULL,
                   STRINGA_LongVal, 75L,
                   GA_ID,           2L,
                   TAG_END));
```
the [SetGadgetAttrs()](../Libraries_Manual_guide/node0205.html#line5) function calls the [strgclass](../Libraries_Manual_guide/node020A.html#line7) dispatcher.  A Boopsi
dispatcher receives three arguments: a pointer to the dispatcher's Class
(defined in <intuition/[classes.h](../Includes_and_Autodocs_2._guide/node00DA.html)>), a pointer to the object that is going
to perform the method, and a pointer to the Boopsi message.  In this case,
the SetGadgetAttrs() function builds an [OM_SET](../Libraries_Manual_guide/node0211.html#line28) message, finds the
strgclass dispatcher, and "sends" the dispatcher the OM_SET message.
SetGadgetAttrs() can find the dispatcher because an object contains a
reference to its dispatcher.

When the dispatcher function "gets" the message, it examines the message
to find out its corresponding method.  In this case, the dispatcher
recognizes the message as an [OM_SET](../Libraries_Manual_guide/node0211.html#line28) message and proceeds to set
myintegergadget's attributes.

An [OM_SET](../Libraries_Manual_guide/node0211.html#line28) message looks like this (defined in <intuition/[classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html#line76)>):


```c
    struct opSet {
        ULONG MethodID;               /* This will be set to OM_SET      */
        struct TagItem *ops_AttrList; /* A tag list containing the       */
                                      /*     attribute/value pairs of    */
                                      /*     the attributes to set.      */
        struct GadgetInfo *ops_GInfo; /* Special information for gadgets */
    }
```
The [OM_SET](../Libraries_Manual_guide/node0211.html#line28) message contains a pointer to a tag list in ops_AttrList that
looks like this:


```c
    {STRINGA_LongVal, 75L},
    {GA_ID, 2L},
    {TAG_END,}
```
The [strgclass](../Libraries_Manual_guide/node020A.html#line7) dispatcher scans through this tag list and recognizes the
[STRINGA_LongVal](../Libraries_Manual_guide/node0512.html) attribute.  The dispatcher sets myintegergadget's internal
STRINGA_LongVal value to the corresponding value (75L) from the
attribute/value pair.

The [strgclass](../Libraries_Manual_guide/node020A.html#line7) dispatcher continues to scan through the tag list.  When it
finds [GA_ID](../Libraries_Manual_guide/node0501.html), it does not process it like [STRINGA_LongVal](../Libraries_Manual_guide/node0512.html).  The strgclass
dispatcher's [OM_SET](../Libraries_Manual_guide/node0211.html#line28) method does not recognize the GA_ID attribute because
strgclass inherited the GA_ID attribute from [gadgetclass](../Libraries_Manual_guide/node020A.html).  To handle
setting the GA_ID attribute, the strgclass dispatcher passes on the OM_SET
message to its superclass's dispatcher.  The strgclass dispatcher passes
control to the gadgetclass dispatcher, which knows about the GA_ID
attribute.

 [Building On Existing Public Classes](../Libraries_Manual_guide/node020F.html) 
 [Writing the Dispatcher](../Libraries_Manual_guide/node0211.html) 
 [White Boxes - The Transparent Base Classes](../Libraries_Manual_guide/node0217.html) 

