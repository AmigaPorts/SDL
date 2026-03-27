# 10 Printer Device / Obtaining Printer Specific Data


Information about the printer in use can be obtained by reading the
[PrinterData](../Includes_and_Autodocs_2._guide/node005A.html#line65) and [PrinterExtendedData](../Includes_and_Autodocs_2._guide/node005A.html#line134) structures.  The values found in these
structures are determined by the printer driver selected through
Preferences.  The data structures are defined in devices/[prtbase.h](../Includes_and_Autodocs_2._guide/node005A.html).

Printer specific data is returned in [printerIO](../Devices_Manual_guide/node0044.html#line16) when the printer device is
opened.  To read the structures, you must first set the [PrinterData](../Includes_and_Autodocs_2._guide/node005A.html#line65)
structure to point to iodrp.io_Device of the [printerIO](../Devices_Manual_guide/node0044.html#line16) used to open the
device and then set [PrinterExtendedData](../Includes_and_Autodocs_2._guide/node005A.html#line134) to point to the extended data
portion of [PrinterData](../Includes_and_Autodocs_2._guide/node005A.html#line65).


```c
     [Printer_Data.c](../Devices_Manual_guide/node0163.html) 
```
