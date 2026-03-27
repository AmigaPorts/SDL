---
title: 3 / Types of Screens / Public Screens and Custom Screens
manual: libraries
chapter: libraries
section: 3-types-of-screens-public-screens-and-custom-screens
functions: []
libraries: []
---

# 3 / Types of Screens / Public Screens and Custom Screens

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An application may choose to use an existing screen or to create its own
screen.  For instance, the normal Amiga startup process opens the
Workbench screen ([Workbench](libraries/14-workbench-and-icon-library.md) is the Amiga's default user interface).  Any
application is free to use the Workbench screen instead of opening a new
one.  Screens that can be shared this way are called public screens.

[Public screens](libraries/3-intuition-screens-public-screen-functions.md) are a new feature of Release 2 (V36).  In older [versions](libraries/1-programming-in-the-amiga-environment-operating-system.md) of
the OS, only the Workbench screen could be shared.  Now any screen may be
set up as a public screen so that other applications may use it.

The use of an existing public screen, like the Workbench screen, requires
little effort by the application and does not use up any memory.  However,
using  Workbench or another existing public screen means some flexibility
is lost; the resolution, maximum number of colors and other attributes are
already set.  If the application cannot function under these limitations,
it may open its own custom screen.

[Custom screens](libraries/3-intuition-screens-custom-screen-functions.md) allow for complete control of the display space so an
application can get exactly the kind of display it wants.  However, since
creating a new, custom screen uses up memory, they should only be used
when there are no suitable public screens available.

Owners of a custom screen can keep their screen private, or they may allow
other applications to share their screen by [registering](libraries/3-public-screen-functions-taking-a-new-custom-screen-public.md) the screen with
the operating system as a public screen.  See the section on
"[Public Screen Functions](libraries/3-public-screen-functions-the-default-public-screen-and.md)" later in this chapter for more about public
screens and Workbench.

