---
title: 2.0 IncludeXREF: K
manual: autodocs-2.0
chapter: autodocs-2.0
section: 2-0-includexref-k
functions: []
libraries: []
---

# 2.0 IncludeXREF: K

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

km_HiCapsable    pointer to unsigned char in struct KeyMap
```c
         +0x0018 [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *30
```
km_HiKeyMap      pointer to unsigned long int in struct KeyMap
```c
         +0x0014 [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *29
```
km_HiKeyMapTypes pointer to unsigned char in struct KeyMap
```c
         +0x0010 [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *28
```
km_HiRepeatable pointer to unsigned char in struct KeyMap
```c
         +0x001c [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *31
```
km_LoCapsable    pointer to unsigned char in struct KeyMap
```c
         +0x0008 [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *26
```
km_LoKeyMap      pointer to unsigned long int in struct KeyMap
```c
         +0x0004 [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *25
```
km_LoKeyMapTypes pointer to unsigned char in struct KeyMap
```c
         +0x0000 [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *24
```
km_LoRepeatable pointer to unsigned char in struct KeyMap
```c
         +0x000c [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *27
```
kn_KeyMap        struct KeyMap(size 0x0020 bytes) in struct KeyMapNode
```c
         +0x000e [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *36
```
kn_Node          struct Node(size 0x000e bytes) in struct KeyMapNode
```c
         +0x0000 [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *35
```
kr_List          struct List(size 0x000e bytes) in struct KeyMapResource
```c
         +0x000e [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *42
```
kr_Node          struct Node(size 0x000e bytes) in struct KeyMapResource
```c
         +0x0000 [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *41
```
KBD_ADDRESETHANDLER #define (CMD_NONSTD+2) = 0x0000000b
```c
                 [devices/keyboard.h](autodocs-2.0/includes-devices-keyboard-h.md): *21
```
KBD_READEVENT    #define (CMD_NONSTD+0) = 0x00000009  [devices/keyboard.h](autodocs-2.0/includes-devices-keyboard-h.md): *19
KBD_READMATRIX   #define (CMD_NONSTD+1) = 0x0000000a  [devices/keyboard.h](autodocs-2.0/includes-devices-keyboard-h.md): *20
KBD_REMRESETHANDLER #define (CMD_NONSTD+3) = 0x0000000c
```c
                 [devices/keyboard.h](autodocs-2.0/includes-devices-keyboard-h.md): *22
```
KBD_RESETHANDLERDONE #define (CMD_NONSTD+4) = 0x0000000d
```c
                 [devices/keyboard.h](autodocs-2.0/includes-devices-keyboard-h.md): *23
```
KCB_ALT          #define 1 = 0x00000001  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *50
KCB_CONTROL      #define 2 = 0x00000002  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *52
KCB_DEAD         #define 5 = 0x00000005  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *57
KCB_DOWNUP       #define 3 = 0x00000003  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *54
KCB_NOP          #define 7 = 0x00000007  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *63
KCB_SHIFT        #define 0 = 0x00000000  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *48
KCB_STRING       #define 6 = 0x00000006  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *60
KCF_ALT          #define 0x02 = 0x00000002  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *51
KCF_CONTROL      #define 0x04 = 0x00000004  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *53
KCF_DEAD         #define 0x20 = 0x00000020  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *58
KCF_DOWNUP       #define 0x08 = 0x00000008  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *55
KCF_NOP          #define 0x80 = 0x00000080  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *64
KCF_SHIFT        #define 0x01 = 0x00000001  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *49
KCF_STRING       #define 0x40 = 0x00000040  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *61
KC_NOQUAL        #define 0 = 0x00000000  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *46
KC_VANILLA       #define 7 = 0x00000007  [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *47
KEEPNUM          #define (NSF_STRING | NSF_SOURCE | NSF_NUMBER | NSF_BINARY) =
```c
                 0x0000009a
                 [rexx/storage.h](autodocs-2.0/includes-rexx-storage-h.md): *79
```
KEEPSTR          #define (NSF_STRING | NSF_SOURCE | NSF_NOTNUM) = 0x00000086
```c
                 [rexx/storage.h](autodocs-2.0/includes-rexx-storage-h.md): *78
```
KEYCODE_B        #define 0x35 = 0x00000035  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1350
KEYCODE_GREATER  #define 0x39 = 0x00000039  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1354
KEYCODE_LESS     #define 0x38 = 0x00000038  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1353
KEYCODE_M        #define 0x37 = 0x00000037  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1352
KEYCODE_N        #define 0x36 = 0x00000036  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1351
KEYCODE_Q        #define 0x10 = 0x00000010  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1346
KEYCODE_V        #define 0x34 = 0x00000034  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1349
KEYCODE_X        #define 0x32 = 0x00000032  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1348
KEYCODE_Z        #define 0x31 = 0x00000031  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *1347
KNOBHIT          #define 0x0100 = 0x00000100  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *507
KNOBHMIN         #define 6 = 0x00000006  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *512
KNOBVMIN         #define 4 = 0x00000004  [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): *513
KeyMap           structure tag size 0x0020 [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *23, 36
```c
                 [devices/conunit.h](autodocs-2.0/includes-devices-conunit-h.md): 76
                 [intuition/intuition.h](autodocs-2.0/includes-intuition-intuition-h.md): 560
```
KeyMapNode       structure tag size 0x002e [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *34
KeyMapResource   structure tag size 0x001c [devices/keymap.h](autodocs-2.0/includes-devices-keymap-h.md): *40
KeyRptDelay      struct timeval(size 0x0008 bytes) in struct Preferences
```c
         +0x000c [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *57
```
KeyRptSpeed      struct timeval(size 0x0008 bytes) in struct Preferences
```c
         +0x0004 [intuition/preferences.h](autodocs-2.0/includes-intuition-preferences-h.md): *56
```
KickCheckSum     pointer to void in struct ExecBase
```c
         +0x022a [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *124
```
KickMemPtr       pointer to void in struct ExecBase
```c
         +0x0222 [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *122
```
KickTagPtr       pointer to void in struct ExecBase

```c
         +0x0226 [exec/execbase.h](autodocs-2.0/includes-exec-execbase-h.md): *123
```
