/* Source: ADCD 2.1
 * Section: intuition-library-getdefaultpubscreen
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-getdefaultpubscreen.md
 */

    This function actually "returns" in register D0 a pointer
    to the public screen.  Unfortunately, the lifespan of
    this pointer is not ensured; the screen could be closed
    at any time.  The *ONLY* legitimate use we can see for
    this return value is to compare for identity with the pointer
    to a public screen you either have a window open in, or
    a lock on using [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html), to determine if that
    screen is in fact the default screen.
