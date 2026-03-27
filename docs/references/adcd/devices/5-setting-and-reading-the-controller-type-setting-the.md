---
title: 5 / Setting and Reading the Controller Type / Setting The Controller Type
manual: devices
chapter: devices
section: 5-setting-and-reading-the-controller-type-setting-the
functions: []
libraries: []
---

# 5 / Setting and Reading the Controller Type / Setting The Controller Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You set the type of gameport controller by passing an I/O request to the
device with [GPD_SETCTYPE](autodocs-2.0/gameport-device-gpd-setctype.md) set in io_Command, 1 set in io_Length and the
address of the byte variable describing the controller type set in io_Data.

The gameport device is a shared device; many tasks may have it open at any
given time. Hence, a high level protocol has been established to prevent
multiple tasks from reading the same unit at the same time.

 [Three Step Protocol for Using the Gameport Device](devices/5-setting-controller-type-three-step-protocol-for-using.md) 

