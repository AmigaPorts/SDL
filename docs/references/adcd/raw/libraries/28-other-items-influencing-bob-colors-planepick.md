# 28 / / Other Items Influencing Bob Colors / PlanePick


Because the [Depth](../Libraries_Manual_guide/node039D.html#line10) of the Bob can be less than the background, the
[PlanePick](../Includes_and_Autodocs_2._guide/node00C3.html#line123) member is provided so that the application can indicate which
background bitplanes are to have image data put into them.  The system
starts with the least significant plane of the Bob, and scans PlanePick
starting at the least significant bit, looking for a plane of the [RastPort](../Libraries_Manual_guide/node034A.html)
to put it in.

For example, if [PlanePick](../Includes_and_Autodocs_2._guide/node00C3.html#line123) has a binary value of: 0 0 0 0   0 0 1 1 (0x03)
then the system draws the first plane of the Bob's image into background
plane 0 and the second plane into background plane 1.

Alternatively, a [PlanePick](../Includes_and_Autodocs_2._guide/node00C3.html#line123) value of:  0 0 0 1   0 0 1 0 (0x12) directs the
system to put the first Bob plane into plane 1, and the second Bob plane
into plane 4.

