# 26 / / Interrupt Servers / Interrupt Server Register Usage



 D0 Scratch.

 D1 Scratch.

 A0 Scratch except in certain cases (see [note above](../Libraries_Manual_guide/node030B.html#line43)).

 A1 Points to the data area specified by the [is_Data](../Libraries_Manual_guide/node0307.html) field of the

```c
    [Interrupt](../Libraries_Manual_guide/node0307.html) structure.  Because this pointer is always fetched
    (regardless of whether you use it), it is to your advantage to make
    some use of it (scratch).
```
 A5 Points to your interrupt code (scratch).

 A6 Scratch.

In a server chain, the interrupt is cleared automatically by the system.
Having a server clear its interrupt is not recommended and not necessary
(clearing could cause the loss of an interrupt on [PORTS](../Libraries_Manual_guide/node0303.html#line79) or [EXTER](../Libraries_Manual_guide/node0303.html#line99)).

Here is an example of a program to install and remove a low-priority
vertical blank interrupt server:


```c
     [vertb.c](../Libraries_Manual_guide/node05EB.html) 
```
This is the assembler VertBServer installed by the C example:


```c
     [vertbserver.asm](../Libraries_Manual_guide/node05EC.html) 
```
