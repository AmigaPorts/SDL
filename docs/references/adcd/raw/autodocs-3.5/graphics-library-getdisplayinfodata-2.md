# graphics.library/GetDisplayInfoData



   NAME
	GetDisplayInfoData -- query [DisplayInfo](../Includes_and_Autodocs_3._guide/node05FF.html#line52) Record parameters (V36)

   SYNOPSIS
	result = GetDisplayInfoData(handle, buf, size, tagID, [ID])
	D0                          A0      A1   D0    D1     [D2]

	ULONG GetDisplayInfoData(DisplayInfoHandle, [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *, ULONG, ULONG, ULONG);

   FUNCTION
	GetDisplayInfoData() fills a buffer with data meaningful to the
	DisplayInfoRecord pointed at by your valid handle. The data type
	that you are interested in is indicated by a tagID for that chunk.
	The types of tagged information that may be available include:

	DTAG_DISP: (DisplayInfo)   - properties and availability information.
	DTAG_DIMS: (DimensionInfo) - default dimensions and overscan info.
	DTAG_MNTR: (MonitorInfo)   - type, position, scanrate, and compatibility
	DTAG_NAME: (NameInfo)      - a user friendly way to refer to this mode.

   INPUTS
	handle - displayinfo handle
	buf    - pointer to destination buffer
	size   - buffer size in bytes
	tagID  - data chunk type
	ID     - displayinfo identifier, optionally used if handle is NULL

   RESULT
	result - if positive, number of bytes actually transferred
	         if zero, no information for ID was available

   BUGS

   SEE ALSO
	[FindDisplayInfo()](../Includes_and_Autodocs_3._guide/node02D3.html), [NextDisplayInfo()](../Includes_and_Autodocs_3._guide/node0305.html)
	[graphics/displayinfo.h](../Includes_and_Autodocs_3._guide/node05FF.html)

