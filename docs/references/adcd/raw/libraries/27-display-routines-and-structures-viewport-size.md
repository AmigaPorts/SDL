# 27 / Display Routines and Structures / Viewport Size Specifications


The following figure illustrates that the variables [DHeight](../Libraries_Manual_guide/node0324.html), and [DWidth](../Libraries_Manual_guide/node0325.html)
specify the size of a [ViewPort](../Libraries_Manual_guide/node032B.html#line59).




```c
                     DISPLAY BIT-PLANES
                  _________________________
                 |                         |
                 |  _____________________  |
                 | |                     | |
                 | |                     | |
                 | |                     | |
                 | |                     | |
                 | |                     | |
                 | |_____________________| |
                 |   __________________ _ _|_ _ _ _ _ _
                 |  |                  |   |       |
                 |  |                  |   |       |
                 |  |                  |   |
                 |  |                  |   |   DHeight = how
                 |  |                  |   |  many lines tall
                 |  |                  |   |
                 |  |                  |   |       |
                 |  |__________________|_ _|_ _ _ _|_ _
                 |                         |
                 |__|__________________|___|

                    |                  |

                    |-- DWidth = how --|
                      many pixels wide
                    |                  |

         Figure 27-11: Size Definition for a ViewPort
```
 [ViewPort Height](../Libraries_Manual_guide/node0324.html)    [ViewPort Width](../Libraries_Manual_guide/node0325.html) 

