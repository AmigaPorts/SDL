# 5 / Producing High-quality Sound / Efficiency


A certain amount of overhead is involved in the handling of audio DMA.
If you are trying to produce a smooth continuous audio synthesis, you
should try to avoid as much of the system control overhead as possible.
Basically, the larger the audio buffer you provide to the system, the less
often it will need to  [interrupt](../Hardware_Manual_guide/node016B.html)  to reset the pointers to the top of the
next buffer and, coincidentally, the lower the amount of system
interaction that will be required. If there is only one waveform buffer,
the hardware automatically resets the pointers, so no software overhead is
used for resetting them.

The  [Joining Tones](../Hardware_Manual_guide/node00E4.html)  section illustrated how you could join "ends" of tones
together by responding to  [interrupts](../Hardware_Manual_guide/node016B.html)  and changing the values of the
 [location registers](../Hardware_Manual_guide/node00DB.html)  to splice tones together. If your system is heavily
loaded, it is possible that the response to the  [interrupt](../Hardware_Manual_guide/node016B.html)  might not
happen in time to assure a smooth audio transition. Therefore, it is
advisable to utilize the longest possible audio table where a smooth
output is required. This takes advantage of the audio DMA capability as
well as minimizing the number of  [interrupts](../Hardware_Manual_guide/node016B.html)  to which the 680x0 must
respond.

