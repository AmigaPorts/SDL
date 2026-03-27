# ILBM IFF Interleaved Bitmap / Standard Properties


ILBM has several defined property [chunk](../Devices_Manual_guide/node01DD.html)s that act on the main data chunks.
The required property "[BMHD](../Devices_Manual_guide/node01AF.html)" and any optional properties must appear
before any "[BODY](../Devices_Manual_guide/node01B7.html)" chunk.  (Since an ILBM has only one BODY chunk, any
following properties would be superfluous.)  Any of these properties may
be shared over a [LIST](../Devices_Manual_guide/node01CA.html#line49) of several ILBMs by putting them in a PROP ILBM (See
the EA IFF 85 document).

 [BMHD](../Devices_Manual_guide/node01AF.html) 
 [CMAP](../Devices_Manual_guide/node01B0.html) 
 [GRAB](../Devices_Manual_guide/node01B1.html) 
 [DEST](../Devices_Manual_guide/node01B2.html) 
 [SPRT](../Devices_Manual_guide/node01B3.html) 
 [CAMG](../Devices_Manual_guide/node01B4.html) 

