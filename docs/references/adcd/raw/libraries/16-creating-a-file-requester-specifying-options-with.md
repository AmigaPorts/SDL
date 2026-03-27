# 16 / Creating a File Requester / Specifying Options with TagItems


Both [AllocAslRequest()](../Libraries_Manual_guide/node027B.html) and [AslRequest()](../Libraries_Manual_guide/node027B.html#line43) accept a [TagItem](../Libraries_Manual_guide/node0497.html) array or tag list
as an argument.  The tag list is used to initialize or alter the values in
the requester data structure.

A single [TagItem](../Libraries_Manual_guide/node0497.html) consists of a tag name and an associated tag value.  Tag
items that apply to the asl.library are defined in <libraries/[asl.h](../Includes_and_Autodocs_2._guide/node00EA.html#line86)>.  The
basic tag items (used in the [first example](../Libraries_Manual_guide/node057F.html) listed below) are:


   Requester
   Tag Name        Used For
   ---------       --------
   ASL_Hail        String to place in the title bar of the requester window
   ASL_Width       Requester window width
   ASL_Height      Requester window height
   ASL_LeftEdge    Requester window y origin
   ASL_TopEdge     Requester window x origin
   ASL_OKText      String to place in OK gadget of requester
   ASL_CancelText  String to place in Cancel gadget of requester
   ASL_File        Default file name (for file requesters only)
   ASL_Dir         Default directory name (for file requesters only)


Note that you are currently limited to about six characters for the
replacement text if you use either the ASL_OKText or ASL_CancelText tags
to change the text that appears in the OK and Cancel gadgets.

The contents of an ASL requester data structure are preserved across calls
to [AslRequest()](../Libraries_Manual_guide/node027B.html#line43).  So, until the requester is freed, tag settings and user
selections will remain in the data structure unless they are altered by
tags in subsequent calls to AslRequest().  This is very useful because it
allows the requester to remember and redisplay the user's previous
selections.  However, this also means that the programmer must assure that
any addresses passed in ASL tags remain valid, or are refreshed on each
call to AslRequest().

Generally, options that you wish to specify only once, such as the initial
position and size, should be specified as tags when you allocate the
requester.  Options that you wish to control for each use of the requester
should be passed as tags each time the requester is opened with
[AslRequest()](../Libraries_Manual_guide/node027B.html#line43).

