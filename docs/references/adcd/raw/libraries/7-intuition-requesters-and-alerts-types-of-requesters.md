# 7 Intuition Requesters and Alerts / Types Of Requesters


There are at least three kinds of display objects in Amiga terminology
called requesters:  [true](../Libraries_Manual_guide/node01A1.html) requesters, [system](../Libraries_Manual_guide/node01AF.html) requesters and ASL requesters.

[True](../Libraries_Manual_guide/node01A1.html) requesters are general purpose display areas that can be thought of
as temporary sub-windows.  They display information to the user and allow
the user to make a selection.  True requesters always open within an
existing window and are constrained to the boundaries of that window
(often referred to as the parent window).  If a requester extends beyond
the edge of its parent window, either its position is adjusted or its
graphics are clipped.  True requesters always block input to their parent
window as long as they are present.

[System](../Libraries_Manual_guide/node01AF.html) requesters are typically used for warnings or to confirm an action
the user has just initiated.  System requesters differ from [true](../Libraries_Manual_guide/node01A1.html)
requesters in that they cannot block input to the parent window.  In fact,
system requesters do not open in a parent window at all, but instead open
their own separate window in the screen.  Since these requesters are so
different from true requesters, they will be discussed separately later in
the chapter.  See the sections on "[Easy Requesters](../Libraries_Manual_guide/node01AC.html)" and "[System Requests](../Libraries_Manual_guide/node01AF.html)"
for more information.

The third type of requester, the ASL requester, is a special purpose
requester available only in Release 2 and later versions of the OS.  ASL
requesters provide an easy, standard way to get a filename from the user
for load and save operations.  They can also be used to get a font
selection from the user.  Since selecting a file or font name is one of
the most common uses for a requester, it has been incorporated into
Release 2 as a standard feature.  For the details about ASL file and font
requesters, see Chapter 16, "[ASL Library](../Libraries_Manual_guide/node0279.html)".

