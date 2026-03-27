# bullet.library/CloseEngine



    NAME
	CloseEngine -- Release an engine handle

    SYNOPSIS
	CloseEngine(engineHandle)
	            A0

	void CloseEngine(struct [GlyphEngine](../Includes_and_Autodocs_3._guide/node0613.html#line25) *);

    FUNCTION
	This function releases the engine handle acquired with
	[OpenEngine](../Includes_and_Autodocs_3._guide/node0088.html).  It first releases any data acquired with
	[ObtainInfoA](../Includes_and_Autodocs_3._guide/node0087.html) associated with the engineHandle that has not yet
	been released.

    INPUTS
	engineHandle -- the handle acquired via [OpenEngine](../Includes_and_Autodocs_3._guide/node0088.html).  If zero,
		no operation is performed.

    RESULT
	This function has no result.  The only error that can occur is
	when the when an invalid engineHandle is supplied: the
	application is assumed not to do that.

    EXAMPLE
	EndGame(code, arg1, arg2, arg3, arg3)
	{
	    ...
	    CloseEngine(EngineHandle);
	    ...
	}

    SEE ALSO
	[OpenEngine()](../Includes_and_Autodocs_3._guide/node0088.html)

