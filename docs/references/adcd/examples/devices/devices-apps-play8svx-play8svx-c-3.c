/* Source: ADCD 2.1
 * Section: devices-apps-play8svx-play8svx-c
 * Library: devices
 * ADCD reference: devices/devices-apps-play8svx-play8svx-c.md
 */

    {
    period = ((per_ntsc[k] * clock) + (NTSC_CLOCK >> 1)) / NTSC_CLOCK;
    per[k] = period;
    D(bug("per[%ld]=%ld ",k,per[k]));
    }
