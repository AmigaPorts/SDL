---
title: 3 / Monitoring Clipboard Changes / Caveats For CBD_CHANGEHOOK
manual: devices
chapter: devices
section: 3-monitoring-clipboard-changes-caveats-for-cbd-changehook
functions: []
libraries: []
---

# 3 / Monitoring Clipboard Changes / Caveats For CBD_CHANGEHOOK

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   *  [CBD_CHANGEHOOK](autodocs-2.0/clipboard-device-cbd-changehook.md) should only be used by a special application, such as

      a clipboard viewing program.  Most applications can check the
      contents of the clipboard when, and if, the user requests a paste.
   *  Do not add system overhead by blindly reading and parsing the

      clipboard everytime a user copies data to it.  If all applications
      did this, the system could become intolerably slow whenever an
      application wrote to the clipboard.  Only read and parse when it is
      necessary.
