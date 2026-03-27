# 15 GadTools Library / GadTools Menus


GadTools menus are easy to use.  Armed only with access to a [VisualInfo](../Libraries_Manual_guide/node026C.html#line12)
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

With GadTools, it takes only one structure, the [NewMenu](../Libraries_Manual_guide/node024F.html) structure, to
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
This [NewMenu](../Libraries_Manual_guide/node024F.html) specification would produce the two menus below:




```c
     [Figure 15-1: Two Example Menus](../Libraries_Manual_guide/node05E2.html) 
```
The [NewMenu](../Libraries_Manual_guide/node024F.html) arrays are designed to be read easily.  The elements in the
NewMenu array appear in the same order as they will appear on-screen.
Unlike the lower-level menu structures described in the "[Intuition Menus](../Libraries_Manual_guide/node0198.html)"
chapter earlier, there is no need to specify sub-menus first, then the
menu items with their sub-menus, and finally the menu headers with their
menu items.  The indentation shown above also helps highlight the
relationship between menus, menu items and sub-items.

 [The NewMenu Structure](../Libraries_Manual_guide/node024F.html)           [GadTools Menus And IntuiMessages](../Libraries_Manual_guide/node0255.html) 
 [GadTools Menus Example](../Libraries_Manual_guide/node059A.html)          [Restrictions on GadTools Menus](../Libraries_Manual_guide/node0256.html) 
 [Functions for GadTools Menus](../Libraries_Manual_guide/node0250.html)    [Language-Sensitive Menus](../Libraries_Manual_guide/node0257.html) 

