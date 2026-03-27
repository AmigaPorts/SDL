---
title: 6 / Setting Up Menus / Menu Selection Messages
manual: libraries
chapter: libraries
section: 6-setting-up-menus-menu-selection-messages
functions: []
libraries: []
---

# 6 / Setting Up Menus / Menu Selection Messages

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An input event is generated every time the user activates the menu system,
either by pressing the mouse menu button or its keyboard equivalent (right
Amiga Alt), or entering an appropriate command key sequence.  The program
receives a message of type [IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) detailing which menu items or
sub-items were selected.  Even if the user activates the menu system
without selecting a menu item or sub-item, an event is generated.

 [Multi-Selection of Menu Items](libraries/6-menu-selection-messages-multi-selection-of-menu-items.md) 

