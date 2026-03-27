# graphics.library/InitArea



   NAME   

	InitArea -- Initialize vector collection matrix

   SYNOPSIS

   	InitArea( areainfo, buffer, maxvectors )
		    a0          a1      d0

	void InitArea(struct [AreaInfo](../Includes_and_Autodocs_3._guide/node05D7.html#line20) *, void *, SHORT);

   FUNCTION
	This function provides initialization for the vector collection matrix
	such that it has a size of (max vectors ).  The size of the region
	pointed to by buffer (short pointer) should be five (5) times as large
	as maxvectors. This size is in bytes.  Areafills done by using [AreaMove](../Includes_and_Autodocs_3._guide/node02AB.html),
	[AreaDraw](../Includes_and_Autodocs_3._guide/node02A8.html), and [AreaEnd](../Includes_and_Autodocs_3._guide/node02AA.html) must have enough space allocated in this table to
	store all the points of the largest fill. [AreaEllipse](../Includes_and_Autodocs_3._guide/node02A9.html) takes up two
	vectors for every call. If AreaMove/Draw/Ellipse detect too many
	vectors going into the buffer they will return -1.

   INPUTS
	areainfo - pointer to [AreaInfo](../Includes_and_Autodocs_3._guide/node05D7.html#line20) structure
	buffer - pointer to chunk of memory to collect vertices
	maxvectors - max number of vectors this buffer can hold

   RESULT
	Pointers are set up to begin storage of vectors done by
	[AreaMove](../Includes_and_Autodocs_3._guide/node02AB.html), [AreaDraw](../Includes_and_Autodocs_3._guide/node02A8.html), and [AreaEllipse](../Includes_and_Autodocs_3._guide/node02A9.html).

   BUGS

   SEE ALSO
	[AreaEnd()](../Includes_and_Autodocs_3._guide/node02AA.html) [AreaMove()](../Includes_and_Autodocs_3._guide/node02AB.html) [AreaDraw()](../Includes_and_Autodocs_3._guide/node02A8.html) [AreaEllipse()](../Includes_and_Autodocs_3._guide/node02A9.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

