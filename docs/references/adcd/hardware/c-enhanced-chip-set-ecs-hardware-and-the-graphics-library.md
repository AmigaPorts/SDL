---
title: C Enhanced Chip Set / ECS Hardware and the Graphics Library
manual: hardware
chapter: hardware
section: c-enhanced-chip-set-ecs-hardware-and-the-graphics-library
functions: []
libraries: []
---

# C Enhanced Chip Set / ECS Hardware and the Graphics Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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

 [Determining Chip Revisions](hardware/c-ecs-hardware-and-the-graphics-library-determining-chip.md) 
 [SuperHires Mode](hardware/c-ecs-hardware-and-the-graphics-library-superhires-mode.md) 
 [SuperHires Mode and the Denise Color Registers](hardware/c-ecs-graphics-library-superhires-mode-and-denise-color.md) 
 [SuperHires 70ns Sprite Positioning](hardware/c-ecs-hardware-graphics-library-superhires-70ns-sprite.md) 
 [Multi-Sync and Bi-Sync Monitors](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) 
 [New BEAMCON0 Register](hardware/c-ecs-hardware-and-the-graphics-library-new-beamcon0.md) 
 [Display Window Specification](hardware/c-ecs-hardware-and-graphics-library-display-window.md) 
 [Genlock Extensions](hardware/c-ecs-hardware-and-the-graphics-library-genlock-extensions.md) 
 [Big Blits](hardware/c-ecs-hardware-and-the-graphics-library-big-blits.md) 
 [Other ECS Modifications](hardware/c-ecs-hardware-and-the-graphics-library-other-ecs.md) 
 [Interpretational Differences](hardware/c-ecs-hardware-and-graphics-library-interpretational.md) 

