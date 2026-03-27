# XI-21/LoadKeyMap.h


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

