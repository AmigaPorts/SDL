# intuition.library/FreeScreenBuffer



    NAME
	FreeScreenBuffer -- Free a [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) structure. (V39)

    SYNOPSIS
	FreeScreenBuffer( [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132), [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) )
	                  A0      A1

	VOID FreeScreenBuffer( struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, struct [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) * );

    FUNCTION
	Frees a [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) structure you got from [AllocScreenBuffer()](../Includes_and_Autodocs_3._guide/node0395.html),
	and releases associated resources.  You must call FreeScreenBuffer()
	before you close your screen.

    INPUTS
	Screen: pointer to the screen this [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) is associated with.
	ScreenBuffer: pointer to a [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) structure obtained from
	    [AllocScreenBuffer()](../Includes_and_Autodocs_3._guide/node0395.html).  It is safe to call this function with
	    a NULL argument.  It will have no effect.

    RESULT
	None.

    NOTES
	Originally, FreeScreenBuffer() did not [WaitBlit()](../Includes_and_Autodocs_3._guide/node0339.html) before freeing
	a [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).  The intent was that the application should do this.
	However, as this sort of thing is easily forgotten, [WaitBlit()](../Includes_and_Autodocs_3._guide/node0339.html)
	was added in V40.  Application writers should ensure that freeing
	the buffer is safe by calling [WaitBlit()](../Includes_and_Autodocs_3._guide/node0339.html) themselves.

	The SB_SCREEN_BITMAP flag instructs [AllocScreenBuffer()](../Includes_and_Autodocs_3._guide/node0395.html) to provide
	a [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) referring to the screen's actual bitmap.  When
	you are done changing screen buffers, you must FreeScreenBuffer()
	the currently-installed [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644) before you close the screen.
	Intuition will recognize when FreeScreenBuffer() is called for
	the currently-installed [ScreenBuffer](../Includes_and_Autodocs_3._guide/node0602.html#line644), and will know to free the
	supporting structures but not the [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).  [CloseScreen()](../Includes_and_Autodocs_3._guide/node039F.html) will
	take care of that.

    BUGS

    SEE ALSO
	[AllocScreenBuffer()](../Includes_and_Autodocs_3._guide/node0395.html), [ChangeScreenBuffer()](../Includes_and_Autodocs_3._guide/node039A.html),
	[graphics.library/ChangeVPBitMap()](../Includes_and_Autodocs_3._guide/node02BD.html)

