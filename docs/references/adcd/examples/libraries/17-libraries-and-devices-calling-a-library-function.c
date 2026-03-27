/* Source: ADCD 2.1
 * Section: 17-libraries-and-devices-calling-a-library-function
 * Library: libraries
 * ADCD reference: libraries/17-libraries-and-devices-calling-a-library-function.md
 */

    System Functions Do Not Preserve D0, D1, A0 and A1.
    ---------------------------------------------------
    If you need to preserve D0, D1, A0, or A1 between calls to system
    functions, you will have to save and restore these values yourself.
    Amiga system functions use these registers as scratch registers and
    may write over the values your program left in these registers.  The
    system functions preserve the values of all other registers.  The
    result of a system function, if any, is returned in D0.


      Some Task             LVO Table                  LibFuncY()
      ---------         __________________             ----------
                       |                  |
                       |        ·         |
      main()           |        ·         |
         ·             | JMP to LibFuncZ  |       {
         ·             |- - - - - - - - - |         blah = openblah();
         x=       ____\| JMP to LibFuncY  |____\    dosomething();
      LibFuncY()      /|- - - - - - - - - |    /    closeblah(blah);
         ·             | JMP to LibFuncX  |       }
         ·             |        ·         |
                       |        ·         |
                       |__________________|
                       |                  |
                       |   Library Base   |
                       |__________________|
