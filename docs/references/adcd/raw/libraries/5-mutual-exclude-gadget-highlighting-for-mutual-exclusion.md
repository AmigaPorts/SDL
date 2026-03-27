# 5 / / Mutual Exclude / Gadget Highlighting for Mutual Exclusion


When using complement mode highlighting, the image supplied must be at
least the size of the complemented area (the gadget select box).  An
extended [boolean](../Libraries_Manual_guide/node014C.html) gadget with a mask may be used to constrain the area that
is highlighted.

Alternate image highlighting may be used provided the two images have
exactly the same size and position.  Likewise, a border and alternate
border may be used provided the two borders are identical in shape and
position, differing only in color.

Do not use other combinations for mutual exclude gadgets such as a gadget
with a border that uses complement mode highlighting or a gadget which
uses highlighting by drawing a box.  See the section on
"[Updating a Gadget's Imagery](../Libraries_Manual_guide/node0145.html)" for more information.

