# 3 / Forming a Dual-playfield Display / Dual Playfield Summary


The steps for defining dual playfields are almost the same as those for
defining the basic playfield. Only in the following steps does the
dual-playfield creation process differ from that used for the basic
playfield:

   *   [Loading colors into the registers](../Hardware_Manual_guide/node007A.html) .

```c
      -----------------------------------
      Keep in mind that color registers 0-7 are used by playfield 1
      and registers 8 through 15 are used by playfield 2 (if there are
      three bitplanes in each playfield).
```
   *   [Building bitplanes](../Hardware_Manual_guide/node0079.html) .

      --------------------
      Recall that playfield 1 is formed from PLANES 1, 3, and 5 and
      playfield 2 from PLANES 2, 4, and 6.
   *   [Setting the modulo registers](../Hardware_Manual_guide/node0072.html#line46) .

```c
      ------------------------------
      Write the modulo to both  [BPL1MOD and BPL2MOD](../Hardware_Manual_guide/node0072.html#line108)  as you will be
      using both odd- and even-numbered bitplanes.
```
These steps are added:

   *   [Defining priority](../Hardware_Manual_guide/node007B.html) .

```c
      -------------------
      If you want playfield 2 to have priority, set bit 6 (PF2PRI)
      in  [BPLCON2](../Hardware_Manual_guide/node0159.html)  to 1.
```
   *   [Activating dual-playfield mode](../Hardware_Manual_guide/node007C.html) .

```c
      --------------------------------
      Set bit 10 ( [DBLPF](../Hardware_Manual_guide/node007C.html) ) in  [BPLCON0](../Hardware_Manual_guide/node0092.html)  to 1.
```
