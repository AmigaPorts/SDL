# graphics.library/MoveSprite



   NAME
	MoveSprite -- [Move](../Includes_and_Autodocs_3._guide/node0301.html) sprite to a point relative to top of viewport.

   SYNOPSIS
	MoveSprite(vp, sprite, x, y)
	           A0  A1      D0 D1

	void MoveSprite(struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *,struct [SimpleSprite](../Includes_and_Autodocs_3._guide/node060B.html#line18) *, WORD, WORD);

   FUNCTION
	[Move](../Includes_and_Autodocs_3._guide/node0301.html) sprite image to new place on display.

   INPUTS
	vp - pointer to [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure
	     if vp = 0, sprite is positioned relative to [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63).
	sprite - pointer to [SimpleSprite](../Includes_and_Autodocs_3._guide/node060B.html#line18) structure
	(x,y)  - new position relative to top of viewport or view.

   RESULTS
	Calculate the hardware information for the sprite and
	place it in the posctldata array. During next video display
	the sprite will appear in new position.

   BUGS
	Sprites really appear one pixel to the left of the position you specify.
	This bug affects the apparent display position of the sprite on the
	screen,	but does not affect the numeric position relative to the
	viewport or view. This behaviour only applies to SimpleSprites,
	not to ExtSprites.


   SEE ALSO
	[FreeSprite()](../Includes_and_Autodocs_3._guide/node02DD.html)  [ChangeSprite()](../Includes_and_Autodocs_3._guide/node02BC.html)  [GetSprite()](../Includes_and_Autodocs_3._guide/node02EC.html)  [graphics/sprite.h](../Includes_and_Autodocs_3._guide/node060B.html)

