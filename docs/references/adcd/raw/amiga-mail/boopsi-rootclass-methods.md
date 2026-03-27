# Boopsi Rootclass Methods


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

 [OM_NEW](../AmigaMail_Vol2_guide/node00A3.html)      [OM_DISPOSE](../AmigaMail_Vol2_guide/node00A4.html)      [OM_SET](../AmigaMail_Vol2_guide/node00A5.html)      [OM_GET](../AmigaMail_Vol2_guide/node00A6.html) 

