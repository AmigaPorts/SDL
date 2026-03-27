# Trackdisk


* Private trackdisk structures have changed.  See trackdisk.doc for a
  compatible REMCHANGEINT.

* Buffer is freeable, so low memory open failure is possible.

* Do not disable interrupts (any of them) then expect trackdisk to
  function while they are disabled.

