# 3 / Moving (Scrolling) Playfields / Scrolling Playfield Summary


The steps for defining a scrolled playfield are the same as those for
defining the basic playfield, except for the following steps:

   *   [Defining the data fetch](../Hardware_Manual_guide/node0089.html) .

```c
      -------------------------
      Fetch one extra word per horizontal line and start it 16 pixels
      before the normal (unscrolled) data-fetch start.
```
   *   [Defining the modulo](../Hardware_Manual_guide/node008A.html) .

      ---------------------
      The modulo is two counts less than when there is no scrolling.
These steps are added:

   *  For  [vertical scrolling](../Hardware_Manual_guide/node0087.html) , reset the bitplane pointers

```c
      -----------------------------------------------------
      for the amount of the scrolling increment.
      -----------------------------------------
      Reset  [BPLxPTH and BPLxPTL](../Hardware_Manual_guide/node006B.html#line32)  during the  [vertical blanking](../Hardware_Manual_guide/node0169.html)  interval.
```
   *  For  [horizontal scrolling](../Hardware_Manual_guide/node0088.html) , specify the delay.

```c
      ---------------------------------------------
      Set bits 7-0 in  [BPLCON1](../Hardware_Manual_guide/node008B.html)  for 0 to 15 bits of delay.
```
