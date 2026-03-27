# 4 / Window Attributes / Extended New Window


Of the three functions for opening a window, only [OpenWindow()](../Libraries_Manual_guide/node0103.html) is present
in all versions of the OS.  This function takes a [NewWindow](../Libraries_Manual_guide/node0102.html#line8) structure as
its sole argument.  In order to allow applications to use the OpenWindow()
call with Release 2 [TagItem](../Libraries_Manual_guide/node0102.html#line8) attributes, an extended version of the
NewWindow structure has been created named [ExtNewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line1039).

Setting WFLG_NW_EXTENDED in the NewWindow.Flags field specifies to the
[OpenWindow()](../Libraries_Manual_guide/node0103.html) call that this [NewWindow](../Libraries_Manual_guide/node0102.html#line8) structure is really an [ExtNewWindow](../Libraries_Manual_guide/node0102.html#line8)
structure.  This is simply a standard NewWindow structure with a pointer
to a tag list at the end.  Since WFLG_NW_EXTENDED is ignored prior to V36,
information provided in the tag list will be ignored by earlier versions
of Intuition.  Note that WFLG_NW_EXTENDED may not be specified in the
[WA_Flags](../Libraries_Manual_guide/node0125.html#line147) tag.

