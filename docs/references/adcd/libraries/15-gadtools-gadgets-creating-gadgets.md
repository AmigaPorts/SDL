---
title: 15 / GadTools Gadgets / Creating Gadgets
manual: libraries
chapter: libraries
section: 15-gadtools-gadgets-creating-gadgets
functions: [CreateContext]
libraries: [gadtools.library]
---

# 15 / GadTools Gadgets / Creating Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The main call used to create a gadget with GadTools is [CreateGadget()](autodocs-2.0/gadtools-library-creategadgeta.md).
This function can be used to create a single gadget or it can be called
repeatedly to create a linked list of gadgets.  It takes three arguments
followed by a set of tags:


```c
    struct Gadget *CreateGadget( ULONG kind, struct Gadget *prevgad,
                                 struct NewGadget *newgad,
                                 struct TagItem *taglist)
    struct Gadget *CreateGadgetA(ULONG kind, struct Gadget *prevgad,
                                 struct NewGadget *newgad,
                                 struct Tag tag1, ...)
```
Set the kind argument to one of the 12 gadget types supported by GadTools.
Set the prevgad argument to the gadget address returned by [CreateContext()](libraries/15-setting-up-gadtools-menus-and-gadgets-createcontext.md)
if this is the first (or only) gadget in the list.  Subsequent calls to
[CreateGadget()](autodocs-2.0/gadtools-library-creategadgeta.md) can be used to create and link AutoDocs/gadgets together in a list
in which case the prevgad argument is set to the address of the gadget
returned by the preceding call to CreateGadget().

Set the newgad argument to the address of the [NewGadget](libraries/15-gadtools-gadgets-the-newgadget-structure.md) structure
describing the gadget to be created and set any special attributes for
this gadget type using the tag arguments, tag1 or taglist.  For instance,
the following code fragment might be used to create the color slider
discussed earlier:


```c
    slidergad = CreateGadget(SLIDER_KIND, newgadget, prevgad,
        GTSL_Min, 0,
        GTSL_Max, 15,
        GTSL_Level, 11,
        TAG_END);
```
[CreateGadget()](autodocs-2.0/gadtools-library-creategadgeta.md) typically allocates and initializes all the necessary
Intuition structures, including in this case the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md), [IntuiText](libraries/8-creating-text-intuitext-structure.md) and
[PropInfo](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) structures, as well as certain buffers.  For more about these
underlying structures, see the "[Intuition Gadgets](libraries/5-intuition-gadgets.md)" chapter.

Since [CreateGadget()](autodocs-2.0/gadtools-library-creategadgeta.md) is a tag-based function, it is easy to add more tags
to get a fancier gadget.  For example, GadTools can optionally display the
running level beside the slider.  The caller must supply a [printf()](autodocs-2.0/amiga-lib-printf.md)-style
formatting string and the maximum length that the string will resolve to
when the number is inserted:


```c
    slidergad = CreateGadget(SLIDER_KIND, newgadget, prevgad,
        GTSL_Min, 0,
        GTSL_Max, 15,
        GTSL_Level, 11,
        GTSL_LevelFormat, "%2ld" /* printf()-style formatting string */
        GTSL_MaxLevelLen, 2,     /* maximum length of string         */
        TAG_END);
```
The level, 0 to 15 in this example, would then be displayed beside the
slider.  The formatting string could instead be "%2ld/15", so the level
would be displayed as "0/15" through "15/15".

---

## See Also

- [CreateContext — gadtools.library](../autodocs/gadtools.library.md#createcontext)
