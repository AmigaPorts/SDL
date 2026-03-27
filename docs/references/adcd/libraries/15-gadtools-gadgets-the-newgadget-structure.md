---
title: 15 / GadTools Gadgets / The NewGadget Structure
manual: libraries
chapter: libraries
section: 15-gadtools-gadgets-the-newgadget-structure
functions: []
libraries: []
---

# 15 / GadTools Gadgets / The NewGadget Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For most gadgets, the NewGadget structure is used to specify its common
attributes.  Additional attributes that are unique to specific kinds of
gadgets are specified as tags sent to the [CreateGadget()](libraries/15-gadtools-gadgets-creating-gadgets.md) function
(described below).

The NewGadget structure is defined in <libraries/[gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md)> as:


```c
    struct NewGadget
        {
        WORD ng_LeftEdge, ng_TopEdge;
        WORD ng_Width, ng_Height;
        UBYTE *ng_GadgetText;
        struct TextAttr *ng_TextAttr;
        UWORD ng_GadgetID;
        ULONG ng_Flags;
        APTR ng_VisualInfo;
        APTR ng_UserData;
        };
```
The fields of the NewGadget structure are used as follows:

ng_LeftEdge, ng_TopEdge

    Define the position of the gadget being created.
ng_Width and ng_Height

    Define the size of the gadget being created.
ng_GadgetText

    Most gadgets have an associated label, which might be the text in a
    button or beside a checkmark.  This field contains a pointer to the
    appropriate string.  Note that only the pointer to the text is
    copied, the text itself is not.  The string supplied must remain
    constant and valid for the life of the gadget.
ng_TextAttr

    The application must specify a font to use for the label and any
    other text that may be associated with the gadget.
ng_Flags

    Used to describe general aspects of the gadget, which includes where
    the label is to be placed and whether the label should be rendered in
    the highlight color.  The label may be positioned on the left side,
    the right side, centered above, centered below or dead-center on the
    gadget.  For most gadget kinds, the label is placed on the left side
    by default, exceptions will be noted.
ng_GadgetID, ng_UserData

```c
    These user fields are copied into the resulting [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.
```
ng_VisualInfo

```c
    This field must contain a pointer to an instance of the [VisualInfo](libraries/15-getvisualinfo-and-freevisualinfo.md)
    structure, which contains information needed to create and render
    GadTools gadgets.  The VisualInfo structure itself is private to
    GadTools and subject to change.  Use the specialized GadTools
    functions for accessing the VisualInfo pointer, defined below.  Never
    access or modify fields within this structure.
```
