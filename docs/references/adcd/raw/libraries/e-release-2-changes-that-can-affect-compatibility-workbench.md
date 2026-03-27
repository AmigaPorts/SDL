# E / Release 2 Changes That Can Affect Compatibility / Workbench


  * The Workbench GUI now has new screen sizes, screen top/left offsets,

    depths, modes, and fonts.
  * Default Tool now searches paths.

  * New Look (boxed) icons take more space.

  * Do not use icons which have more 1bits set in [PlanePick](../Libraries_Manual_guide/node01BA.html#line63) than planes

```c
    in the [ImageData](../Libraries_Manual_guide/node01BA.html#line47) (one IFF-to-Icon utility does this).  Such icons
    will appear trashed on deeper Workbenches.
```
  * New Look colors have black and white swapped (as compared to 1.3).

  * The Workbench screen may not be open at startup-sequence time until

```c
    some output occurs to the initial Shell window.  This can break
    startup-sequence-started games that think they can steal WB's screen
    bitplanes.  Do not steal the Workbench screen's bitplanes.  (For
    compatibility, booting off pre-2.0 disks forces the initial screen
    open. This is not guaranteed to remain in the system.)  Use startup
    code that can detach when RUN (such as cback.o) and use
    [CloseWorkbench()](../Libraries_Manual_guide/node00E8.html#line25) to regain the screen's memory.  In addition, see
    "[Workbench and Startup](../Libraries_Manual_guide/node0576.html)" in the "Additional Information" section
    below.
```
