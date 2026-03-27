# 12 / OOP Overview / The Interconnection Classes


The [IDCMP_IDCMPUPDATE](../Libraries_Manual_guide/node01E1.html#line98) scheme presents a problem to an application that
wants to make gadgets talk to each other and talk to the application.
Boopsi gadgets only have one [ICA_TARGET](../Libraries_Manual_guide/node020B.html#line20).  One Boopsi gadget can talk to
either another Boopsi object or its window's IDCMP port, but not both.
Using this scheme alone would force the application to update the integer
value of the gadgets, which is what we are trying to avoid in the first
place.

One of the standard Boopsi classes, [icclass](../Libraries_Manual_guide/node0200.html#line55), is a class of information
forwarders.  An icclass object receives [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) messages from one object
and passes those messages on to its own [ICA_TARGET](../Libraries_Manual_guide/node04C9.html).  If it needs to map
any incoming attributes, it can use its own [ICA_MAP](../Libraries_Manual_guide/node04CA.html) to do so.

[Icclass](../Libraries_Manual_guide/node0200.html#line55) has a subclass called [modelclass](../Libraries_Manual_guide/node04CC.html).  Using a modelclass object, an
application can chain a series of these objects together to set up a
"broadcast list" of icclass objects.  The modelclass object is similar to
the icclass object in that it has its own [ICA_TARGET](../Libraries_Manual_guide/node04C9.html) and [ICA_MAP](../Libraries_Manual_guide/node04CA.html).  It
differs in that an application can use the modelclass [OM_ADDMEMBER](../Libraries_Manual_guide/node04CD.html) method
to add icclass objects to the modelclass object's broadcast list.

The [OM_ADDMEMBER](../Libraries_Manual_guide/node0211.html#line48) method is defined by [rootclass](../Libraries_Manual_guide/node0200.html#line50).  It adds one Boopsi
object to the personal list of another Boopsi object.  It is up to the
Boopsi object's class to determine the purpose of the objects in the list.
Unlike the other methods mentioned so far in this chapter, OM_ADDMEMBER
does not have an Intuition function equivalent.  To pass an OM_ADDMEMBER
message to an object use the amiga.lib function [DoMethodA()](../Includes_and_Autodocs_2._guide/node0157.html), or its
stack-based equivalent, [DoMethod()](../Includes_and_Autodocs_2._guide/node0156.html):


```c
    ULONG DoMethodA(Object *myobject, Msg boopsimessage);
    ULONG DoMethod(Object *myobject, ULONG methodID, ...);
```
The return value is class-dependent.  The first argument to both of these
functions points to the object that will receive the Boopsi message.

For [DoMethodA()](../Includes_and_Autodocs_2._guide/node0157.html), boopsimessage is the actual Boopsi message.  The layout
of it depends on the method.  Every method's message starts off with an
Msg (from <intuition/[classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html#line24)>):


```c
    typedef struct {
        ULONG MethodID; /* Method-specific data may follow this field */
    } *Msg;
```
The message that the [OM_ADDMEMBER](../Libraries_Manual_guide/node0211.html#line48) method uses looks like this (from
<intuition/[classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html#line121)>):


```c
    struct opMember {
        ULONG    MethodID;
        Object   *opam_Object;
    };
```
where MethodID is [OM_ADDMEMBER](../Libraries_Manual_guide/node0211.html#line48) and opam_Object points to the object to add
to myobject's list.

[DoMethod()](../Includes_and_Autodocs_2._guide/node0156.html) uses the stack to build a message.  To use DoMethod(), just
pass the elements of the method's message structure as arguments to
DoMethod() in the order that they appear in the structure.  For example,
to ask the Boopsi object myobject to add the object addobject to its
personal list:


```c
    DoMethod(myobject, OM_ADDMEMBER, addobject);
```
To rearrange [Talk2boopsi.c](../Libraries_Manual_guide/node0582.html) so that it uses a [modelclass](../Libraries_Manual_guide/node04CC.html) object (also known
as a model):

  * Create the integer and prop gadget.

  * Create the model.

  * Create two [icclass](../Libraries_Manual_guide/node0200.html#line55) objects, one called int2prop and the other called

    prop2int.
  * Make the model the [ICA_TARGET](../Libraries_Manual_guide/node020B.html#line20) of both the integer gadget and the prop

```c
    gadget.  The gadgets do not need an [ICA_MAP](../Libraries_Manual_guide/node020B.html#line63).
```
  * Using [DoMethod()](../Includes_and_Autodocs_2._guide/node0156.html) to call [OM_ADDMEMBER](../Libraries_Manual_guide/node0211.html#line48), add the [icclass](../Libraries_Manual_guide/node0200.html#line55) objects to the

    model's personal list.
  * Make the prop gadget the [ICA_TARGET](../Libraries_Manual_guide/node04C9.html) of int2prop.  Make the integer

    gadget the ICA_TARGET of prop2int.
  * Create an [ICA_MAP](../Libraries_Manual_guide/node04CA.html) map list for int2prop that maps [STRINGA_LongVal](../Libraries_Manual_guide/node0512.html) to

```c
    [PGA_Top](../Libraries_Manual_guide/node050F.html).  Create an ICA_MAP map list for prop2int that maps PGA_Top
    to STRINGA_LongVal.  Make the [ICA_TARGET](../Libraries_Manual_guide/node04C9.html) of the model [ICTARGET_IDCMP](../Libraries_Manual_guide/node020C.html#line38).
```
Diagrammatically, the new [Talk2boopsi.c](../Libraries_Manual_guide/node0582.html) should look something like this:


```c
     [Figure 12-4: ICC Diagram](../Libraries_Manual_guide/node05DE.html) 
```
When either of these gadgets has some interim state change (caused by the
user manipulating the gadgets), it sends an [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) message to its
[ICA_TARGET](../Libraries_Manual_guide/node04C9.html), which in this case is the [modelclass](../Libraries_Manual_guide/node04CC.html) object.  When this model
gets the message, it does two things.  It sends an [IDCMP_IDCMPUPDATE](../Libraries_Manual_guide/node01E1.html#line98) to
the IDCMP port of the gadget's window and it also sends OM_UPDATE messages
to all of the objects in its personal list.  When int2prop gets an
OM_UPDATE message, it forwards that message to its ICA_TARGET, the prop
gadget.  Similarly, when prop2int gets an OM_UPDATE message, it forwards
that message to its ICA_TARGET, the integer gadget.

Although in this case it isn't a problem, [icclass](../Libraries_Manual_guide/node0200.html#line55) and [modelclass](../Libraries_Manual_guide/node04CC.html) objects
contain loop inhibition capabilities.  If an icclass object (or modelclass
object) receives an [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) message, it forwards the message to its
target.  If somehow that forwarded message gets forwarded (or broadcast)
back to the icclass object, the icclass object ignores the message.  This
prevents the possibility of an infinite OM_UPDATE loop.

