---
title: K Zorro Expansion Bus / Physical and Logical Signal Names
manual: hardware
chapter: hardware
section: k-zorro-expansion-bus-physical-and-logical-signal-names
functions: []
libraries: []
---

# K Zorro Expansion Bus / Physical and Logical Signal Names

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga 3000 Bus signals vary based on the particular bus mode in
effect. This table lists each physical pin by physical name, and then by
the logical names for Zorro II mode, Zorro III mode, address phase, and
Zorro III data mode, data phase.


   PIN     Physical        Zorro II        Zorro III       Zorro III
   NO.     Name            Name            Address Phase   Data Phase
   ---     --------        --------        -------------   ----------
   1       Ground          [Ground](hardware/k-signal-description-power-connections.md)          [Ground](hardware/k-signal-description-power-connections-2.md)          Ground
   2       Ground          Ground          Ground          Ground
   3       Ground          Ground          Ground          Ground
   4       Ground          Ground          Ground          Ground
   5       +5VDC           [+5VDC](hardware/k-signal-description-power-connections.md)           [+5VDC](hardware/k-signal-description-power-connections-2.md)           [+5VDC](hardware/k-signal-description-power-connections-2.md) 
   6       +5VDC           +5VDC           +5VDC           +5VDC
   7       /OWN            [/OWN](hardware/k-signal-description-dma-control-signals.md)            [/OWN](hardware/k-signal-description-dma-control-signals-2.md)            [/OWN](hardware/k-signal-description-dma-control-signals-2.md) 
   8       -5VDC           [-5VDC](hardware/k-signal-description-power-connections.md)           [-5VDC](hardware/k-signal-description-power-connections-2.md)           [-5VDC](hardware/k-signal-description-power-connections-2.md) 
   9       /SLAVEn         [/SLAVEn](hardware/k-signal-description-slot-control-signals.md)         [/SLAVEn](hardware/k-signal-description-slot-control-signals-2.md)         [/SLAVEn](hardware/k-signal-description-slot-control-signals-2.md) 
   10      +12VDC          [+12VDC](hardware/k-signal-description-power-connections.md)          [+12VDC](hardware/k-signal-description-power-connections-2.md)          [+12VDC](hardware/k-signal-description-power-connections-2.md) 
   11      /CFGOUTn        [/CFGOUTn](hardware/k-signal-description-slot-control-signals.md)        [/CFGOUTn](hardware/k-signal-description-slot-control-signals-2.md)        [/CFGOUTn](hardware/k-signal-description-slot-control-signals-2.md) 
   12      /CFGINn         [/CFGINn](hardware/k-signal-description-slot-control-signals.md)         [/CFGINn](hardware/k-signal-description-slot-control-signals-2.md)         [/CFGINn](hardware/k-signal-description-slot-control-signals-2.md) 
   13      Ground          Ground          Ground          Ground
   14      /C3             [/C3 Clock](hardware/k-signal-description-clock-signals.md)       [/C3 Clock](hardware/k-signal-description-clock-signals-2.md)       [/C3 Clock](hardware/k-signal-description-clock-signals-2.md) 
   15      CDAC            [CDAC Clock](hardware/k-signal-description-clock-signals.md)      [CDAC Clock](hardware/k-signal-description-clock-signals-2.md)      [CDAC Clock](hardware/k-signal-description-clock-signals-2.md) 
   16      /C1             [/C1 Clock](hardware/k-signal-description-clock-signals.md)       [/C1 Clock](hardware/k-signal-description-clock-signals-2.md)       [/C1 Clock](hardware/k-signal-description-clock-signals-2.md) 
   17      /CINH           [/OVR](hardware/k-signal-description-addressing-and-control-signals.md)            [/CINH](hardware/k-signal-description-data-and-related-control-signals.md)           [/CINH](hardware/k-signal-description-data-and-related-control-signals.md) 
   18      /MTCR           [XRDY](hardware/k-signal-description-addressing-and-control-signals.md)            [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)           [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md) 
   19      /INT2           [/INT2](hardware/k-signal-description-system-control-signals.md)           [/INT2](hardware/k-signal-description-system-control-signals-2.md)           [/INT2](hardware/k-signal-description-system-control-signals-2.md) 
   20      -12VDC          [-12VDC](hardware/k-signal-description-power-connections.md)          [-12VDC](hardware/k-signal-description-power-connections-2.md)          [-12VDC](hardware/k-signal-description-power-connections-2.md) 
   21      A5              [A5](hardware/k-signal-description-addressing-and-control-signals.md)              [A5](hardware/k-signal-description-address-and-related-control-signals.md)              [A5](hardware/k-signal-description-address-and-related-control-signals.md) 
   22      /INT6           [/INT6](hardware/k-signal-description-system-control-signals.md)           [/INT6](hardware/k-signal-description-system-control-signals-2.md)           [/INT6](hardware/k-signal-description-system-control-signals-2.md) 
   23      A6              [A6](hardware/k-signal-description-addressing-and-control-signals.md)              [A6](hardware/k-signal-description-address-and-related-control-signals.md)              [A6](hardware/k-signal-description-address-and-related-control-signals.md) 
   24      A4              [A4](hardware/k-signal-description-addressing-and-control-signals.md)              [A4](hardware/k-signal-description-address-and-related-control-signals.md)              [A4](hardware/k-signal-description-address-and-related-control-signals.md) 
   25      Ground          Ground          Ground          Ground
   26      A3              [A3](hardware/k-signal-description-addressing-and-control-signals.md)              [A3](hardware/k-signal-description-address-and-related-control-signals.md)              [A3](hardware/k-signal-description-address-and-related-control-signals.md) 
   27      A2              [A2](hardware/k-signal-description-addressing-and-control-signals.md)              [A2](hardware/k-signal-description-address-and-related-control-signals.md)              [A2](hardware/k-signal-description-address-and-related-control-signals.md) 
   28      A7              [A7](hardware/k-signal-description-addressing-and-control-signals.md)              [A7](hardware/k-signal-description-address-and-related-control-signals.md)              [A7](hardware/k-signal-description-address-and-related-control-signals.md) 
   29      /LOCK           [A1](hardware/k-signal-description-addressing-and-control-signals.md)              [/LOCK](hardware/k-advanced-mode-support-logic-bus-locking.md)           [/LOCK](hardware/k-advanced-mode-support-logic-bus-locking.md) 
   30      AD8             [A8](hardware/k-signal-description-addressing-and-control-signals.md)              [A8](hardware/k-signal-description-address-and-related-control-signals.md)              [D0](hardware/k-signal-description-data-and-related-control-signals.md) 
   31      FC0             [FC0](hardware/k-signal-description-addressing-and-control-signals.md)             [FC0](hardware/k-signal-description-address-and-related-control-signals.md)             [FC0](hardware/k-signal-description-address-and-related-control-signals.md) 
   32      AD9             [A9](hardware/k-signal-description-addressing-and-control-signals.md)              [A9](hardware/k-signal-description-address-and-related-control-signals.md)              [D1](hardware/k-signal-description-data-and-related-control-signals.md) 
   33      FC1             [FC1](hardware/k-signal-description-addressing-and-control-signals.md)             [FC1](hardware/k-signal-description-address-and-related-control-signals.md)             [FC1](hardware/k-signal-description-address-and-related-control-signals.md) 
   34      AD10            [A10](hardware/k-signal-description-addressing-and-control-signals.md)             [A10](hardware/k-signal-description-address-and-related-control-signals.md)             [D2](hardware/k-signal-description-data-and-related-control-signals.md) 
   35      FC2             [FC2](hardware/k-signal-description-addressing-and-control-signals.md)             [FC2](hardware/k-signal-description-address-and-related-control-signals.md)             [FC2](hardware/k-signal-description-address-and-related-control-signals.md) 
   36      AD11            [A11](hardware/k-signal-description-addressing-and-control-signals.md)             [A11](hardware/k-signal-description-address-and-related-control-signals.md)             [D3](hardware/k-signal-description-data-and-related-control-signals.md) 
   37      Ground          Ground          Ground          Ground
   38      AD12            [A12](hardware/k-signal-description-addressing-and-control-signals.md)             [A12](hardware/k-signal-description-address-and-related-control-signals.md)             [D4](hardware/k-signal-description-data-and-related-control-signals.md) 
   39      AD13            [A13](hardware/k-signal-description-addressing-and-control-signals.md)             [A13](hardware/k-signal-description-address-and-related-control-signals.md)             [D5](hardware/k-signal-description-data-and-related-control-signals.md) 
   40      Reserved        [(/EINT7)](hardware/k-signal-description-system-control-signals.md)        Reserved        Reserved
   41      AD14            [A14](hardware/k-signal-description-addressing-and-control-signals.md)             [A14](hardware/k-signal-description-address-and-related-control-signals.md)             [D6](hardware/k-signal-description-data-and-related-control-signals.md) 
   42      Reserved        [(/EINT5)](hardware/k-signal-description-system-control-signals.md)        Reserved        Reserved
   43      AD15            [A15](hardware/k-signal-description-addressing-and-control-signals.md)             [A15](hardware/k-signal-description-address-and-related-control-signals.md)             [D7](hardware/k-signal-description-data-and-related-control-signals.md) 
   44      Reserved        [(/EINT4)](hardware/k-signal-description-system-control-signals.md)        Reserved        Reserved
   45      AD16            [A16](hardware/k-signal-description-addressing-and-control-signals.md)             [A16](hardware/k-signal-description-address-and-related-control-signals.md)             [D8](hardware/k-signal-description-data-and-related-control-signals.md) 
   46      /BERR           [/BERR](hardware/k-signal-description-system-control-signals.md)           [/BERR](hardware/k-signal-description-system-control-signals-2.md)           [/BERR](hardware/k-signal-description-system-control-signals-2.md) 
   47      AD17            [A17](hardware/k-signal-description-addressing-and-control-signals.md)             [A17](hardware/k-signal-description-address-and-related-control-signals.md)             [D9](hardware/k-signal-description-data-and-related-control-signals.md) 
   48      /MTACK          [(/VPA)](hardware/k-changes-from-the-a2000-bus-6800-bus-interface.md)          [/MTACK](hardware/k-signal-description-data-and-related-control-signals.md)          [/MTACK](hardware/k-signal-description-data-and-related-control-signals.md) 
   49      Ground          Ground          Ground          Ground
   50      E Clock         [E Clock](hardware/k-signal-description-clock-signals.md)         [E Clock](hardware/k-signal-description-clock-signals-2.md)         [E Clock](hardware/k-signal-description-clock-signals-2.md) 
   51      /DS0            [(/VMA)](hardware/k-changes-from-the-a2000-bus-6800-bus-interface.md)          [/DS0](hardware/k-signal-description-data-and-related-control-signals.md)            [/DS0](hardware/k-signal-description-data-and-related-control-signals.md) 
   52      AD18            [A18](hardware/k-signal-description-addressing-and-control-signals.md)             [A18](hardware/k-signal-description-address-and-related-control-signals.md)             [D10](hardware/k-signal-description-data-and-related-control-signals.md) 
   53      /RESET          [/RST](hardware/k-signal-description-system-control-signals.md)            [/RESET](hardware/k-signal-description-system-control-signals-2.md)          [/RESET](hardware/k-signal-description-system-control-signals-2.md) 
   54      AD19            [A19](hardware/k-signal-description-addressing-and-control-signals.md)             [A19](hardware/k-signal-description-address-and-related-control-signals.md)             [D11](hardware/k-signal-description-data-and-related-control-signals.md) 
   55      /HLT            [/HLT](hardware/k-signal-description-system-control-signals.md)            [/HLT](hardware/k-signal-description-system-control-signals-2.md)            [/HLT](hardware/k-signal-description-system-control-signals-2.md) 
   56      AD20            [A20](hardware/k-signal-description-addressing-and-control-signals.md)             [A20](hardware/k-signal-description-address-and-related-control-signals.md)             [D12](hardware/k-signal-description-data-and-related-control-signals.md) 
   57      AD22            [A22](hardware/k-signal-description-addressing-and-control-signals.md)             [A22](hardware/k-signal-description-address-and-related-control-signals.md)             [D14](hardware/k-signal-description-data-and-related-control-signals.md) 
   58      AD21            [A21](hardware/k-signal-description-addressing-and-control-signals.md)             [A21](hardware/k-signal-description-address-and-related-control-signals.md)             [D13](hardware/k-signal-description-data-and-related-control-signals.md) 
   59      AD23            [A23](hardware/k-signal-description-addressing-and-control-signals.md)             [A23](hardware/k-signal-description-address-and-related-control-signals.md)             [D15](hardware/k-signal-description-data-and-related-control-signals.md) 
   60      /BRn            [/BRn](hardware/k-signal-description-dma-control-signals.md)            [/BRn](hardware/k-signal-description-dma-control-signals-2.md)            [/BRn](hardware/k-signal-description-dma-control-signals-2.md) 
   61      Ground          Ground          Ground          Ground
   62      /BGACK          [/BGACK](hardware/k-signal-description-dma-control-signals.md)          [/BGACK](hardware/k-signal-description-dma-control-signals-2.md)          [/BGACK](hardware/k-signal-description-dma-control-signals-2.md) 
   63      AD31            [D15](hardware/k-signal-description-addressing-and-control-signals.md)             [A31](hardware/k-signal-description-address-and-related-control-signals.md)             [D31](hardware/k-signal-description-data-and-related-control-signals.md) 
   64      /BGn            [/BGn](hardware/k-signal-description-dma-control-signals.md)            [/BGn](hardware/k-signal-description-dma-control-signals-2.md)            [/BGn](hardware/k-signal-description-dma-control-signals-2.md) 
   65      AD30            [D14](hardware/k-signal-description-addressing-and-control-signals.md)             [A30](hardware/k-signal-description-address-and-related-control-signals.md)             [D30](hardware/k-signal-description-data-and-related-control-signals.md) 
   66      /DTACK          [/DTACK](hardware/k-signal-description-addressing-and-control-signals.md)          [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)          [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md) 
   67      AD29            [D13](hardware/k-signal-description-addressing-and-control-signals.md)             [A29](hardware/k-signal-description-address-and-related-control-signals.md)             [D29](hardware/k-signal-description-data-and-related-control-signals.md) 
   68      READ            [READ](hardware/k-signal-description-addressing-and-control-signals.md)            [READ](hardware/k-signal-description-address-and-related-control-signals.md)            [READ](hardware/k-signal-description-address-and-related-control-signals.md) 
   69      AD28            [D12](hardware/k-signal-description-addressing-and-control-signals.md)             [A28](hardware/k-signal-description-address-and-related-control-signals.md)             [D28](hardware/k-signal-description-data-and-related-control-signals.md) 
   70      /DS2            [/LDS](hardware/k-signal-description-addressing-and-control-signals.md)            [/DS2](hardware/k-signal-description-data-and-related-control-signals.md)            [/DS2](hardware/k-signal-description-data-and-related-control-signals.md) 
   71      AD27            [D11](hardware/k-signal-description-addressing-and-control-signals.md)             [A27](hardware/k-signal-description-address-and-related-control-signals.md)             [D27](hardware/k-signal-description-data-and-related-control-signals.md) 
   72      /DS3            [/UDS](hardware/k-signal-description-addressing-and-control-signals.md)            [/DS3](hardware/k-signal-description-data-and-related-control-signals.md)            [/DS3](hardware/k-signal-description-data-and-related-control-signals.md) 
   73      Ground          Ground          Ground          Ground
   74      /CCS            [/AS](hardware/k-signal-description-addressing-and-control-signals.md)             [/CCS](hardware/k-signal-description-address-and-related-control-signals.md)            [/CCS](hardware/k-signal-description-address-and-related-control-signals.md) 
   75      SD0             [D0](hardware/k-signal-description-addressing-and-control-signals.md)              Reserved        [D16](hardware/k-signal-description-data-and-related-control-signals.md) 
   76      AD26            [D10](hardware/k-signal-description-addressing-and-control-signals.md)              [A26](hardware/k-signal-description-address-and-related-control-signals.md)            [D26](hardware/k-signal-description-data-and-related-control-signals.md) 
   77      SD1             [D1](hardware/k-signal-description-addressing-and-control-signals.md)              Reserved        [D17](hardware/k-signal-description-data-and-related-control-signals.md) 
   78      AD25            [D9](hardware/k-signal-description-addressing-and-control-signals.md)              [A25](hardware/k-signal-description-address-and-related-control-signals.md)             [D25](hardware/k-signal-description-data-and-related-control-signals.md) 
   79      SD2             [D2](hardware/k-signal-description-addressing-and-control-signals.md)              Reserved        [D18](hardware/k-signal-description-data-and-related-control-signals.md) 
   80      AD24            [D8](hardware/k-signal-description-addressing-and-control-signals.md)              [A24](hardware/k-signal-description-address-and-related-control-signals.md)             [D24](hardware/k-signal-description-data-and-related-control-signals.md) 
   81      SD3             [D3](hardware/k-signal-description-addressing-and-control-signals.md)              Reserved        [D19](hardware/k-signal-description-data-and-related-control-signals.md) 
   82      SD7             [D7](hardware/k-signal-description-addressing-and-control-signals.md)              Reserved        [D23](hardware/k-signal-description-data-and-related-control-signals.md) 
   83      SD4             [D4](hardware/k-signal-description-addressing-and-control-signals.md)              Reserved        [D20](hardware/k-signal-description-data-and-related-control-signals.md) 
   84      SD6             [D6](hardware/k-signal-description-addressing-and-control-signals.md)              Reserved        [D22](hardware/k-signal-description-data-and-related-control-signals.md) 
   85      Ground          Ground          Ground          Ground
   86      SD5             [D5](hardware/k-signal-description-addressing-and-control-signals.md)              Reserved        [D21](hardware/k-signal-description-data-and-related-control-signals.md) 
   87      Ground          Ground          Ground          Ground
   88      Ground          Ground          Ground          Ground
   89      Ground          Ground          Ground          Ground
   90      Ground          Ground          Ground          Ground
   91      SenseZ3         Ground          [SenseZ3](hardware/k-signal-description-slot-control-signals-2.md)         [SenseZ3](hardware/k-signal-description-slot-control-signals-2.md) 
   92      7M              [E7M](hardware/k-signal-description-clock-signals.md)             [7M](hardware/k-signal-description-clock-signals-2.md)              [7M](hardware/k-signal-description-clock-signals-2.md) 
   93      DOE             [DOE](hardware/k-signal-description-slot-control-signals.md)             [DOE](hardware/k-signal-description-data-and-related-control-signals.md)             [DOE](hardware/k-signal-description-data-and-related-control-signals.md) 
   94      /IORST          [/BUSRST](hardware/k-signal-description-system-control-signals.md)         [/IORST](hardware/k-signal-description-system-control-signals-2.md)          [/IORST](hardware/k-signal-description-system-control-signals-2.md) 
   95      /BCLR           [/GBG](hardware/k-signal-description-dma-control-signals.md)            [/BCLR](hardware/k-signal-description-dma-control-signals-2.md)           [/BCLR](hardware/k-signal-description-dma-control-signals-2.md) 
   96      Reserved        [(/EINT1)](hardware/k-signal-description-system-control-signals.md)        Reserved        Reserved
   97      /FCS            No Connect      [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)            [/FCS](hardware/k-signal-description-address-and-related-control-signals.md) 
   98      /DS1            No Connect      [/DS1](hardware/k-signal-description-data-and-related-control-signals.md)            [/DS1](hardware/k-signal-description-data-and-related-control-signals.md) 
   99      Ground          Ground          Ground          Ground
   100     Ground          Ground          Ground          Ground

