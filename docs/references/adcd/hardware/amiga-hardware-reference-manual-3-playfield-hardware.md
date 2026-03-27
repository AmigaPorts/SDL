---
title: Amiga® Hardware Reference Manual: 3 Playfield Hardware
manual: hardware
chapter: hardware
section: amiga-hardware-reference-manual-3-playfield-hardware
functions: []
libraries: []
---

# Amiga® Hardware Reference Manual: 3 Playfield Hardware

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The screen display of the Amiga consists of two basic parts -- playfields,
which are sometimes called backgrounds, and sprites, which are easily
movable graphics objects. This chapter describes how to directly access
hardware registers to form playfields.  The chapter begins with a brief
overview of playfield features and covers the following major topics:

   *  Forming a single "basic" playfield, which is a playfield the same
      size as the display screen.  This section includes concepts that are
      fundamental to forming any playfield.
   *  Forming a dual-playfield display in which one playfield is
      superimposed upon another.  This procedure differs from that of
      forming a basic playfield in some details.
   *  Forming playfields of various sizes and displaying only part of a
      larger playfield.
   *  Moving playfields by scrolling them vertically and horizontally.
   *  Advanced topics to help you use playfields in special situations.

For information about  [movable sprite objects](hardware/4-sprite-hardware-moving-a-sprite.md) , see Chapter 4, Sprite
Hardware.  There are also movable playfield objects, which are subsections
of a playfield.  To move portions of a playfield, you use a technique
called  [playfield animation](hardware/6-function-generator-designing-the-lf-control-byte-with.md) , which is described in Chapter 6, Blitter
Hardware.

For information relating to the playfield hardware in the Enhanced Chip
Set (ECS), such as  [SuperHires Mode](hardware/c-enhanced-chip-set-ecs-hardware-and-the-graphics-library.md) ,  [programmable scan rates](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md)  and
 [synchronization](hardware/c-ecs-hardware-and-graphics-library-multi-sync-and-bi-sync.md) , see Appendix C.

 [About Amiga Playfields](hardware/3-playfield-hardware-about-amiga-playfields.md) 
 [Forming a Basic Playfield](hardware/3-playfield-hardware-forming-a-basic-playfield.md) 
 [Forming a Dual-playfield Display](hardware/3-playfield-hardware-forming-a-dual-playfield-display.md) 
 [Bitplanes and Display Windows of All Sizes](hardware/3-playfield-hardware-bitplanes-and-display-windows-of-all.md) 
 [Moving (Scrolling) Playfields](hardware/3-playfield-hardware-moving-scrolling-playfields.md) 
 [Advanced Topics](hardware/3-playfield-hardware-advanced-topics.md) 
 [Summary of Playfield Registers](hardware/3-playfield-hardware-summary-of-playfield-registers.md) 
 [Summary of Color Selection Registers](hardware/3-playfield-hardware-summary-of-color-selection-registers.md) 

