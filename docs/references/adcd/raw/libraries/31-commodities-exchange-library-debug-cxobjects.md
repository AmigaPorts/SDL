# 31 Commodities Exchange Library / Debug CxObjects


The final [CxObject](../Libraries_Manual_guide/node0401.html) is the debug CxObject.  When a debug CxObject receives
a [CxMessage](../Libraries_Manual_guide/node0403.html), it sends debugging information to the serial port using
[KPrintF()](../Includes_and_Autodocs_2._guide/node0178.html).


```c
    debugCxObj  = CxObj  *CxDebug(LONG ID);
```
The debug [CxObject](../Libraries_Manual_guide/node0401.html) will [KPrintF()](../Includes_and_Autodocs_2._guide/node0178.html) the following information about itself,
the [CxMsg](../Includes_and_Autodocs_2._guide/node00F0.html#line71), and the corresponding [InputEvent](../Libraries_Manual_guide/node01D0.html) structure:


    DEBUG NODE: 7CB5AB0, ID: 2
     CxMsg: 7CA6EF2, type: 0, data 2007CA destination 6F1E07CB
    dump IE: 7CA6F1E
     Class 1
     Code 40
     Qualifier 8000
     EventAddress 40001802
There has to be a terminal connected to the Amiga's serial port to receive
this information.  See the [KPrintF()](../Includes_and_Autodocs_2._guide/node0178.html) Autodoc (debug.lib) for more details.
Note that the debug [CxObject](../Libraries_Manual_guide/node0401.html) did not work before V37.

