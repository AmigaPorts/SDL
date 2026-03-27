# 28 / / Simple Sprite Functions / Controlling Sprite DMA


Two additional functions used with Simple Sprites are the graphics library
macros ON_SPRITE and OFF_SPRITE.  These macros can be used to control
sprite DMA.  OFF_SPRITE prevents the system from displaying any sprites,
whether Simple Sprites or VSprites. ON_SPRITE restores the sprite display.


    Be Careful With OFF_SPRITE.
    ---------------------------
    The Intuition mouse pointer is a sprite.  Thus, if OFF_SPRITE is
    used, Intuition's pointer will disappear too.  Use care when calling
    OFF_SPRITE. The macro turns off sprite fetch DMA, so that no new
    sprite data is fetched. Whatever sprite data was last being displayed
    at this point will continue to be displayed for every line on the
    screen.  This may lead to a vertical color bar if a sprite is being
    displayed when OFF_SPRITE is called.
