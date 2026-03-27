---
title: 8 / Floppy Disk Controller / Disk Subsystem Timing
manual: hardware
chapter: hardware
section: 8-floppy-disk-controller-disk-subsystem-timing
functions: []
libraries: []
---

# 8 / Floppy Disk Controller / Disk Subsystem Timing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Figures 8-7, 8-8 and 8-9 show the timing parameters of the Amiga's floppy
disk subsystem with a Chinon drive. Keep in mind that this information can
change with floppy drives from other vendors.  To ensure compatibility
with future versions of the system, you should avoid using this
information in applications.


             500ms min
           |<--------->|
         __            |
  MOTOR    |           |
  ON       |___________________________________________________________

         __            |                                       ________
  DRIVE    |           |                                      |
  SELECT   |__________________________________________________|

           |           |                         1.2ms min    |
           |           |                    |<--------------->|
         _____    ___________________________________    ______________
  STEP        |  |                                   |  |
           |  |__|     |                    |        |__|
           |           |                    |
           |  -->|     |<--18ms min         | 1.3ms min |
        -->|           |<--1us min          |<--------->|
         ______________                      __________________________
  WRITE                |                    |
  GATE                 |____________________|
```c
                                               1.2ms min
                 -->|  |<--1000us min       |<---------->|
         ___________   |   (see text)       |             _____________
```
  SIDE              |  |                    |            |
  SELECT            |____________________________________|

             8us max-->|  |<--        -->|  |<--8us max
         ______________________________________________________________
  WRITE                   |  |  |  |  |  |
  DATA                 |  |__|__|__|__|__|  |


                 Figure 8-7: Chinon Write Timing Diagram

         ____                                                   _______
  DRIVE      |                                                 |
  SELECT     |_________________________________________________|

             |      |            |      | 3ms  |            |  |
             |  t   | 18 ms min  |      | min  | 18 ms min  |  |
             |<---->|<---------->|      |<---->|<---------->|  |<-t
         ________    _________    ___    ___    _________    __________
  STEP           |  |         |  |   |  |   |  |         |  |
                 |__|         |__|   |__|   |__|         |__|

              |  t  |  t  |  t   |   |  |      |  t  |  t   |
              |<--->|<--->|<---->| ->|  |<-t   |<--->|<---->|
               ___________       |                    _________________
  DIRECTION   |           |      |                   |
  SELECT _____|     |     |__________________________|
                    | 4ms
                    | max  |     |  |
                    |<---->|   ->|  |<-t
         __________________          __________________________________
                           |        |
  TRACK 00                 |________|


                 Figure 8-8: Chinon Access Timing Diagram

         __
  DRIVE    |
  SELECT   |___________________________________________________________

        -->|     |<--1us min
         _____    _____________________________________________________
  STEP        |  |
           |  |__|
           |         18ms min
           |     |<------------->|
           |     |   1us min     |
           |<------------------->|
         ________________________         _____________________________
  WRITE                          |       |
  GATE     |     |               |_______|
```c
           |     | 1000us min  |             1.2ms min
           |     | (see text)->| |<--    |<------------>|
         ______________________  |       |               ______________
```
  SIDE                         |         |              |
  SELECT   |  -->|  |<--18ms   |________________________|
```c
           |     |  |    max
           |1us min |                    |  |           |  |  1000us min
           |<------>|        1.2ms max-->|  |<--     -->|  |<-(see text)
         ______________________________________________________________
```
  VALID             |  |  |  |              |  |  |  |  |  |  |  |  |  |
  READ DATA         |__|__|__|              |__|__|__|__|  |__|__|__|__|




                  Figure 8-8: Chinon Read Timing Diagram
 [CIAAPRA/CIABPRB - Disk selection, control and sensing](hardware/8-disk-timing-ciaapra-prb-disk-selection-control-and-sensing.md) 
 [Disk DMA Channel Control](hardware/8-disk-subsystem-timing-disk-dma-channel-control.md) 
 [DSKPTH - Pointer to Data](hardware/8-disk-subsystem-timing-dskpth-pointer-to-data.md) 
 [DSKLEN - Length, Direction, DMA Enable](hardware/8-disk-subsystem-timing-dsklen-length-direction-dma-enable.md) 
 [DSKBYTR - Disk Data Byte and Status Read (read-only)](hardware/8-timing-dskbytr-disk-data-byte-and-status-read-read-only.md) 
 [ADKCON and ADKCONR - Audio and Disk Control Register](hardware/8-timing-adkcon-and-adkconr-audio-and-disk-control-register.md) 
 [DSKSYNC - Disk Input Synchronizer](hardware/8-disk-subsystem-timing-dsksync-disk-input-synchronizer.md) 

