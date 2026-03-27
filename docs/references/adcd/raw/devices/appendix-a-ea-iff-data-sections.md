# Appendix A / EA IFF/ Data Sections


The first thing we need of a file is to check: Does it contain IFF data
and, if so, does it contain the kind of data we're looking for?  So we
come to the notion of a "data section".

A "data section" or IFF "[FORM](../Devices_Manual_guide/node01C7.html#line52)" is one self-contained "data object" that
might be stored in a file by itself.  It is one high level data object
such as a picture or a sound effect, and generally contains a grouping of
chunks.  The IFF structure "FORM" makes it self-identifying.  It could be
a composite object like a musical score with nested musical instrument
descriptions.

 [Group FORM](../Devices_Manual_guide/node01E3.html) 
 [Composite FORMs](../Devices_Manual_guide/node01E4.html) 
 [Designing New Data Sections](../Devices_Manual_guide/node01E9.html) 

