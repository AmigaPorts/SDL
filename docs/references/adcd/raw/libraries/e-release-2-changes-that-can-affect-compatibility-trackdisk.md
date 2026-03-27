# E / Release 2 Changes That Can Affect Compatibility / Trackdisk Device


  * Private trackdisk structures have changed.  See [trackdisk.doc](../Includes_and_Autodocs_2._guide/node051E.html) for a

```c
    compatible [REMCHANGEINT](../Includes_and_Autodocs_2._guide/node052F.html).
```
  * Buffer is freeable, so low memory open failure is possible.

  * Do not disable interrupts (any of them), then expect trackdisk to

    function while they are disabled.
