---
title: Devices/Dev_examples/Epsonx_macros.i
manual: devices
chapter: devices
section: devices-dev-examples-epsonx-macros-i
functions: []
libraries: []
---

# Devices/Dev_examples/Epsonx_macros.i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

**********************************************************************
*
*       printer device macro definitions
*
**********************************************************************

*------ external definition macros -----------------------------------

XREF_EXE        MACRO

        XREF            _LVO\1
                ENDM
XREF_DOS        MACRO

        XREF            _LVO\1
                ENDM
XREF_GFX        MACRO

        XREF            _LVO\1
                ENDM
XREF_ITU        MACRO

        XREF            _LVO\1
                ENDM
*------ library dispatch macros --------------------------------------

CALLEXE         MACRO

                CALLLIB _LVO\1
                ENDM
LINKEXE         MACRO

                LINKLIB _LVO\1,_SysBase
                ENDM
LINKDOS         MACRO

                LINKLIB _LVO\1,_DOSBase
                ENDM
LINKGFX         MACRO

                LINKLIB _LVO\1,_GfxBase
                ENDM
LINKITU         MACRO

                LINKLIB _LVO\1,_IntuitionBase
                ENDM
