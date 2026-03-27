---
title: 13 / Preferences in Release 2 / Preferences Editors and Storage
manual: libraries
chapter: libraries
section: 13-preferences-in-release-2-preferences-editors-and-storage
functions: []
libraries: []
---

# 13 / Preferences in Release 2 / Preferences Editors and Storage

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In Release 2, the devs:system-configuration file has been replaced by
various .prefs files, located in the ENV:sys and ENVARC:sys directories.
System Preferences options currently in use are located in ENV:sys.
Permanent, saved copies of system Preferences files are stored in
ENVARC:sys. The contents of ENVARC: is copied at boot time to ENV:.
Applications may also store their own preference files in ENV: but should
use a subdirectory for that purpose.

Currently the following Preferences editors and files are available:




       Table 13-1: Preferences Editors in Release 2


    Preferences Editor  Preferences Configuration File
    ------------------  ------------------------------
    IControl            icontrol.prefs
    Input               input.prefs
    Palette             palette.ilbm
    Pointer             pointer.ilbm
    Printer             printer.prefs
    PrinterGfx          printergfx.prefs
    Overscan            overscan.prefs
    ScreenMode          screenmode.prefs
    Serial              serial.prefs
    ---                 wbconfig.prefs
    Font                wbfont.prefs, sysfont.prefs and screenfont.prefs
    Time                ---
    WBPattern           wb.pat and win.pat
Each .prefs file is managed by editor with the same name, except for
wbconfig.prefs, which is written directly by Workbench and has no editor.
One Preferences editor has no .prefs file, Time.  That Preferences editor
writes directly to the battery backed clock.

When the user makes a change to a Preferences item with one of the
editors, the changes will be saved in either ENV:sys or both ENV:sys and
ENVARC:sys depending on whether the user saves the changes with the "Use"
gadget or "Save" gadget of the Preferences editor.

The "Use" gadget is for making temporary changes and the new preferences
will be stored only in ENV:sys.  If the user reboots, the old preferences
will be restored from the permanent copy in ENVARC:sys.

The "Save" gadget is for making permanent changes and the new preferences
will be stored in both ENV:sys and ENVARC:sys.  That way, if the user
reboots, the new preferences will still be in effect since the system
looks in ENVARC:sys to find out what preferences should be set to at boot
time.

