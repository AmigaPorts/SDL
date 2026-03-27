# K Zorro Expansion Bus / Physical and Logical Signal Names


The Amiga 3000 Bus signals vary based on the particular bus mode in
effect. This table lists each physical pin by physical name, and then by
the logical names for Zorro II mode, Zorro III mode, address phase, and
Zorro III data mode, data phase.


   PIN     Physical        Zorro II        Zorro III       Zorro III
   NO.     Name            Name            Address Phase   Data Phase
   ---     --------        --------        -------------   ----------
   1       Ground          [Ground](../Hardware_Manual_guide/node029D.html#line4)          [Ground](../Hardware_Manual_guide/node02AF.html#line6)          Ground
   2       Ground          Ground          Ground          Ground
   3       Ground          Ground          Ground          Ground
   4       Ground          Ground          Ground          Ground
   5       +5VDC           [+5VDC](../Hardware_Manual_guide/node029D.html#line8)           [+5VDC](../Hardware_Manual_guide/node02AF.html#line10)           [+5VDC](../Hardware_Manual_guide/node02AF.html#line10) 
   6       +5VDC           +5VDC           +5VDC           +5VDC
   7       /OWN            [/OWN](../Hardware_Manual_guide/node02A1.html#line5)            [/OWN](../Hardware_Manual_guide/node02B3.html#line4)            [/OWN](../Hardware_Manual_guide/node02B3.html#line4) 
   8       -5VDC           [-5VDC](../Hardware_Manual_guide/node029D.html#line14)           [-5VDC](../Hardware_Manual_guide/node02AF.html#line15)           [-5VDC](../Hardware_Manual_guide/node02AF.html#line15) 
   9       /SLAVEn         [/SLAVEn](../Hardware_Manual_guide/node02A0.html#line3)         [/SLAVEn](../Hardware_Manual_guide/node02B2.html#line3)         [/SLAVEn](../Hardware_Manual_guide/node02B2.html#line3) 
   10      +12VDC          [+12VDC](../Hardware_Manual_guide/node029D.html#line20)          [+12VDC](../Hardware_Manual_guide/node02AF.html#line19)          [+12VDC](../Hardware_Manual_guide/node02AF.html#line19) 
   11      /CFGOUTn        [/CFGOUTn](../Hardware_Manual_guide/node02A0.html#line20)        [/CFGOUTn](../Hardware_Manual_guide/node02B2.html#line17)        [/CFGOUTn](../Hardware_Manual_guide/node02B2.html#line17) 
   12      /CFGINn         [/CFGINn](../Hardware_Manual_guide/node02A0.html#line20)         [/CFGINn](../Hardware_Manual_guide/node02B2.html#line17)         [/CFGINn](../Hardware_Manual_guide/node02B2.html#line17) 
   13      Ground          Ground          Ground          Ground
   14      /C3             [/C3 Clock](../Hardware_Manual_guide/node029E.html#line12)       [/C3 Clock](../Hardware_Manual_guide/node02B0.html#line10)       [/C3 Clock](../Hardware_Manual_guide/node02B0.html#line10) 
   15      CDAC            [CDAC Clock](../Hardware_Manual_guide/node029E.html#line16)      [CDAC Clock](../Hardware_Manual_guide/node02B0.html#line14)      [CDAC Clock](../Hardware_Manual_guide/node02B0.html#line14) 
   16      /C1             [/C1 Clock](../Hardware_Manual_guide/node029E.html#line8)       [/C1 Clock](../Hardware_Manual_guide/node02B0.html#line6)       [/C1 Clock](../Hardware_Manual_guide/node02B0.html#line6) 
   17      /CINH           [/OVR](../Hardware_Manual_guide/node02A2.html#line79)            [/CINH](../Hardware_Manual_guide/node02B5.html#line36)           [/CINH](../Hardware_Manual_guide/node02B5.html#line36) 
   18      /MTCR           [XRDY](../Hardware_Manual_guide/node02A2.html#line90)            [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)           [/MTCR](../Hardware_Manual_guide/node02B5.html#line44) 
   19      /INT2           [/INT2](../Hardware_Manual_guide/node029F.html#line51)           [/INT2](../Hardware_Manual_guide/node02B1.html#line61)           [/INT2](../Hardware_Manual_guide/node02B1.html#line61) 
   20      -12VDC          [-12VDC](../Hardware_Manual_guide/node029D.html#line29)          [-12VDC](../Hardware_Manual_guide/node02AF.html#line25)          [-12VDC](../Hardware_Manual_guide/node02AF.html#line25) 
   21      A5              [A5](../Hardware_Manual_guide/node02A2.html#line13)              [A5](../Hardware_Manual_guide/node02B4.html#line21)              [A5](../Hardware_Manual_guide/node02B4.html#line21) 
   22      /INT6           [/INT6](../Hardware_Manual_guide/node029F.html#line51)           [/INT6](../Hardware_Manual_guide/node02B1.html#line61)           [/INT6](../Hardware_Manual_guide/node02B1.html#line61) 
   23      A6              [A6](../Hardware_Manual_guide/node02A2.html#line13)              [A6](../Hardware_Manual_guide/node02B4.html#line21)              [A6](../Hardware_Manual_guide/node02B4.html#line21) 
   24      A4              [A4](../Hardware_Manual_guide/node02A2.html#line13)              [A4](../Hardware_Manual_guide/node02B4.html#line21)              [A4](../Hardware_Manual_guide/node02B4.html#line21) 
   25      Ground          Ground          Ground          Ground
   26      A3              [A3](../Hardware_Manual_guide/node02A2.html#line13)              [A3](../Hardware_Manual_guide/node02B4.html#line21)              [A3](../Hardware_Manual_guide/node02B4.html#line21) 
   27      A2              [A2](../Hardware_Manual_guide/node02A2.html#line13)              [A2](../Hardware_Manual_guide/node02B4.html#line21)              [A2](../Hardware_Manual_guide/node02B4.html#line21) 
   28      A7              [A7](../Hardware_Manual_guide/node02A2.html#line13)              [A7](../Hardware_Manual_guide/node02B4.html#line21)              [A7](../Hardware_Manual_guide/node02B4.html#line21) 
   29      /LOCK           [A1](../Hardware_Manual_guide/node02A2.html#line13)              [/LOCK](../Hardware_Manual_guide/node02A8.html)           [/LOCK](../Hardware_Manual_guide/node02A8.html) 
   30      AD8             [A8](../Hardware_Manual_guide/node02A2.html#line13)              [A8](../Hardware_Manual_guide/node02B4.html#line13)              [D0](../Hardware_Manual_guide/node02B5.html#line10) 
   31      FC0             [FC0](../Hardware_Manual_guide/node02A2.html#line67)             [FC0](../Hardware_Manual_guide/node02B4.html#line28)             [FC0](../Hardware_Manual_guide/node02B4.html#line28) 
   32      AD9             [A9](../Hardware_Manual_guide/node02A2.html#line13)              [A9](../Hardware_Manual_guide/node02B4.html#line13)              [D1](../Hardware_Manual_guide/node02B5.html#line10) 
   33      FC1             [FC1](../Hardware_Manual_guide/node02A2.html#line67)             [FC1](../Hardware_Manual_guide/node02B4.html#line28)             [FC1](../Hardware_Manual_guide/node02B4.html#line28) 
   34      AD10            [A10](../Hardware_Manual_guide/node02A2.html#line13)             [A10](../Hardware_Manual_guide/node02B4.html#line13)             [D2](../Hardware_Manual_guide/node02B5.html#line10) 
   35      FC2             [FC2](../Hardware_Manual_guide/node02A2.html#line67)             [FC2](../Hardware_Manual_guide/node02B4.html#line28)             [FC2](../Hardware_Manual_guide/node02B4.html#line28) 
   36      AD11            [A11](../Hardware_Manual_guide/node02A2.html#line13)             [A11](../Hardware_Manual_guide/node02B4.html#line13)             [D3](../Hardware_Manual_guide/node02B5.html#line10) 
   37      Ground          Ground          Ground          Ground
   38      AD12            [A12](../Hardware_Manual_guide/node02A2.html#line13)             [A12](../Hardware_Manual_guide/node02B4.html#line13)             [D4](../Hardware_Manual_guide/node02B5.html#line10) 
   39      AD13            [A13](../Hardware_Manual_guide/node02A2.html#line13)             [A13](../Hardware_Manual_guide/node02B4.html#line13)             [D5](../Hardware_Manual_guide/node02B5.html#line10) 
   40      Reserved        [(/EINT7)](../Hardware_Manual_guide/node029F.html#line51)        Reserved        Reserved
   41      AD14            [A14](../Hardware_Manual_guide/node02A2.html#line13)             [A14](../Hardware_Manual_guide/node02B4.html#line13)             [D6](../Hardware_Manual_guide/node02B5.html#line10) 
   42      Reserved        [(/EINT5)](../Hardware_Manual_guide/node029F.html#line51)        Reserved        Reserved
   43      AD15            [A15](../Hardware_Manual_guide/node02A2.html#line13)             [A15](../Hardware_Manual_guide/node02B4.html#line13)             [D7](../Hardware_Manual_guide/node02B5.html#line10) 
   44      Reserved        [(/EINT4)](../Hardware_Manual_guide/node029F.html#line51)        Reserved        Reserved
   45      AD16            [A16](../Hardware_Manual_guide/node02A2.html#line13)             [A16](../Hardware_Manual_guide/node02B4.html#line13)             [D8](../Hardware_Manual_guide/node02B5.html#line10) 
   46      /BERR           [/BERR](../Hardware_Manual_guide/node029F.html#line4)           [/BERR](../Hardware_Manual_guide/node02B1.html#line4)           [/BERR](../Hardware_Manual_guide/node02B1.html#line4) 
   47      AD17            [A17](../Hardware_Manual_guide/node02A2.html#line13)             [A17](../Hardware_Manual_guide/node02B4.html#line13)             [D9](../Hardware_Manual_guide/node02B5.html#line10) 
   48      /MTACK          [(/VPA)](../Hardware_Manual_guide/node0292.html)          [/MTACK](../Hardware_Manual_guide/node02B5.html#line44)          [/MTACK](../Hardware_Manual_guide/node02B5.html#line44) 
   49      Ground          Ground          Ground          Ground
   50      E Clock         [E Clock](../Hardware_Manual_guide/node029E.html#line20)         [E Clock](../Hardware_Manual_guide/node02B0.html#line18)         [E Clock](../Hardware_Manual_guide/node02B0.html#line18) 
   51      /DS0            [(/VMA)](../Hardware_Manual_guide/node0292.html)          [/DS0](../Hardware_Manual_guide/node02B5.html#line17)            [/DS0](../Hardware_Manual_guide/node02B5.html#line17) 
   52      AD18            [A18](../Hardware_Manual_guide/node02A2.html#line13)             [A18](../Hardware_Manual_guide/node02B4.html#line13)             [D10](../Hardware_Manual_guide/node02B5.html#line10) 
   53      /RESET          [/RST](../Hardware_Manual_guide/node029F.html#line27)            [/RESET](../Hardware_Manual_guide/node02B1.html#line40)          [/RESET](../Hardware_Manual_guide/node02B1.html#line40) 
   54      AD19            [A19](../Hardware_Manual_guide/node02A2.html#line13)             [A19](../Hardware_Manual_guide/node02B4.html#line13)             [D11](../Hardware_Manual_guide/node02B5.html#line10) 
   55      /HLT            [/HLT](../Hardware_Manual_guide/node029F.html#line39)            [/HLT](../Hardware_Manual_guide/node02B1.html#line52)            [/HLT](../Hardware_Manual_guide/node02B1.html#line52) 
   56      AD20            [A20](../Hardware_Manual_guide/node02A2.html#line13)             [A20](../Hardware_Manual_guide/node02B4.html#line13)             [D12](../Hardware_Manual_guide/node02B5.html#line10) 
   57      AD22            [A22](../Hardware_Manual_guide/node02A2.html#line13)             [A22](../Hardware_Manual_guide/node02B4.html#line13)             [D14](../Hardware_Manual_guide/node02B5.html#line10) 
   58      AD21            [A21](../Hardware_Manual_guide/node02A2.html#line13)             [A21](../Hardware_Manual_guide/node02B4.html#line13)             [D13](../Hardware_Manual_guide/node02B5.html#line10) 
   59      AD23            [A23](../Hardware_Manual_guide/node02A2.html#line13)             [A23](../Hardware_Manual_guide/node02B4.html#line13)             [D15](../Hardware_Manual_guide/node02B5.html#line10) 
   60      /BRn            [/BRn](../Hardware_Manual_guide/node02A1.html#line14)            [/BRn](../Hardware_Manual_guide/node02B3.html#line12)            [/BRn](../Hardware_Manual_guide/node02B3.html#line12) 
   61      Ground          Ground          Ground          Ground
   62      /BGACK          [/BGACK](../Hardware_Manual_guide/node02A1.html#line56)          [/BGACK](../Hardware_Manual_guide/node02B3.html#line22)          [/BGACK](../Hardware_Manual_guide/node02B3.html#line22) 
   63      AD31            [D15](../Hardware_Manual_guide/node02A2.html#line31)             [A31](../Hardware_Manual_guide/node02B4.html#line13)             [D31](../Hardware_Manual_guide/node02B5.html#line10) 
   64      /BGn            [/BGn](../Hardware_Manual_guide/node02A1.html#line14)            [/BGn](../Hardware_Manual_guide/node02B3.html#line12)            [/BGn](../Hardware_Manual_guide/node02B3.html#line12) 
   65      AD30            [D14](../Hardware_Manual_guide/node02A2.html#line31)             [A30](../Hardware_Manual_guide/node02B4.html#line13)             [D30](../Hardware_Manual_guide/node02B5.html#line10) 
   66      /DTACK          [/DTACK](../Hardware_Manual_guide/node02A2.html#line49)          [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)          [/DTACK](../Hardware_Manual_guide/node02B5.html#line27) 
   67      AD29            [D13](../Hardware_Manual_guide/node02A2.html#line31)             [A29](../Hardware_Manual_guide/node02B4.html#line13)             [D29](../Hardware_Manual_guide/node02B5.html#line10) 
   68      READ            [READ](../Hardware_Manual_guide/node02A2.html#line6)            [READ](../Hardware_Manual_guide/node02B4.html#line6)            [READ](../Hardware_Manual_guide/node02B4.html#line6) 
   69      AD28            [D12](../Hardware_Manual_guide/node02A2.html#line31)             [A28](../Hardware_Manual_guide/node02B4.html#line13)             [D28](../Hardware_Manual_guide/node02B5.html#line10) 
   70      /DS2            [/LDS](../Hardware_Manual_guide/node02A2.html#line37)            [/DS2](../Hardware_Manual_guide/node02B5.html#line17)            [/DS2](../Hardware_Manual_guide/node02B5.html#line17) 
   71      AD27            [D11](../Hardware_Manual_guide/node02A2.html#line31)             [A27](../Hardware_Manual_guide/node02B4.html#line13)             [D27](../Hardware_Manual_guide/node02B5.html#line10) 
   72      /DS3            [/UDS](../Hardware_Manual_guide/node02A2.html#line37)            [/DS3](../Hardware_Manual_guide/node02B5.html#line17)            [/DS3](../Hardware_Manual_guide/node02B5.html#line17) 
   73      Ground          Ground          Ground          Ground
   74      /CCS            [/AS](../Hardware_Manual_guide/node02A2.html#line18)             [/CCS](../Hardware_Manual_guide/node02B4.html#line53)            [/CCS](../Hardware_Manual_guide/node02B4.html#line53) 
   75      SD0             [D0](../Hardware_Manual_guide/node02A2.html#line31)              Reserved        [D16](../Hardware_Manual_guide/node02B5.html#line10) 
   76      AD26            [D10](../Hardware_Manual_guide/node02A2.html#line31)              [A26](../Hardware_Manual_guide/node02B4.html#line13)            [D26](../Hardware_Manual_guide/node02B5.html#line10) 
   77      SD1             [D1](../Hardware_Manual_guide/node02A2.html#line31)              Reserved        [D17](../Hardware_Manual_guide/node02B5.html#line10) 
   78      AD25            [D9](../Hardware_Manual_guide/node02A2.html#line31)              [A25](../Hardware_Manual_guide/node02B4.html#line13)             [D25](../Hardware_Manual_guide/node02B5.html#line10) 
   79      SD2             [D2](../Hardware_Manual_guide/node02A2.html#line31)              Reserved        [D18](../Hardware_Manual_guide/node02B5.html#line10) 
   80      AD24            [D8](../Hardware_Manual_guide/node02A2.html#line31)              [A24](../Hardware_Manual_guide/node02B4.html#line13)             [D24](../Hardware_Manual_guide/node02B5.html#line10) 
   81      SD3             [D3](../Hardware_Manual_guide/node02A2.html#line31)              Reserved        [D19](../Hardware_Manual_guide/node02B5.html#line10) 
   82      SD7             [D7](../Hardware_Manual_guide/node02A2.html#line31)              Reserved        [D23](../Hardware_Manual_guide/node02B5.html#line10) 
   83      SD4             [D4](../Hardware_Manual_guide/node02A2.html#line31)              Reserved        [D20](../Hardware_Manual_guide/node02B5.html#line10) 
   84      SD6             [D6](../Hardware_Manual_guide/node02A2.html#line31)              Reserved        [D22](../Hardware_Manual_guide/node02B5.html#line10) 
   85      Ground          Ground          Ground          Ground
   86      SD5             [D5](../Hardware_Manual_guide/node02A2.html#line31)              Reserved        [D21](../Hardware_Manual_guide/node02B5.html#line10) 
   87      Ground          Ground          Ground          Ground
   88      Ground          Ground          Ground          Ground
   89      Ground          Ground          Ground          Ground
   90      Ground          Ground          Ground          Ground
   91      SenseZ3         Ground          [SenseZ3](../Hardware_Manual_guide/node02B2.html#line33)         [SenseZ3](../Hardware_Manual_guide/node02B2.html#line33) 
   92      7M              [E7M](../Hardware_Manual_guide/node029E.html#line28)             [7M](../Hardware_Manual_guide/node02B0.html#line23)              [7M](../Hardware_Manual_guide/node02B0.html#line23) 
   93      DOE             [DOE](../Hardware_Manual_guide/node02A0.html#line35)             [DOE](../Hardware_Manual_guide/node02B5.html#line5)             [DOE](../Hardware_Manual_guide/node02B5.html#line5) 
   94      /IORST          [/BUSRST](../Hardware_Manual_guide/node029F.html#line27)         [/IORST](../Hardware_Manual_guide/node02B1.html#line40)          [/IORST](../Hardware_Manual_guide/node02B1.html#line40) 
   95      /BCLR           [/GBG](../Hardware_Manual_guide/node02A1.html#line66)            [/BCLR](../Hardware_Manual_guide/node02B3.html#line27)           [/BCLR](../Hardware_Manual_guide/node02B3.html#line27) 
   96      Reserved        [(/EINT1)](../Hardware_Manual_guide/node029F.html#line51)        Reserved        Reserved
   97      /FCS            No Connect      [/FCS](../Hardware_Manual_guide/node02B4.html#line73)            [/FCS](../Hardware_Manual_guide/node02B4.html#line73) 
   98      /DS1            No Connect      [/DS1](../Hardware_Manual_guide/node02B5.html#line17)            [/DS1](../Hardware_Manual_guide/node02B5.html#line17) 
   99      Ground          Ground          Ground          Ground
   100     Ground          Ground          Ground          Ground

