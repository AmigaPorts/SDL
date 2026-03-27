# 6 / Setting The Conditions For A Mouse Port Report


You set the conditions for a mouse port report by passing an [IOStdReq](../Devices_Manual_guide/node00CC.html#line12) to
the device with [IND_SETMTRIG](../Includes_and_Autodocs_2._guide/node04E4.html) set in io_Command, the address of a
GamePortTrigger structure set in io_Data and the length of the structure
set in io_Length.

   struct GamePortTrigger InputTR;

   InputIO->io_Data = (APTR)InputTR;     /* set trigger conditions */
   InputIO->io_Command = IND_SETMTRIG;   /* from InputTR */
   InputIO->io_Length = sizeof(struct GamePortTrigger);
   DoIO(InputIO);

The information needed for mouse port report setting is contained in a
GamePortTrigger data structure which is defined in the include file
devices/[gameport.h](../Includes_and_Autodocs_2._guide/node0039.html).

   struct GamePortTrigger
   {
```c
       UWORD    gpt_Keys;      /* key transition triggers */
       UWORD    gpt_Timeout;   /* time trigger (vertical blank units) */
       UWORD    gpt_XDelta;    /* X distance trigger */
       UWORD    gpt_YDelta;    /* Y distance trigger */
```
   };

See the [Gameport Device](../Devices_Manual_guide/node00AE.html) chapter of this manual for a full description
of setting mouse port trigger conditions.

