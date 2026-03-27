---
title: reaction.lib/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-datasheet
functions: [OpenLibrary]
libraries: [exec.library]
---

# reaction.lib/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       reaction.lib -- ReAction support functions link library
   DESCRIPTION

```c
       This library contains the autoinitialization code for the shared
       library versions of the ReAction BOOPSI classes, thus sparing the
       programmer from having to [OpenLibrary()](autodocs-3.5/exec-library-openlibrary-2.md) the classes manually. It
       also contains stub functions for the node taglist allocation
       functions of certain classes. These can be used by the DICE
       compiler, which does not support #pragma tagcall.

       Autoinitialization works just like normal SAS/C library autoinit.
       By declaring the class base extern in all source files (easiest
       done by #including the "proto" header, such as proto/layout.h),
       the SAS/C linker will take the class base, together with the code
       to open the class on program startup (and to close it on exit)
       from this library. The same autoinitialisation code should also
       work for DICE.

       The version number to use for [OpenLibrary()](autodocs-3.5/exec-library-openlibrary-2.md) is contained in the
       variable long __reactionversion. If you do not set this global
       variable in your source code, it will be linked from this library,
       With the release of V41 or greater classes in Release 2.0, it has
       been considered prudent to requier them, so you should set this
       value to 41. Note however, that classes NOT part of the ReAction
       package are not effected by __reactionversion and will open with
       any version available.

       If the opening of a class fails, the autoinit code will cause the
       program to exit with an error message of "Can't open version Y of
       X". If you wish to continue without using a certain class, you
       will have to open it manually.
```
   SUPPORTED CLASSES

```c
       Version 1 of reaction.lib supports the following ReAction classes.
       The version variable of each class is listed after the shared class
       name.

       images/bevel.image
       images/bitmap.image
       gadgets/button.gadget
       gadgets/checkbox.gadget
       gadgets/chooser.gadget
       gadgets/datebrowser.gadget
       images/drawlist.image
       gadgets/fuelgauge.gadget
       gadgets/getfile.gadget
       gadgets/getfont.gadget
       gadgets/getscreenmode.gadget
       images/glyph.image
       gadgets/integer.gadget
       images/label.image
       gadgets/layout.gadget
       gadgets/listbrowser.gadget
       gadgets/radiobutton.gadget
       gadgets/scroller.gadget
       gadgets/slider.gadget
       gadgets/space.gadget
       gadgets/speedbar.gadget
       gadgets/string.gadget

       Additionally, to help programmers, reaction.lib contains
       autoinitialization for the following shared classes NOT part of
       the ReAction package. Please remember that these gadgets do not
       necessarily contain a CLASS_GetClass() type function for getting
       the base class. Some of them have registered class names, some
       have a function with another name. Some don't have functions at
       all, in which case special care must be taken to make sure the
       autoinit code is loaded (reference the class base variable, for
       example TapeDeckBase, somewhere within the source). Refer to the
       documentation of these classes to find out more.

       gadgets/calendar.gadget
       [gadgets/colorwheel.gadget](autodocs-3.5/colorwheel-gadget-colorwheel-gadget.md)
       [gadgets/gradientslider.gadget](autodocs-3.5/gradientslider-gadget-gradientslider-gadgetlider-gadget.md)
       images/led.image
       gadgets/statusbar.gadget
       gadgets/tabs.gadget
       gadgets/tapedeck.gadget
       gadgets/textfield.gadget
```
   EXAMPLE

```c
       The following program will print out the class base of
       layout.gadget and the base address of [gradientslider.gadget](autodocs-3.5/gradientslider-gadget-gradientslider-gadgetlider-gadget.md) (which
       doesn't have functions or a proto header) when compiled and linked
       with reaction.lib:

       #include <proto/layout.h>
       #include <proto/dos.h>

       extern void *GradientSliderBase;
       long __reactionversion = 37;

       main()
       {
           Printf( "layout.gadget minimum version %ld class base is %lxn",
                   __layoutversion, [LAYOUT_GetClass()](autodocs-3.5/layout-gc-layout-getclass.md) );
           Printf( "explicit reference to GradientSliderBase will force "
                   "initialization:n base address is %lxn",
                   GradientSliderBase );
       }
```

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
