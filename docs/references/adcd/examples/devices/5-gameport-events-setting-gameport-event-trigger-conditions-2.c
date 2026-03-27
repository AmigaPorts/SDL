/* Source: ADCD 2.1
 * Section: 5-gameport-events-setting-gameport-event-trigger-conditions
 * Library: devices
 * ADCD reference: devices/5-gameport-events-setting-gameport-event-trigger-conditions.md
 */

    *  Setting GPTF_UPKEYS enables the reporting of upward transitions.
       Setting GPTF_DOWNKEYS enables the reporting of downward transitions.
       These flags may both be specified.

    *  The field gpt_Timeout specifies the time interval (in vertical blank
       units) between reports in the absence of another trigger condition.
       In other words, an event is generated every gpt_Timeout ticks.
       Vertical blank units may differ from country to country (e.g 60 Hz
       NTSC, 50 Hz PAL.)  To find out the exact frequency use this code
       fragment:

       #include <exec/execbase.h>
       extern struct ExecBase *SysBase;

       UBYTE get_frequency(void)
       {
       return((UBYTE)SysBase->VBlankFrequency);
       }

    *  The gpt_XDelta and gpt_YDelta fields specify the x and y distances
       which, if exceeded, trigger a report.
