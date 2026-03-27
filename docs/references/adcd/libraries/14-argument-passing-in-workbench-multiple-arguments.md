---
title: 14 / / Argument Passing In Workbench / Multiple Arguments
manual: libraries
chapter: libraries
section: 14-argument-passing-in-workbench-multiple-arguments
functions: []
libraries: []
---

# 14 / / Argument Passing In Workbench / Multiple Arguments

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

With extended select, the user can activate many icons at once.  (Extended
select means the user holds down the Shift key while clicking the mouse
select button once on each icon in a group, double-clicking on the last
icon.)  If one of the icons in a group activated with extended select is
an application tool, Workbench runs that application passing it the name
of all the other icons in the group.  This allows the user to start an
application with multiple project files as arguments.  If none of the
icons in a group activated with extended select is a tool icon, then
Workbench looks in the default tool field of each icon in the order they
were selected and runs the first tool it finds.

