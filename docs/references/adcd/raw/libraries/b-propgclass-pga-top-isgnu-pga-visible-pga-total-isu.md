# B / propgclass / PGA_Top (ISGNU), PGA_Visible, PGA_Total (ISU)


These attributes replace the [Pot](../Libraries_Manual_guide/node015B.html) and [Body](../Libraries_Manual_guide/node015C.html) variables of the Release 1.3
prop gadget. They are based on the use of proportional gadgets to control
scrolling text.  When scrolling 100 lines of text in a 25 line visible
window, you would set PGA_Total to 100, PGA_Visible to 25, and watch
PGA_Top run from 0 to 75 (the top line of the last page).

If the user clicks in the prop gadget but not on the knob, the entire knob
jumps one "page" (the size of the visible area minus one, PGA_Visible-1).
The page jump will leave an overlap of one line, unless the value
PGA_Visible is 1, in which case the prop gadget acts as an integer numeric
slider, sliding from 0 to PGA_Total - 1.

Note that when PGA_Top changes, the gadget sends itself an [OM_NOTIFY](../Libraries_Manual_guide/node04F9.html)
message about this attribute change (see the [propgclass](../Libraries_Manual_guide/node0507.html) description of
[GM_HANDLEINPUT](../Libraries_Manual_guide/node0508.html) for more information).  All three of these attributes have
[OM_UPDATE](../Libraries_Manual_guide/node04C4.html) access, so they can be controlled from other objects.

