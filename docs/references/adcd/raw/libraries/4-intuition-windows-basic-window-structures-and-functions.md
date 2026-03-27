# 4 Intuition Windows / Basic Window Structures and Functions


This section introduces the basic data structures and functions an
application uses to create an Intuition window.  Intuition uses the Window
data structure defined in <intuition/[intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html)> to represent windows.
Most of Intuition's window functions use this structure in some way.
Other related structures used to create and operate windows are summarized
in Table 4-1.




       Table 4-1: Data Structures Used with Intuition Windows
  Structure Name  Description                    Defined in Include File
  --------------  -----------                    -----------------------
  [Window](../Libraries_Manual_guide/node0121.html)          Main Intuition structure that  <intuition/[intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line797)>

                  defines a window
  [TagItem](../Libraries_Manual_guide/node0104.html)         General purpose parameter        <utility/[tagitem.h](../Includes_and_Autodocs_2._guide/node012E.html#line31)>

                  structure used to set up
                  windows in V37
  NewWindow       Parameter structure used to    <intuition/[intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line973)>

                  create a window in V34
  [ExtNewWindow](../Libraries_Manual_guide/node0123.html)    An extension to the NewWindow  <intuition/[intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line1039)>

                  structure used in V37 for
                  backward compatibility with
                  older systems
  [Layer](../Libraries_Manual_guide/node03E4.html)           A drawing rectangle that          <graphics/[clip.h](../Includes_and_Autodocs_2._guide/node00A1.html#line33)>

                  clips graphic operations
                  falling within its boundaries
  [RastPort](../Libraries_Manual_guide/node034A.html)        General purpose handle used     <graphics/[rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html#line55)>


                  for graphics library drawing
                  operations.
Intuition's window system relies on the layers library and graphics
library to implement many of its features.  The Window structure is
closely related to the Layer structure defined in <graphics/[clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)> and
the RastPort structure defined in <graphics/[rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)>.  The system uses
these structures to store drawing state data. In general, applications
don't have to worry about the internal details of these structures but use
them instead as convenient handles, passing them as arguments to
lower-level functions. See the "[Layers Library](../Libraries_Manual_guide/node03E3.html)" and "[Graphics Primitives](../Libraries_Manual_guide/node0349.html)"
chapters for more information.

 [Opening a Window](../Libraries_Manual_guide/node0103.html)                [Window Dimensions](../Libraries_Manual_guide/node0108.html) 
 [Closing Windows](../Libraries_Manual_guide/node0105.html)                 [Window Border Dimensions](../Libraries_Manual_guide/node010A.html) 
 [Windows and Screens](../Libraries_Manual_guide/node0106.html)             [Changing Window Size Limits](../Libraries_Manual_guide/node010B.html) 
 [Graphics and Text in Windows](../Libraries_Manual_guide/node0107.html) 

