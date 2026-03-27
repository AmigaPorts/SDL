---
title: Expansion Index
manual: libraries
chapter: libraries
section: expansion-index
functions: [InitResident]
libraries: [exec.library]
---

# Expansion Index

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Expansion, [924](libraries/e-release-2-changes-that-can-affect-compatibility-expansion.md)
  AddBootNode(), [759](libraries/32-expansion-board-drivers-expansion-drivers-and-dos.md), [776](libraries/32-expansion-library-function-reference.md)
  AddDosNode(), [759](libraries/32-expansion-board-drivers-expansion-drivers-and-dos.md), [776](libraries/32-expansion-library-function-reference.md)
  autoboot - BOOT, [768](libraries/32-rom-based-and-autoboot-drivers-events-at-boot-time.md), DIAG, [761](libraries/32-rom-based-and-autoboot-drivers-events-at-diag-time.md), ROMTAG INIT, [768](libraries/32-rom-based-and-autoboot-drivers-events-at-romtag-init-time.md)
  AUTOCONFIG, [755](libraries/32-expansion-library-autoconfig-tm.md) - hardware manufacturer number, [756](libraries/32-expansion-library-autoconfig-tm.md)
  ConfigDev flags, [756](libraries/32-expansion-library-the-expansion-sequence.md)
  device drivers, [758](libraries/32-expansion-library-expansion-board-drivers.md)
  DiagArea flags, [761](libraries/32-rom-based-and-autoboot-drivers-events-at-diag-time.md)
  disk based expansion board drivers, [758](libraries/32-expansion-board-drivers-disk-based-drivers.md)
  examples
```c
    DiagArea in RAM, [762](libraries/32-rom-based-and-autoboot-drivers-events-at-diag-time.md)
    list AUTOCONFIG boards, [757](libraries/lib-examples-findboards-c.md)
    sample autoboot code, [763](libraries/lib-examples-diag-asm.md)
    sample AUTOCONFIG ROM, [767](libraries/32-rom-based-and-autoboot-drivers-events-at-diag-time.md)
```
  expansion board drivers - Autoboot, [760](libraries/32-expansion-board-drivers-rom-based-and-autoboot-drivers.md), ROM based, [760](libraries/32-expansion-board-drivers-rom-based-and-autoboot-drivers.md)
  FileSysRes, [775](libraries/32-rigiddiskblock-and-alternate-filesystems-filesysres-h.md)
  FileSysResource, [769](libraries/32-expansion-board-drivers-rigiddiskblock-and-alternate.md)
  FindConfigDev(), [756](libraries/32-expansion-library-the-expansion-sequence.md), [757](libraries/32-the-expansion-sequence-simple-expansion-library-example.md), [776](libraries/32-expansion-library-function-reference.md)
  GetCurrentBinding(), [759](libraries/32-expansion-board-drivers-disk-based-drivers.md), [776](libraries/32-expansion-library-function-reference.md)
  Hardware Manufacturer Number, [756](libraries/32-expansion-library-autoconfig-tm.md)
  InitResident(), [759](libraries/32-expansion-board-drivers-disk-based-drivers.md)
  MakeDosNode(), [759](libraries/32-expansion-board-drivers-expansion-drivers-and-dos.md), [776](libraries/32-expansion-library-function-reference.md)
  ObtainConfigBinding(), [759](libraries/32-expansion-board-drivers-disk-based-drivers.md)
  ReleaseConfigBinding(), [759](libraries/32-expansion-board-drivers-disk-based-drivers.md)
  RigidDiskBlock, [769](libraries/32-expansion-board-drivers-rigiddiskblock-and-alternate.md), - see also "[SCSI Device](devices/11-scsi-device.md)" in RKM:Devices
```c
    BadBlockBlock, [772](libraries/32-rigiddiskblock-and-alternate-filesystems-badblockblock.md)
    Environment, [773](libraries/32-rigiddiskblock-and-alternate-filesystems-partitionblock.md)
    FileSysHeaderBlock, [774](libraries/32-rigiddiskblock-and-alternate-filesystems.md)
    LoadSegBlock, [775](libraries/32-rigiddiskblock-and-alternate-filesystems-loadsegblock.md)
    PartitionBlock, [773](libraries/32-rigiddiskblock-and-alternate-filesystems-partitionblock.md)
```
  RigidDiskBlock specification, [770](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md)
  SetCurrentBinding(), [759](libraries/32-expansion-board-drivers-disk-based-drivers.md), [776](libraries/32-expansion-library-function-reference.md)
  struct ConfigDev, [756](libraries/32-expansion-library-the-expansion-sequence.md)
  struct CurrentBinding, [759](libraries/32-expansion-board-drivers-disk-based-drivers.md)
  struct DiagArea, [761](libraries/32-rom-based-and-autoboot-drivers-events-at-diag-time.md)
  struct DosEnvc, [760](libraries/32-expansion-board-drivers-expansion-drivers-and-dos.md)
  struct ExpansionRom, [757](libraries/32-expansion-library-the-expansion-sequence.md)

---

## See Also

- [InitResident — exec.library](../autodocs/exec.library.md#initresident)
