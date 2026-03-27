# 6 Input Device


The input device is the central collection point for input events
disseminated throughout the system. The best way to describe the input
device is a manager of a stream with feeders.  The input device itself and
other modules such as the file system add events to the stream; so do
input device "users" - programs or other devices that use parts of the
stream or change it in some way.  Feeders of the input device include the
keyboard, timer and gameport devices.  The keyboard, gameport, and timer
devices are special cases in that the input device opens them and asks
them for input. Users of the input device include Intuition and the
console device.


```c
                     NEW FEATURES FOR VERSION 2.0

                    Feature              Description
             ---------------------    -----------------
             [IECLASS_NEWPOINTERPOS](../Devices_Manual_guide/node00D6.html)    Input Event Class
             IECLASS_MENUHELP         Input Event Class
             IECLASS_CHANGEWINDOW     Input Event Class
             IESUBCLASS_COMPATIBLE    Input Event SubClass
             IESUBCLASS_PIXEL         Input Event SubClass
             IESUBCLASS_TABLET        Input Event SubClass
             [PeekQualifier()](../Includes_and_Autodocs_2._guide/node04E9.html)          Function
```
   Compatibility Warning:
   ----------------------
   The new features for the 2.0 input device are not backwards
   compatible.

 [Input Device Commands and Functions](../Devices_Manual_guide/node00CB.html) 
 [Device Interface](../Devices_Manual_guide/node00CC.html) 
 [Using the Mouse Port With the Input Device](../Devices_Manual_guide/node00D0.html) 
 [Adding an Input Handler](../Devices_Manual_guide/node00D2.html) 
 [Writing Events to the Input Device Stream](../Devices_Manual_guide/node00D5.html) 
 [Setting the Key Repeat Threshold](../Devices_Manual_guide/node00D7.html) 
 [Setting the Key Repeat Interval](../Devices_Manual_guide/node00D8.html) 
 [Determining the Current Qualifiers](../Devices_Manual_guide/node00D9.html) 
 [Input Device and Intuition](../Devices_Manual_guide/node00DA.html) 
 [Example Input Device Program](../Devices_Manual_guide/node019A.html) 
 [Additional Information on the Input Device](../Devices_Manual_guide/node00DB.html) 

