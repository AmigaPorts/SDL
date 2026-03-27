# 27 Graphics Primitives / ECS and Genlocking Features


The Enhanced Chip Set (ECS) Denise chip (8373-R2a), coupled with the
Release 2 graphics library, opens up a whole new set of genlocking
possibilities.  Unlike the old Denise, whose only genlocking ability
allowed keying on color register zero, the ECS Denise allows keying on any
color register.  Also, the ECS Denise allows keying on any bitplane of the
[ViewPort](../Libraries_Manual_guide/node032B.html#line59) being genlocked.  With the ECS Denise, the border area
surrounding the display can be made transparent (always passes video) or
opaque (overlays using color 0).  All the new features are set
individually for each ViewPort.  These features can be used in conjunction
with each other, making interesting scenarios possible.

 [Genlock Control](../Libraries_Manual_guide/node036D.html) 

