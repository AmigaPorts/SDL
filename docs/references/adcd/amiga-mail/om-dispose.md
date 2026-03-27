---
title: OM_DISPOSE
manual: amiga-mail
chapter: amiga-mail
section: om-dispose
functions: []
libraries: []
---

# OM_DISPOSE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The OM_DISPOSE method instructs the class to deallocate an object. This
method receives no parameters.

For the OM_DISPOSE method, the new class's dispatcher should do the
following:

1) Free any additional memory you allocated (memory allocated in step
   3 from OM_NEW).

2) Dispose of any objects that you created as components of your
   object (component objects created in step 3 from OM_NEW).

3) Pass the message up to the superclass, which will eventually reach
   rootclass, which will free the memory allocated for the object.

The mytextlabelclass example at the end of this article does not allocate
any extra resources when it creates an object.  Because it does not have
to release any resources, the mytextlabelclass dispatcher lets its
superclass handle the OM_DISPOSE method. Eventually, some superclass of
mytextlabelclass will deallocate all of the memory for the OM_DISPOSEd
object.

