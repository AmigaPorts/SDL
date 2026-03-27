---
title: XI-25/AppKeyMap.c
manual: amiga-mail
chapter: amiga-mail
section: xi-25-appkeymap-c
functions: [MapANSI]
libraries: [keymap.library]
---

# XI-25/AppKeyMap.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* appkeymap.c link module - Execute me to compile me with SAS/C 6.56
sc data=far nominc strmer streq nostkchk saveds ign=73 appkeymap.c
quit
*/

/* appkeymap.c - subroutines to create/delete an application keymap
 *               by modifying a copy of a keymap
 *
 * The modifications made to the keymap are controlled by the "mykeys" array.
 * To create more complex keymappings, see the Rom Kernel Manual Libraries
 * keymap library chapter (p 821 et al).
 *
 * NOTE: disabling all numeric pad keys creates a good keymap for use
 * with either keymap.library MapANSI() or commodities InvertString().
 * If you used a default keymap with the above functions, numeric keypad
 * raw key values would be returned for keys which are available with
 * fewer keypresses on numeric pad than on the normal keyboard.
 * It is generally preferable to have the normal keyboard raw values
 * since many applications attach special meanings to numeric pad keys.
 */

#include <exec/types.h>
#include <exec/memory.h>
#include <devices/console.h>
#include <devices/keymap.h>

#include <clib/exec_protos.h>
#include <clib/keymap_protos.h>
#include <clib/alib_protos.h>

#include "appkeymap.h"

/* local functions */
static void CopyKeyMap (struct KeyMap *source, struct KeyMap *dest);


