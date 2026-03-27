/* Source: ADCD 2.1
 * Section: 8-narrator-device-writing-to-the-narrator-device
 * Library: devices
 * ADCD reference: devices/8-narrator-device-writing-to-the-narrator-device.md
 */

    In a parallel formant synthesizer, the amplitudes of the formants
    need to be specified along with their frequencies.  These fields bias
    the amplitudes computed by the narrator device.  This is useful for
    creating different tonal balances (bass or treble), and listening to
    formants in isolation for educational purposes.  The adjustments are
    calibrated directly in ±1db (decibel) steps.  Using negative values
    will cause no problems; use of positive numbers can cause clipping.
    If you want to raise an amplitude, try cutting the others the same
    relative amount, then bring them all up equally until clipping is
    heard, then back them off.  This should produce an optimum setting.
    This field has a +31 to -32 db range and the value -32db is
    equivalent to -infinity, shutting that formant off completely.
