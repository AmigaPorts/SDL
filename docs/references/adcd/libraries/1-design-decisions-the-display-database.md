---
title: 1 / / Design Decisions / The Display Database
manual: libraries
chapter: libraries
section: 1-design-decisions-the-display-database
functions: [ModeNotAvailable, OpenScreen, VideoControl]
libraries: [graphics.library, intuition.library]
---

# 1 / / Design Decisions / The Display Database

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [Release 2](libraries/1-operating-system-versions-about-release-2.md) graphics library and the Enhanced Chip Set ([ECS](libraries/1-the-custom-chips-custom-chip-revisions.md)) provide
programmable [display modes](libraries/27-introduction-about-ecs.md) and enhanced [genlock](libraries/27-graphics-primitives-ecs-and-genlocking-features.md) capabilities.  Users with
Release 2 and ECS may wish to use your application in one of the newer
display modes.  The Release 2 display database provides information on all
of the display modes available with the user's machine and monitor.  In
addition, it provides useful information on the capabilities and aspect
ratio of each mode (DisplayInfo.Resolution.x and .y).  A new function
named [ModeNotAvailable()](libraries/27-monitors-modes-and-the-display-database-mode-availability.md) allows you to easily check if particular modes
are available.

The [ExtNewScreen](libraries/3-creating-a-custom-screen-that-works-with-older-systems.md) structure used with Intuition's [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md) function
allows you to specify new display modes with the [SA_DisplayID](libraries/3-custom-screen-functions-screen-attributes.md) tag and a
longword ModeID.  The Release 2 graphics library [VideoControl()](libraries/27-ecs-and-genlocking-features-genlock-control.md) function
provides greatly enhanced [genlock](libraries/27-graphics-primitives-ecs-and-genlocking-features.md) capabilities for machines with [ECS](libraries/1-the-custom-chips-custom-chip-revisions.md) and a
genlock.  Little conditional code is required to support these features.
See the [graphics library](libraries/graphics-libraries.md) chapters and [Autodocs](autodocs-2.0/autodocs-2-0.md) for more information.

---

## See Also

- [ModeNotAvailable — graphics.library](../autodocs/graphics.library.md#modenotavailable)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
