# App.A EA IFF/ LISTs, CATs, and Shared Properties (Advanced topics)


Data often needs to be grouped together, for example, consider a list of
icons. Sometimes a trick like arranging little images into a big raster
works, but generally they'll need to be structured as a first class group.
The objects "[LIST](../Devices_Manual_guide/node01CA.html#line49)" and "[CAT](../Devices_Manual_guide/node01CA.html#line2) " are IFF-universal mechanisms for this
purpose.  Note: [LIST](../Devices_Manual_guide/node01CA.html#line49) and CAT are advanced topics the first time reader
will want to skip.

Property settings sometimes need to be shared over a list of similar
objects. E.g., a list of icons may share one color map.  [LIST](../Devices_Manual_guide/node01CA.html#line49) provides a
means called "[PROP](../Devices_Manual_guide/node01CA.html#line49)" to do this.  One purpose of a LIST is to define the
scope of a PROP. A "[CAT](../Devices_Manual_guide/node01CA.html#line2) ", on the other hand, is simply a concatenation of
objects.

Simpler programs may skip [LIST](../Devices_Manual_guide/node01CA.html#line49)s and [PROP](../Devices_Manual_guide/node01CA.html#line49)s altogether and just handle [FORM](../Devices_Manual_guide/node01C7.html#line52)s
and [CAT](../Devices_Manual_guide/node01CA.html#line2) s.  All "fully-conforming" IFF programs also know about "CAT ",
"LIST", and "PROP".  Any program that reads a [FORM](../Devices_Manual_guide/node01C7.html#line52) inside a LIST must
process shared PROPs to correctly interpret that FORM.

 [Group CAT](../Devices_Manual_guide/node01EB.html)     [Group LIST](../Devices_Manual_guide/node01EC.html)     [Group PROP](../Devices_Manual_guide/node01ED.html)     [Properties for LIST](../Devices_Manual_guide/node01EE.html) 

