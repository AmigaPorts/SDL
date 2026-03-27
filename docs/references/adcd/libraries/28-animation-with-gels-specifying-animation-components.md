---
title: 28 / Animation with GELs / Specifying Animation Components
manual: libraries
chapter: libraries
section: 28-animation-with-gels-specifying-animation-components
functions: []
libraries: []
---

# 28 / Animation with GELs / Specifying Animation Components

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For each [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md), you initially specify:


```c
      * A pointer to the [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md)'s controlling [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md).

      * Initial and alternate views, their timing and order.

      * The initial inter-component drawing priorities (for multiple
        [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md) sequences, this specifies which sequence to display
        frontmost).

      * A pointer to a special animation routine related to this
        component (optional).

      * Your own extensions to this structure (optional).
```
 [Sequencing AnimComps](libraries/28-specifying-animation-components-sequencing-animcomps.md)              [Linking Multiple AnimComp Sequences](libraries/28-animation-components-linking-multiple-animcomp-sequences.md) 
 [Position of an AnimComp](libraries/28-specifying-animation-components-position-of-an-animcomp.md)           [Component Ordering](libraries/28-specifying-animation-components-component-ordering.md) 
 [Specifying Time for Each Image](libraries/28-animation-components-specifying-time-for-each-image.md) 

