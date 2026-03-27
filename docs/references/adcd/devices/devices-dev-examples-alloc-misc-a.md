---
title: Devices/Dev_examples/Alloc_Misc.a
manual: devices
chapter: devices
section: devices-dev-examples-alloc-misc-a
functions: []
libraries: []
---

# Devices/Dev_examples/Alloc_Misc.a

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* Alloc_Misc.a
*
* Assembly language fragment that grabs the two parts of the serial
* resource (using misc.resource).  If it gets the resource, it will
* wait for CTRL-C to be pressed before releasing.
*
* While we are waiting, the query_serial program should be run.  It will try
* to open the serial device and if unsuccessful, will return the name of the
* owner.  It will be us, Serial Port Hog!
*
* When a task has successfully obtained the serial resource, it "owns"
* the hardware registers that control the serial port.  No other tasks
* are allowed to interfere.
*
* Assemble with Adapt
*     HX68 Allocate_Misc.a to Allocate_Misc.o
*
* Link
*     Blink FROM Allocate_Misc.o TO Allocate_Misc LIB LIB:amiga.lib
*


```c
                INCDIR  "include:"
                INCLUDE "exec/types.i"
                INCLUDE "resources/misc.i"
                INCLUDE "dos/dos.i"

        xref    _AbsExecBase     ; We get this from outside...
        xref    _LVOOpenResource ; We get this from outside...
        xref    _LVOWait         ; We get this from outside...
```
;
; Open Exec and the misc.resource, check for success
;

```c
                move.l  _AbsExecBase,a6         ;Prepare to use exec
                lea.l   MiscName(pc),a1
                jsr     _LVOOpenResource(a6)    ;Open "misc.resource"
                move.l  d0,d7                   ;Stash resource base
                bne.s   resource_ok
                moveq   #RETURN_FAIL,d0
                rts
```
resource_ok     exg.l   d7,a6                   ;Put resource base in A6

;
; We now have a pointer to a resource.
; Call one of the resource's library-like vectors.
;
```c
                move.l  #MR_SERIALBITS,d0       ;We want these bits
                lea.l   MyName(pc),a1           ;This is our name
                jsr     MR_ALLOCMISCRESOURCE(a6)
                tst.l   d0
                bne.s   no_bits                 ;Someone else has it...
                move.l  #MR_SERIALPORT,d0
                lea.l   MyName(pc),a1
                jsr     MR_ALLOCMISCRESOURCE(a6)
                tst.l   d0
                bne.s   no_port                 ;Someone else has it...
```
;
; We just stole the serial port registers; wait.
; Nobody else can use the serial port, including the serial.device!
;
```c
                exg.l   d7,a6                   ;use exec again
                move.l  #SIGBREAKF_CTRL_C,d0
                jsr     _LVOWait(a6)            ;Wait for CTRL-C
                exg.l   d7,a6                   ;Get resource base back
```
;
; Free 'em up
;
```c
                move.l  #MR_SERIALPORT,d0
                jsr     MR_FREEMISCRESOURCE(a6)
```
no_port
```c
                move.l  #MR_SERIALBITS,d0
                jsr     MR_FREEMISCRESOURCE(a6)
```
no_bits
                moveq   #RETURN_FAIL,d0
                rts
;
; Text area
;
MiscName        dc.b    'misc.resource',0
MyName          dc.b    'Serial Port Hog',0

                dc.w    0
                END
