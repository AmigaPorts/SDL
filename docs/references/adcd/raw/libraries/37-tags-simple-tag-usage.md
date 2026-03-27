# 37 / Tags / Simple Tag Usage


One way tags are passed to system functions is in the form of tag lists. A
tag list is an array or chain of arrays of [TagItem](../Libraries_Manual_guide/node0497.html) structures.  Within
this array, different data items are identified by the value of [ti_Tag](../Libraries_Manual_guide/node0497.html#line5).
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
 | TAG_MORE    The [ti_Data](../Libraries_Manual_guide/node0497.html#line5) points to another tag list, to support     |
 |             chaining of [TagItem](../Libraries_Manual_guide/node0497.html) arrays.                            |
 |                                                                    |
 | TAG_DONE    Terminates the [TagItem](../Libraries_Manual_guide/node0497.html) array (or chain).               |
 |                                                                    |
 | TAG_SKIP    Ignore the current tag item, and skip the next n array |
 |             elements, where n is kept in [ti_Data](../Libraries_Manual_guide/node0497.html#line5).                  |
 |____________________________________________________________________|


Note that user tags need only be unique within the particular context of
their use.  For example, the attribute tags defined for [OpenWindow()](../Libraries_Manual_guide/node0103.html) have
the same numeric value as some tags used by [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6), but the same
numeric value has different meaning in the different contexts.

System functions receive [TagItem](../Libraries_Manual_guide/node0497.html)s in several ways.  One way is illustrated
in the Intuition function [OpenWindow()](../Libraries_Manual_guide/node0103.html).  This function supports an
extented [NewWindow](../Libraries_Manual_guide/node0102.html#line8) structure called [ExtNewWindow](../Libraries_Manual_guide/node0102.html#line8).  When the [NW_EXTENDED](../Libraries_Manual_guide/node0123.html)
flag is set in the ExtNewWindow.Flags field, OpenWindow() assumes that the
ExtNewWindow.Extension field contains a pointer to a tag list.

Another method of passing a tag list is to directly pass a pointer to a
tag list, as [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) does in the following code fragment.


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

The amiga.lib support library offers another way to pass [TagItem](../Libraries_Manual_guide/node0497.html)s to a
function.  Rather than passing a tag list, the function [OpenWindowTags()](../Libraries_Manual_guide/node0103.html)
receives the attribute/value pairs in the argument list, much like
[printf()](../Includes_and_Autodocs_2._guide/node0162.html) receives its arguments.  Any number of attribute/value pairs can
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

