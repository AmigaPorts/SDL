# 36 Translator Library


This chapter describes the translator library which, together with the
narrator device, provides the Amiga's text-to-speech capability. To fully
understand how speech is produced on the Amiga, you should also read the
"[Narrator Device](../Devices_Manual_guide/node0113.html)" chapter of the Amiga ROM Kernel Reference Manual:
Devices.

The translator library provides a single function, [Translate()](../Libraries_Manual_guide/node0492.html), that
converts an English language string into a phonetic string. You may then
pass this phonetic string to the narrator device which will say the string
using the Amiga's audio hardware. The two subsystems may also be used
individually.  You don't have to use the narrator to say the phonetic
strings; you could use them instead for phonetic analysis or some other
special purpose.

 [Opening the Translator Library](../Libraries_Manual_guide/node0491.html)    [Closing the Translator Library](../Libraries_Manual_guide/node0493.html) 
 [Using the Translate Function](../Libraries_Manual_guide/node0492.html)      [Additional Notes About Translate](../Libraries_Manual_guide/node0494.html) 