struct KeyMap *
CreateAppKeyMap (struct KeyMap *defkeymap)
{
  struct KeyMap *appkeymap = NULL;
  struct KeyMapArrays *karrays;
  ULONG keymapsize;

```c
                                /* Because of the way this code allocates memory,  */
                                /* it must make sure the KeyMap structure will take*/
                                /* up an even amount of bytes (so the tables that  */
                                /* follow it will be word aligned).  This adds one */
                                /* to the size of the KeyMap structure's size if   */
                                /* necessary.  This is only for future compatibil- */
                                /* ity as a KeyMap structure is currently even.    */
```
  keymapsize = (sizeof(struct KeyMap)+1)&0x0000FFFE;

                                /* Allocate the space for the clone of the KeyMap. */
                                /* This includes space for the KeyMap structure    */
                                /* which is immediately followed by space for the  */
                                /* keymapping tables.                              */
  if (appkeymap = (struct KeyMap *)
```c
          AllocVec (sizeof (struct KeyMap) + sizeof (struct KeyMapArrays),
                    MEMF_CLEAR|MEMF_PUBLIC) )
```
  {
```c
                  /* Initialize the pointer to the KeyMapArrays structure. These   */
                  /* arrays are organized so that the "Lo" tables are immediately  */
                  /* followed by the "Hi" tables, so you don't have to treat the   */
                  /* Lo and Hi maps separately.  This allows AlterKeyMap() to find */
                  /* Hi map raw key entries by use the raw key value as an index   */
                  /* into the Lo map tables.                                       */
    karrays = (struct KeyMapArrays *) ((ULONG)appkeymap + keymapsize);

                  /* Initialize the appkeymap fields to point to the KeyMapArrays. */
                  /* Each LH array contains the Lo table followed by the Hi table. */
    appkeymap->km_LoKeyMap      = &karrays->LHKeyMap[0];
    appkeymap->km_HiKeyMap      = &karrays->LHKeyMap[LO_MAP_SIZE];
    appkeymap->km_LoKeyMapTypes = &karrays->LHKeyMapTypes[0];
    appkeymap->km_HiKeyMapTypes = &karrays->LHKeyMapTypes[LO_TYPE_SIZE];
    appkeymap->km_LoCapsable    = &karrays->LHCapsable[0];
    appkeymap->km_HiCapsable    = &karrays->LHCapsable[LO_CAPS_SIZE];
    appkeymap->km_LoRepeatable  = &karrays->LHRepeatable[0];
    appkeymap->km_HiRepeatable  = &karrays->LHRepeatable[LO_REPS_SIZE];


    CopyKeyMap (defkeymap, appkeymap);     /* Copy the keymap arrays to appkeymap. */
```
  }

  return (appkeymap);
}


void
DeleteAppKeyMap (struct KeyMap *appkeymap)
{
  if (appkeymap)
```c
    FreeVec (appkeymap);
```
}


void
AlterAppKeyMap (struct KeyMap *appkeymap, struct MyKey *mykeys, UWORD mykeycount)
{
  ULONG *keymappings;
  UBYTE *keymaptypes, *capsables, *repeatables;
  UBYTE rawkeynum;
  int i, bytenum, bitnum;


/* AlterAppKeyMap() assumes that the tables of the keymap passed to it are */
/* contiguous from Lo through Hi. This allows AlterAppKeyMap() to directly */
/* reference any key using its raw key code as an index.  This also limits */
/* an application to using AlterAppKeyMap() to modify only keymap created  */
/* by CreateAppKeyMap().                                                   */


  keymappings = appkeymap->km_LoKeyMap;
  keymaptypes = appkeymap->km_LoKeyMapTypes;
  capsables   = appkeymap->km_LoCapsable;
  repeatables = appkeymap->km_LoRepeatable;

  for (i = 0; i < mykeycount; i++)
  {

```c
                                    /* Because we allocated each of our Lo and Hi    */
    rawkeynum = mykeys[i].RawCode;  /* array pairs as sequential memory, we can use  */
                                    /* the RAWKEY values directly  to index into our */
                                    /* sequential Lo/Hi array.                       */

    keymaptypes[rawkeynum] = mykeys[i].MapType;
    keymappings[rawkeynum] = mykeys[i].Map;

    bytenum = rawkeynum >> 3; /* These are for the Capsable + Repeatable bit tables. */
    bitnum = rawkeynum % 8;   /*    Careful--There's only a 1 bit entry per raw key! */

    if (mykeys[i].Capsable)
      capsables[bytenum] |= (1 << bitnum);          /* If capsable, set bit, else... */
    else
      capsables[bytenum] &= (~(1 << bitnum));       /*             ...clear the bit. */

    if (mykeys[i].Repeatable)
      repeatables[bytenum] |= (1 << bitnum);      /* If repeatable, set bit, else... */
    else
      repeatables[bytenum] &= (~(1 << bitnum));   /*               ...clear the bit. */
```
  }
}





static void
CopyKeyMap (struct KeyMap *source, struct KeyMap *dest)
{
  UBYTE *bb;
  ULONG *ll;
  int i;

  for (i = 0, ll = source->km_LoKeyMap; i < LO_MAP_SIZE; i++)
```c
    dest->km_LoKeyMap[i] = *ll++;
```
  for (i = 0, ll = source->km_HiKeyMap; i < HI_MAP_SIZE; i++)

```c
    dest->km_HiKeyMap[i] = *ll++;
```
  for (i = 0, bb = source->km_LoKeyMapTypes; i < LO_TYPE_SIZE; i++)
```c
    dest->km_LoKeyMapTypes[i] = *bb++;
```
  for (i = 0, bb = source->km_HiKeyMapTypes; i < HI_TYPE_SIZE; i++)

```c
    dest->km_HiKeyMapTypes[i] = *bb++;
```
  for (i = 0, bb = source->km_LoCapsable; i < LO_CAPS_SIZE; i++)
```c
    dest->km_LoCapsable[i] = *bb++;
```
  for (i = 0, bb = source->km_HiCapsable; i < HI_CAPS_SIZE; i++)

```c
    dest->km_HiCapsable[i] = *bb++;
```
  for (i = 0, bb = source->km_LoRepeatable; i < LO_REPS_SIZE; i++)
```c
    dest->km_LoRepeatable[i] = *bb++;
```
  for (i = 0, bb = source->km_HiRepeatable; i < HI_REPS_SIZE; i++)
```c
    dest->km_HiRepeatable[i] = *bb++;
```
}

---

## See Also

- [MapANSI — keymap.library](../autodocs/keymap.library.md#mapansi)
