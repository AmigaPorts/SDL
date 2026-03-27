# 1 / Programming in the Amiga Environment / The Custom Chips


The most important feature of the Amiga's hardware design is the set of
custom chips that perform specialized tasks independently of the CPU. Each
of the custom chips (named Paula, Agnus, and Denise) is dedicated to a
particular job:

Paula   (8364)            Audio, floppy disk, serial, interrupts
Agnus   (8361/8370/8372)  [Copper](../Libraries_Manual_guide/node031F.html) (video coprocessor), blitter, DMA control
Denise  (8362)            Color registers, color DACs (Digital to Analog

```c
                          Converters) and sprites
```
The custom chips can perform work independently of the CPU because they
have DMA, or Direct Memory Access, capability.  DMA means the custom chips
can access special areas of memory by themselves without any CPU
involvement.  (On computer systems without DMA, the CPU must do some or
all of the memory handling for support chips.)  The Amiga's custom chips
make [multitasking](../Libraries_Manual_guide/node000A.html) especially effective because they can handle things like
rendering graphics and playing sound independently, giving the CPU more
time to handle the overhead of [task-switching](../Libraries_Manual_guide/node000B.html) and other important jobs.

 [Custom Chip Revisions](../Libraries_Manual_guide/node0017.html)    [Two Kinds of Memory](../Libraries_Manual_guide/node0018.html) 

