# 12 Serial Device


The serial device provides a hardware-independent interface to the Amiga's
built-in RS-232C compatible serial port.  Serial ports have a wide range
of uses, including communication with modems, printers, MIDI devices, and
other computers.  The same device interface can be used for additional
"byte stream oriented devices" - usually more serial ports.  The serial
device is based on the conventions of Exec device I/O, with extensions for
parameter setting and control.


                   Serial Device Characteristics
                   -----------------------------
                   MODES           Exclusive
                                   Shared Access

                   BAUD RATES      110-292,000

                   HANDSHAKING     Three-Wire
                                   Seven-Wire
 [Serial Device Commands and Functions](../Devices_Manual_guide/node009B.html) 
 [Device Interface](../Devices_Manual_guide/node009C.html) 
 [A Simple Serial Port Example](../Devices_Manual_guide/node0192.html) 
 [Alternative Modes for Serial Input or Output](../Devices_Manual_guide/node00A1.html) 
 [Setting Serial Parameters (SDCMD_SETPARAMS)](../Devices_Manual_guide/node00A6.html) 
 [Querying the Serial Device](../Devices_Manual_guide/node00A8.html) 
 [Sending the Break Command](../Devices_Manual_guide/node00A9.html) 
 [Error Codes from the Serial Device](../Devices_Manual_guide/node00AA.html) 
 [Multiple Serial Port Support](../Devices_Manual_guide/node00AB.html) 
 [Taking Over the Hardware](../Devices_Manual_guide/node00AC.html) 
 [Advanced Example of Serial Device Usage](../Devices_Manual_guide/node0193.html) 
 [Additional Information on the Serial Device](../Devices_Manual_guide/node00AD.html) 

