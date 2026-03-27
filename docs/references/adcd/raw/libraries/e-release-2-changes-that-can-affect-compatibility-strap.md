# E / Release 2 Changes That Can Affect Compatibility / Strap


  * Romboot.library is gone.

  * Audio.device cannot be [OpenDevice()](../Libraries_Manual_guide/node029E.html)ed by a boot block program.  See

```c
    "[Audio Device](../Libraries_Manual_guide/node0565.html)" below.
```
  * Boot from other floppies (+5,-10,-20,-30) is possible.

  * Undocumented system stack and register usage at Diag and Boot time

    have changed.
