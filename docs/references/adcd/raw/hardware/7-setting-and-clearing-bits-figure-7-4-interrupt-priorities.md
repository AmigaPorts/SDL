# 7 / / Setting and Clearing Bits / Figure 7-4: Interrupt Priorities


               Exec
Hardware     Software
Priority     Priority     Description                  Name
--------     --------     -----------                  ----
```c
           ____
          |     1         transmitter buffer empty     [TBE](../Hardware_Manual_guide/node016E.html) 
          |
```
   1 -----|     2         disk block complete          [DSKBLK](../Hardware_Manual_guide/node016D.html) 
          |
          |     3         software interrupt           SOFTINT
          |----
   2 -----|     4         external INT2 & CIAA         [PORTS](../Hardware_Manual_guide/node0168.html) 
```c
          |----
          |     5         graphics coprocessor         [COPER](../Hardware_Manual_guide/node016A.html) 
          |
```
   3 -----|     6         vertical blank interval      [VERTB](../Hardware_Manual_guide/node0169.html) 
```c
          |
          |     7         blitter finished             [BLIT](../Hardware_Manual_guide/node016C.html) 
          |----
          |     8         audio channel 2              [AUD2](../Hardware_Manual_guide/node016B.html) 
          |
          |     9         audio channel 0              [AUD0](../Hardware_Manual_guide/node016B.html) 
```
   4 -----|
```c
          |     10        audio channel 3              [AUD3](../Hardware_Manual_guide/node016B.html) 
          |
          |     11        audio channel 1              [AUD1](../Hardware_Manual_guide/node016B.html) 
          |----
          |     12        receiver buffer full         [RBF](../Hardware_Manual_guide/node016E.html) 
```
   5 -----|
```c
          |     13        disk sync pattern found      [DSKSYNC](../Hardware_Manual_guide/node016D.html) 
          |----
          |     14        external INT6 & CIAB         [EXTER](../Hardware_Manual_guide/node0168.html) 
```
   6 -----|
```c
          |     15        special (master enable)      [INTEN](../Hardware_Manual_guide/node0167.html) 
          |----
```
   7 -----|____ --        non-maskable interrupt       [NMI](../Hardware_Manual_guide/node0166.html) 

