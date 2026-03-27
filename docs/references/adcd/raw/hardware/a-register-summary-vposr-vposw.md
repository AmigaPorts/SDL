# A Register Summary / VPOSR, VPOSW


                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
VPOSR      004      R      A( [E](../Hardware_Manual_guide/node00A2.html) ) Read vertical most significant bit
```c
                                      (and frame flop)
```
VPOSW      02A      W       A     Write vertical most significant bit

```c
                                      (and frame flop)

                 BIT# 15,14,13,12,11,10,09,08,07,06,05,04,03,02,01,00
                      -----------------------------------------------
                 USE  LOF-- -- -- -- -- -- --,-- -- -- -- -- -- -- V8

                 LOF=Long frame (auto toggle control bit in  [BPLCON0](../Hardware_Manual_guide/node0022.html) )
```
