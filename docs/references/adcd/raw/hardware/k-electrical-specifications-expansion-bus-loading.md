# K / Electrical Specifications / Expansion Bus Loading


The Zorro III bus loading is specified based on typical TTL family "F"
series buffer devices, though in reality, compatible CMOS devices are
likely to be used in some bus controllers or PICs.   Thus, it's important
to accept the TTL levels as a minimum voltage level, and make sure that
all inputs are the appropriate TTL levels, while outputs can be at TTL or
CMOS voltage levels as long as they provide the required source and sink.

While some A2000 designs used "LS" or "ALS" buffers instead of "F," the
bus will generally work with these older cards, at least with current
backplane designs such as the A3000 backplane.  However, Zorro III designs
must exactly obey these loading rules; it's very probable that some future
Zorro III machines will have a large number of slots.  In such machines,
PICs built on the Zorro II specification will still work in a lightly
loaded bus, but may not function in a fully loaded bus.  All Zorro III
PICs built to spec will work in any Zorro III backplane, without any
loading problems, if all loading and  [timing](../Hardware_Manual_guide/node02B6.html)  rules are followed by the
PIC designer. The bus signals are divided up into the four groups shown in
Table K-2, based on the loading characteristics of the particular signal.
The signals in each group are given here. Standard Signals

The majority of signals on the bus are in this group.  These are bussed
signals, driven actively on the bus by F-series (or compatible) drivers
such as 74F245, usually tri-stated when ownership of the signal changed
for master and slave, and generally terminated with a 220(omega)/330(omega)
thevenin terminator.  PICs can apply two standard loads to each of these
signals when necessary.



```c
        [/FCS](../Hardware_Manual_guide/node02B4.html#line73)      [/CCS](../Hardware_Manual_guide/node02B4.html#line53)       [/DS0-/DS3](../Hardware_Manual_guide/node02B5.html#line17)   [/LOCK](../Hardware_Manual_guide/node02A8.html) 
        [A2-A7](../Hardware_Manual_guide/node02B4.html#line21)     AD8-AD31   SD0-SD7     [READ](../Hardware_Manual_guide/node02B4.html#line6) 
        [FC0-FC2](../Hardware_Manual_guide/node02B4.html#line28)   [DOE](../Hardware_Manual_guide/node02B5.html#line5)        [/IORST](../Hardware_Manual_guide/node02B1.html#line40)      [/BCLR](../Hardware_Manual_guide/node02B3.html#line27) 
        [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)     [/MTACK](../Hardware_Manual_guide/node02B5.html#line44) 
```
 [Clock Signals](../Hardware_Manual_guide/node02BD.html)      [Open Collector Signals](../Hardware_Manual_guide/node02BE.html)      [Non-bussed Signals](../Hardware_Manual_guide/node02BF.html) 

