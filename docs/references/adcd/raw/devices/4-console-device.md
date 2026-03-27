# 4 Console Device


The console device provides the text-oriented interface for Intuition
windows.  It acts like an enhanced ASCII terminal obeying many of the
standard ANSI sequences as well as special sequences unique to the Amiga.
The console device also provides a copy-and-paste facility and an internal
character map to redraw a window when it is resized.


```c
                  NEW CONSOLE FEATURES FOR VERSION 2.0

               Feature                       Description
               -------                       -----------
              [CONU_LIBRARY](../Devices_Manual_guide/node0084.html#line21)                    New #define
              [CONU_STANDARD](../Devices_Manual_guide/node0084.html#line24)                   New #define
              [CONU_CHARMAP](../Devices_Manual_guide/node0084.html#line26)                    Console Unit
              [CONU_SNIPMAP](../Devices_Manual_guide/node0084.html#line28)                    Console Unit
              [CONFLAG_DEFAULT](../Devices_Manual_guide/node0084.html#line42)                 Console Flag
              [CONFLAG_NODRAW_ON_NEWSIZE](../Devices_Manual_guide/node0084.html#line45)       Console Flag
```
   Compatibility Warning:
   ----------------------
   The new features for the 2.0 console device are not backwards
   compatible.

 [Console Device Commands and Functions](../Devices_Manual_guide/node0081.html) 
 [Device Interface](../Devices_Manual_guide/node0082.html) 
 [About Console I/O](../Devices_Manual_guide/node0086.html) 
 [Writing to the Console Device](../Devices_Manual_guide/node008A.html) 
 [Reading from the Console Device](../Devices_Manual_guide/node008F.html) 
 [Copy and Paste Support](../Devices_Manual_guide/node0093.html) 
 [Selecting Raw Input Events](../Devices_Manual_guide/node0094.html) 
 [Input Event Reports](../Devices_Manual_guide/node0095.html) 
 [Using the Console Device Without a Window](../Devices_Manual_guide/node0096.html) 
 [Where Is All the Keymap Information?](../Devices_Manual_guide/node0097.html) 
 [Console Device Caveats](../Devices_Manual_guide/node0098.html) 
 [Console Device Example Code](../Devices_Manual_guide/node0190.html) 
 [Additional Information on the Console Device](../Devices_Manual_guide/node0099.html) 

