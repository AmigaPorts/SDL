# 10 / Creating a Printer Driver / Writing A Graphics Printer Driver


Designing the graphics portion of a custom printer driver consists of two
steps: writing the printer-specific [Render()](../Devices_Manual_guide/node005C.html), [Transfer()](../Devices_Manual_guide/node005D.html) and [SetDensity()](../Devices_Manual_guide/node005E.html)
functions, and replacing the printer-specific values in printertag.asm.
Render(), Transfer() and SetDensity() comprise render.c, transfer.c, and
density.c modules, respectively.

A printer that does not support graphics has a very simple form of
Render(); it returns an error. Here is sample code for Render() for a
non-graphics printer (such as an Alphacom or Diablo 630):

   #include "exec/types.h"
   #include "devices/printer.h"
   int Render()
   {
```c
       return(PDERR_NOTGRAPHICS);
```
   }

The following section describes the contents of a typical driver for a
printer that does support graphics.

 [Render()](../Devices_Manual_guide/node005C.html)      [Transfer()](../Devices_Manual_guide/node005D.html)      [SetDensity()](../Devices_Manual_guide/node005E.html)      [Printertag.asm](../Devices_Manual_guide/node005F.html) 

