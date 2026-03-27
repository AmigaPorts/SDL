---
title: V-39: Naming Graphics Display Modes
manual: amiga-mail
chapter: amiga-mail
section: v-39-naming-graphics-display-modes
functions: []
libraries: []
---

# V-39: Naming Graphics Display Modes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Naming Graphics Display Modes

by Martin Taillefer


The graphics.library database contains a list of all available display modes
on any given Amiga. Each mode has a given set of attributes, including
possibly a name. Only a subset of the available modes in the system have
names. The other modes are less significant and don't have names directly
associated with them.

When showing a list of available modes to the user, unnamed modes become a
problem. How should they be presented to the user? A simple solution is to
dynamically construct names for unnamed modes. The name construction can be
based on a mode's attributes, resulting in a descriptive name for the mode.

The NameMode() routine in the program below accepts a graphics.library mode
id, and a string buffer, and fills-in the string buffer with the name of the
given mode. If the mode has a real name entry in the graphics database, that
name is returned. If there is no real name entry, a name is constructed for
the mode based on the mode's properties. A routine very similar to this is
present in the ASL screen mode requester, and in the ScreenMode prefs editor.

The following program outputs the names of all current graphics database modes
to the console.

 [NameMode.c](amiga-mail/v-39-namemode-c.md) 

