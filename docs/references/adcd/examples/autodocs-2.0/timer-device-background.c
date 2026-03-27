/* Source: ADCD 2.1
 * Section: timer-device-background
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/timer-device-background.md
 */

    In the V1.2/V1.3 release, the timer device has problems with
    very short time requests.  When one of these is made, other
    timer requests may be finished inaccurately.  A side effect
    is that AmigaDOS requests such as "Delay(0);" or
    "WaitForChar(x,0);" are unreliable.
