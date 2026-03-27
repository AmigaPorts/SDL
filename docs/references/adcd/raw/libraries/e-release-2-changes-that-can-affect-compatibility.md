# E / Release 2 Changes That Can Affect Compatibility / Preferences


  * Some old struct [Preferences](../Libraries_Manual_guide/node0224.html) fields are now ignored by [SetPrefs()](../Libraries_Manual_guide/node0225.html) (for

```c
    example [FontHeight](../Libraries_Manual_guide/node0224.html#line7)). SetPrefs() also stops listening to the pointer
    fields as soon as a new-style pointer is passed to Intuition
    (new-style pointers can be taller or deeper).
```
  * [Preferences](../Libraries_Manual_guide/node0224.html) [ViewX/YOffset](../Libraries_Manual_guide/node0224.html#line36) only applies to the default mode. You

    cannot use these fields to move the position of all modes.
  * The [Preferences](../Libraries_Manual_guide/node0224.html) [LaceWB](../Libraries_Manual_guide/node0224.html#line71) bit is not necessarily correct when Workbench

```c
    is in a new display mode (akin to [GetScreenData()](../Libraries_Manual_guide/node00FC.html#line20)).
```
