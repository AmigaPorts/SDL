---
title: exec.library/AddDevice
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-adddevice
functions: []
libraries: []
---

# exec.library/AddDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddDevice -- add a device to the system
SYNOPSIS

```c
    AddDevice(device)
              A1

    void AddDevice(struct [Device](autodocs-2.0/includes-exec-devices-h.md) *);
```
FUNCTION

    This function adds a new device to the system device list, making
    it available to other programs.  The device must be ready to be
    opened at this time.
INPUTS

    device - pointer to a properly initialized device node
SEE ALSO

```c
    [RemDevice](autodocs-2.0/exec-library-remdevice.md), [OpenDevice](autodocs-2.0/exec-library-opendevice.md), [CloseDevice](autodocs-2.0/serial-device-closedevice.md), [MakeLibrary](autodocs-2.0/exec-library-makelibrary.md)
```
