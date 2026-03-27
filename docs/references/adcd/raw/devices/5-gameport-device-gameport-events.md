# 5 Gameport Device / Gameport Events


A gameport event is an InputEvent structure which describes the following:

   * The class of the event - always set to IECLASS_RAWMOUSE for the

     gameport device.
   * The subclass of the event - 0 for the left port; 1 for the right port.

   * The code - which button and its state.  (No report = 0xFF)

   * The qualifier - only button and relative mouse bits are set.

   * The position - either a data address or mouse position count.

   * The time stamp - delta time since last report, returned as frame

     count in tv_secs field.
   * The next event - pointer to next event.



```c
    struct InputEvent GameEV
    {
        struct InputEvent *ie_NextEvent;  /* next event */
        UBYTE    ie_Class;                /* input event class */
        UBYTE    ie_SubClass;             /* subclass of the class */
        UWORD    ie_Code;                 /* input event code */
        UWORD    ie_Qualifier;            /* event qualifiers in effect */
           union
           {
             struct
             {
              WORD   ie_x;                /* x position for the event */
              WORD   ie_y;                /* y position for the event */
             }  ie_xy;
             APTR ie_addr;
           } ie_position;
        struct timeval ie_TimeStamp;      /* delta time since last report
    }
```
See the include file devices/[inputevent.h](../Includes_and_Autodocs_2._guide/node0051.html) for the complete structure
definition and listing of input event fields.

 [Reading Gameport Events](../Devices_Manual_guide/node00B5.html) 
 [Setting Gameport Event Trigger Conditions](../Devices_Manual_guide/node00B6.html) 
 [Determining The Trigger Conditions](../Devices_Manual_guide/node00B7.html) 

