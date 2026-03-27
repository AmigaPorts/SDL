# B / rootclass / New Methods: OM_DISPOSE


This method instructs an object to delete itself.  The [rootclass](../Libraries_Manual_guide/node04BB.html)
dispatcher's OM_DISPOSE method decrements the true class's internal count
of instances of true class.  The return value for this method is not
explicitly defined.

This method uses the default Boopsi message.

Applications should not call this method directly.  Instead they should
use the intuition.library function [DisposeObject()](../Libraries_Manual_guide/node0204.html).

For the OM_DISPOSE method, an object should do the following:

Free any additional resources the object explicitly allocated itself in
the [OM_NEW](../Libraries_Manual_guide/node04BC.html) method (this does not include the instance data).

Pass the message up to the superclass, which will eventually reach
[rootclass](../Libraries_Manual_guide/node04BB.html), which will free the instance data allocated for the object.

If a class does not allocate any extra resources when it creates an
object, it can defer all OM_DISPOSE processing to its superclass.

