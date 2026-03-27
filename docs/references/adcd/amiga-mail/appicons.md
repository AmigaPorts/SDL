---
title: AppIcons
manual: amiga-mail
chapter: amiga-mail
section: appicons
functions: [GetDiskObject]
libraries: [icon.library]
---

# AppIcons

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The workbench.library function AddAppIcon() adds an AppIcon to the
Workbench window.  There are three parameters unique to this AddApp
function.  The mytext parameter (from the prototype above) is the string
that will appear beneath the AppIcon on the Workbench window.  The diskobj
parameter points to a DiskObject structure that Workbench will use for the
AppIcon's imagery.  It should be filled in as follows (from the wb.doc
Autodoc):

   diskobj - pointer to a DiskObject structure filled in as follows:

```c
       do_Magic - NULL
       do_Version - NULL
       do_Gadget - a gadget structure filled in as follows:
           NextGadget - NULL
           LeftEdge - NULL
           TopEdge - NULL
           Width - width of icon hit-box
           Height - height of icon hit-box
           Flags - NULL or GADGHIMAGE
           Activation - NULL
           GadgetType - NULL
           GadgetRender - pointer to Image structure filled in as follows:
               LeftEdge - NULL
               TopEdge - NULL
               Width - width of image (must be <= Width of hit box)
               Height - height of image (must be <= Height of hit box)
               Depth - # of bit-planes in image
               ImageData - pointer to actual word aligned bits (CHIP MEM)
               PlanePick - Plane mask ((1 << depth) - 1)
               PlaneOnOff - 0
               NextImage - NULL
           SelectRender - pointer to alternate Image struct or NULL
           GadgetText - NULL
           MutualExclude - NULL
           SpecialInfo - NULL
           GadgetID - NULL
           UserData - NULL
       do_Type - NULL
       do_DefaultTool - NULL
       do_ToolTypes - NULL
       do_CurrentX - NO_ICON_POSITION (recommended)
       do_CurrentY - NO_ICON_POSITION (recommended)
       do_DrawerData - NULL
       do_ToolWindow - NULL
       do_StackSize - NULL
```
An easy way to create a DiskObject is to make an icon with the V2.0 icon
editor, IconEdit.  An application can call GetDiskObject() on the icon and
pass that to AddAppIcon().

AddAppIcon()'s mylock parameter is for future enhancements and should be
set to NULL.

Because AppIcons are Workbench icons, the user can drop them on an
AppWindow or another AppIcon (or select them with an AppMenuItem).  As
there is no file, directory, or disk associated with an AppIcon (at least
for the moment), the lock passed for the icon in NULL.  Do not try to
process icons with a NULL lock.

The C source code example [AppIcon.c](amiga-mail/iv-59-appicon-c.md) at the end of this article is a simple
example of how to create an AppIcon.

   [AppIcon.h](amiga-mail/iv-59-appicon-h.md) 

---

## See Also

- [GetDiskObject — icon.library](../autodocs/icon.library.md#getdiskobject)
