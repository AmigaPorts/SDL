# 8 Intuition Images, Line Drawing and Text / Creating Images


With an [Image](../Libraries_Manual_guide/node01BA.html) structure an application can create graphic objects quickly
and easily and display them almost anywhere.  Images have an additional
attribute that makes them even more economical--by changing two simple
data elements in the Image structure, the color of the image may be
changed.

Images are rectangular bitmaps which individually define the color of each
pixel represented.  Images may not be masked to allow part of the
background to show through.  The entire rectangular image is drawn into
the target element, overwriting any data it may overlap.  All bitplanes
defined in the target [RastPort](../Libraries_Manual_guide/node034A.html) within the image's rectangle are
overwritten either with image data, ones or zeros.

[Image](../Libraries_Manual_guide/node01BA.html)s may be directly drawn by the application by using the [DrawImage()](../Libraries_Manual_guide/node01BB.html)
function, described below.  The image may be rendered into any screen or
window [RastPort](../Libraries_Manual_guide/node034A.html) with this function.  ([DrawImageState()](../Includes_and_Autodocs_2._guide/node0211.html) can also be used to
draw the image.

The visual imagery for an [Image](../Libraries_Manual_guide/node01BA.html) can be removed from the display by calling
[EraseImage()](../Includes_and_Autodocs_2._guide/node0215.html).  For a normal Image structure, this will call the graphics
function [EraseRect()](../Includes_and_Autodocs_2._guide/node0439.html), which clears the Image rectangle by using the
layer's backfill pen to overwrite it.

Alternately, images can be used indirectly by attaching them to menus,
gadgets or requesters when they are initialized.  For instance, in menus
the [MenuItem](../Libraries_Manual_guide/node019A.html) structure has the [ItemFill](../Libraries_Manual_guide/node019A.html#line47) and [SelectFill](../Libraries_Manual_guide/node019A.html#line64) fields.  If the
[ITEMTEXT](../Libraries_Manual_guide/node019B.html#line14) flag is cleared and the [HIGHIMAGE](../Libraries_Manual_guide/node019B.html#line53) flag is set, the application
may place a pointer to a list of [Image](../Libraries_Manual_guide/node01BA.html) structures in each of these fields.
The system will display the ItemFill images when the menu item is not
selected and the SelectFill images when the menu item is selected.  The
application does not have to take any specific action to display these
images.  Once the menus have been added to a window, their management and
display is under Intuition control.

The number of bitplanes in an image does not have to match the number of
bitplanes in the display element in which the image is rendered.  This
provides great flexibility in using [Image](../Libraries_Manual_guide/node01BA.html) structures, as the same image
may be reused in many places.

If the application's window is on the Workbench or some other public
screen, it must use caution with hard-coded or constant image data, as the
color palette of that screen is subject to change.  If the application has
its own custom screen, and it is appropriate for the colors of that screen
to change, the same situation arises.  Starting with V36, Intuition allows
the screen opener to provide a mapping of pen number and rendering
functions.  For example, pens are specified for the bright and dark edges
of three dimensional objects.  Applications can obtain this mapping from
the [DrawInfo](../Libraries_Manual_guide/node00DE.html#line6) structure.  See the "[Intuition Screens](../Libraries_Manual_guide/node00EB.html)" chapter for more
information on DrawInfo and the new 3D look of Intuition in Release 2.

A suitably designed image may be drawn into a screen or window of any
depth.  To accomplish this, the application must ensure that detail is not
lost when the image is displayed in a single bitplane [RastPort](../Libraries_Manual_guide/node034A.html), where only
the first bitplane of image data will be displayed.  This is important if
the image will ever be displayed on the Workbench screen or any other
public screen.

 [Image Structure](../Libraries_Manual_guide/node01BA.html)               [Picking Bitplanes for Image Display](../Libraries_Manual_guide/node01BE.html) 
 [Directly Drawing the Image](../Libraries_Manual_guide/node01BB.html)    [Image Example](../Libraries_Manual_guide/node01BF.html) 
 [Image Data](../Libraries_Manual_guide/node01BC.html) 

