# C Enhanced Chip Set / ECS Hardware and the Graphics Library


The Enhanced Chip Set consists of compatible revisions to the Agnus and
Denise custom chips.  The V36 graphics.library software makes it possible
for these chips to display images in new resolutions, at new monitor scan
rates and with new sprite and genlock abilities.

With the enhanced Agnus, the V36 graphics.library supports the new
programmable scan rate registers to provide multi-sync and bi-sync monitor
capability. The new SuperHires mode provides 35ns pixel rates and sprite
positioning at 70ns rates.  Support for big blits (up to 32k x 32k) is
provided for all graphics functions if the ECS Agnus is present.

With the enhanced Denise, the V36 graphics.library provides display window
start and stop with explicit control over larger ranges than was possible
before.  There are new color register interpretations as part of the
SuperHires mode.  Genlock control has been expanded for more flexibility.
Borders may be explicitly transparent or opaque, color registers other
than zero can control video overlay and a bitplane mask may be used for
special-purpose video masking concurrently with the other genlock features.

   Warning:
   --------
   With these new features come certain  new responsibilities when
   using the graphics.library.

 [Determining Chip Revisions](../Hardware_Manual_guide/node00A2.html) 
 [SuperHires Mode](../Hardware_Manual_guide/node00A3.html) 
 [SuperHires Mode and the Denise Color Registers](../Hardware_Manual_guide/node00A4.html) 
 [SuperHires 70ns Sprite Positioning](../Hardware_Manual_guide/node00A5.html) 
 [Multi-Sync and Bi-Sync Monitors](../Hardware_Manual_guide/node00A6.html) 
 [New BEAMCON0 Register](../Hardware_Manual_guide/node00A7.html) 
 [Display Window Specification](../Hardware_Manual_guide/node00A8.html) 
 [Genlock Extensions](../Hardware_Manual_guide/node00A9.html) 
 [Big Blits](../Hardware_Manual_guide/node00AA.html) 
 [Other ECS Modifications](../Hardware_Manual_guide/node00AB.html) 
 [Interpretational Differences](../Hardware_Manual_guide/node00AC.html) 

