# 12 / Creating a Boopsi Class / Writing the Dispatcher


The C prototype for a Boopsi dispatcher looks like this:


```c
    ULONG dispatchRKMModel(Class *cl, Object *recvobject, Msg msg);
```
where cl points to the Class (defined in <intuition/[classes.h](../Includes_and_Autodocs_2._guide/node00DA.html)>) of the
dispatcher, recvobject points to the object that received the message, and
msg is that Boopsi message.  The format of the message varies according to
the method.  The default Boopsi message is an Msg (from
<intuition/[classusr.h](../Includes_and_Autodocs_2._guide/node00E2.html#line24)>):


```c
    typedef struct {
        ULONG MethodID;
    } *Msg;
```
Boopsi methods that require parameters use custom message structures. The
first field of any message structure is always the method's methodID.
This makes custom messages look like an Msg.  The dispatcher looks at an
incoming message's first field to tell what its method is.  [Rkmmodelclass](../Libraries_Manual_guide/node020F.html)
objects respond to several [rootclass](../Libraries_Manual_guide/node0200.html#line50) methods:

[OM_NEW](../Libraries_Manual_guide/node04BC.html)

```c
    This method creates a new [rkmmodelclass](../Libraries_Manual_guide/node020F.html) object.  It uses an [opSet](../Libraries_Manual_guide/node0211.html)
    structure as its Boopsi message.
```
[OM_DISPOSE](../Libraries_Manual_guide/node04BD.html)

    This method tells an object to dispose of itself.  It uses an Msg as
    its Boopsi message.
[OM_SET](../Libraries_Manual_guide/node04C3.html)

```c
    This method tells an object to set one or more of its attribute
    values.  It uses an [opSet](../Libraries_Manual_guide/node020E.html#line37) structure as its Boopsi message.
```
[OM_UPDATE](../Libraries_Manual_guide/node04C4.html)

```c
    This method tells an object to update one or more of its attribute
    values.  It uses an [opUpdate](../Libraries_Manual_guide/node0213.html#line14) structure as its Boopsi message.
```
[OM_GET](../Libraries_Manual_guide/node04C2.html)

```c
    This method tells an object to report an attribute value.  It uses an
    [opGet](../Libraries_Manual_guide/node0214.html) structure as its Boopsi message.
```
[OM_ADDTAIL](../Libraries_Manual_guide/node04BE.html)

```c
    This method tells an object to add itself to the end of an Exec list.
    It uses an [opAddTail](../Includes_and_Autodocs_2._guide/node00E2.html#line115) structure as its Boopsi message.
```
[OM_REMOVE](../Libraries_Manual_guide/node04BF.html)

    This method tells an object to remove itself from an Exec list.  It
    uses an Msg as its Boopsi message.
[OM_ADDMEMBER](../Libraries_Manual_guide/node04C0.html)

```c
    This method tells an object to add an object to its broadcast list.
    It uses an [opMember](../Libraries_Manual_guide/node020D.html#line42) structure as its Boopsi message.
```
[OM_REMMEMBER](../Libraries_Manual_guide/node04C1.html)

```c
    This method tells an object to remove an object from its broadcast
    list.  It uses an [opMember](../Libraries_Manual_guide/node020D.html#line42) structure as its Boopsi message.
```
[OM_NOTIFY](../Libraries_Manual_guide/node04C5.html)

```c
    This method tells an object to broadcast an attribute change to its
    broadcast list.  It uses an [opSet](../Libraries_Manual_guide/node020E.html#line37) structure as its Boopsi message.
```
Of these, [rkmmodelclass](../Libraries_Manual_guide/node020F.html) has to process OM_NEW, OM_SET, OM_UPDATE, and
OM_GET.

 [OM_NEW](../Libraries_Manual_guide/node0212.html)              [OM_GET](../Libraries_Manual_guide/node0214.html)                  [RKMModel.c](../Libraries_Manual_guide/node0216.html) 
 [OM_SET/OM_UPDATE](../Libraries_Manual_guide/node0213.html)    [Making the New Class](../Libraries_Manual_guide/node0215.html) 

