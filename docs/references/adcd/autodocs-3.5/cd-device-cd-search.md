---
title: cd.device/CD_SEARCH
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-search
functions: []
libraries: []
---

# cd.device/CD_SEARCH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_SEARCH -- configure the mode in which PLAY commands play
   IO REQUEST

       io_Command      CD_SEARCH
       io_Data         NULL
       io_Length       searchmode
       io_Offset       0
   RESULTS

       io_Actual - if io_Error is 0, this contains the previous search mode.
   FUNCTION

```c
       This command causes a play command to play in fast-forward,
       fast-reverse, or normal play mode.  These modes are defined as:

       CDMODE_NORMAL   0   Normal play (current speed setting)
       CDMODE_FFWD     1   Play in fast forward mode
       CDMODE_FREV     2   Play in fast reverse mode

       The search mode can be set before the play command is sent, or during
       a play.  If CD_SEARCH is sent before a play command is sent, the
       mode is set and the command immediately returns.  If the mode is set
       to REV mode, when the play command is sent the play will begin at the
       requested end position and work backwards to the start position.

       If CD_SEARCH is sent during a play, the play will automatically
       switch to the desired mode and continue playing until the original
       play command is completed.  If REV mode is set and the beginning of
       the play is encountered before switching back to forward play, the
       play command will terminate with no error.
```
   EXAMPLE

```c
       /* Search in fast forward mode. */
       ior->io_Command = CD_SEARCH;
       ior->io_Data    = NULL;
       ior->io_Offset  = 0;
       ior->io_Length  = CDMODE_FFWD;
       DoIO(ior);
```
   NOTES

   BUGS

   SEE ALSO

