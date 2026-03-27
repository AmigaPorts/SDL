# 10 / Creating a Printer Driver / Writing Alphanumeric Printer Drivers


The alphanumeric portion of the printer driver is designed to convert ANSI
x3.64 style commands into the specific escape codes required by each
individual printer.  For example, the ANSI code for underline-on is
ESC[4m.  The Commodore MPS-1250 printer would like a ESC[-1 to set
underline-on. The HP LaserJet accepts ESC[&dD as a start underline
command. By using the printer driver, all printers may be handled in a
similar manner.

There are two parts to the alphanumeric portion of the printer driver: the
Command Table data table and the DoSpecial() routine.

 [Command Table](../Devices_Manual_guide/node0056.html) 
 [DoSpecial()](../Devices_Manual_guide/node0057.html) 
 [Printertag.asm](../Devices_Manual_guide/node0058.html) 
 [Extended Character Table](../Devices_Manual_guide/node0059.html) 
 [Character Conversion Routine](../Devices_Manual_guide/node005A.html) 

