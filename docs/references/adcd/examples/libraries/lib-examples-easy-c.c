/* Source: ADCD 2.1
 * Section: lib-examples-easy-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-easy-c.md
 */

    IntuitionBase=(struct IntuitionBase *)
                  OpenLibrary("intuition.library",33L);

    if(IntuitionBase)           /* Check to see if it actually opened.   */
        {                       /* The Intuition library is now open so  */
        DisplayBeep(0L);        /* any of its functions may be used.     */

        CloseLibrary(IntuitionBase); /* Always close a library if not    */
                                     /* in use.                          */
        }
    else                        /* The library did not open so return an */
       {                        /* error code.  The exit() function is   */
       exit(20);                /* not part of the OS, it is part of the */
       }                        /* compiler link library.                */
