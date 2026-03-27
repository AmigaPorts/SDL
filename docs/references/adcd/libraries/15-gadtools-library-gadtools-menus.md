---
title: 15 GadTools Library / GadTools Menus
manual: libraries
chapter: libraries
section: 15-gadtools-library-gadtools-menus
functions: []
libraries: []
---

# 15 GadTools Library / GadTools Menus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

GadTools menus are easy to use.  Armed only with access to a [VisualInfo](libraries/15-getvisualinfo-and-freevisualinfo.md)
data structure, GadTools allows the application to easily create, layout
and delete Intuition menus.

Normally, the greatest difficulty in creating menus is that a large number
of structures must be filled out and linked.  This is bothersome since
much of the required information is orderly and is easier to do
algorithmically than to do manually.  GadTools handles this for you.

There are also many complexities in creating a sensible layout for menus.
This includes some mechanical items such as handling various font sizes,
automatic columnization of menus that are too tall and accounting for
space for checkmarks and Amiga-key equivalents.  There are also aesthetic
considerations, such as how much spacing to provide, where sub-menus
should be placed and so on.

GadTools menu functions support all the features that most applications
will need.  These include:

  * An easily constructed and legible description of the menus.

  * Font-sensitive layout.

  * Support for menus and sub-menus.

  * Sub-menu indicators (a ">>" symbol attached to items with sub-menus).

  * Separator bars for sectioning menus.

  * Command-key equivalents.

  * Checkmarked and mutually exclusive checkmarked menu items.

  * Graphical menu items.

With GadTools, it takes only one structure, the [NewMenu](libraries/15-gadtools-menus-the-newmenu-structure.md) structure, to
specifiy the whole menu bar,  For instance, here is how a typical menu
strip containing two menus might be specified:


```c
    struct NewMenu mynewmenu[] =
        {
            { NM_TITLE, "Project",    0 , 0, 0, 0,},
            {  NM_ITEM, "Open...",   "O", 0, 0, 0,},
            {  NM_ITEM, "Save",      "S", 0, 0, 0,},
            {  NM_ITEM, NM_BARLABEL,  0 , 0, 0, 0,},
            {  NM_ITEM, "Print",      0 , 0, 0, 0,},
            {   NM_SUB, "Draft",      0 , 0, 0, 0,},
            {   NM_SUB, "NLQ",        0 , 0, 0, 0,},
            {  NM_ITEM, NM_BARLABEL,  0 , 0, 0, 0,},
            {  NM_ITEM, "Quit...",   "Q", 0, 0, 0,},

            { NM_TITLE, "Edit",       0 , 0, 0, 0,},
            {  NM_ITEM, "Cut",       "X", 0, 0, 0,},
            {  NM_ITEM, "Copy",      "C", 0, 0, 0,},
            {  NM_ITEM, "Paste",     "V", 0, 0, 0,},
            {  NM_ITEM, NM_BARLABEL,  0 , 0, 0, 0,},
            {  NM_ITEM, "Undo",      "Z", 0, 0, 0,},

            {   NM_END, NULL,         0 , 0, 0, 0,},
        };
```
This [NewMenu](libraries/15-gadtools-menus-the-newmenu-structure.md) specification would produce the two menus below:




```c
     [Figure 15-1: Two Example Menus](libraries/lib-pics-15-1-pic.md) 
```
The [NewMenu](libraries/15-gadtools-menus-the-newmenu-structure.md) arrays are designed to be read easily.  The elements in the
NewMenu array appear in the same order as they will appear on-screen.
Unlike the lower-level menu structures described in the "[Intuition Menus](libraries/6-intuition-menus-menu-data-structures.md)"
chapter earlier, there is no need to specify sub-menus first, then the
menu items with their sub-menus, and finally the menu headers with their
menu items.  The indentation shown above also helps highlight the
relationship between menus, menu items and sub-items.

 [The NewMenu Structure](libraries/15-gadtools-menus-the-newmenu-structure.md)           [GadTools Menus And IntuiMessages](libraries/15-gadtools-menus-gadtools-menus-and-intuimessages.md) 
 [GadTools Menus Example](libraries/lib-examples-gadtoolsmenu-c.md)          [Restrictions on GadTools Menus](libraries/15-gadtools-menus-restrictions-on-gadtools-menus.md) 
 [Functions for GadTools Menus](libraries/15-gadtools-menus-functions-for-gadtools-menus.md)    [Language-Sensitive Menus](libraries/15-gadtools-menus-language-sensitive-menus.md) 

