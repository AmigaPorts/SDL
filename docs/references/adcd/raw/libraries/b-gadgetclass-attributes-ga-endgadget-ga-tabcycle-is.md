# B / gadgetclass / Attributes: GA_EndGadget - GA_TabCycle (IS)


GA_EndGadget, GA_Immediate, GA_RelVerify, GA_FollowMouse, (IS)
GA_RightBorder, GA_LeftBorder, GA_TopBorder, GA_BottomBorder, (IS)
GA_ToggleSelect, GA_TabCycle (IS) - These are boolean attributes that
correspond to the flags in the object's [Gadget.Activation](../Libraries_Manual_guide/node0149.html#line53) field.  If the
value passed with the attribute is TRUE, the corresponding flag in
Gadget.Activation is set.  If the value passed with the attribute is
FALSE, the corresponding flag in Gadget.Activation is cleared.  See the
<intuition/[intuition.h](../Includes_and_Autodocs_2._guide/node00D4.html#line212)> include file or the "[Intuition Gadgets](../Libraries_Manual_guide/node0149.html)" chapter of
the Amiga ROM Kernel Reference Manual: Libraries for more information.

