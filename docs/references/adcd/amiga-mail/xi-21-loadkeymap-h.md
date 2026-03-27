---
title: XI-21/LoadKeyMap.h
manual: amiga-mail
chapter: amiga-mail
section: xi-21-loadkeymap-h
functions: []
libraries: []
---

# XI-21/LoadKeyMap.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef LOADKEYMAP_H
#define LOADKEYMAP_H

/*****************************************************************************/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef DEVICES_KEYMAP_H
#include <devices/keymap.h>
#endif

/*****************************************************************************/

struct KeyMap *LoadKeyMap(STRPTR name);

/*****************************************************************************/

#endif /* LOADKEYMAP_H */

