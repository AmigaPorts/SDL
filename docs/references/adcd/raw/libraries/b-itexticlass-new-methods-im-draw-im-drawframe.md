# B / itexticlass / New Methods: IM_DRAW/IM_DRAWFRAME


These methods ask an [itexticlass](../Libraries_Manual_guide/node04F0.html) object to render its [IntuiText](../Libraries_Manual_guide/node01C7.html) structure,
which it gets from the [imageclass](../Libraries_Manual_guide/node04D1.html) [IA_Data](../Libraries_Manual_guide/node04DD.html) attribute.  An itexticlass
object renders its IntuiText relative to the [IA_Left](../Libraries_Manual_guide/node04DB.html) and [IA_Top](../Libraries_Manual_guide/node04DB.html) attributes
it inherits from imageclass.  This method uses the JAM1 drawing mode and
the [IA_FGPen](../Libraries_Manual_guide/node04DC.html) to render the text.  See the imageclass description of
[IM_DRAW](../Libraries_Manual_guide/node04D2.html)/[IM_DRAWFRAME](../Libraries_Manual_guide/node04D5.html) for more details.

