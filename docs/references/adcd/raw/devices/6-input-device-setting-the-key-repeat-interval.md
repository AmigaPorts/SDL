# 6 Input Device / Setting the Key Repeat Interval


The key repeat interval is the time period, in seconds and microseconds,
between key repeat events once the initial key repeat threshold has
elapsed. (See [Setting the Key Repeat Threshold](../Devices_Manual_guide/node00D7.html).)  Like the key
repeat threshold, this is normally issued by Intuition and preset by the
Preferences tool.

You set the key repeat interval by passing a [timerequest](../Devices_Manual_guide/node00CC.html#line30) with
[IND_SETPERIOD](../Includes_and_Autodocs_2._guide/node04E6.html) set in io_Command and the number of seconds set in tv_secs
and the number of microseconds set in tv_micro. struct timerequest
*InputTime; /* Initialize with CreateExtIO() before using */

   InputTime->tr_time.tv_secs=0;
   InputTime->tr_time.tv_micro=12000;  /* .012 seconds */
   InputTime->tr_node.io_Command=IND_SETPERIOD;
   DoIO((struct IORequest *)InputTime);

The code above sets the key repeat interval to .012 seconds.

   The Right Tool For The Right Job.
   ---------------------------------
   As previously stated, you must use a [timerequest](../Devices_Manual_guide/node00CC.html#line29) structure with
   [IND_SETTHRESH](../Includes_and_Autodocs_2._guide/node04E7.html) and [IND_SETPERIOD](../Includes_and_Autodocs_2._guide/node04E6.html).

