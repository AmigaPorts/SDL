/* Source: ADCD 2.1
 * Section: 18-what-is-a-library-changing-the-contents-of-a-library
 * Library: libraries
 * ADCD reference: libraries/18-what-is-a-library-changing-the-contents-of-a-library.md
 */

    Don't Do This!
    --------------
    For those of you who might be thinking about writing down the ROM
    addresses returned by [SetFunction()](../Includes_and_Autodocs_2._guide/node037C.html) and using them in some other
    programs: Forget It.  The address returned by SetFunction() is
    only good on the current system at the current time.
