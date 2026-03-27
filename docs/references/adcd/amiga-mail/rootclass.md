---
title: rootclass
manual: amiga-mail
chapter: amiga-mail
section: rootclass
functions: [NextObject]
libraries: [intuition.library]
---

# rootclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  rootclass
Superclass:             None
Description:            Base class for all other classes
Include File:           <intuition/classusr.h>


New Methods:
------------

OM_NEW - Create a new object.  This method is passed a pointer to the
"true class" of the object in place of the yet to be created object.
The Root class will allocate enough memory for all the instance data of
the true class.


OM_DISPOSE - Delete an object.  This method will free the same amount of
memory as allocated by OM_NEW.


OM_ADDTAIL - Add an object to an Exec list, based on a MinNode in the
private rootclass object header.  You can provide any Exec list you
want, and iterate the objects on the list using the Intuition function
NextObject().


OM_REMOVE  - Remove an object from an Exec list.


The following methods are defined for all objects, but are no-ops in the
rootclass.  Implementation for specific subclasses is done to support
these conventions.


OM_ADDMEMBER - Add some object (passed to the method) to the objects
list, which is defined by the class.  Examples include the broadcast
list of modelclass objects, and the component gadgets of a groupgclass
object.  This is typically implemented by sending the OM_ADDTAIL message
to the member object.


OM_REMMEMBER - Remove a member object previously added by OM_ADDMEMBER.
You typically send the OM_REMOVE message to the member object.


OM_SET - Set attributes from passed attribute list.  The Root class
defines no attributes.


OM_GET - Retrieve an attribute.


OM_UPDATE - "Be updated" of external changes.  A no-op for rootclass.


OM_NOTIFY - Notify other of changes provided in the message.  A no-op
for the root class.


Changed Methods:
----------------

Not applicable.


Attributes:
-----------

None.

---

## See Also

- [NextObject — intuition.library](../autodocs/intuition.library.md#nextobject)
