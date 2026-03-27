# FTXT IFF Formatted / Standard Data and Property Chunks


The main contents of a [FORM FTXT](../Devices_Manual_guide/node0168.html) is in its character stream "[CHRS](../Devices_Manual_guide/node016D.html)" chunks.
Formatting property chunks may also appear.  The only formatting property
yet defined is "[FONS](../Devices_Manual_guide/node016E.html)", a font specifier.  A FORM FTXT with no CHRS
represents an empty text stream.  A FORM FTXT may contain nested IFF
[FORM](../Devices_Manual_guide/node01C7.html#line51)s, [LIST](../Devices_Manual_guide/node01CA.html#line49)s, or [CAT](../Devices_Manual_guide/node01CA.html) s, although a "stripping" reader (see section 3) will
ignore them.

 [Character Sets](../Devices_Manual_guide/node016B.html) 
 [Control Sequences](../Devices_Manual_guide/node016C.html) 
 [Data Chunk CHRS](../Devices_Manual_guide/node016D.html) 
 [Property Chunk FONS](../Devices_Manual_guide/node016E.html) 
 [Future Properties](../Devices_Manual_guide/node016F.html) 
 [Positioning Units](../Devices_Manual_guide/node0170.html) 

