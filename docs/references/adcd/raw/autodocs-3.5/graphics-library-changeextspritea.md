# graphics.library/ChangeExtSpriteA



   NAME

```c
       ChangeExtSpriteA -- Change the sprite image pointer. (V39)
```
   SYNOPSIS

```c
       ChangeExtSpriteA( vp, oldsprite, newsprite, tags)
                     	  a0  a1   	 a2	    a3
```
	success=ChangeExtSpriteA(struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *, struct [ExtSprite](../Includes_and_Autodocs_3._guide/node060B.html#line26) *,
			struct [ExtSprite](../Includes_and_Autodocs_3._guide/node060B.html#line26) *, struct TagList *);

	success=ChangeExtSprite(vp,old_sp,new_sp,tag,....);

   FUNCTION 
	Attempt to change which sprite is displayed for a given
	sprite engine.

   INPUTS
```c
       vp - pointer to [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure that this sprite is
```
		  relative to,  or 0 if relative only top of [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63)
	oldsprite - pointer the old [ExtSprite](../Includes_and_Autodocs_3._guide/node060B.html#line26) structure
	newsprite - pointer to the new [ExtSprite](../Includes_and_Autodocs_3._guide/node060B.html#line26) structure.

   RESULTS 
 	success - 0 if there was an error.
   BUGS 

   SEE ALSO
	[FreeSprite()](../Includes_and_Autodocs_3._guide/node02DD.html) [ChangeSprite()](../Includes_and_Autodocs_3._guide/node02BC.html) [MoveSprite()](../Includes_and_Autodocs_3._guide/node0302.html) [AllocSpriteDataA()](../Includes_and_Autodocs_3._guide/node02A3.html)
	[graphics/sprite.h](../Includes_and_Autodocs_3._guide/node060B.html)

