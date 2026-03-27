---
title: 2 / Hardware Control Commands / CMD_STOP
manual: devices
chapter: devices
section: 2-hardware-control-commands-cmd-stop
functions: []
libraries: []
---

# 2 / Hardware Control Commands / CMD_STOP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This command stops the current write cycle immediately. If there are no
[CMD_WRITE](devices/2-hardware-control-commands-cmd-write.md)s in progress, it sets a flag so any future CMD_WRITEs are queued
up and do not begin processing (playing).

