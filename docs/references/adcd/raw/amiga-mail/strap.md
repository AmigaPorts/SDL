# Strap


* romboot.library is gone.

* audio.device cannot be OpenDevice()ed by a boot block program because
  it is not yet InitResident()ed.  If OpenDevice() of audio.device fails
  during strap, you must FindResident()/InitResident() audio.device, and
  then try OpenDevice() again.

* Boot from other floppies (+5,-10,-20,-30) is possible.

* Undocumented system stack and register usage at Diag and Boot time
  have changed.

