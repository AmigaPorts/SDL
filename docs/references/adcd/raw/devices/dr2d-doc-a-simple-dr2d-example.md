# DR2D.doc / A Simple DR2D Example


Here is a (symbolic) DR2D FORM:

 FORM { DR2D
```c
        DRHD 16 { 0.0, 0.0, 10.0, 8.0 }
        CMAP  6 { 0,0,0, 255,255,255 }
        FONS  9 { 1, 0, 1, 0, "Roman" } 0
        DASH 12 { 1, 2, {1.0, 1.0} }
        ATTR 14 { 0, 0, 1, 0, 0, 0, 0, 0.0 }
        BBOX 16 { 2.0, 2.0, 8.0, 6.0 }
        FORM { DR2D
              GRUP  2 { 2 }
              BBOX 16 { 3.0, 4.0, 7.0, 5.0 }
              STXT 36 { 0,1, 0.5, 1.0, 3.0, 5.0, 0.0, 12, "Hello, World" }
              BBOX 16 { 2.0, 2.0, 8.0, 6.0 }
              OPLY 42 { 5, {2.0,2.0, 8.0,2.0, 8.0,6.0, 2.0,6.0, 2.0,2.0 }
        }
```
 }

 [Figure 4 - Simple DR2D Drawing](../Devices_Manual_guide/node02E4.html) 

