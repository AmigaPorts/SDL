# graphics.library/FreeSpriteData



   NAME
	FreeSpriteData -- free sprite data allocated by AllocSpriteData() (V39)

   SYNOPSIS
	FreeSpriteData(extsp)
			a2

	void FreeSpriteData(struct [ExtSprite](../Includes_and_Autodocs_3._guide/node060B.html#line26) *);


   FUNCTION

   INPUTS
	extsp - The extended sprite structure to be freed. Passing NULL is a
	NO-OP.

   SEE ALSO
	FreeSpriteData() [FreeSprite()](../Includes_and_Autodocs_3._guide/node02DD.html) [ChangeSprite()](../Includes_and_Autodocs_3._guide/node02BC.html) [MoveSprite()](../Includes_and_Autodocs_3._guide/node0302.html) GetExtSprite()
	[AllocBitMap()](../Includes_and_Autodocs_3._guide/node02A0.html) [graphics/sprite.h](../Includes_and_Autodocs_3._guide/node060B.html)

