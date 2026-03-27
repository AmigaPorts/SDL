---
title: 12 / OOP Overview / Using Boopsi
manual: libraries
chapter: libraries
section: 12-oop-overview-using-boopsi
functions: []
libraries: []
---

# 12 / OOP Overview / Using Boopsi

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are several levels on which a programmer can use Boopsi.  The most
elementary level is to use Intuition functions to create and manipulate
Boopsi objects that are instances of existing, public classes.

At present there is a hierarchy of 14 public classes built into Intuition:


```c
                        Figure 12-3: Class Diagram


                            [rootclass](libraries/b-boopsi-class-reference-rootclass.md)
                               /
                 _____________/____________
                /         /                \
               /         /                  \
           [icclass](libraries/12-boopsi-object-oriented-intuition-oop-overview.md)      /                [gadgetclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md)
             /         /                      \
            /         /         _______________\___________________
           /     [imageclass](libraries/12-the-public-classes-the-imageclass-subclasses.md)    /           /         \             \
          /         /         /           /           \             \
     [modelclass](libraries/b-boopsi-class-reference-modelclass.md)    /      [propgclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md)  [strgclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md)  [buttongclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md)  [groupgclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md)
                  /                                     \
                 /                                       \
         _______/___________________________        [frbuttongclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md)
        /         \            \            \
       /           \            \            \
```
  [frameiclass](libraries/12-the-public-classes-the-imageclass-subclasses.md)  [sysiclass](libraries/12-the-public-classes-the-imageclass-subclasses.md)  [fillrectclass](libraries/12-the-public-classes-the-imageclass-subclasses.md)  [itexticlass](libraries/12-the-public-classes-the-imageclass-subclasses.md)


 [Boopsi and Tags](libraries/12-using-boopsi-boopsi-and-tags.md) 
 [Creating an Object](libraries/12-using-boopsi-creating-an-object.md) 
 [Disposing of an Object](libraries/12-using-boopsi-disposing-of-an-object.md) 
 [Setting an Existing Object's Attributes](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md) 
 [Getting an Object's Attributes](libraries/12-using-boopsi-getting-an-object-s-attributes.md) 
 [What About the Boopsi Messages and Methods?](libraries/12-using-boopsi-what-about-the-boopsi-messages-and-methods.md) 

