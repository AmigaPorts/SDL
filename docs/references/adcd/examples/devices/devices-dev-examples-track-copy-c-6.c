/* Source: ADCD 2.1
 * Section: devices-dev-examples-track-copy-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-track-copy-c.md
 */

           {
           printf("\nYou must specify different disks for source and destination\n");
           return(!OKAY);
           }
     else while (params == OKAY && j<3)
           {
           if (strnicmp(argv[j],"df",2)==0)
             {
             if (argv[j][2] >= '0' && argv[j][2] <= '3' && argv[j][3] == '\0')
               {
               Unit[j-1] = argv[j][2] - 0x30;
               }
             else
               {
               printf("\n%s parameter is wrong, unit number must be 0-3\n",position[j-1]);
               params = !OKAY;
               return(!OKAY);
               }
             }
           else
             {
             printf("\n%s parameter is wrong, you must specify a floppy device df0 - df3\n",
                     position[j-1]);
             params=!OKAY;
             return(!OKAY);
             }
           j++;
           }
