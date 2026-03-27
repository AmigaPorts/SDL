---
title: B / rootclass / New Methods: OM_NOTIFY
manual: libraries
chapter: libraries
section: b-rootclass-new-methods-om-notify
functions: []
libraries: []
---

# B / rootclass / New Methods: OM_NOTIFY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method tells an object to broadcast an attribute change to a set of
target objects using [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) messages.  The return value for this method
is not explicitly defined.

The OM_NOTIFY method uses the same message structure as [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md).

Most dispatchers do not handle the OM_NOTIFY message directly.  Normally
they inherit this method from a superclass, so they pass the OM_NOTIFY
message on to the superclass dispatcher.

Although most dispatchers don't have to process OM_NOTIFY messages, most
do have to send them.  Whenever an object receives an [OM_SET](libraries/b-rootclass-new-methods-om-set.md) or [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md)
about one of its attributes, it may need to notify other objects of the
change.  For example, when a prop gadget's [PGA_Top](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md) value changes, its
target object(s) need to hear about it.

If an object needs to notify other objects about a change to one or more
of its attributes, it sends itself an OM_NOTIFY message.  The OM_NOTIFY
message will eventually end up in the hands of a superclass that
understands OM_NOTIFY and it will send [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) messages to the target
objects.

