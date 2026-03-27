---
title: 37 / Tags / Simple Tag Usage
manual: libraries
chapter: libraries
section: 37-tags-simple-tag-usage
functions: [OpenScreen, OpenWindow, OpenWindowTagList]
libraries: [intuition.library]
---

# 37 / Tags / Simple Tag Usage

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One way tags are passed to system functions is in the form of tag lists. A
tag list is an array or chain of arrays of [TagItem](libraries/37-tags-tag-functions-and-structures.md) structures.  Within
this array, different data items are identified by the value of [ti_Tag](libraries/37-tags-tag-functions-and-structures.md).
Items specific to a subsystem (Intuition, Graphics,...) have a ti_Tag
value which has the TAG_USER bit set. Global system tags have a ti_Tag
value with TAG_USER bit clear.  The global system tags include:


                      Table 37-2: Global System Tags
  ____________________________________________________________________
 |                                                                    |
 | Tag Value   Meaning                                                |
 |====================================================================|
 | TAG_IGNORE  A no-op.  The data item is ignored.                    |
 |                                                                    |
 | TAG_MORE    The [ti_Data](libraries/37-tags-tag-functions-and-structures.md) points to another tag list, to support     |
 |             chaining of [TagItem](libraries/37-tags-tag-functions-and-structures.md) arrays.                            |
 |                                                                    |
 | TAG_DONE    Terminates the [TagItem](libraries/37-tags-tag-functions-and-structures.md) array (or chain).               |
 |                                                                    |
 | TAG_SKIP    Ignore the current tag item, and skip the next n array |
 |             elements, where n is kept in [ti_Data](libraries/37-tags-tag-functions-and-structures.md).                  |
 |____________________________________________________________________|


Note that user tags need only be unique within the particular context of
their use.  For example, the attribute tags defined for [OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) have
the same numeric value as some tags used by [OpenScreen()](libraries/3-intuition-screens-custom-screen-functions.md), but the same
numeric value has different meaning in the different contexts.

System functions receive [TagItem](libraries/37-tags-tag-functions-and-structures.md)s in several ways.  One way is illustrated
in the Intuition function [OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md).  This function supports an
extented [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure called [ExtNewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).  When the [NW_EXTENDED](libraries/4-window-attributes-extended-new-window.md)
flag is set in the ExtNewWindow.Flags field, OpenWindow() assumes that the
ExtNewWindow.Extension field contains a pointer to a tag list.

Another method of passing a tag list is to directly pass a pointer to a
tag list, as [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) does in the following code fragment.


```c
    struct TagItem tagitem[3];
    struct Screen *screen;
    struct Window *window;

    tagitem[0].ti_Tag = WA_CustomScreen;
    tagitem[0].ti_Data = screen;    /* Open on my own screen */
    tagitem[1].ti_Tag = WA_Title;
    tagitem[1].ti_Data = "RKM Test Window";
    tagitem[2].ti_Tag = TAG_DONE;   /* Marks the end of the tag array. */

    /* Use defaults for everything else. Will open as big as the screen. */
    /* Because all window parameters are specified using tags, we don't  */
    /* need a NewWindow structure                                        */

    if (window = OpenWindowTagList(NULL, tagitem))
    {
        /* rest of code */
        CloseWindow(window);
    }
```
Notice that window parameters need not be explicitly specified. Functions
that utilize tags have reasonable defaults to fall back on in case no
valid attribute/value pair was supplied for a particular parameter. This
fall back capability is a useful feature. An application only has to
specify the attributes that differ from the default, rather than
unnecessarily listing all the possible attributes.

The amiga.lib support library offers another way to pass [TagItem](libraries/37-tags-tag-functions-and-structures.md)s to a
function.  Rather than passing a tag list, the function [OpenWindowTags()](libraries/4-basic-window-structures-and-functions-opening-a-window.md)
receives the attribute/value pairs in the argument list, much like
[printf()](autodocs-2.0/amiga-lib-printf.md) receives its arguments.  Any number of attribute/value pairs can
be specified.  This type of argument passing is called VarArgs. The
following code fragment illustrates the usage of OpenWindowTags().


```c
    struct Window *window;

    /* Just pass NULL to show we aren't using a NewWindow */
    window = OpenWindowTags( NULL,
                             WA_CustomScreen, screen,
                             WA_Title, "RKM Test Window",
                             TAG_DONE );
```
Tags are not exclusively for use with the operating system; the programmer
can implement them as well.  The run-time utility library contains several
functions to make using tags easier.

---

## See Also

- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
