# 4 Sprite Hardware / What are Sprites?


Sprites are graphic objects that are created and moved independently of
the playfield display and independently of each other. Together with
playfields, sprites form the graphics display of the Amiga.  You can
create more complex  [animation](../Hardware_Manual_guide/node011D.html#line45)  effects by using the blitter, which is
described in the chapter called "Blitter Hardware." Sprites are produced
on-screen by eight special-purpose sprite  [DMA channels](../Hardware_Manual_guide/node00BF.html) . Basic sprites
are 16 pixels wide and any number of lines high. You can choose from three
colors for a sprite's pixels, and a pixel may also be transparent, showing
any object behind the sprite. For larger or more complex objects, or for
more color choices, you can  [combine sprites](../Hardware_Manual_guide/node00C6.html) .

Sprite DMA channels can be  [reused](../Hardware_Manual_guide/node00C4.html)  several times within the same display
field. Thus, you are not limited to having only eight sprites on the
screen at the same time.

