# icon.library/NewDiskObject



   NAME
	NewDiskObject -- Create an empty icon (V44)

   SYNOPSIS
	icon = NewDiskObject(type)
	D0                   D0

	struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) * NewDiskObject(LONG type);

   FUNCTION
	This function is used to create an "empty" [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64)
	structure, which has no image data associated with it.
	Still, all the necessary structures are in place,
	you just have to fill them in.

   INPUTS
	type -- Icon type to create, this must be one of WBDISK,
	    WBDRAWER, WBTOOL, WBPROJECT, WBGARBAGE, WBDEVICE or WBKICK.

   RESULT
	icon -- Pointer to a struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) or NULL in case of error.
	    You can use [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) to retrieve the error code.

   NOTES
	The [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) returned by this function will have a zero
	width and height [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) in the do_Gadget.GadgetRender member
	and the do_Gadget.Width/do_Gadget.Height members will both
	be 0, too.

   SEE ALSO
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	[workbench/icon.h](../Includes_and_Autodocs_3._guide/node0618.html)
	[workbench/workbench.h](../Includes_and_Autodocs_3._guide/node05D6.html)

