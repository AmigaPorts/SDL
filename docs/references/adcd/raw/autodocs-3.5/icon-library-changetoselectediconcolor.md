# icon.library/ChangeToSelectedIconColor



   NAME
	ChangeToSelectedIconColor -- Modify an RGB colour value for use in
	    a selected icon image (V44)

   SYNOPSIS
	ChangeToSelectedIconColor(cr)
	                          A0

	VOID ChangeToSelectedIconColor(struct [ColorRegister](../Includes_and_Autodocs_3._guide/node05DD.html#line223) *cr);

   FUNCTION
	This function will change the provided RGB colour value to make it
	suitable for use in an icon's select image. This may involve darkening
	or toning the colour. Usually, icon.library calls this function
	when creating a select image for palette mapped icons which do not
	contain "real" select images.

   INPUTS
	cr -- Pointer to a [ColorRegister](../Includes_and_Autodocs_3._guide/node05DD.html#line223), containing the RGB colour value
	    to be changed.

