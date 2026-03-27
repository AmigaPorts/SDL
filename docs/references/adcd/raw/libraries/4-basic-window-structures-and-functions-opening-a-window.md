# 4 / Basic Window Structures and Functions / Opening a Window


A window is opened and displayed by a call to one of the OpenWindow()
functions:  [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html), [OpenWindowTagList()](../Includes_and_Autodocs_2._guide/node023A.html) or [OpenWindowTags()](../Includes_and_Autodocs_2._guide/node023A.html).


```c
    struct Window *OpenWindowTagList( struct NewWindow *newWindow,
                                     struct TagItem *tagList );
    struct Window *OpenWindowTags( struct NewWindow *newWindow,
                                  unsigned long tag1Type, ... );
    struct Window *OpenWindow( struct NewWindow *newWindow );
```
The type of window and its attributes are specified in [NewWindow](../Libraries_Manual_guide/node0102.html#line8) or
[TagItem](../Libraries_Manual_guide/node0102.html#line8) structures depending on which function is used.  These functions
all return a pointer to a new [Window](../Libraries_Manual_guide/node0102.html#line8) structure if they succeed.  A NULL
return indicates failure.

[OpenWindowTagList()](../Includes_and_Autodocs_2._guide/node023A.html) and [OpenWindowTags()](../Includes_and_Autodocs_2._guide/node023A.html) are available only in Release 2
(V36) and later versions of the OS.  For these functions, window
attributes are specified in [TagItem](../Libraries_Manual_guide/node0102.html#line8) structures which are paired data items
specifying an attribute and its setting.  (See the `[Utility Library](../Libraries_Manual_guide/node0496.html)'
chapter for more information on TagItems.)

[OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html) is available in all versions of the OS.  Window attributes
can be specified using a [NewWindow](../Libraries_Manual_guide/node0102.html#line8) structure but only a limited set of
window attributes are available this way.  To support both the new window
features of Release 2 and compatibility with older versions of the OS, use
OpenWindow() with an extended version of the [NewWindow](../Libraries_Manual_guide/node0102.html#line8) structure named
[ExtNewWindow](../Libraries_Manual_guide/node0102.html#line8).  See the [WFLG_NW_EXTENDED](../Libraries_Manual_guide/node0123.html) flag description in the "Window
Attributes" section below for more information on using OpenWindow() with
the extended NewWindow structure.

Further references to OpenWindow() in this chapter will apply to all three
functions.  These calls are the only proper method for allocating a [Window](../Libraries_Manual_guide/node0102.html#line8)
structure.  The tag based versions are recommended for V36 and later
versions of the OS.  Use the [ExtNewWindow](../Libraries_Manual_guide/node0102.html#line8) structure with OpenWindow() to
provide backward compatibility.

 [OpenWindowTagList() Example](../Libraries_Manual_guide/node05BC.html)    [Setting Window Attributes](../Libraries_Manual_guide/node0104.html) 

