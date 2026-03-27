---
title: 6 Intuition Menus / Setting Up Menus
manual: libraries
chapter: libraries
section: 6-intuition-menus-setting-up-menus
functions: []
libraries: []
---

# 6 Intuition Menus / Setting Up Menus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The application does not have to worry about handling the menu display.
The menus are simply submitted to Intuition and the application waits for
Intuition to send messages about the selection of menu items.  These
messages, along with the data in the menu structures, give the application
all the information required for the processing of the user actions.

Menus can be set up with the GadTools library on systems running Release 2
or a later version of the OS.  Since GadTools makes menu set up easier and
handles much of the detail work of menu processing (including adjusting to
the current font selection), it should be used whenever possible.

Under 1.3 (V34) and older versions of the OS, GadTools is not available.
To set up menus that work with these older systems, you use the [Menu](libraries/6-menu-data-structures-menu-structure.md) and
[MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structures.  In general, for each menu in the menu bar, you
declare one instance of the Menu structure.  For each item or sub-item
within a menu, you declare one instance of the MenuItem structure.
Text-based menus like the kind used in this chapter require an additional
[IntuiText](libraries/8-creating-text-intuitext-structure.md) structure for each menu, menu item and sub-item.  All these
structures are defined in <intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>.

The data structures used for menus are linked together to form a list
known as a menu strip.  For all the details of how the structures are
linked and for listings of [Menu](libraries/6-menu-data-structures-menu-structure.md) and [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md), see the [Menu Data Structures](libraries/6-intuition-menus-menu-data-structures.md)"
section later in this chapter.

 [Submitting and Removing Menu Strips](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) 
 [Simple Menu Example](libraries/6-setting-up-menus-simple-menu-example.md) 
 [Disabling Menu Operations](libraries/6-setting-up-menus-disabling-menu-operations.md) 
 [Changing Menu Strips](libraries/6-setting-up-menus-changing-menu-strips.md) 
 [Sharing Menu Strips](libraries/6-setting-up-menus-sharing-menu-strips.md) 
 [Menu Selection Messages](libraries/6-setting-up-menus-menu-selection-messages.md) 
 [Menu Numbers](libraries/6-setting-up-menus-menu-numbers.md) 
 [Help Key Processing in Menus](libraries/6-setting-up-menus-help-key-processing-in-menus.md) 
 [Menu Layout](libraries/6-setting-up-menus-menu-layout.md) 
 [About Menu Item Boxes](libraries/6-setting-up-menus-about-menu-item-boxes.md) 
 [Attribute Items and the Checkmark](libraries/6-setting-up-menus-attribute-items-and-the-checkmark.md) 
 [Toggle Selection](libraries/6-setting-up-menus-toggle-selection.md) 
 [Mutual Exclusion](libraries/6-setting-up-menus-mutual-exclusion.md) 
 [Managing the State of Checkmarks](libraries/6-setting-up-menus-managing-the-state-of-checkmarks.md) 
 [Command Key Sequences](libraries/6-setting-up-menus-command-key-sequences.md) 
 [Enabling and Disabling Menus and Menu Items](libraries/6-setting-up-menus-enabling-and-disabling-menus-and-menu.md) 
 [Intercepting Normal Menu Operations](libraries/6-setting-up-menus-intercepting-normal-menu-operations.md) 

