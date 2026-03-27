/* Source: ADCD 2.1
 * Section: devices-dev-examples-get-disk-unit-id-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-get-disk-unit-id-c.md
 */

      {
       printf("Defined drive types are:\n");
       printf("  AMIGA  $00000000\n");
       printf("  5.25'' $55555555\n");
       printf("  AMIGA  $00000000 (high density)\n");
       printf("  None   $FFFFFFFF\n\n");

       /* What are the UnitIDs? */
        for (ids = 0; ids < 4; ids++)
           {
            type = GetUnitID(ids);
            printf("The UnitID for unit %d is $%08lx\n",ids,type);
           }
      }
