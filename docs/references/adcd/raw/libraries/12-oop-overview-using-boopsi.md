# 12 / OOP Overview / Using Boopsi


There are several levels on which a programmer can use Boopsi.  The most
elementary level is to use Intuition functions to create and manipulate
Boopsi objects that are instances of existing, public classes.

At present there is a hierarchy of 14 public classes built into Intuition:


```c
                        Figure 12-3: Class Diagram


                            [rootclass](../Libraries_Manual_guide/node04BB.html)
                               /
                 _____________/____________
                /         /                \
               /         /                  \
           [icclass](../Libraries_Manual_guide/node0200.html#line55)      /                [gadgetclass](../Libraries_Manual_guide/node020A.html)
             /         /                      \
            /         /         _______________\___________________
           /     [imageclass](../Libraries_Manual_guide/node0209.html)    /           /         \             \
          /         /         /           /           \             \
     [modelclass](../Libraries_Manual_guide/node04CC.html)    /      [propgclass](../Libraries_Manual_guide/node020A.html#line4)  [strgclass](../Libraries_Manual_guide/node020A.html#line7)  [buttongclass](../Libraries_Manual_guide/node020A.html#line14)  [groupgclass](../Libraries_Manual_guide/node020A.html#line10)
                  /                                     \
                 /                                       \
         _______/___________________________        [frbuttongclass](../Libraries_Manual_guide/node020A.html#line20)
        /         \            \            \
       /           \            \            \
```
  [frameiclass](../Libraries_Manual_guide/node0209.html#line4)  [sysiclass](../Libraries_Manual_guide/node0209.html#line9)  [fillrectclass](../Libraries_Manual_guide/node0209.html#line13)  [itexticlass](../Libraries_Manual_guide/node0209.html#line16)


 [Boopsi and Tags](../Libraries_Manual_guide/node0202.html) 
 [Creating an Object](../Libraries_Manual_guide/node0203.html) 
 [Disposing of an Object](../Libraries_Manual_guide/node0204.html) 
 [Setting an Existing Object's Attributes](../Libraries_Manual_guide/node0205.html) 
 [Getting an Object's Attributes](../Libraries_Manual_guide/node0206.html) 
 [What About the Boopsi Messages and Methods?](../Libraries_Manual_guide/node0207.html) 

