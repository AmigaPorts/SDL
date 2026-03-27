# dos.library/Relabel



   NAME
	Relabel -- Change the volume name of a volume (V36)

   SYNOPSIS
	success = Relabel(volumename,name)
	D0                    D1      D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) Relabel(STRPTR,STRPTR)

   FUNCTION
	Changes the volumename of a volume, if supported by the filesystem.

   INPUTS
	volumename - Full name of device to rename (with ':')
	newname    - New name to apply to device (without ':')

   RESULT
	success    - Success/failure indicator

   SEE ALSO

