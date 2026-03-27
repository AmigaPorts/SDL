# graphics.library/ChangeSprite



   NAME

       ChangeSprite -- Change the sprite image pointer.
   SYNOPSIS

```c
       ChangeSprite( vp, s, newdata)
                     a0  a1   a2
```
	void ChangeSprite(struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *, struct [SimpleSprite](../Includes_and_Autodocs_3._guide/node060B.html#line18) *, void * )

   FUNCTION 
	The sprite image is changed to use the data starting at newdata

   INPUTS
```c
       vp - pointer to [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure that this sprite is
```
		  relative to,  or 0 if relative only top of [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63)
	s - pointer to [SimpleSprite](../Includes_and_Autodocs_3._guide/node060B.html#line18) structure
	newdata	- pointer to data structure of the following form.
		struct spriteimage
		{
		    [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43)    posctl[2];	/* used by simple sprite machine*/
		    [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43)    data[height][2];   /* actual sprite image */
		    [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43)    reserved[2];	/* initialized to */
			                             /*  0x0,0x0 */
		};
	The programmer must initialize reserved[2].  Spriteimage must be
	in CHIP memory. The height subfield of the [SimpleSprite](../Includes_and_Autodocs_3._guide/node060B.html#line18) structure
	must be set to reflect the height of the new spriteimage BEFORE
	calling ChangeSprite(). The programmer may allocate two sprites to
	handle a single attached sprite.  After [GetSprite()](../Includes_and_Autodocs_3._guide/node02EC.html), ChangeSprite(),
	the programmer can set the SPRITE_ATTACHED bit in posctl[1] of the
	odd numbered sprite.
	If you need more than 8 sprites, look up VSprites in the
	graphics documentation.

   RESULTS 

   BUGS 

   SEE ALSO
	[FreeSprite()](../Includes_and_Autodocs_3._guide/node02DD.html) ChangeSprite() [MoveSprite()](../Includes_and_Autodocs_3._guide/node0302.html) [AddVSprite()](../Includes_and_Autodocs_3._guide/node029F.html) [graphics/sprite.h](../Includes_and_Autodocs_3._guide/node060B.html)

