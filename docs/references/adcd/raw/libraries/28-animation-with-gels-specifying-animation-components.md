# 28 / Animation with GELs / Specifying Animation Components


For each [AnimComp](../Libraries_Manual_guide/node03B9.html#line3), you initially specify:


```c
      * A pointer to the [AnimComp](../Libraries_Manual_guide/node03B9.html#line3)'s controlling [AnimOb](../Libraries_Manual_guide/node03B9.html#line34).

      * Initial and alternate views, their timing and order.

      * The initial inter-component drawing priorities (for multiple
        [AnimComp](../Libraries_Manual_guide/node03B9.html#line3) sequences, this specifies which sequence to display
        frontmost).

      * A pointer to a special animation routine related to this
        component (optional).

      * Your own extensions to this structure (optional).
```
 [Sequencing AnimComps](../Libraries_Manual_guide/node03BF.html)              [Linking Multiple AnimComp Sequences](../Libraries_Manual_guide/node03C2.html) 
 [Position of an AnimComp](../Libraries_Manual_guide/node03C0.html)           [Component Ordering](../Libraries_Manual_guide/node03C3.html) 
 [Specifying Time for Each Image](../Libraries_Manual_guide/node03C1.html) 

