---
title: 8 / Floppy Disk Controller / Registers Used by the Disk Subsystem
manual: hardware
chapter: hardware
section: 8-floppy-disk-controller-registers-used-by-the-disk
functions: []
libraries: []
---

# 8 / Floppy Disk Controller / Registers Used by the Disk Subsystem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The disk subsystem uses two ports on the system's  [8520 CIA](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md)  chips, and
several registers in the Paula chip:

   [CIAAPRA](hardware/8-disk-timing-ciaapra-prb-disk-selection-control-and-sensing.md)    ($BFE001)    four input bits for disk sensing
   [CIABPRB](hardware/8-disk-timing-ciaapra-prb-disk-selection-control-and-sensing.md)    ($BFD100)    eight output bits for disk selection, control
                             and stepping
   [ADKCON](hardware/8-timing-adkcon-and-adkconr-audio-and-disk-control-register.md)     ($DFF09E)    control bits (write only register)
   [ADKCONR](hardware/8-timing-adkcon-and-adkconr-audio-and-disk-control-register.md)    ($DFF010)    control bits (read only register)
   [DSKPTH](hardware/8-disk-subsystem-timing-dskpth-pointer-to-data.md)     ($DFF020)    DMA pointer (32 bits)
   [DSKLEN](hardware/8-disk-subsystem-timing-dsklen-length-direction-dma-enable.md)     ($DFF024)    length of DMA
   [DSKBYTR](hardware/8-timing-dskbytr-disk-data-byte-and-status-read-read-only.md)    ($DFF01A)    Disk data byte and status read
   [DSKSYNC](hardware/8-disk-subsystem-timing-dsksync-disk-input-synchronizer.md)    ($DFF07E)    Disk sync finder; holds a match word

