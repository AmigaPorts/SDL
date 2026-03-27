# B / rootclass / New Methods: OM_NOTIFY


This method tells an object to broadcast an attribute change to a set of
target objects using [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) messages.  The return value for this method
is not explicitly defined.

The OM_NOTIFY method uses the same message structure as [OM_UPDATE](../Libraries_Manual_guide/node04C4.html).

Most dispatchers do not handle the OM_NOTIFY message directly.  Normally
they inherit this method from a superclass, so they pass the OM_NOTIFY
message on to the superclass dispatcher.

Although most dispatchers don't have to process OM_NOTIFY messages, most
do have to send them.  Whenever an object receives an [OM_SET](../Libraries_Manual_guide/node04C3.html) or [OM_UPDATE](../Libraries_Manual_guide/node04C4.html)
about one of its attributes, it may need to notify other objects of the
change.  For example, when a prop gadget's [PGA_Top](../Libraries_Manual_guide/node050F.html) value changes, its
target object(s) need to hear about it.

If an object needs to notify other objects about a change to one or more
of its attributes, it sends itself an OM_NOTIFY message.  The OM_NOTIFY
message will eventually end up in the hands of a superclass that
understands OM_NOTIFY and it will send [OM_UPDATE](../Libraries_Manual_guide/node04C4.html) messages to the target
objects.

