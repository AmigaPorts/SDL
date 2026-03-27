# commodities.library/DeleteCxObj



   NAME
	DeleteCxObj -- delete a commmodity object. (V36)

   SYNOPSIS
	DeleteCxObj(co);
	            A0

	VOID DeleteCxObj(CxObj *);

   FUNCTION
	Deletes a commodity object of any type. If the object
	is linked into a list, it is first removed. Note that
	the handle 'co' is invalid after this function is called.

	Also note that deleting an object which has other objects attached
	to it may be undesirable. Use the function [DeleteCxObjAll()](../Includes_and_Autodocs_3._guide/node00EC.html)
	to delete an entire sub-tree of objects.

   INPUTS
	co - the commodity object to delete (may be NULL)

   SEE ALSO
	[DeleteCxObjAll()](../Includes_and_Autodocs_3._guide/node00EC.html)

