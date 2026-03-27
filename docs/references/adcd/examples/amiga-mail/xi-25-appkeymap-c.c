/* Source: ADCD 2.1
 * Section: xi-25-appkeymap-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/xi-25-appkeymap-c.md
 */

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
