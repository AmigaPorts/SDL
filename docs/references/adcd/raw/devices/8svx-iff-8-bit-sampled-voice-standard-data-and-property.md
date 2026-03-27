# 8SVX IFF 8-Bit Sampled Voice / Standard Data and Property Chunks


[FORM 8SVX](../Devices_Manual_guide/node02C9.html) stores all the waveform data in one body chunk "[BODY](../Devices_Manual_guide/node02D0.html)".  It
stores playback parameters in the required header chunk "[VHDR](../Devices_Manual_guide/node02CD.html)".  "VHDR"
and any optional property chunks "[NAME](../Devices_Manual_guide/node02CE.html)", "[(c)](../Devices_Manual_guide/node02CE.html) ", and "[AUTH](../Devices_Manual_guide/node02CE.html)" must all
appear before the BODY chunk.  Any of these properties may be shared over
a LIST of FORMs 8SVX by putting them in a PROP 8SVX.  [See "[EA IFF 85](../Devices_Manual_guide/node01C5.html)"
Standard for Interchange Format Files.]

 [Background](../Devices_Manual_guide/node02CC.html) 
 [Required Property VHDR](../Devices_Manual_guide/node02CD.html) 
 [Optional Text Chunks](../Devices_Manual_guide/node02CE.html) 
 [Optional Data Chunks ATAK and RLSE](../Devices_Manual_guide/node02CF.html) 
 [Data Chunk BODY](../Devices_Manual_guide/node02D0.html) 
 [Other Chunks](../Devices_Manual_guide/node02D1.html) 

