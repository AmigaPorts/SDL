---
title: 1 / Using a Device / Amiga System Device Command Prefixes and Examples
manual: devices
chapter: devices
section: 1-using-a-device-amiga-system-device-command-prefixes-and
functions: []
libraries: []
---

# 1 / Using a Device / Amiga System Device Command Prefixes and Examples

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

        Device          Prefix                          Example
        ------          ------                          -------
        Audio           ADCMD                           ADCMD_ALLOCATE
        Clipboard       CBD                             CBD_POST
        Console         CD                              CD_ASKKEYMAP
        Gameport        GPD                             GPD_SETCTYPE
        Input           IND                             IND_SETMPORT
        Keyboard        KBD                             KBD_READMATRIX
        Narrator        no device specific commands
        Parallel        PDCMD                           PDCMD_QUERY
        Printer         PRD                             PRD_PRTCOMMAND
        SCSI            HD                              HD_SCSICMD
        Serial          SDCMD                           SDCMD_BREAK
        Timer           TR                              TR_ADDREQUEST
        Trackdisk       TD and ETD                      TD_MOTOR/ETD_MOTOR
Each device maintains its own I/O request queue.  When a device receives
an I/O request, it either processes the request immediately or puts it in
the queue because one is already being processed.   After an I/O request
is completely processed, the device checks its queue and if it finds
another I/O request, begins to process that request.

