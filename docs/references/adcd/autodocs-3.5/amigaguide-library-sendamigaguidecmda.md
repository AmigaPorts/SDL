---
title: amigaguide.library/SendAmigaGuideCmdA
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-sendamigaguidecmda
functions: []
libraries: []
---

# amigaguide.library/SendAmigaGuideCmdA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
        SendAmigaGuideCmdA - Send a command string to AmigaGuide (V34)
```
   SYNOPSIS
```c
        success = SendAmigaGuideCmdA (handle, cmd, attrs );
          d0                            a0    d0   d1

        [BOOL](autodocs-3.5/include-exec-types-h.md) SendAmigaGuideCmdA (AMIGAGUIDECONTEXT, [STRPTR](autodocs-3.5/include-exec-types-h.md), struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
```
;


```c
        success = SendAmigaGuideCmd (handle, cmd, tag1, ...);

        [BOOL](autodocs-3.5/include-exec-types-h.md) SendAmigaGuideCmd (AMIGAGUIDECONTEXT, [STRPTR](autodocs-3.5/include-exec-types-h.md), Tag);
```
   FUNCTION

```c
        This function sends a command string to an AmigaGuide system.  The
        command can consist of any valid AmigaGuide action command.

        The following are the currently valid action commands:

        ALINK <name> - Load the named node into a new window.

        LINK <name> - Load the named node.

        RX <macro> - [Execute](autodocs-3.5/dos-library-execute-2.md) an ARexx macro.

        RXS <cmd> - [Execute](autodocs-3.5/dos-library-execute-2.md) an ARexx string file.  To display a picture,
            use 'ADDRESS COMMAND DISPLAY <picture name>', to
            display a text file 'ADDRESS COMMAND MORE <doc>'.

        CLOSE - [Close](autodocs-3.5/dos-library-close-2.md) the window (should only be used on windows
            that were started with ALINK).

        QUIT - Shutdown the current database.
```
   INPUTS

        handle - Handle to an AmigaGuide system.

        cmd - Command string.

        attrs - Future expansion, must be set to NULL for now.
   TAGS

```c
        AGA_Context (ULONG) - Data is used as an index into nag_Context
            array.  This is used to build and send a LINK command.
```
   EXAMPLE


```c
        /* bring up help on a particular subject */
        SendAmigaGuideCmd(handle, "LINK MAIN", NULL);
```
   RETURNS

        Returns TRUE if the message was sent, otherwise returns FALSE.
   BUGS

        ALINK does not open a new window when using V39.
   SEE ALSO

