# B / propgclass / Attributes: GA_Highlight (I)


[Propgclass](../Libraries_Manual_guide/node0507.html) intercepts this [gadgetclass](../Libraries_Manual_guide/node04F2.html) attribute before passing it on to
gadgetclass.  It does this to make sure the highlighting is not set to
GADGHBOX.  GADGHBOX will be converted to GADGHCOMP.  See the
"[Intuition Gadgets](../Libraries_Manual_guide/node013E.html)" chapter of the Amiga ROM Kernel Reference Manual:
Libraries for more information on the types of gadget highlighting.

Other [gadgetclass](../Libraries_Manual_guide/node04F2.html) attributes are passed along to the superclass.

