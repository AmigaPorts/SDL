# B / gadgetclass / Attributes:GA_IntuiText, GA_Text, GA_LabelImage (IS)


These attributes correspond to one field in the object's embedded [Gadget](../Libraries_Manual_guide/node0149.html)
structure--the [GadgetText](../Libraries_Manual_guide/node0149.html#line111) field.  Setting any of these attributes copies
the attribute's value blindly into the GadgetText field.  In addition,
setting GA_Text also sets the [GFLG_LABELSTRING](../Includes_and_Autodocs_2._guide/node00D4.html#line298) flag in [Gadget.Flags](../Libraries_Manual_guide/node0149.html#line48) and
setting GA_LabelImage sets the [GFLG_LABELIMAGE](../Includes_and_Autodocs_2._guide/node00D4.html#line298) flag in Gadget.Flags.  The
GA_IntuiText attribute must be an [IntuiText](../Libraries_Manual_guide/node01C7.html) pointer, as with old-style
gadgets.  GA_Text takes a pointer to a NULL- terminated string (UBYTE *).
GA_LabelImage takes a pointer to a (Boopsi) image.  Note that most gadget
classes do not support GA_Text and GA_LabelImage.  See the description of
specific gadget classes for more details.

