/* Source: ADCD 2.1
 * Section: 35-transcendental-mathematics-library-ffp-transcendental
 * Library: libraries
 * ADCD reference: libraries/35-transcendental-mathematics-library-ffp-transcendental.md
 */

    Return sine and cosine of FFP variable.  This function accepts an FFP
    radian argument and returns the trigonometric sine as its result and
    the trigonometric cosine in the first parameter.  If both the sine
    and cosine are required for a single radian value, this function will
    result in almost twice the execution speed of calling the SPSin() and
    SPCos() functions independently.  For extremely large arguments where
    little or no precision would result, the computation is aborted and
    the "V" condition code is set.  A direct return to the caller is made.
