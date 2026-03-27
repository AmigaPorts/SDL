# 2 / Using the Copper Registers / Jump Strobe Address


When you write to a Copper strobe address, the Copper reloads its program
counter from the corresponding  [location register](../Hardware_Manual_guide/node0050.html) . The Copper can write
its own location registers and strobe addresses to perform programmed
jumps. For instance, you might  [MOVE](../Hardware_Manual_guide/node004A.html)  an indirect address into the
 [COP2LC](../Hardware_Manual_guide/node0050.html)  location register. Then, any  [MOVE](../Hardware_Manual_guide/node004A.html)  instruction that addresses
COPJMP2 strobes this indirect address into the program counter.

There are two jump strobe addresses:


```c
     COPJMP1/Restart Copper from address contained in  [COP1LC](../Hardware_Manual_guide/node0050.html) .
     COPJMP2/Restart Copper from address contained in  [COP2LC](../Hardware_Manual_guide/node0050.html) .
```
