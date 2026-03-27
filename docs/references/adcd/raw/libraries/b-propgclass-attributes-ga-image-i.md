# B / propgclass / Attributes: GA_Image (I)


[Propgclass](../Libraries_Manual_guide/node0507.html) intercepts this [gadgetclass](../Libraries_Manual_guide/node04F2.html) attribute before passing it on to
gadgetclass.  This attribute passes an image for the prop gadget's knob,
which gets stored in the propgclass object's [Gadget.Image](../Libraries_Manual_guide/node0149.html#line91) structure.  If
the propgclass does not get a GA_Image when it creates a prop gadget, the
prop gadget's knob defaults to an AUTOKNOB.  An AUTOKNOB automatically
sizes itself according to how large the range of the gadget is compared to
the visible range of the gadget.  See the [PGA_Visible](../Libraries_Manual_guide/node050F.html) and [PGA_Total](../Libraries_Manual_guide/node050F.html)
attributes for more details.

