# 32 / Expansion Board Drivers / ROM Based and Autoboot Drivers


Since 1.3, the system software supports the initialization of ROM drivers
residing on expansion peripherals, including the ability for drivers to
provide a DOS node which the system can boot from. This feature is known
as Autoboot.

Automatic boot from a ROM-equipped expansion board is accomplished before
DOS is initialized.  This facility makes it possible to automatically boot
from a hard disk without any floppy disks inserted.  Likewise, it is
possible to automatically boot from any device which supports the ROM
protocol, even allowing the initialization of a disk operating system
other than the Amiga's dos.library.  ROM-based drivers contain several
special entry points that are called at different stages of system
initialization. These three stages are known as DIAG, ROMTAG INIT and BOOT.

 [Events At DIAG Time](../Libraries_Manual_guide/node041C.html)    [Events At ROMTAG INIT Time](../Libraries_Manual_guide/node041D.html)    [Events At BOOT Time](../Libraries_Manual_guide/node041E.html) 

