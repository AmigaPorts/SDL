# 3 Clipboard Device


The clipboard device allows the exchange of data dynamically between one
application and another. It is responsible for caching data that has been
"cut" and providing data to "paste" in an application. A special
"post" mode allows an application to inform the clipboard device that
the application has data available. The clipboard device will request this
data only if the data is actually needed. The clipboard will cache the
data in RAM and will automatically spool the data to disk if necessary.

The clipboard device is implemented as an Exec-style device, and supports
random access reads and writes on data within the clipboard. All data in
the clipboard must be in IFF format.  A new library, [IFFParse Library](../Libraries_Manual_guide/node0427.html), has
been added to the Amiga libraries.  The routines in iffparse.library can
and should be used for reading and writing data to the clipboard.  This
chapter contains a brief discussion of IFF as it relates to the clipboard
(for more details see [Appendix A](../Devices_Manual_guide/node0129.html)).


```c
               NEW CLIPBOARD FEATURES FOR VERSION 2.0

                   Feature                 Description
               --------------             --------------
               [CBD_CHANGEHOOK](../Includes_and_Autodocs_2._guide/node04D9.html)             Device Command
```
   Compatibility Warning:
   ----------------------
   The new features for the 2.0 clipboard device are not backwards
   compatible.

 [Clipboard Device Commands and Functions](../Devices_Manual_guide/node0066.html) 
 [Device Interface](../Devices_Manual_guide/node0067.html) 
 [Monitoring Clipboard Changes](../Devices_Manual_guide/node0070.html) 
 [Example Clipboard Programs](../Devices_Manual_guide/node018C.html) 
 [Support Functions Called from Example Programs](../Devices_Manual_guide/node018D.html) 
 [Include File for the Example Programs](../Devices_Manual_guide/node018E.html) 
 [Additional Information on the Clipboard Device](../Devices_Manual_guide/node0072.html) 

