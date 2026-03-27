---
title: Boopsi Rootclass Methods
manual: amiga-mail
chapter: amiga-mail
section: boopsi-rootclass-methods
functions: []
libraries: []
---

# Boopsi Rootclass Methods

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Since all classes should be subclasses of some class, with the exception
of rootclass, all classes you write will be subclasses--perhaps indirectly
so--of rootclass.  Because of this, your class must either implement the
rootclass methods or defer processing of these methods to the superclass
(as DispatchmyTextLabel() did).  Provided below are brief descriptions of
the rootclass methods.  Remember that any message unrecognized by a class
dispatcher should be passed to the superclass (using the amiga.lib
functions DSM() or DoSuperMethod() ).

The rootclass method IDs that a subclass of imageclass needs to understand
are:

	OM_NEW			Create a new object.
	OM_DISPOSE		Delete an object.
	OM_SET			Change an object's attributes.
	OM_GET			Retrieve the value of one of the object's attributes.

The dispatcher should pass other rootclass methods on to the superclass.

Each method requires one or more parameters.  The MethodID is the only
common parameter for each method.

 [OM_NEW](amiga-mail/om-new.md)      [OM_DISPOSE](amiga-mail/om-dispose.md)      [OM_SET](amiga-mail/om-set.md)      [OM_GET](amiga-mail/om-get.md) 

