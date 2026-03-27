# bullet.library/OpenEngine



    NAME
	OpenEngine -- Acquire engine handle

    SYNOPSIS
	engineHandle = OpenEngine()

	struct [GlyphEngine](../Includes_and_Autodocs_3._guide/node0613.html#line25) *OpenEngine(void)

    FUNCTION
	This function establishes a context for access to the bullet
	library.  This context remains valid until it is closed via
	[CloseEngine](../Includes_and_Autodocs_3._guide/node0086.html).  Each specific context isolates the specification
	of the various font attributes from other contexts concurrently
	accessing the bullet library.  A context can be shared among
	different tasks.

    RESULT
	This function returns an engineHandle, or NULL if for some
	reason no engineHandle can be created.

    EXAMPLE
	    BulletBase = OpenLibrary("bullet.library", 0);
	    if (!BulletBase)
		EndGame(ERROR_LibOpen, "bullet.library", 0);
	    EngineHandle = OpenEngine();
	    if (!EngineHandle)
		EndGame(ERROR_InternalCall, "OpenEngine");

    SEE ALSO
	[CloseEngine()](../Includes_and_Autodocs_3._guide/node0086.html)

